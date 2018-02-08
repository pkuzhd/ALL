import os, sys
import subprocess
import time
import math
import operator
from functools import reduce
from PIL import Image

error     = -1
start     =  0
play      =  1
auto      =  2
skip_all  =  3
continued =  4
replay    =  5

wait_auto = 15
wait_replay = 1

replay_button   = (1450, 930, 1740, 1040)
play_button     = (1320, 860, 1610,  970)
auto_button     = (1760,  20, 1820,   60)
skip_button     = (1690,  26, 1900,  100)
continue_button = ( 820, 990, 1100, 1040)

img_replay_button      = Image.open("picture/replay_button.png")
img_play_button        = Image.open("picture/play_button.png")
img_not_auto_button    = Image.open("picture/not_auto_button.png")
img_skip_button_yellow = Image.open("picture/skip_button_yellow.png")
img_skip_button_blue   = Image.open("picture/skip_button_blue.png")
img_continue_button    = Image.open("picture/continue_button.png")

def position(button):
    return (button[0]+button[2])//2, (button[1]+button[3])//2

def click(button):
    x, y = position(button)
    press_time = 200
    cmd = 'adb shell input swipe {x1} {y1} {x2} {y2} {duration}'.format(
            x1=x, y1=y, x2=x, y2=y, duration=press_time)
    os.system(cmd)

def screen_shot(name='new_screen_shot'):
    process = subprocess.Popen('adb shell screencap -p', shell=True, stdout=subprocess.PIPE)
    binary_screenshot = process.stdout.read()
    binary_screenshot = binary_screenshot.replace(b'\r\n', b'\n')
    f = open('temp/{}.png'.format(name), 'wb')
    f.write(binary_screenshot)
    f.close()
    img = Image.open('temp/{}.png'.format(name))
    return img

def is_eq(img1, img2):
    h1 = img1.histogram()
    h2 = img2.histogram()
    result = math.sqrt(reduce(operator.add, list(map(lambda a,b: (a-b)**2, h1, h2)))/len(h1) )
    return result < 10.0
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


def main():
    state = start
    times = 0
    money = 0
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
            print('等待点击"闯关"')
            while True:
                img = screen_shot()
                if is_play(img):
                    click(play_button)
                    times = times + 1
                    money = money + 19
                    print('闯关')
                    state = play
                    print("start wait {} seconds".format(wait_auto))
                    time.sleep(wait_auto)
                    print("end wait {} seconds".format(wait_auto))
                    break
                time.sleep(2)
        if state == play:
            print('等待点击"自动"')
            while True:
                img = screen_shot()
                if is_not_auto(img):
                    click(auto_button)
                    print('自动')
                    state = auto
                    break
                wait_auto = wait_auto + 1
                print("start wait 2 seconds")
                time.sleep(2)
                print("end wait 2 seconds")
        if state == auto:
            print('等待所有跳过')
            while True:
                img = screen_shot()
                if is_skip_blue(img):
                    click(skip_button)
                    print('点击蓝色跳过')
                    continue
                elif is_skip_yellow(img):
                    click(skip_button)
                    print('点击黄色跳过')
                    state = skip_all
                    break
                elif is_continue(img):
                    click(continue_button)
                    state = continued
                    print("点击屏幕继续")
                    break
                time.sleep(2)
        if state == skip_all:
            while True:
                img = screen_shot()
                if is_continue(img):
                    click(continue_button)
                    state = continued
                    print("点击屏幕继续")
                    break
                print('start 2')
                time.sleep(2)
                print('end 2')
        if state == continued:
            print('等待点击"再次挑战"')
            time.sleep(wait_replay)
            while True:
                img = screen_shot()
                if is_replay(img):
                    click(replay_button)
                    state = start
                    print("点击再次挑战")
                    break
                    wait_replay = wait_replay + 1
                print("start 2")
                time.sleep(2)
                print("end 2")
        elif state == error:
            img = screen_shot()
            if is_play(img):
                pass
            elif is_replay(img):
                pass
            elif is_continue(img):
                pass
            elif is_skip_yellow(img):
                pass
            elif is_skip_blue(img):
                pass
            elif is_not_auto(img):
                pass
            else:
                time.sleep(5)



    

if __name__ == '__main__':
    main()