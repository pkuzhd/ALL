# from multiprocessing import Process
# import os, time

# # 子进程要执行的代码
# def run_proc(name, t):
#     print('Run child process %s (%s)...' % (name, os.getpid()))
#     time.sleep(t)

# if __name__=='__main__':
#     print('Parent process %s.' % os.getpid())
#     p1 = Process(target=run_proc, args=('test1', 0.2))
#     p2 = Process(target=run_proc, args=('test2', 0.1))
#     print('Child process will start.')
#     p1.start()
#     p2.start()
#     # p1.join()
#     print('Child process end.')

from multiprocessing import Pool
import os, time, random

def long_time_task(name, t):
    print('Run task %s (%s)...' % (name, os.getpid()))
    start = time.time()
    time.sleep(t+1)
    end = time.time()
    print('Task %s runs %0.2f seconds.' % (name, (end - start)))

if __name__=='__main__':
    print('Parent process %s.' % os.getpid())
    p = Pool(4)
    for i in range(5):
        p.apply_async(long_time_task, args=(i, i))
    print('Waiting for all subprocesses done...')
    p.close()
    p.join()
    print('All subprocesses done.')