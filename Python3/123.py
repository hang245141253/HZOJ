a, b = input().split()
c, d = input().split()

a = int(a)
b = int(b)
c = int(c)
d = int(d)

if a <= c and d <= b or c <= a and b <= d:
    print("YES")
else:
    print("NO")