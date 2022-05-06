import requests
import csv
import time
import re
url = 'https://m.sm.cn/api/rest?format=json&method=Huoshenshan.riskArea&_=1628665447912'
r = requests.get(url)
sum=0
response_dict = r.json()
dicts = response_dict['data']
updatetime = dicts['dateline']
citymaps = dicts['map']
count = dicts['count']
for item in updatetime:
    print('风险地区%s更新时间：%s' % (str(item), str(updatetime[item])))
results = []
ShangHai=[]
for item in citymaps:
    for item1 in item:
        for item2 in citymaps[item1]:
            areas = citymaps[item1][item2]
            for area in areas:
                result = []
                grade = str(area['grade'])
                if grade == '1':
                    result.append('中风险')
                if grade == '2':
                    result.append('高风险')

                result.append(str(item2))
                result.append(str(area['city'] + '市' + area['addr']))
                #print('风险等级:%s,省：%s,具体位置：%s'%(str(area['grade']),str(item2),str(area['city']+area['addr'])))
                #print(area['city']+area['addr'])
                results.append(result)
                if str(item2)=="上海":
                    sum+=1
                    ShangHai.append(area['grade'])
                    ShangHai.append(item2)
                    ShangHai.append(area['city'])
                    ShangHai.append(area['addr'])
header = ['风险等级', '省份', '区域']
header1 = ['更新时间：', updatetime['1']]
filename = '全国最新风险等级区域' + time.strftime("%Y-%m-%d", time.localtime()) + '.csv'
print(len(results))
print(filename)
print(f"上海风险区{sum}")
for i in ShangHai:
    print(i)
with open(filename, 'w', newline='',encoding='utf-8') as f:
    f_csv = csv.writer(f)
    f_csv.writerow(ShangHai)