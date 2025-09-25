x = "abccbaaaa"
start, end = 0, 0
def expand_around_center(left, right):
    while left >= 0 and right < len(x) and x[left] == x[right]:
        left -= 1
        right += 1
    return left + 1, right - 1

for i in range(len(x)):
    l1, r1 = expand_around_center(i, i)
    l2, r2 = expand_around_center(i, i + 1)
    if r1 - l1 > end - start:
        start, end = l1, r1
    if r2 - l2 > end - start:
        start, end = l2, r2


print(x[start:end+1])



