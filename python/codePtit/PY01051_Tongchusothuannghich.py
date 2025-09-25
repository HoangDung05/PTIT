for _ in range(int(input())):
    def solve(n):
        s = str(sum(int(x) for x in n))
        if len(s) == 1: return "NO"
        return "YES" if s[::1] == s[::-1] else "NO"
    print(solve(input()))
