t=int(input())
for z in range(t):
	n,p=list(map(int,input().split()))
	a=list(map(int,input().split()))
	cl=p//2
	hl=p//10
	cw,hw=0,0
	for i in a:
		if(i>=cl):
			cw+=1
		elif(i<=hl):
			hw+=1
	if(cw==1 and hw==2):
		print("yes")
	else:
		print("no")