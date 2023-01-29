birthday = input("Enter birthday: ")

birthday_list = birthday.split("/")
print(birthday_list)

birthday_dict = {
    "month": birthday_list[0],
    "day": birthday_list[1],
    "year": birthday_list[2]
}

print(birthday_dict)

birthday_str = "/".join(birthday_dict.values())

print(birthday_str)
