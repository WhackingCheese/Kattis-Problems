n = int(input())
r = [int(x) for x in input().split()]

start = 0
finish = 0
s = False
v = max(r)
for i in range(n):
    if r[i] == v:
        if not s:
            s = True
            start = i
    else:
        if s == True:
            finish = i-1
            break
        s = False
print(start, finish)