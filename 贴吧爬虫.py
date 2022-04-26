import requests
import random
class Tieba(object):
    def __init__(self):
        self.h=[
            "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.127 Safari/537.36",
            "Mozilla / 5.0(Macintosh;IntelMacOSX10_7_0) AppleWebKit / 535.11(KHTML, likeGecko) Chrome / 17.0.963.56Safari / 535.11",
            "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1; Maxthon 2.0)",
            "Mozilla/5.0 (Macintosh; U; Intel Mac OS X 10_6_8; en-us) AppleWebKit/534.50 (KHTML, like Gecko) Version/5.1 Safari/534.50",
            "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.127 Safari/537.36 Edg/100.0.1185.50"
        ]
        self.url_="https://tieba.baidu.com/f"
        self.headers_={
            "User-Agent":str(random.choice(self.h)),
            "Cookie":"BIDUPSID=A451FD37266DB03C1EFE2BBDF16FF8E3; PSTM=1641577112; __yjs_duid=1_ca9568f2d0fc51a1a9c085fce1cf8bab1645314386975; MCITY=-289:; BAIDUID=A451FD37266DB03C8445A2DF1E71FB8C:SL=0:NR=10:FG=1; BDORZ=B490B5EBF6F3CD402E515D22BCDA1598; H_PS_PSSID=36309_31253_34813_36167_34584_36120_36073_36235_26350_36302_36316_36061; delPer=0; PSINO=5; BAIDUID_BFESS=A451FD37266DB03C8445A2DF1E71FB8C:SL=0:NR=10:FG=1; BA_HECTOR=ah2h20048kal2584121h6daoq0q; wise_device=0; Hm_lvt_98b9d8c2fd6608d564bf2ac2ae642948=1650887030,1650895875; BAIDU_WISE_UID=wapp_1650895875026_837; USER_JUMP=-1; st_key_id=17; video_bubble0=1; Hm_lpvt_98b9d8c2fd6608d564bf2ac2ae642948=1650895912; ab_sr=1.0.1_YTkxZjYyNDczN2E5OGIyNWU3N2I4NGZkNmU3N2IxM2Q1ZWYxY2RhY2MyZmM2Y2RiOTVhN2Q4ZTlhNTQxMDI4OWFlN2ExMTc3NzU1YjA1MzE1MTFkNGI4ODhiNDc5M2RmNjZmNTEwZWFlODQ5NGI3MDc4MzAyOGJkNGMyNDdjMjk0OTdmYTRhYWUwNzJlYWUxZWZkMTY4ZmYzNDE2Y2Y5Mg==; st_data=eb963e9ea84b36e0b1ed3a4d43739d037ef1c4f1a1ea53669edcc238f23fd57d013fb4e060e0a8f6d24d4a6695659b9f457a4ceba797e493e667e44cbd59c9493b80149c0d689f006399480d0472dfb8c6d00937d341be3d817e589928615af5; st_sign=95660d30"
        }
    def send_request(self,params):
        response_=requests.get(self.url_,headers=self.headers_,params=params)
        str_data=response_.content.decode()
        return str_data
    def save_data(self,page,str_data,data_):
        with open(f'{data_}第{page+1}页',"w",encoding='utf-8')as f:
            f.write(str_data)
    def run(self):
        data_=input("你要爬啥贴吧")
        pages_=int(input("你爬取的页数"))
        for page in range(pages_):
            params_={
                "kw":data_,
                "pn":page*50
            }
            str_data=self.send_request(params_)
            self.save_data(page,str_data,data_)
if __name__=="__main__":
    tieba_=Tieba()
    tieba_.run()