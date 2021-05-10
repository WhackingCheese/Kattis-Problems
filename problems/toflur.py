def main():
    n = int(input())
    j = [int(x) for x in input().split()]
    j.sort()
    prev = j[0]
    total = 0
    for i in range(len(j)):
        total += (j[i] - prev) ** 2
        prev = j[i]
    print(total)

if __name__ == "__main__":
    main()
