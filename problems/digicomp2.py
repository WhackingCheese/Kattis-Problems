import heapq

class Switch:
    def __init__(self):
        self.dir = 0
        self.left = 0
        self.right = 0
        self.balls = 0
        self.value = 0

    def flip(self):
        if self.dir == 'L':
            self.dir = 'R'
        else:
            self.dir = 'L'
    
    def set_const(self, _dir, left, right):
        self.dir = _dir
        self.left = int(left)
        self.right = int(right)

def inc_child_values(sw, ch, l, r):
    sw[sw[ch].left].value += l
    sw[sw[ch].right].value += r

def inc_child_balls(sw, ch, inc):
    sw[sw[ch].left].balls += inc
    sw[sw[ch].right].balls += inc

def main():
    n, m = [int(x) for x in input().split()]
    switches = [Switch() for x in range(m+1)]
    for i in range(1, m+1):
        switches[i].set_const(*input().split())
        inc_child_balls(switches, i, 1)
    heap = []
    for i in range(1, m):
        if(switches[i].balls == 0):
            heapq.heappush(heap, -i)
    switches[1].value = n
    while heap and heap[0] != 0:
        c = -heapq.heappop(heap)
        leftv = switches[c].value//2
        rightv = switches[c].value//2
        if switches[c].value % 2 != 0:
            if switches[c].dir == 'L':
                leftv += 1
            else:
                rightv += 1
            switches[c].flip()
        inc_child_values(switches, c, leftv, rightv)
        inc_child_balls(switches, c, -1)
        if switches[switches[c].left].balls == 0:
            heapq.heappush(heap, -switches[c].left)
        if switches[switches[c].right].balls == 0 and switches[c].right != switches[c].left:
            heapq.heappush(heap, -switches[c].right)
    for i in range(1, m+1):
        print(switches[i].dir, end="")

if __name__ == "__main__":
    main()
