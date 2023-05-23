a, b, c, t = input().split()
a = float(a)
b = float(b)
c = float(c)
t = float(t)

t1 = (1 - (1 / a + 1 / b) * t) / (1 / a + 1 / b - 1 / c)

print("{:.2f}".format(t1 + t))