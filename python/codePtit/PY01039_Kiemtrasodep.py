def check(n):
    a = n[0]
    b = n[1]
    for i in range(len(n)):
        if i % 2 == 0 and n[i] != a:
            return False
        if i % 2 != 0 and n[i] != b:
            return False
    return True

for _ in range(int(input())):
    n = input()
    if check(n):
        print("YES")
    else:
        print("NO")
