# Write the Python programs for the following (TUPLES):
#   a. To insert an element into a tuple of values.
#   b. To test whether the tuple is distinct or not.

# a
# Method 1
t = (1, 2, 3, 4)
print(t)
t = t + (5,)
print(t)

# Method 2
t = (5, 6, 7)
print(t)
l = list(t)
print(l)
l.append(6)
t = tuple(l)
print(t)

# b
print("method 1")
# Checking if a tuple is distinct
t = (1, 2, 3, 4, 4, 3)
s = set(t)
print(s)

if len(s) == len(t):
    print(True)
else:
    print(False)

print("method 2")
t = (1, 2, 4, 3)
l = []
for i in t:
    if i not in l:
        l.append(i)

print(l)
if len(s) == len(t):
    print(True)
else:
    print(False)
