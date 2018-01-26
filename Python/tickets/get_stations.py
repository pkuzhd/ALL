# -*- coding: utf-8 -*-
import re
import requests
from pprint import *

def main():
    url = 'https://kyfw.12306.cn/otn/resources/js/framework/station_name.js?station_version=1.9019'
    r = requests.get(url, verify=False)
    pattern = '([\u4e00-\u9fa5]+)\|([A-Z]+)'
    result = re.findall(pattern, r.text)
    text = pformat(dict(result), indent=4)
    f = open('stations.py', 'w', encoding='utf-8')
    f.write('stations = '+text)
    f.close()


if __name__ == '__main__':
    main()