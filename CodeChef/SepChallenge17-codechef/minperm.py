t=int(input())
for z in range(t):
	n=int(input())
	a=[0]*n
	
	if(n%2):
		for i in range(1,n-1):
			if(i%2):
				a[i-1]=i+1
			else:
				a[i-1]=i-1
		a[i]=i+2
		a[i+1]=i
	else:
		for i in range(1,n+1):
			if(i%2):
				a[i-1]=i+1
			else:
				a[i-1]=i-1
	for i in a:
		print(i,end=" ")
	print("")
