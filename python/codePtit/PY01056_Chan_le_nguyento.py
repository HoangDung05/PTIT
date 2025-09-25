import math
def check_snt(n):
    if (n < 2):
        return False
    for i in range(2, int(math.sqrt(n) + 1)):
        if (n % i == 0):
            return False
    return True
def check(n):
    sum_digit = 0
    for i in range(len(n)):
        sum_digit += int(n[i])
        if (i % 2 == 0):
            if (int(n[i]) % 2 != 0):
                return False
        else:
            if (int(n[i]) % 2 == 0):
                return False
    if (check_snt(sum_digit) == False):
        return False
    return True
for _ in range (int(input())):
    n = input()
    if (check(n)):
        print("YES")
    else:
        print("NO")
