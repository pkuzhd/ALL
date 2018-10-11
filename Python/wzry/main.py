import os, sys
import subprocess
import time
import math
import operator
from functools import reduce
from PIL import Image

wait_auto = 15
wait_replay = 1
adb_id = None
max_money = 4000

error     = -1
start     =  0
play      =  1
auto      =  2
skip_all  =  3
continued =  4
replay    =  5

p = 1
state = start
money = 0
t0 = time.time()
t_start = time.time()
t_end = time.time()
t_end = time.time()
times = 0

replay_button    = (1450, 930, 1740, 1040)
play_button      = (1320, 860, 1610,  970)
auto_button      = (1760,  20, 1820,   60)
skip_button      = (1690,  26, 1900,  100)
continue_button  = ( 820, 990, 1100, 1040)
next_button      = (1460, 920, 1758, 1020)
challage_button  = ( 800, 800, 1100,  900)
adventure_button = (1460, 790, 1758,  880)

img_replay_button      = Image.open("picture/replay_button.png")
img_play_button        = Image.open("picture/play_button.png")
img_not_auto_button    = Image.open("picture/not_auto_button.png")
img_skip_button_yellow = Image.open("picture/skip_button_yellow.png")
img_skip_button_blue   = Image.open("picture/skip_button_blue.png")
img_continue_button    = Image.open("picture/continue_button.png")
img_next_button        = Image.open("picture/next_button.png")
img_challage_button    = Image.open("picture/challage_button.png")
img_adventure_button   = Image.open("picture/adventure_button.png")

def position(button):
    return (button[0]+button[2])//2, (button[1]+button[3])//2

def click(button):
    global adb_id
    x, y = position(button)
    press_time = 200
    cmd = 'adb -s {adb_id} shell input swipe {x1} {y1} {x2} {y2} {duration}'.format(
            adb_id=adb_id, x1=x, y1=y, x2=x, y2=y, duration=press_time)
    os.system(cmd)

def screen_shot():
    global p, adb_id
    process = subprocess.Popen('adb -s {} shell screencap -p'.format(adb_id), shell=True, stdout=subprocess.PIPE)
    binary_screenshot = process.stdout.read()
    binary_screenshot = binary_screenshot.replace(b'\r\n', b'\n')
    f = open('temp/{}_{}.png'.format(adb_id, p), 'wb')
    f.write(binary_screenshot)
    f.close()
    img = Image.open('temp/{}_{}.png'.format(adb_id, p))
    p += 1
    return img

def is_eq(img1, img2):
    h1 = img1.histogram()
    h2 = img2.histogram()
    result = math.sqrt(reduce(operator.add, list(map(lambda a,b: (a-b)**2, h1, h2)))/len(h1) )
    print(result)
    return result < 40.0
def is_replay(img):
    return is_eq(img_replay_button  , img.crop(replay_button))
def is_play(img):
    return is_eq(img_play_button    , img.crop(play_button))
def is_not_auto(img):
    return is_eq(img_not_auto_button    , img.crop(auto_button))
def is_skip_yellow(img):
    return is_eq(img_skip_button_yellow, img.crop(skip_button))
def is_skip_blue(img):
    return is_eq(img_skip_button_blue, img.crop(skip_button))
def is_continue(img):
    return is_eq(img_continue_button, img.crop(continue_button))
def is_next(img):
    return is_eq(img_next_button, img.crop(next_button))
def is_challage(img):
    return is_eq(img_challage_button, img.crop(challage_button))
def is_adventure(img):
    return is_eq(img_adventure_button, img.crop(adventure_button))
def my_operator(img):
    global state, t0, t_start, t_end, money, times
    if is_adventure(img):
        click(adventure_button)
        state = start
        return
    if is_challage(img):
        click(challage_button)
        state = start
        return
    if is_next(img):
        click(next_button)
        state = start
        return
    if is_play(img):
        click(play_button)
        state = play
        time.sleep(15)
        return
    if is_replay(img):
        click(replay_button)
        state = start
        money += 19
        os.system("cls")
        t_end = time.time()
        total_s = int(t_end-t0)
        # wait_auto = wait_auto
        # wait_replay = wait_replay
        times += 1
        print("第{}次用时{}s, 总用时:{}h {}min {}s, 总金币:{}".format(times, int(t_end-t_start), total_s//3600, (total_s//60)%60, total_s%60, money))
        t_start = time.time()
        time.sleep(2)
        return
    elif is_not_auto(img):
        click(auto_button)
        state = auto
    elif is_skip_yellow(img):
        click(skip_button)
    elif is_skip_blue(img):
        click(skip_button)
    elif is_continue(img):
        click(continue_button)
        state = continued
    else:
        pass

def main():
    global wait_auto, wait_replay, state, adb_id
    state = start
    times = 0
    money = 0
    adb_id = input('请输入手机ID:')
    t0 = time.time()
    t_start = time.time()
    while True:
        if state == start:
            t_end = time.time()
            os.system("cls")
            total_s = int(t_end-t0)
            print("wait_auto: {}".format(wait_auto))
            print("wait_replay: {}".format(wait_replay))
            # wait_auto = wait_auto
            # wait_replay = wait_replay
            print("第{}次用时{}s, 总用时:{}h {}min {}s, 总金币:{}".format(times, int(t_end-t_start), total_s//3600, (total_s//60)%60, total_s%60, money))
            t_start = time.time()
            # if money > max_money:
            #     os.system("adb shell reboot -p")
            #     os.system("shutdown -s -t 60")
            #     sys.exit()
            print('等待点击"闯关"')
            while True:
                img = screen_shot()
                my_operator(img)
                time.sleep(2)
        if state == play:
            print('等待点击"自动"')
            while True:
                img = screen_shot()
                my_operator(img)
                wait_auto = wait_auto + 1
                print("start wait 2 seconds")
                time.sleep(2)
                print("end wait 2 seconds")
        if state == auto:
            print('等待所有跳过')
            while True:
                img = screen_shot()
                my_operator(img)
                time.sleep(2)
        if state == skip_all:
            while True:
                img = screen_shot()
                my_operator(img)
                print('start 2')
                time.sleep(2)
                print('end 2')
        if state == continued:
            print('等待点击"再次挑战"')
            time.sleep(wait_replay)
            while True:
                img = screen_shot()
                my_operator(img)
                print("start 2")
                time.sleep(2)
                print("end 2")
        else:
            img = screen_shot()
            my_operator(img)



    

if __name__ == '__main__':
    main()