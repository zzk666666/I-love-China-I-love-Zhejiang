import pygame, sys
from tkinter import *
pygame.init()
screen = pygame.display.set_mode((1920, 1083))
bgImg = pygame.image.load(r".\叶宇轩灵异事件_看图王.png")
user1=pygame.image.load(".\新图网_卡通可爱小乌鸦_ixintu.com.png")
user2=pygame.image.load(r".\蔡徐坤.png")
x=0
y=0
screen.blit(user1,(x,y))
pygame.display.set_caption("叶宇轩界面")
while x<=1920:
    screen.blit(bgImg, (0, 0))
    screen.blit(user1,(x,y))
    screen.blit(user2, (500,500))
    x += 8
    pygame.display.update()
pygame.quit()