N = int(input())
def init(i):
    t, p = map(int, input().split())
    if t+i>N: t = p = 0
    return [t, p]
arr = [init(i) for i in range(N)]+[[0,0]]
for i in range(N-2, -1, -1):
    temp = arr[i+arr[i][0]][1] + arr[i][1]
    if arr[i+1][1] < temp: arr[i][1] = temp
    else: arr[i][1] = arr[i+1][1]
print(arr[0][1])
