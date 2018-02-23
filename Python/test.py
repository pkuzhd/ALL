lst = [0 for i in range(10)]

def _judge(lst, depth, two=False):
    if sum(lst) == 0:
        return two
    if lst[depth] == 0:
        return _judge(lst, depth+1, two)
    # 将
    if not two:
        if lst[depth] >= 2:
            newlst = lst[:]
            newlst[depth] -= 2
            if _judge(newlst, depth, True):
                return True
    # 111
    if lst[depth] >= 3:
        newlst = lst[:]
        newlst[depth] -= 3
        if _judge(newlst, depth, two):
            return True
    # 123
    if depth <= 7 and lst[depth] >= 1 and lst[depth+1] >= 1 and lst[depth+2] >= 1:
        newlst = lst[:]
        newlst[depth] -= 1
        newlst[depth+1] -= 1
        newlst[depth+2] -= 1
        if _judge(newlst, depth, two):
            return True
    return False

def judge(lst, flag=0):
    if flag == 0:
        for i in range(1, 10):
            newlst = lst[:]
            newlst[i] += 1
            if not judge(newlst, flag=1):
                return False
        return True
    else:
        return _judge(lst, 1)

def f(depth):
    if depth == 10:
        if sum(lst) == 13 and judge(lst):
            print(lst)
        return
    for i in range(4):
        lst[depth] = i
        if sum(lst) > 13:
            lst[depth] = 0
            return
        elif sum(lst) == 13 and judge(lst):
            print(lst)
            lst[depth] = 0
            return
        else:
            f(depth+1)
            lst[depth] = 0

f(1)