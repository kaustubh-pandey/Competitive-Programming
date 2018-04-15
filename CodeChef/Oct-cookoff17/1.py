t=int(input())
for z in range(t):
	a=list(input())
	count=0
	s=0
	p=[]
	a.append('$')
	for i in range(len(a)-1):
		if(a[i]==a[i+1] and s!=1):
			p.append(i)
			c=1
			s=1
		elif(a[i]!=a[i+1] and s==1):
			p.append(i)
			s=0
	#print(p)
	for i in range(0,len(p),2):
		#print(p[i],p[i+1])
		k=p[i+1]-p[i]+1
		count+=k*(k-1)//2
		#print(a[p[i+1]+1],a[p[i]-1])
		if(p[i+1]+1 <=len(a) and p[i]-1>=0 and a[p[i+1]+1]==a[p[i]-1]):
			count+=1
	for i in range(len(a)-2):
		if(a[i]==a[i+2] and a[i]!=a[i+1]):
			count+=1

	print(count)