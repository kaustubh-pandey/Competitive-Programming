t=int(input())
for z in range(t):
	n=int(input())
	a=list(map(int,input().split()))
	print(a.index(min(a))+1)