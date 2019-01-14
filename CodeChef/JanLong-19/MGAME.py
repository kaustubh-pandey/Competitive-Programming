for _ in range(int(input())):
	n,p=list(map(int,input().split()))
	t=n%(n//2+1)
	if(n<=2):
		result=p**3
	else:
		result=((p-t)**2)+(p-n)*(p-t)+(p-n)**2
	print(result)
