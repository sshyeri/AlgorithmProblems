# import sys
# sys.stdin=open('4013.txt')

for tc in range(1, int(input())+1):
    K = int(input())
    ans = 0
    arr = [[i for i in input().split()] for _ in range(4)]
    for i in range(K):
        num, d = map(int, input().split())
        num-=1
        dd = [0]*4
        dd[num] = d
        j = num
        while(j>0 and arr[j][-2] != arr[j-1][2]):
            dd[j-1] = -dd[j]
            j-=1
        j = num
        while(j<3 and arr[j][2] != arr[j+1][-2]):
            dd[j+1] = -dd[j]
            j+=1
        for p in range(4):
            if dd[p] == 0: continue
            elif dd[p] == -1:
                arr[p].append(arr[p].pop(0))
            elif dd[p] == 1: 
                arr[p] = [arr[p].pop()] + arr[p]
    for p in range(4):
        ans =<< int(arr[p][0])
    print('#{} {}'.format(tc, ans))