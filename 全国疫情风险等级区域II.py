import requests
import csv
import time
import random
import json
import jsonpath
url = 'https://m.sm.cn/api/rest?format=json&method=Huoshenshan.riskArea&_=1628665447912'
url_= "http://www.lagou.com/lbs/getAllCitySearchLabels.json"
h=[
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.127 Safari/537.36",
    "Mozilla / 5.0(Macintosh;IntelMacOSX10_7_0) AppleWebKit / 535.11(KHTML, likeGecko) Chrome / 17.0.963.56Safari / 535.11",
    "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1; Maxthon 2.0)",
    "Mozilla/5.0 (Macintosh; U; Intel Mac OS X 10_6_8; en-us) AppleWebKit/534.50 (KHTML, like Gecko) Version/5.1 Safari/534.50",
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.127 Safari/537.36 Edg/100.0.1185.50"
]
header = {"User-Agent":str(random.choice(h))}
response_=requests.get(url=url_,headers=header)
json_data=response_.text
py_data=json.loads(json_data)
city_list=jsonpath.jsonpath(py_data,"$..name")
p=[]
r = requests.get(url)
sum=0
ans=0
response_dict = r.json()
dicts = response_dict['data']
updatetime = dicts['dateline']
citymaps = dicts['map']
count = dicts['count']
for item in updatetime:
    print('风险地区%s更新时间：%s' % (str(item), str(updatetime[item])))
results = []
ShangHai=[]
d=[]
for item in citymaps:
    for item1 in item:
        for item2 in citymaps[item1]:
            areas = citymaps[item1][item2]
            for area in areas:
                result = []
                grade = str(area['grade'])
                if grade == '1':
                    result.append('中风险')
                    d.append('中风险')
                if grade == '2':
                    result.append('高风险')
                    d.append('高风险')
                result.append(str(item2))
                result.append(str(area['city'] + '市' + area['addr']))
                print('风险等级:%s,省：%s,具体位置：%s'%(str(d[ans]),str(item2),str(area['city']+area['addr'])))
                print(area['city']+area['addr'])
                results.append(result)
                for i in city_list:
                    if str(area['city']):
                        p.append(str(area["city"]))
                ans+=1

header = ['风险等级', '省份', '区域']
header1 = ['更新时间：', updatetime['1']]
filename = '全国最新风险等级区域' + time.strftime("%Y-%m-%d", time.localtime()) + '.csv'
print("注：1代表")
print(len(results))
print(filename)
print("下列有中高风险的地区（不包含地址）：")
p=set(p)
for i in p:
    print(i)
with open(filename, 'w', newline='',encoding='utf-8') as f:
    f_csv = csv.writer(f)
    for i in results:
        f_csv.writerow(i)
with open("中高风险地区（不包含地址）.txt",'w',encoding='utf-8') as f:
    for i in p:
        f.write(i)
        f.write("\n")
