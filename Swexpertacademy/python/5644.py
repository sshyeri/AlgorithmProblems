dr = (0, -1, 0, 1, 0)
dc = (0, 0, 1, 0, -1)

for tc in range(1, int(input())+1):
    M, A = map(int, input().spint())
    AM = [i for i in map(int, input().split())]
    BM = [i for i in map(int, input().split())]
    BC = [[i for i in map(int, input().split())] for _ in range(A)]
    print(BC)