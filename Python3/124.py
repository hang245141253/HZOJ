x, b, n, g = input().split()
x = int(x)
b = int(b)
n = int(n)
g = int(g)

if (b <= 50 or x >= 1) and (n <= 25 or g >= 5):
    print("ok")
else:
    print("pass")
