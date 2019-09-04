dr = [0, -1, 0, 1]
dc = [-1, 0, 1, 0]
ans = 0

def init():
    global ans
    temp = [i for i in map(int, input().split())]
    ans += temp.count(0)
    return temp

N, M = map(int, input().split())
arr = [init() for _ in range(N)]

print(arr)
print(ans)