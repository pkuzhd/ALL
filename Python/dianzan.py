import time, threading, requests

i = 0

def main():
    url = 'http://www.9org.com/47/trailer/society-praise?type=add'
    global i
    while True:
        r = requests.get(url)
        r.raise_for_status()
        i += 1
        print(str(i)+''+r.text)


t1 = threading.Thread(target=main)
t2 = threading.Thread(target=main)
t1.start()
t2.start()
t1.join()
t2.join()

