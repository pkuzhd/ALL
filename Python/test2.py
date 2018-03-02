for _1 in range(4):
    for _2 in range(4):
        for _3 in range(4):
            for _4 in range(4):
                for _5 in range(4):
                    for _6 in range(4):
                        for _7 in range(4):
                            for _8 in range(4):
                                for _9 in range(4):
                                    for _10 in range(4):
                                        count = [0 for i in range(4)]
                                        t = (_1, _2, _3, _4, _5, _6, _7, _8, _9, _10)
                                        for i in (_1, _2, _3, _4, _5, _6, _7, _8, _9, _10):
                                            count[i] = count[i] + 1
                                        if not (_2-_5+4)%4==2:
                                            continue
                                        if not ((_3!=_6 and _6==_2 and _6==_4)\
                                             or (_3!=_6 and _3==_2 and _3==_4)\
                                             or (_3!=_2 and _6==_3 and _3==_4)\
                                             or (_3!=_4 and _3==_2 and _6==_3)):
                                            continue
                                        if _4==0 and _1!=_5:
                                            continue
                                        elif _4==1 and _2!=_7:
                                            continue
                                        elif _4==2 and _1!=_9:
                                            continue
                                        elif _4==3 and _6!=_10:
                                            continue
                                        if _5==0 and _8!=0:
                                            continue
                                        elif _5==1 and _4!=1:
                                            continue
                                        elif _5==2 and _9!=2:
                                            continue
                                        elif _5==3 and _7!=3:
                                            continue
                                        if _6==0 and not (_2==_8 and _4==_8):
                                            continue
                                        elif _6==1 and not (_1==_8 and _6==_8):
                                            continue
                                        elif _6==2 and not (_3==_8 and _10==_8):
                                            continue
                                        elif _6==3 and not (_5==_8 and _9==_8):
                                            continue
                                        if _7==0 and not min(count)==2:
                                            continue
                                        elif _7==1 and not min(count)==1:
                                            continue
                                        elif _7==2 and not min(count)==0:
                                            continue
                                        elif _7==3 and not min(count)==3:
                                            continue
                                        if _8==0 and _7!=1:
                                            continue
                                        elif _8==1 and abs(_5-1)!=1:
                                            continue
                                        elif _8==2 and abs(_2-2)!=1:
                                            continue
                                        elif _8==3 and abs(_10-3)!=1:
                                            continue
                                        # TODO
                                        if _10==0 and not max(count)-min(count)==3:
                                            continue
                                        elif _10==1 and not max(count)-min(count)==2:
                                            continue
                                        elif _10==2 and not max(count)-min(count)==4:
                                            continue
                                        elif _10==3 and not max(count)-min(count)==1:
                                            continue




                                        print(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10)