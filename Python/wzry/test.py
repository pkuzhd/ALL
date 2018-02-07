import os, sys
import subprocess
import time
import math
import operator
from functools import reduce

from PIL import Image

replay_button = (1450, 930, 1740, 1040)


def screen_shot(name='new_screen_shot'):
    t1 = time.time()
    process = subprocess.Popen('adb shell screencap -p', shell=True, stdout=subprocess.PIPE)
    binary_screenshot = process.stdout.read()
    binary_screenshot = binary_screenshot.replace(b'\r\n', b'\n')
    t2 = time.time()
    f = open('{}.png'.format(name), 'wb')
    f.write(binary_screenshot)
    f.close()
    t3 = time.time()
    print(t3-t1)

def is_eq(img1, img2):
    h1 = img1.histogram()
    h2 = img2.histogram()
    result = math.sqrt(reduce(operator.add, list(map(lambda a,b: (a-b)**2, h1, h2)))/len(h1) )
    return result

def main():
    img = Image.open("replay_button.png")
    screen_shot("tmp")
    tmp_img = Image.open("tmp.png")
    print(is_eq(img, tmp_img.crop(replay_button)))




if __name__ == "__main__":
    main()

