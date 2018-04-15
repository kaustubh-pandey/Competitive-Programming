def onesComp(s):
	a=list(s)
	for i in range(len(a)):
		if(a[i]=='1'):
			a[i]='0'
		else:
			a[i]='1'
	return "".join(a)
def add(a,b):
	s=[0]*len(a)
	for i in range(len(a)):
		s[i]=a[i]+b[i]
	return s

n,q=list(map(int,input().split()))
a=list(map(int,input().split()))
bin=[]
for i in range(len(a)):
	e="{0:b}".format(a[i])
	e=onesComp(e)
	e='1'*(31-len(e))+e
	
	bin.append(e)
dp=[]
dp.append(list(map(int,list(bin[0]))))
for i in range(1,len(bin)):
	dp.append(add(dp[i-1],list(map(int,list(bin[i])))))
#print(dp)
for z in range(q):
 	l,r=list(map(int,input().split()))
 	l-=1
 	r-=1
 	# for y in range(l,r+1):
 	# 	print(dp[l-1])
 	w=[]
 	for i in range(31):
 		if(l>0):
 			x=dp[l-1][i]
 		else:
 			x=0
 		count1=dp[r][i]-x
 		count0=r-l-count1+1
 		if(count1>count0):
 			w.append('1')
 		else:
 			w.append('0')
		
 	print(int("".join(w),2))




