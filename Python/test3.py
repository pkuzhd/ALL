# import random

# print([random.randint(1, 100) for i in range(50000)])

# from pythonds.basic.queue import Queue

from num import a

class Queue:
    def __init__(self):
        self.items = []
    def isEmpty(self):
        return self.items == []
    def enqueue(self, item):
        self.items.insert(0, item)
    def dequeue(self):
        return self.items.pop()
    def size(self):
        return len(self.items)

#基数排序函数
def radixSort(numberlist):
    #main队列用来记录每次排序之后的数列
    main = Queue()
    #queue_list是十个队列的列表，用来对每个位进行排序
    queue_list = [Queue() for i in range(10)]
    #lenmax用来记录最大的位数
    lenmax = 0
    #依次入队列并得出lenmax
    for num in numberlist:
        lenmax = len(num) if len(num) > lenmax else lenmax
        main.enqueue(int(num))
    #依次对每一位进行排序
    for times in range(lenmax):
        while not main.isEmpty():
            num = main.dequeue()
            queue_list[num // (10 ** times) % 10].enqueue(num)
        for i in range(10):
            while not queue_list[i].isEmpty():
                main.enqueue(queue_list[i].dequeue())
    #以列表的形式输出
    sortedlist = []
    while not main.isEmpty():
        sortedlist.append(str(main.dequeue())) 
    #return sortedlist
    #根据计蒜客要求改为字符串输出
    return " ".join(sortedlist)

numberlist = a.split()
# print(sorted(numberlist))
print(radixSort(numberlist))
