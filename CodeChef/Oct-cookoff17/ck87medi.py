t=int(input())
for z in range(t):
	n,k=list(map(int,input().split()))
	a=list(map(int,input().split()))
	a.sort()
	print(a[(n+k)//2])