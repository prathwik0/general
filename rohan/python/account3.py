class account:
    def __init__(self, num, bal=100):
        self.__bal = bal
        self.__acc_num = num

    def withdraw(self, amt):
        if (self.__bal <= 100+amt):
            print("insufficient balance")
        else:
            self.__bal = self.__bal - amt

    def deposit(self, amt):
        self.__bal = self.__bal+amt

    def getaccno(self):
        return self.__acc_num

    def getbal(self):
        return self.__bal

    def display(self):
        print("account num : ", self.__acc_num)
        print("balance : ", self.__bal)


acc_list = []


def new_account(num):
    for i in acc_list:
        if (i.getaccno == num):
            print("account already exisiting")
            return
    acc_list.append(account(num))


def process(num, operation, amt):
    for i in acc_list:
        if (i.getaccno() == num):
            if (operation == "withdraw"):
                i.withdraw(amt)
            elif (operation == "deposit"):
                i.deposit(amt)
            elif (operation == "display"):
                i.display()
            return
    print("account doesn't exsist ")


def highestacc():
    highestacc = None
    highestbal = 0
    for i in acc_list:
        if (highestbal < i.getbal()):
            highestbal = i.getbal()
            highestacc = i.getaccno()
    print("highest balance : ", highestbal)
    print("highest account : ", highestacc)


n = int(input("enter number of bank accounts : "))
for i in range(0, n):
    acc_num = int(input("enter account : "))
    new_account(acc_num)

while (1):
    ch = int(input(
        "enter your choice\n1.withdraw\n2.deposit\n3.display\n4.highestacc\n5.exit\n"))
    if (ch == 1):
        num = int(input("enter bank account number : "))
        amt = int(input("enter amount to be withdrawed : "))
        process(num, "withdraw", amt)

    elif (ch == 2):
        num = int(input("enter bank account number : "))
        amt = int(input("enter amount to be deposited : "))
        process(num, "deposit", amt)

    elif (ch == 3):
        num = int(input("enter bank account number : "))
        process(num, "display", 0)

    elif (ch == 4):
        highestacc()

    elif (ch == 5):
        quit()

    else:
        print("wrong input")
