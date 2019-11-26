import sys
sys.stdin = open('input.txt')

for tc in range(1, int(input())+1):
    arr = list(map(int, input().split()))
    maxs = [0]*arr[0]
    mins = [0]*arr[0]
    arr.pop(0)
    ans = sum(arr)
    temp = 0
    tag = False
    for a in arr:


    print(ans)
