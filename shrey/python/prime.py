r = int(input("Enter upper limit: "))
print("The prime numbers before", r, "are:")
for i in range(2, r+1):
    count = 0
    for j in range(2, i//2+1):
        if (i % j == 0):
            count = count+1
    if (count <= 0):
        print(i)
