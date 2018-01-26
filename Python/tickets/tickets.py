# -*- coding: utf-8 -*-
'''Train tickets query via CLI

Usage:
    ticket [-dgktz] <from> <to> <date>

Options:
    -h --help       Show this screen
    -d              动车
    -g              高铁
    -k              快速
    -t              特快
    -z              直达
'''

import requests
from docopt import docopt
from stations import stations
from prettytable import PrettyTable
from requests.packages.urllib3.exceptions import InsecureRequestWarning
# 禁用安全请求警告
requests.packages.urllib3.disable_warnings(InsecureRequestWarning)

def cli():
    arguments = docopt(__doc__, version='Tickets 1.0')
    from_station = stations[arguments['<from>']]
    to_station = stations[arguments['<to>']]
    date = arguments['<date>']
    url = ('https://kyfw.12306.cn/otn/leftTicket/query?'
           'leftTicketDTO.train_date={}&'
           'leftTicketDTO.from_station={}&'
           'leftTicketDTO.to_station={}&'
           'purpose_codes=ADULT'.format(date, from_station, to_station))
    print(url)
    r = requests.get(url, verify=False)
    raw_trains = r.json()['data']['result']
    pt = PrettyTable()
    pt._set_field_names('车次 车站 时间 历时 一等座 二等座 软卧 硬卧 硬座 无座'.split())
    for raw_train in raw_trains:
        data_list = raw_train.split('|')
        
        train_no = data_list[3]                           # 车次
        start_station_code = data_list[4]                 # 始发站
        end_station_code = data_list[5]                   # 终点站
        from_station_code = data_list[6]                  # 出发站
        to_station_code = data_list[7]                    # 到达站
        start_time = data_list[8]                         # 出发时间
        arrive_time = data_list[9]                        # 到达时间
        total_time = data_list[10]                        # 历时
        # canWebBuy = data_list[11]
        # yp_info = data_list[12]
        # start_train_date = data_list[13]
        # train_seat_feature = data_list[14]
        # location_code = data_list[15]
        # from_station_no = data_list[16]
        # to_station_no = data_list[17]
        # is_support_card = data_list[18]
        # controlled_train_flag = data_list[19]
        gg_num = data_list[20] or "--"                    #
        gr_num = data_list[21] or "--"                    # 高级软卧
        qt_num = data_list[22] or "--"                    #
        soft_sleep = data_list[23] or "--"                # 软卧
        soft_seat = data_list[24] or "--"                 #
        tz_num = data_list[25] or "--"                    #
        no_seat = data_list[26] or "--"                   # 无座
        yb_num = data_list[27] or "--"                    #
        hard_sleep = data_list[28] or "--"                # 硬卧
        hard_seat = data_list[29] or "--"                 # 硬座
        second_class_seat = data_list[30] or "--"         # 二等座
        first_class_seat = data_list[31] or "--"          # 一等座
        swz_num = data_list[32] or "--"                   # 商务座特等座
        srrb_num = data_list[33] or "--"                  # 动卧
        # yp_ex = data_list[34]
        # seat_types = data_list[35]
        pt.add_row([train_no,
                   '\n'.join([from_station_code, to_station_code]),
                   '\n'.join([start_time, arrive_time]), total_time,
                   first_class_seat, second_class_seat,
                   soft_sleep, hard_sleep, hard_seat, no_seat])

    print(pt)



if __name__ == '__main__':
    cli()