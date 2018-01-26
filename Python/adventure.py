import os
from time import sleep
press_time = 200

# 魔女回忆

1621, 987 # 下一步, 再次挑战
1480, 908 # 闯关
1795, 56 # 自动


t = 0
while True:
    print(t)
    t += 1
    swipe_x1, swipe_y1 = 1480, 908 # 闯关
    cmd = 'adb shell input swipe {x1} {y1} {x2} {y2} {duration}'.format(
            x1=swipe_x1,
            y1=swipe_y1,
            x2=swipe_x1,
            y2=swipe_y1,
            duration=press_time)
    print(cmd)
    os.system(cmd)


    sleep(26)
    swipe_x1, swipe_y1 = 1795, 56 # 自动
    cmd = 'adb shell input swipe {x1} {y1} {x2} {y2} {duration}'.format(
            x1=swipe_x1,
            y1=swipe_y1,
            x2=swipe_x1,
            y2=swipe_y1,
            duration=press_time)
    print(cmd)
    os.system(cmd)

    sleep(26)
    swipe_x1, swipe_y1 = 1809, 78 # 跳过
    cmd = 'adb shell input swipe {x1} {y1} {x2} {y2} {duration}'.format(
            x1=swipe_x1,
            y1=swipe_y1,
            x2=swipe_x1,
            y2=swipe_y1,
            duration=press_time)
    print(cmd)
    os.system(cmd)

    sleep(8)
    swipe_x1, swipe_y1 = 1728, 70 # 跳过
    cmd = 'adb shell input swipe {x1} {y1} {x2} {y2} {duration}'.format(
            x1=swipe_x1,
            y1=swipe_y1,
            x2=swipe_x1,
            y2=swipe_y1,
            duration=press_time)
    print(cmd)
    os.system(cmd)

    sleep(7)
    swipe_x1, swipe_y1 = 500, 500 # 跳过
    cmd = 'adb shell input swipe {x1} {y1} {x2} {y2} {duration}'.format(
            x1=swipe_x1,
            y1=swipe_y1,
            x2=swipe_x1,
            y2=swipe_y1,
            duration=press_time)
    print(cmd)
    os.system(cmd)

    sleep(4)
    swipe_x1, swipe_y1 = 1621, 987 # 下一步, 再次挑战
    cmd = 'adb shell input swipe {x1} {y1} {x2} {y2} {duration}'.format(
            x1=swipe_x1,
            y1=swipe_y1,
            x2=swipe_x1,
            y2=swipe_y1,
            duration=press_time)
    print(cmd)
    os.system(cmd)
    sleep(7)