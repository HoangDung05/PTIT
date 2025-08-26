

a, k, n = map(int, input().split())
check = False
for i in range (k, n + 1, k):
    if i > a:
        print(i - a, end=" ")
        check = True
if check == False:
    print(-1)