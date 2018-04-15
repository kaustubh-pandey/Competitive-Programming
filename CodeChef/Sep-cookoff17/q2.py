t=int(input())
for z in range(t):
	n=int(input())
	if(n==1):
		print("1")
	elif(n==2):
		print("1 2")
	else:
		if(n%2):
			k=(n-1)//2
			a=[]
			for i in range(n-k,n+k+1):
				#print(i)
				a.append(i)
		else:
			k=n//2
			a=[]
			for i in range(n-k,n+k):
				a.append(i)
		for i in range(len(a)):
			print(a[i],end=" ")
		print("")