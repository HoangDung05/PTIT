def check(a):
    b = a[::-1]
    for i in range(1, len(a)):
        if abs(ord(a[i]) - ord(a[i-1])) != abs(ord(b[i]) - ord(b[i-1])):
            return "NO"
    return "YES"
for _ in range(int(input())):
    s = input()
    print(check(s))