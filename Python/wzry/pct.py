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
next_button = (1460, 920, 1758, 1020)
challage_button = (800, 800, 1100, 900)
adventure_button = (1460, 790, 1758, 880)

def change(button):
	return button
	return (1080-button[3], button[0], 1080-button[1], button[2])

def is_eq(img1, img2):
    h1 = img1.histogram()
    h2 = img2.histogram()
    result = math.sqrt(reduce(operator.add, list(map(lambda a,b: (a-b)**2, h1, h2)))/len(h1) )
    return result

# img = Image.open("t.png")
# img.crop(change(adventure_button)).save('picture/adventure_button.png')

img1 = Image.open("picture/not_auto_button.png")
img2 = Image.open("picture/auto_button.png")

print(is_eq(img1, img2))

