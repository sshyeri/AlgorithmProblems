import sys
sys.stdin = open('input.txt')
MAXN = 200002
MAXD = 1000000001
maxHeap = [0]*MAXN
minHeap = [0]*MAXN

def minpush(n):
    global minp, minHeap
    minp += 1
    minHeap[minp] = n
    i = minp
    while i>1:
        if minHeap[i] >= minHeap[i//2]: return
        else:
            minHeap[i], minHeap[i//2] = minHeap[i//2], minHeap[i]
            i//=2

def maxpush(n):
    global maxp, maxHeap
    maxp += 1
    maxHeap[maxp] = n
    i = maxp
    while i>1:
        if maxHeap[i] <= maxHeap[i//2]: return
        else:
            maxHeap[i], maxHeap[i//2] = maxHeap[i//2], maxHeap[i]
            i//=2

def minpop():
    global minp, minHeap
    n = minHeap[1]
    minHeap[1] = minHeap[minp]
    minp -= 1
    i = 1
    while(i*2<=minp):
        l = minHeap[i * 2]
        if (i*2+1 > minp): r = MAXD
        else: r = minHeap[i*2 + 1]
        if l<=r:
            if minHeap[i] <= l: return n
            else:
                minHeap[i], minHeap[i*2] = minHeap[i*2], minHeap[i]
                i*=2
        else:
            if minHeap[i] <= r: return n
            else:
                minHeap[i], minHeap[i*2 + 1] = minHeap[i*2 + 1], minHeap[i]
                i = i*2 + 1
    return n

def maxpop():
    global maxp, maxHeap
    n = maxHeap[1]
    maxHeap[1] = maxHeap[maxp]
    maxp -= 1
    i = 1
    while(i*2 <= maxp):
        l = maxHeap[i*2]
        if i*2 + 1 > maxp: r = 0
        else: r = maxHeap[i*2 + 1]
        if l>=r:
            if l<= maxHeap[i]: return n
            else:
                maxHeap[i], maxHeap[i*2] = maxHeap[i*2], maxHeap[i]
                i *= 2
        else:
            if r<= maxHeap[i]: return n
            else:
                maxHeap[i], maxHeap[i*2 + 1] = maxHeap[i*2+1], maxHeap[i]
                i = i*2 + 1
    return n

for tc in range(1, int(input())+1):
    ans = 0
    minp = 0
    maxp = 0
    N, A = map(int, input().split())
    mid = A
    for n in range(N):
        X, Y = map(int, input().split())
        if X>mid and Y>mid:
            minpush(X)
            minpush(Y)
            maxpush(mid)
            mid = minpop()
        elif X<mid and Y<mid:
            maxpush(X)
            maxpush(Y)
            minpush(mid)
            mid = maxpop()
        elif X<=mid<=Y:
            minpush(Y)
            maxpush(X)
        elif Y<=mid<=X:
            minpush(X)
            maxpush(Y)

        ans = (ans + mid)%20171109
    print('#{} {}'.format(tc, ans))