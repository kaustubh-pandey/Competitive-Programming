t=int(input())
for z in range(t):
	n,k=list(map(int,input().split()))
	a=list(map(int,input().split()))

	p=(1<<k)-1-len(set(a))
	if(p<0):
		p=0
	print(p)