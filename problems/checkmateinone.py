def getKingMoves(k, moves_only=False):
    moves = []
    for i in range(k[0]-1, k[0]+2):
        for j in range(k[1]-1, k[1]+2):
            if(i >= 0 and i <= 7 and j >= 0 and j <= 7):
                if moves_only and k[0] == i and k[1] == j:
                    continue
                moves.append((i, j))
    return set(moves)

def getRookMoves(r):
    moves = []
    for i in range(8):
        if(i != r[0]):
            moves.append((i, r[1]))
    for j in range(8):
        if(j != r[1]):
            moves.append((r[0], j))
    return set(moves)

def main():
    for i in range(8):
        inp = [char for char in input()]
        for j in range(len(inp)):
            if inp[j] == "k":
                k = (i, j)
            if inp[j] == "K":
                K = (i, j)
            if inp[j] == "R":
                R = (i, j)
    coverage = getKingMoves(k)
    k_moves = getKingMoves(K, moves_only=True)
    r_moves = getRookMoves(R)
    mate = False
    for position in k_moves:
        if position in coverage:
            continue
        moves = getKingMoves(position, moves_only=True)
        if coverage.issubset(moves.union(r_moves)):
            mate = True
            break
    if not mate:
        for position in r_moves:
            if position in coverage:
                continue
            moves = getRookMoves(position)
            if coverage.issubset(moves.union(k_moves)):
                mate = True
                break
    if(mate):
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()
