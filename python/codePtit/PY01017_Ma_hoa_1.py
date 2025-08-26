
for _ in range(int(input())):
    s = input()
    i, n = 0, len(s)
    result = []
    while i < n:
        l = i
        while l < n and s[l] == s[i]:
            l += 1
        result.append(f"{l - i}{s[i]}")
        i = l
    print("".join(result))
    print()

