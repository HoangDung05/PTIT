import math
def check(n):
    for i in n:
        if i != '0' and i != '1' and i != '2':
            return False
    return True
for _ in range(int(input())):
    n = input()
    if check(n):
        print("YES")
    else:
        print("NO")
