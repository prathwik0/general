class account:
    def __init__(self, num, bal=100):
        self.__acc_num = num
        self.__balance = bal

    def withdraw(self, amount):
        if self.__balance <= amount+100:
            print("Insufficient Balance")
        else:
            self.__balance = self.__balance - amount

    def deposit(self, amount):
        self.__balance = self.__balance + amount
    
    def getAccountNum(self):
        return self.__acc_num
    
    def getBalance(self):
        return self.__balance

    def display(self):
        print("\nThe account number is :", self.__acc_num)
        print("The Account balance is :", self.__balance)


acc_list = []


def new_account(num):
    for i in acc_list:
        if i.getAccountNum() == num:
            print("Account already present")
            return
    acc_list.append(account(num))


def process(num, operation, amount):
    for i in acc_list:
        if i.getAccountNum() == num:
            if operation == "withdraw":
                i.withdraw(amount)
            elif operation == "deposit":
                i.deposit(amount)
            elif operation == "display":
                i.display()
            return
    print("Error: Account", num, "not found")


def highest_balance():

    highest_balance = 0
    highest_acc = None

    for i in acc_list:
        if i.getBalance() > highest_balance:
            highest_balance = i.getBalance()
            highest_acc = i

    print("Account", highest_acc.getAccountNum(),
          "has the highest balance of", highest_balance)


n = int(input("Enter number of accounts: "))
for i in range(n):
    acc_num = int(input("Enter the account number :"))
    new_account(acc_num)

while (1):
    print("\n1)DEPOSIT\n2)WITHDRAWL\n3)DISPLAY\n4)HIGHEST_BAL\n")
    ch = int(input("Enter your choice:"))

    if ch == 1:
        acc_num = int(input("Enter the account number to be accessed:"))
        amt = int(input("Enter the amount to be deposited:"))
        process(acc_num, "deposit", amt)

    elif ch == 2:
        acc_num = int(input("Enter the account number to be accessed:"))
        amt = int(input("Enter the amount to be withdrawn:"))
        process(acc_num, "withdraw", amt)

    elif ch == 3:
        acc_num = int(input("Enter the account number to be accessed:"))
        process(acc_num, "display", 0)

    elif ch == 4:
        highest_balance()
        
    else: 
        quit()
