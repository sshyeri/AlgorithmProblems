import itertools
import sys
sys.stdin = open('input.txt')

N = int(input())
ans = 1000
populations = [-1] + list(map(int, input().split()))
linked = [-1] + [list(map(int, input().split()[1:])) for _ in range(N)]
districts = list(range(1, N+1))
def chk(g):
	global chkl, group
	if len(chkl)==len(group): return True
	for l in linked[g]:
		if l in group and l not in chkl:
			chkl.append(l)
			if len(chkl) == len(group): return True
			chk(l)

if N==2:
	ans = abs(populations[1] - populations[2])
else:
	un = 0
	for l in range(1, N+1):
		if not linked[l]:
			if un:
				ans = -1
				break
			un = l
	else:
		if un:
			districts.pop(un-1)
			chkl = [districts[0]]
			group = districts
			chk(districts[0])
			if len(chkl) == N-1:
				ans = abs(populations.pop(un) - (sum(populations) + 1))
			else:
				ans = -1
		else:
			for i in range(N//2, 0, -1):
				groups = list(itertools.combinations(districts, i))
				for group in groups:
					temp = sum(populations)+1
					for g in group:
						temp -= populations[g]*2
					temp = abs(temp)
					if temp < ans:
						chkl = [group[0]]
						chk(group[0])
						if len(chkl)==len(group):
							group = list(set(districts) - set(group))
							chkl = [group[0]]
							chk(group[0])
							if len(chkl)==len(group):
								ans = temp
								if not ans: break
					if not ans: break
				if not ans: break
	if ans==1000: ans = -1
print(ans)