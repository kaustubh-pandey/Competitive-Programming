def index(dp,n,u):
	for i in range(u-1,-1,-1):
		if(dp[i]==n):
			return i
	return -1
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
			if(a[i][1]>a[j][1] and a[i][0]>a[j][0] and dp[i]<dp[j]+1):
				dp[i]=dp[j]+1
				prev[i]=j
	i=dp.index(max(dp))
	s=[]
	seq(a,prev,i,s)
	return [max(dp),s]

#An application of longest increasing subsequence
n=int(input())
a=[]
for z in range(n):
	a.append(list(map(int,input().split()))+[z+1])
#a.sort()
#Sorted on the basis of strength
#Find longest increasing subsequence on the basis of beauty
m,s=lis(a,n)
print(m)
for i in s[::-1]:
	print(i[2],end=" ")
print("")

