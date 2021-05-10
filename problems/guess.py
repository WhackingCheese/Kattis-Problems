def main():
    inp = ""
    n = 1
    g = 500
    m = 1001
    while inp != "correct":
        print(g)
        inp = input().strip('\n')
        if inp == "lower":
            m = g
        elif inp == "higher":
            n = g
        g = n+((m-n)//2)

if __name__ == "__main__":
    main()
