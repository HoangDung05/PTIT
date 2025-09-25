
n = input()
step = 0
while len(n) > 1:
    sum = 0
    for i in n: sum += ord(i) - ord('0')
    n = str(sum)
    step += 1
print(step)