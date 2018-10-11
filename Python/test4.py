import os
    
path = "C:\\"
# os.chdir(path)
filepath = "F:\\Github\\"
# print(os.getcwd())
# print(os.listdir())
# print(os.path.getsize(filepath))
def getFileSize(filePath, size=0):
    for root, dirs, files in os.walk(filePath):
        for f in files:
            t_size = os.path.getsize(os.path.join(root, f))
            size += t_size
            print(f, t_size)
    return size

# print(getFileSize("."))
# for root, dirs, files in os.walk("."):
#     print(os.getcwd() + root[1:], dirs, files)
# print(os.path.join())

file_list = []

def walk(rootPath, depth=0, func=lambda *k,**kw:1):
    if depth == 0:
        func(rootPath)
    try:
        for item in os.listdir(rootPath):
            files = []
            dirs = []
            if os.path.isdir(os.path.join(rootPath, item)):
                dirs.append(item)
            else:
                files.append(item)
                path = os.path.join(rootPath, item)
                file_list.append((path , os.path.getsize(path)))
            for name in dirs:
                func("  "*(depth+1)+name)
                walk(os.path.join(rootPath, name), depth+1, func)
            for name in files:
                func("  "*(depth+1)+name)
    except PermissionError as e:
        pass
    except Exception as e:
        pass

for path in ("F:\\", ):
    file_list = []
    walk(path, func=print)
    # file_list.sort(key=lambda x:-x[1])
    # for file, size in file_list:
    #     print(file, size) 
    # print(os.path.split(file)[1], size)

