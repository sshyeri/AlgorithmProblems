for tc in range(1, int(input())+1):
    N, X = input().split()
    N = int(N)
    R = 0
    for x in X:
        R+=(int(x)%(N-1))
    print(f"#{tc} {R%(N-1)}")