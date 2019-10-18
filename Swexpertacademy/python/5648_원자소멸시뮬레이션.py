import sys
sys.stdin = open('input.txt')
dy = (0.5, -0.5, 0, 0)
dx = (0, 0, -0.5, 0.5)

def move():
	global energy, atoms
	new = {}
	for xy, dk in atoms.items():
		x = xy[0] + dx[dk[0]]
		y = xy[1] + dy[dk[0]]
		if -1000<=x<=1000 and -1000<=y<=1000:
			if (x, y) in new:
				energy += dk[1] + new[(x, y)][1]
				new[(x, y)][1] = 0
			else:
				new[(x, y)] = [dk[0], dk[1]]
	atoms = {}
	for k, v in new.items():
		if v[1]:
			atoms[k] = v
for tc in range(1, int(input()) + 1):
	atoms = {}
	energy = 0
	for _ in range(int(input())):
		x, y, d, k = map(int, input().split())
		atoms[(x, y)] = [d, k]
	for c in range(4000):
		if len(atoms) < 2:
			break
		move()
	print('#{} {}'.format(tc, energy))