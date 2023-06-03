ch = input()
m, n = input().split()

if ch == 'r':
    print("{:.2f}".format(float(m) * float(n)))
else:
    print("{:.2f}".format(float(m) * float(n) / 2))