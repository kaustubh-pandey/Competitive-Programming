t=int(input())
for z in range(t):
	n=int(input())
	loss=0
	for i in range(n):
		c,q,x=list(map(int,input().split()))
		loss+=(c*x**2)*q/10000
	print(loss)