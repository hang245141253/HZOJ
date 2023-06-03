n = int(input())
g = n % 10
s = n // 10 % 10
b = n // 100 % 10
q = n // 1000
if g % 2 == 0 or s % 2 == 0 or b % 2 == 0 or q % 2 == 0:
    print("YES")
else:
    print("NO")