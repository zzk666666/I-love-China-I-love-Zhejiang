import time
from tkinter import *
class fileedit(object):
    def edit_(self,string):
        with open("test2.txt", "a") as f:
            return f.write(string)
    @classmethod
    def read_(self):
        with open("test2.txt", "a",encoding="utf-8") as f:
            return f.read()
    @classmethod
    def close_(self):
        f = open("test2.txt", "r")
        return f.close()
    def clean_(self):
        with open("test2.txt","w") as f:
            return f.truncate()
fe = fileedit()
tk = Tk()
tk.title("title")
tk.geometry("500x500")
en = Entry(tk, width="20")
lb1 = Label(tk, text="10086", font=("微软雅黑", 20), fg="red")
lb1.grid(column=0, row=0)
en = Entry(tk, width="20")
en.grid(column=1, row=0)
en.focus()
def func():
    txt = en.get()
    lb1.configure(text=txt, fg="green")
    fe.edit_(txt)
    fe.read_()
    fe.close_()
btn1 = Button(tk, text="提交", bg="blue", fg="white", command=func)
def func2():
    txt = en.get()
    lb1.configure(text=txt, fg="green")
    fe.clean_()
btn2=Button(tk, text="清空", bg="red", fg="white", command=func2)
btn1.grid(column=0, row=1)
btn2.grid(column=0, row=2)
tk.mainloop()