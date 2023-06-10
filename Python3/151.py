m1, m2 = input().split()
l1, l2 = input().split()
m1 = ord(m1)
m2 = ord(m2)
l1 = ord(l1)
l2 = ord(l2)

if m1 - l1 == -10 or m1 - l1 == -7 or m1 - l1 == 17:
    if m1 - l2 == -10 or m1 - l2 == -7 or m1 - l2 == 17 or m1 == l2:
        print("MING")
    else :
        if m2 - l2 == -10 or m2 - l2 == -7 or m2 - l2 == 17:
            print("MING")
        else :
            print("LIHUA")
elif m1 == l1:
    if m2 - l2 == -10 or m2 - l2 == -7 or m2 - l2 == 17:
        print("MING")
    elif m2 == l2 :
        print("TIE")
    else :
        print("LIHUA")
else :
    if m2 - l1 == -10 or m2 - l1 == -7 or m2 - l1 == 17:
        if m2 - l2 == -10 or m2 - l2 == -7 or m2 - l2 == 17 or m2 == l2:
            print("MING")
        else :
            print("LIHUA")
    else :
        print("LIHUA")