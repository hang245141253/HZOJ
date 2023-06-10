y, m = input().split()
y = int(y)
m = int(m)

if m == 4 or m == 6 or m == 9 or m == 11:
    print("30")
elif m == 2:
    if y % 4 == 0 and y % 100 != 0 or y % 400 == 0:
        print("29")
    else :
        print("28")
else :
    print("31")