def check(n):
    length = len(n)
    i = 0
    while i < length:
        satisfy = False
        l = i + 3
        if l <= length and n[i:l] == "688":
            i = l
            satisfy = True
            continue
        l = i + 2
        if l <= length and n[i:l] == "68":
            i = l
            satisfy = True
            continue
        l = i + 1
        if l <= length and n[i:l] == "6":
            i = l
            satisfy = True
            continue
        if satisfy == False:
            return False
    return True

n = input()
if check(n):
    print("YES")
else:
    print("NO")