def check(n):
    len_n = len(n)
    if len_n < 3:
        return False
    l = 0; r = len_n - 1
    while int(n[l + 1]) > int(n[l]):
        l += 1
    while int(n[r - 1]) > int(n[r]):
        r -= 1
    return l == r

for _ in range(int(input())):
    n = input()
    if check(n):
        print("YES")
    else:
        print("NO")
