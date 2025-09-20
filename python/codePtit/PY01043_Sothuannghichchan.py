def check(s):
    length = len(s)
    if length % 2 != 0:
        return False
    if s != s[::-1]:
        return False
    for char in s:
        digit = int(char)
        if digit % 2 != 0:
            return False
    return True

for _ in range(int(input())):
    n = int(input())
    for i in range(2, n, 2):
        s = str(i)
        if check(s):
            print(i, end=" ")
    print()