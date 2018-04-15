t=int(input())
for z in range(t):
	a=list(map(int,list(input())))
	n=len(a)
	i=0
	j=n-1
	#print(j)
	s=0
	while(i<=(n-1)//2):
		#print(i,j)
		if(a[i]!=a[j]):
			#print(i,j)
			if(a[j]>a[i]):
				a[j]=a[i]
			else:
				a[j]=a[i]
				s=1
		i+=1
		j-=1
	if(s):
		a[n//2]-=1
	a=list(map(str,a))
	print("".join(a))

