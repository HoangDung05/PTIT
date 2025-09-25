def Try(a, b, c, n):
    if n == 1:
        print(f"{a} -> {c}")
        return
    Try(a, c, b, n - 1)
    Try(a, b, c, 1)
    Try(b, a, c, n - 1)

n = int(input())
Try("A", "B", "C", n)
