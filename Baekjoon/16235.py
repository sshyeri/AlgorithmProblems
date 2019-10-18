def init():
    r, c, a = map(int, input().split())
    r -= 1
    c -= 1
    return [r, c, a]

N, M, K = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
trees = {}
for _ in range(M):
    r, c, a = map(int, input().split())
    trees[r, c] = [a]
ground = [[5]*N for _ in range(N)]
dr = (-1, -1, -1, 0, 0, 1, 1, 1)
dc = (-1, 0, 1, -1, 1, -1, 0, 1)
deads = []
def spring():
    global M
    for k, v in trees.items():
        l = len(v)
        if l>1: v.sort()
        for i in range(l):
            if ground[k[0]][k[1]] < v[i]:
                deads.append(k)
                M -= 1
            else:
                ground[k[0]][k[1]] -= v[i]
                v[i] += 1
def summer():
    while deads:
        r, c, a = trees.pop(deads.pop())
        ground[r][c] += a//2

def autumn():
    global M
    for k, v in trees.items():
        for a in v:
            if not a%5:
                for d in range(8):
                    nr = k[0]+dr[d]
                    nc = k[1]+dc[d]
                    if 0<=nr<N and 0<=nc<N:
                        M+=1
                        deads.append
#
# def winter():
#     for i in range(N):
#         for j in range(N):
#             ground[i][j] += A[i][j]
spring()
# for i in range(K):
#     spring()
#     summer()
#     autumn()
#     winter()
# print(len(trees))
