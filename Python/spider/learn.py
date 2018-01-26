import requests

url = 'https://e4ftl01.cr.usgs.gov//DP106/MOLT/MOD13Q1.006/2000.02.18/MOD13Q1.A2000049.h27v05.006.2015136104801.hdf'
data = {
    "username":"guoheyi",
    "password":"aGUOHEYI1"
    }
r = requests.get(url, data=data)

# r.encoding = 'utf-8'

# print(r.text)
r.raise_for_status()