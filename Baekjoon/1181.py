A = list(set([input() for _ in range(int(input()))]))
A.sort(key=lambda a: (len(a), a))
for i in A:print(i)