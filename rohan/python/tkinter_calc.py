from tkinter import *
from tkinter import font


def buttonclick(a):
    global exprsn
    exprsn = exprsn+str(a)
    input_txt.set(exprsn)
    print(exprsn)


def buttonequal():
    global exprsn
    res = str(eval(exprsn))
    input_txt.set(res)
    exprsn = str(res)
    print(exprsn)


def buttonclear():
    global exprsn
    exprsn = ""
    input_txt.set(exprsn)


def buttondel():
    global exprsn
    temp = list(exprsn)
    temp1 = ''
    del temp[-1]
    for i in temp:
        temp1 += i
    exprsn = temp1
    input_txt.set(exprsn)
    print(exprsn)


exprsn = ""
root = Tk()

f = Frame(root, height=20, width=20)
f.propagate(0)
f.pack()
input_txt = StringVar()
input_text = Entry(f, textvariable=input_txt, width=20, fg="white",
                   bg="black", font=("Times New Roman", 18, "bold"), justify="right")
input_text.grid(row=0, column=0)
bframe = Frame(root, height=20, width=20)

b = Button(bframe, text="1", width=10, height=2, fg="black",
           bg="white", command=lambda: buttonclick(1)).grid(row=0, column=1)
b = Button(bframe, text="2", width=10, height=2, fg="black",
           bg="white", command=lambda: buttonclick(2)).grid(row=0, column=2)
b = Button(bframe, text="3", width=10, height=2, fg="black",
           bg="white", command=lambda: buttonclick(3)).grid(row=0, column=3)
b = Button(bframe, text="4", width=10, height=2, fg="black",
           bg="white", command=lambda: buttonclick(4)).grid(row=1, column=1)
b = Button(bframe, text="5", width=10, height=2, fg="black",
           bg="white", command=lambda: buttonclick(5)).grid(row=1, column=2)
b = Button(bframe, text="6", width=10, height=2, fg="black",
           bg="white", command=lambda: buttonclick(6)).grid(row=1, column=3)
b = Button(bframe, text="7", width=10, height=2, fg="black",
           bg="white", command=lambda: buttonclick(7)).grid(row=2, column=1)
b = Button(bframe, text="8", width=10, height=2, fg="black",
           bg="white", command=lambda: buttonclick(8)).grid(row=2, column=2)
b = Button(bframe, text="9", width=10, height=2, fg="black",
           bg="white", command=lambda: buttonclick(9)).grid(row=2, column=3)
b = Button(bframe, text="0", width=10, height=2, fg="black",
           bg="white", command=lambda: buttonclick(0)).grid(row=3, column=1)

b = Button(bframe, text="-", width=10, height=2, fg="black",
           bg="white", command=lambda: buttonclick("-")).grid(row=3, column=2)
b = Button(bframe, text="+", width=10, height=2, fg="black",
           bg="white", command=lambda: buttonclick("+")).grid(row=3, column=3)

b = Button(bframe, text="/", width=10, height=2, fg="black",
           bg="white", command=lambda: buttonclick("/")).grid(row=1, column=4)
b = Button(bframe, text="*", width=10, height=2, fg="black",
           bg="white", command=lambda: buttonclick("*")).grid(row=2, column=4)

b = Button(bframe, text="del", width=10, height=2, fg="black",
           bg="white", command=lambda: buttondel()).grid(row=0, column=4)

b = Button(bframe, text="=", width=10, height=2, fg="black",
           bg="tomato", command=lambda: buttonequal()).grid(row=3, column=4)

b = Button(bframe, text="AC", width=10, height=2, fg="blue",
           bg="cyan", command=lambda: buttonclear()).grid(row=4, column=3)

bframe.pack()
root.mainloop()
