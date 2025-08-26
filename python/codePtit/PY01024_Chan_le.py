def check(n):
    sum = 0
    length = len(str(n))
    n = str(n)
    for i in range(length):
        sum += int(n[i])
        if i == length - 1:
            break
        if abs(int(n[i]) - int(n[i + 1])) != 2:
            return False
    if sum % 10 != 0:
        return False
    return True


for _ in range(int(input())):
    n = int(input())
    if check(n):
        print("YES")
    else:
        print("NO")
