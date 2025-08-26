p = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_."
def find_index(x):
    return p.index(x)
while 1:
    s = input()
    if s[0] == '0':
        break
    k, s = s.split()
    result = ""
    for i in s:
        temp = (find_index(i) + int(k)) % 28
        result += p[temp]
    print("".join(reversed(result)))


