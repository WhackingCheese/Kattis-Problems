def hasRepeatCharacters(word):
    return len(word) == len(set([w for w in word]))

def main():
    n = int(input())
    words = [input() for i in range(n)]
    words = [word for word in words if len(word) >= 5 and hasRepeatCharacters(word)]
    if len(words) == 0:
        print("neibb!")
        return
    min_ = min([len(word) for word in words])
    words = [word for word in words if len(word) == min_]
    words.sort()
    print(words[len(words)-1])

if __name__ == "__main__":
    main()
