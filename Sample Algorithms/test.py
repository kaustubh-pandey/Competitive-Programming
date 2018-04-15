def seq(a,prev,i,s):
	if(prev[i]==-1):
		s.append(a[i])
		return s
	else:
		s.append(a[i])
		seq(a,prev,prev[i],s)

def lis(a,n):
	dp=[1]*n
	prev=[-1]*n
	for i in range(1,n):
		for j in range(i):
			if(a[i]>a[j] and dp[i]<dp[j]+1):
				dp[i]=dp[j]+1
				prev[i]=j
	print(prev)
	i=dp.index(max(dp))
	s=[]
	seq(a,prev,i,s)
	return max(dp),s

a=[0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15]
print(lis(a,len(a)))