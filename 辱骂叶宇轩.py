#-*- encoding:utf-8 -*-
import time,random,os
from threading import Thread
team1=["康申","潘总","臂窝","腿窝"]
team2=["开哥","骚猪"]
aw1=["叶宇轩是贱逼、叶宇轩欺负女人不要脸","打的叶宇轩狗不吃叶宇轩","电锯惊魂来叶宇轩家了","瘦长鬼影使叶宇轩发高烧最后离奇失踪","我自横刀向天笑，去留肝胆两昆仑！","君子报仇十年不晚，有恩报恩有仇报仇","此头须向国门悬，必杀叶（指叶宇轩的兵）家军十万！","叶宇轩不小心进了游戏遭遇头号玩家的轮番攻击","叶宇轩去了火葬场火化","把叶宇轩分尸、碎石、再烹尸！","把叶宇轩骨灰扔进日本海里"]
abuse_word2=["叶宇轩的包皮被卖","叶宇轩是没有包皮","叶宇轩傻逼","叶宇轩智障","叶宇轩死妈","叶宇轩被割包皮","干你妈的叶宇轩家的iPhone*（*代表所有系列）","武士刀劈死叶宇轩","把叶宇轩抓进三体，让三体人用指令使他消失！","兄弟们为初中往事尽情的骂！","叶宇轩躺进棺材里头","把叶宇轩骨灰扔进恒河水里","宇宙的厚度是叶宇轩∞分之一光年"]
laladui=["加油","加油！奥利给","奥利给","奥力干","冲冲冲"]
def yyx1(q):
    for i in range(1000):
        print(f"({q}){random.choice(aw1)}|")
        q+=1
        time.sleep(1)
    time.sleep(6)
    print("发泄完毕，立即关机！")
    os.system('shutdown -s -t 10')
def yyx2(q):
    for i in range(1000):
        print(f"({q}){random.choice(abuse_word2)}|")
        q+=1
        time.sleep(1)
    time.sleep(6)
    print("发泄完毕，立即关机！")
    os.system('shutdown -s -t 10')
def guangzhong(q):
    for i in range(1000):
        print(f"{q}观众：{random.choice(laladui)}|")
        q+=1
        time.sleep(1)
    time.sleep(6)
    os.system('shutdown -s -t 10')
if __name__=='__main__':
    t1=Thread(target=yyx1,args=(1,))
    t2 = Thread(target=yyx2, args=(2,))
    t3 = Thread(target=guangzhong, args=(1,))
    print("大家好！这里是有薇姿德克士西八水冠名播出的有仇必报节目，我是主持人李天昊。")
    t1.setName(random.choice(team1))
    t2.setName(random.choice(team2))
    print(f"由请{t1.getName()}战队登场")
    print(f"由请{t2.getName()}战队登场")
    print(f"大家好我是{t1.getName()}战队我是第一个出场（谁先出场谁先骂按照数字来）")
    print(f"大家好我是{t2.getName()}战队我是我第二个出场")
    time.sleep(3)
    t1.start()
    t2.start()
    t3.start()