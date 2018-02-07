import os, sys
import subprocess
import time
import math
import operator
from functools import reduce
from PIL import Image

replay_button = (1450, 930, 1740, 1040)
play_button = (1320, 860, 1610, 970)
auto_button = (1760, 20, 1820, 60)
skip_button = (1690, 26, 1900, 100)
continue_button = (820, 990, 1100, 1040)

def is_eq(img1, img2):
    h1 = img1.histogram()
    h2 = img2.histogram()
    result = math.sqrt(reduce(operator.add, list(map(lambda a,b: (a-b)**2, h1, h2)))/len(h1) )
    return result

img = Image.open("skip_blue.png")
img.crop(skip_button).save('skip_button_blue.png')


