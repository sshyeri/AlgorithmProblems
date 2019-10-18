import sys
sys.stdin = open('input.txt')

def honeypick(p, honey, v):
	global C, maxi, j, i, arr
	if honey<=C:
		if v > maxi: maxi = v
		if p<j+M:
			honeypick(p+1, honey + arr[i][p], v + arr[i][p]**2)
			honeypick(p+1, honey, v)

for tc in range(1, int(input())+1):
    N, M, C = map(int, input().split())
    arr = [list(map(int, input().split())) for _ in range(N)]
    maxi=a=b=0
    for i in range(N):
    	maxi = 0
    	for j in range(N-M+1): honeypick(j, 0, 0)
    	if maxi >= a : a, b = maxi, a
    	elif maxi > b: b = maxi
    print('#{} {}'.format(tc, a+b))