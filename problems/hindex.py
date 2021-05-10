n = int(input())
H = []
for i in range(n):
    H.append(int(input()))
H.sort(key=lambda x: -x)
ans = 0
for i in range(n):
    if H[i] >= i+1:
        ans = i+1
    else:
        break
print(ans)
