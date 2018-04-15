def checkD(b,n):
	for i in range(1,n+1):
		if(b[i][i]!=-1 and b[i][i]!=0):
			return 0
	return 1
def checkSym(b,n):
	for i in range(1,n):
		for j in range(i+1,n+1):
		
			if(b[i][j]!=-1 and b[j][i]!=-1):
				if(b[i][j]!=b[j][i]):
					return 0
			elif(b[i][j]!=-1 and b[j][i]==-1):
				b[j][i]=b[i][j]
			elif(b[i][j]==-1 and b[j][i]!=-1):
				b[i][j]=b[j][i]

	return 1

def checkT(b,n):
	for i in range(1,n-1):
		for j in range(i+1,n+1):
			if(b[i][j]!=-1 and b[i][j+1]!=-1 and b[i+1][j+1]!=-1):
				if(b[i+1][j+1]!=abs(b[i][j]-b[i+1][j+1]) and b[i+1][j+1]!=abs(b[i][j]+b[i+1][j+1])):
					return 0
	return 1

t=int(input())
for z in range(t):
	n,m=list(map(int,input().split()))
	b=[]
	for i in range(n+1):
		b.append([-1]*(n+1))
	for h in range(m):
		i,j,a=list(map(int,input().split()))
		if(a<0):
			print("no")
		else:
			b[i][j]=a
	if(checkD(b,n) and checkSym(b,n)):
		if(checkT(b,n)):
			print("yes")
		else:
			print("no")
	else:
		print("no")


	

