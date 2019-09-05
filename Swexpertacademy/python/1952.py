for tc in range(1, int(input())+1):
    cost = list(map(int, input().split()))
    month = list(map(int, input().split()))
    arr = [0]
    arr+=[min(cost[0]*month[0], cost[1])]
    arr+=[arr[1] + min(cost[0]*month[1], cost[1])]
    for i in range(3, 13):
        arr+=[min(arr[i-1] + min(cost[0]*month[i-1], cost[1]), cost[3], cost[2] + arr[i-3])]
        if arr[i] >= cost[3]:
            arr[-1] = cost[3]
            break
    print('#{} {}'.format(tc, arr[-1]))