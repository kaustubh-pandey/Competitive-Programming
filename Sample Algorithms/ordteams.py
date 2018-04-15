t=int(input())
for z in range(t):
	a=[]
	for x in range(3):
		a.append(list(map(int,input().split())))
	a.sort()
	eq=0
	get=0
	for i in range(3):
		if(a[0][i]<a[1][i]):
			get+=1
		elif(a[0][i]==a[1][i]):
			eq+=1
	s1=0
	if(get>=1 and get+eq==3):
		s1=1
	eq=0
	get=0
	for i in range(3):
		if(a[1][i]<a[2][i]):
			get+=1
		elif(a[1][i]==a[2][i]):
			eq+=1
	s2=0
	if(get>=1 and get+eq==3):
		s2=1
	if(s2 and s1):
		print("yes")
	else:
		print("no")
