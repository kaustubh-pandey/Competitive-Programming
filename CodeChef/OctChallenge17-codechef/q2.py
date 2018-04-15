t=int(input())
for z in range(t):
	n,k=list(map(int,input().split()))
	a=list(map(int,input().split()))
	dm=[-1]*(max(a)+1)
	
	for i in a:
		dm[i]=i
	#print(dm)
	for i in range(len(dm)):
		if(k==0):
			break
		if(dm[i]==-1):
			k-=1
			dm[i]=i
			
	if(dm.count(-1)!=0):
		ans=dm.index(-1)
	else:
		ans=len(dm)+k
	print(ans)
