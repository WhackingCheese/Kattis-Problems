from itertools import permutations

def main():
    inp = input().strip('\n')
    num = int(inp)
    x = [m for m in [int(''.join(n)) for n in permutations(inp)] if m > num]
    if not x:
        print(0)
    else:
        print(min(x))

if __name__ == "__main__":
    main()
