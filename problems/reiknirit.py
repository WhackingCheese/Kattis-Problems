n = int(input())
e = [int(x) for x in input().split()]

data = {}
for i in range(n):
    if e[i] not in data:
        data[e[i]] = 1
    else:
        data[e[i]] += 1

data = [(v, k) for k, v in data.items()]
data.sort(key=lambda x: -x[0])

total = n
t = n
for i in range(len(data)):
    t -= data[i][0]
    total += t
print(total)