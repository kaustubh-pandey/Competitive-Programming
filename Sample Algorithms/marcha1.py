def sum(a,n,m):
	if(m!=0 and n==0):
		return 0
	if(m==0):
		return 1
	if(a[n-1]>m):
		return sum(a,n-1,m)
	return sum(a,n-1,m) or sum(a,n-1,m-a[n-1])
t=int(input())
for z in range(t):
	n,m=list(map(int,input().split()))
	a=[]
	for i in range(n):
			a.append(int(input()))
	if(sum(a,n,m)):
		print("Yes")
	else:
		print("No")