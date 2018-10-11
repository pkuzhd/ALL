def separate(poker): # 拆分手牌牌型并组成基本牌集合
    res = []
    if len(poker) == 0:
        return res
    myPoker = [i for i in poker]
    newPoker = ordinalTransfer(myPoker)
    if 16 in newPoker and 17 in newPoker: # 单独列出火箭/小王、大王
        newPoker = newPoker[:-2]
        myPoker = myPoker[:-2]
        res += [[16, 17]]
    elif 16 in newPoker:
        newPoker = newPoker[:-1]
        myPoker = myPoker[:-1]       
        res += [[16]]
    elif 17 in newPoker:
        newPoker = newPoker[:-1]
        myPoker = myPoker[:-1]     
        res += [[17]]
        

        
    singlePoker = list(set(newPoker)) # 都有哪些牌
    singlePoker.sort()

    for i in singlePoker:    # 分出炸弹，其实也可以不分，优化点之一
        if newPoker.count(i) == 4:
            idx = newPoker.index(i)
            val = myPoker[idx]
            res += [ myPoker[idx:idx+4] ]
            newPoker = newPoker[0:idx] + newPoker[idx+4:]
            myPoker = myPoker[0:idx] + myPoker[idx+4:]

    # 为了简便处理带2的情形，先把2单独提出来
    specialCount, specialRes = 0, []
    if 15 in newPoker:
        specialCount = newPoker.count(15)
        idx = newPoker.index(15)
        specialRes = [15 for i in range(specialCount)]
        newPoker = newPoker[:-specialCount]
        myPoker = myPoker[:-specialCount]

    def findSeq(p, dupTime, minLen): # 这里的p是点数，找最长的顺子，返回值为牌型组合
        resSeq, tmpSeq = [], []
        singleP = list(set(p))
        singleP.sort()
        for curr in singleP:
            if p.count(curr) >= dupTime:
                if len(tmpSeq) == 0:
                    tmpSeq = [curr]
                    continue
                elif curr == (tmpSeq[-1] + 1):
                    tmpSeq += [curr]
                    continue
            if len(tmpSeq) >= minLen:
                tmpSeq = [i for i in tmpSeq for j in range(dupTime)]
                resSeq += [tmpSeq]
            tmpSeq = []
        return resSeq

    def subSeq(allp, p, subp): # 一定保证subp是p的子集
        singleP = list(set(subp))
        singleP.sort()
        for curr in singleP:
            idx = p.index(curr)
            countP = subp.count(curr)
            p = p[0:idx] + p[idx+countP:]
            allp = allp[0:idx] + allp[idx+countP:]
        return allp, p
    
    # 单顺：1，5；双顺：2，3；飞机：3，2；航天飞机：4，2。因为前面已经把炸弹全都提取出来，所以这里就不主动出航天飞机了

    para = [[1,5],[2,3],[3,2]]
    validChoice = [0,1,2]
    allSeq = [[], [], []] # 分别表示单顺、双顺、三顺（飞机不带翼）
    restRes = []
    while(True): # myPoker，这里会找完所有的最长顺子
        if len(newPoker) == 0 or len(validChoice) == 0:
            break
        dupTime = random.choice(validChoice)
        tmp = para[dupTime]
        newSeq = findSeq(newPoker, tmp[0], tmp[1])
        for tmpSeq in newSeq:
            myPoker, newPoker = subSeq(myPoker, newPoker, tmpSeq)
        if len(newSeq) == 0:
            validChoice.remove(dupTime)
        else:
            allSeq[dupTime] += [tmpSeq]
    res += allSeq[0] + allSeq[1] # 对于单顺和双顺没必要去改变
    plane = allSeq[2]

    allRetail = [[], [], []] # 分别表示单张，对子，三张
    singlePoker = list(set(newPoker)) # 更新目前为止剩下的牌，newPoker和myPoker是一一对应的
    singlePoker.sort()
    for curr in singlePoker:
        countP = newPoker.count(curr)
        allRetail[countP-1] += [[curr for i in range(countP)]]

    # 接下来整合有需要的飞机or三张 <-> 单张、对子。这时候的飞机和三张一定不会和单张、对子有重复。
    # 如果和单张有重复，即为炸弹，而这一步已经在前面检测炸弹时被检测出
    # 如果和对子有重复，则同一点数的牌有5张，超出了4张

    # 先整合飞机
    for curr in plane:
        lenKind = int(len(curr) / 3)
        tmp = curr
        for t in range(2): # 分别试探单张和对子的个数是否足够
            tmpP = allRetail[t]
            if len(tmpP) >= lenKind:
                tmp += [i[j] for i in tmpP[0:lenKind] for j in range(t+1)]
                allRetail[t] = allRetail[t][lenKind:]
                break
        res += [tmp]

    if specialCount == 3:
        allRetail[2] += [specialRes]
    elif specialCount > 0 and specialCount <= 2:
        allRetail[specialCount - 1] += [specialRes]
    # 之后整合三张
    for curr in allRetail[2]: # curr = [1,1,1]
        tmp = curr
        for t in range(2):
            tmpP = allRetail[t]
            if len(tmpP) >= 1:
                tmp += tmpP[0]
                allRetail[t] = allRetail[t][1:]
                break
        res += [tmp]
    
    res += allRetail[0] + allRetail[1]
    return res
