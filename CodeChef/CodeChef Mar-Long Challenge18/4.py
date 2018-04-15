import math
def check(a,k):
	s=0
	for i in range(len(a)):
			s+=math.ceil(a[i]/k)
	return s

t=int(input())
for z in range(t):
	n,h=list(map(int,input().split()))
	a=list(map(int,input().split()))
	k=int(sum(a)/h)
	if(k==0):
		k+=1
	s=check(a,k)
	while(s>h):
		k+=int(s/h)
		s=check(a,k)
	print(k)

