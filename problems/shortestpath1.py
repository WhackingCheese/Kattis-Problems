import heapq
import collections

while True:
    n, m, q, s = [int(x) for x in input().split()]
    if n == m == q == s == 0:
        break
    dictionary, shortest, sets = collections.defaultdict(list), {}, []
    [[dictionary[u].append((v, w)) for u, v, w in [(int(x) for x in input().split())]] for i in range(m)]
    heapq.heappush(sets, (0, s))
    while len(shortest) < n and len(sets) > 0:
        weight, current = heapq.heappop(sets)
        if not (current in shortest and shortest[current] <= weight):
            shortest[current] = weight
            for item in dictionary[current]:
                if not (item[0] in shortest and shortest[item[0]] <= weight + item[1]):
                    heapq.heappush(sets, (weight + item[1], item[0]))
    for i in range(q):
        inp = int(input())
        if inp in shortest:
            print(shortest[inp])
            continue
        print("Impossible")