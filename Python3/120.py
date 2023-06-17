y, m, d = input().split()
y = int(y)
m = int(m)
d = int(d)

if m < 1 or d < 1 or m > 12 or d > 31:
    print("NO")
elif (m == 4 or m == 6 or m == 9 or m == 11) and d > 30:
    print("NO")
elif ((y % 4 == 0 and y % 100 != 0 or y % 400 == 0) and m == 2 and d > 29):
    print("NO")
elif (not (y % 4 == 0 and y % 100 != 0 or y % 400 == 0) and m == 2 and d > 28):
    print("NO")
else:
    print("YES")
