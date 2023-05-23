n = int(input())
sum = 0
LI = 0.00417
for i in range(6):
    sum = (n + sum) * (1 + LI)
print("${:.2f}".format(sum))