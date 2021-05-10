MAX_D = 2**22
fj = [[None for j in range(150)] for i in range(150)]
n, m, q = [int(i) for i in input().split()]

while not (n == m == q == 0):
    for i in range(n):
        for j in range(n):
            fj[i][j] = 0 if i == j else MAX_D
    for i in range(m):
        u, v, w = [int(i) for i in input().split()]
        if w < fj[u][v]: fj[u][v] = w
    for i in range(n):
        for j in range(n):
            for k in range(n):
                if fj[j][i] + fj[i][k] < fj[j][k] and fj[j][i] < MAX_D and fj[i][k] < MAX_D:
                    fj[j][k] = fj[j][i] + fj[i][k]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                if fj[i][i] < 0 and fj[j][i] != MAX_D and fj[i][k] != MAX_D:
                    fj[j][k] = -MAX_D
    for i in range(q):
        u, v = [int(i) for i in input().split()]
        print("Impossible") if fj[u][v] == MAX_D else print("-Infinity") if fj[u][v] == -MAX_D else print(fj[u][v])
    n, m, q = [int(i) for i in input().split()]
