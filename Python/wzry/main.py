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
    while True:
        if state == start:
            while True:
                img = screen_shot()
                if is_play(img):
                    # 点击闯关
                    state = play
                    break
                time.sleep(2)
        elif state == play:
            while True:
                img = screen_shot()
                if is_not_auto(img):
                    # 点击自动
                    state = auto
                    break
                time.sleep(5)
        elif state == auto:
            while True:
                img = screen_shot()
                if is_skip_blue(img):
                    # 点击跳过
                    continue
                elif is_skip_yellow(img)
                    # 点击跳过
                    state = skip_all
                    break
                time.sleep(5)
        elif state == skip_all:
            while True:
                img = screen_shot()
                if is_continue(img):
                    # 点击屏幕继续
                    state = continued
                    break
                time.sleep(2)
        elif state == continued:
            while True:
                img = screen_shot()
                if is_replay(img):
                    # 点击重新开始
                    state = replay
                    break
                time.sleep(2)
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
            else
                time.sleep(5)



    

if __name__ == '__main__':
    main()