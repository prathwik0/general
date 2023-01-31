class account:
    def __init__(self, num, bal=100):
        self.__bal = bal
        self.__acc_num = num

    def withdraw(self, amt):
        if (self.__bal <= 100+amt):
            print("insufficient balance")
        else:
            self.__bal = self.__bal-amt

    def deposit(self, amt):
        self.__bal = self.__bal+amt

    def display(self):
        print("account num : ", self.__acc_num)
        print("balance : ", self.__bal)


acc_list = []


def new_account(num):
    for i in acc_list:
        if (i.__acc_num == num):
            print("account already exisits")
            return
    acc_list.append(account(num))
    print(acc_list)


def process(num, operation, amt):
    for i in acc_list:
        if (i.__acc_num == num):
            if (operation == "withdraw"):
                i.withdraw(amt)
            elif (operation == "deposit"):
                i.deposit(amt)
            elif (operation == "display"):
                i.display()
            return

    print("account doesn't exsist")


def highestbal():
    highestbal = 0
    highestacc = None

    for i in acc_list:
        if (i.bal > highestbal):
            highestbal = i.__bal
            highestacc = i.__acc_num

    print("highestacc : ", highestacc)
    print("highestbal : ", highestbal)


n = int(input("enter number of bank accounts\n"))

for i in range(0, n):
    x = int(input("enter bank account number : "))
    new_account(x)


while (1):
    ch = int(input(
        "Enter your choice\n1.withdraw\n2.deposit\n3.display\n4.highestbal\n5.exit\n"))
    if (ch == 1):
        num = int(input("enter bank account number :"))
        amt = int(input("enter amount to be withdrawn :"))
        process(num, "withdraw", amt)

    elif (ch == 2):
        num = int(input("enter bank account number :"))
        amt = int(input("enter amount to be deposited :"))
        process(num, "deposit", amt)

    elif (ch == 3):
        num = int(input("enter bank account number :"))
        process(num, "display", 0)

    elif (ch == 4):
        highestbal()

    elif (ch == 5):
        quit()

    else:
        print("invalid input")
