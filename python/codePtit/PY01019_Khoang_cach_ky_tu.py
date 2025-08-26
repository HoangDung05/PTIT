def check(s1, s2):
    length = len(s1)
    for i in range(1, length):
        if abs(ord(s1[i]) - ord(s1[i-1])) != abs(ord(s2[i]) - ord(s2[i-1])):
            return False
    return True

t = int(input())
for i in range(t):
    s1 = input()
    s2 = "".join(reversed(s1))
    if check(s1, s2):
        print("YES")
    else:
        print("NO")
