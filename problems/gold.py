(W, H) = map(int, input().split())
board = [[char for char in input()] for i in range(H)]
visited = [[False for x in range(W)] for y in range(H)]
for y in range(H):
    for x in range(W):
        if board[y][x] == 'P':
            start = (y, x)
            data = [start]
            visited[y][x] = True
            break
    else:
        continue
    break
gold = 0
while(data != []):
    value = data.pop(0)
    if board[value[0]][value[1]] == 'G':
        gold += 1
    if board[value[0]+1][value[1]] == 'T' or board[value[0]-1][value[1]] == 'T' or board[value[0]][value[1]+1] == 'T' or board[value[0]][value[1]-1] == 'T':
        continue
    if not visited[value[0]+1][value[1]] and (board[value[0]+1][value[1]] == '.' or board[value[0]+1][value[1]] == 'G'):
        data.append((value[0]+1, value[1]))
        visited[value[0]+1][value[1]] = True
    if not visited[value[0]-1][value[1]] and (board[value[0]-1][value[1]] == '.' or board[value[0]-1][value[1]] == 'G'):
        data.append((value[0]-1, value[1]))
        visited[value[0]-1][value[1]] = True
    if not visited[value[0]][value[1]+1] and (board[value[0]][value[1]+1] == '.' or board[value[0]][value[1]+1] == 'G'):
        data.append((value[0], value[1]+1))
        visited[value[0]][value[1]+1] = True
    if not visited[value[0]][value[1]-1] and (board[value[0]][value[1]-1] == '.' or board[value[0]][value[1]-1] == 'G'):
        data.append((value[0], value[1]-1))
        visited[value[0]][value[1]-1] = True
print(gold)
