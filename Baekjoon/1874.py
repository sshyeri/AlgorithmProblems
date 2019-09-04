N = int(input())
A = list(range(1, N+1))
i = 0
print('+')
for _ in range(N):
    a = int(in
    put())
    while a > i+1:
        i += 1
        if not A[i]: continue
        print('+')
    A[i] = 0
    i -= 1
    print('-')

    
