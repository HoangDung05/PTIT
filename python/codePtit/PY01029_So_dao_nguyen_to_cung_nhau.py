import math

for _ in range(int(input())):
    a = int(input())
    b = int("".join(reversed(str(a))))
    if math.gcd(a, b) == 1:
        print("YES")
    else:
        print("NO")
