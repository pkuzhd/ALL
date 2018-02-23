import subprocess

process = subprocess.Popen('adb shell screencap -p', shell=True, stdout=subprocess.PIPE)
binary_screenshot = process.stdout.read()
binary_screenshot = binary_screenshot.replace(b'\r\n', b'\n')

f = open('123', 'wb')
f.write(binary_screenshot)
f.close()