f = {1: 1, 2: 1}
mod = int(1e9)

def fib(n):
    if n == 0: return 0
    if n == 1 or n == 2: return 1
    if n in f: return f[n]
    if n % 2 == 0:
        k = n / 2
        f[n] = fib(k) * (2 * fib(k+1) - fib(k))
        f[n] %= mod
    else:
        k = (n-1) / 2
        f[n] = fib(k+1)*fib(k+1) + fib(k) * fib(k)
        f[n] %= mod
    return f[n]

N = int(input())
for i in range(N):
    K, Y = [int(x) for x in input().split()]
    print(K, fib(Y))