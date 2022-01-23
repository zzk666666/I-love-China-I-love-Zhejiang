import requests
from lxml import etree
from urllib import request
import time

#1.目标  定义虎牙
url='https://www.huya.com/g/2168'

#2.请求  网络请求<Response [200]>
src=requests.get(url)
#编译
html=etree.HTML(src.text)

#3.数据  所需数据
id_list=html.xpath('.//img[@class="pic"]')

#4.下载  下载保存
for data in id_list:
    img=data.xpath('./@data-original')[0]
    img=img.split('?')[0]
    print(img)
    name=data.xpath('./@alt')[0]
    file = '虎牙美女文件夹/' + name +'.jpg'
    request.urlretrieve(img,file)
    requests.get(url)
    print('<%s>下载完成!'% name)
    time.sleep(1)
