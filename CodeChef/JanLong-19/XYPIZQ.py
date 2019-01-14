def gcd(a,b):
	if(b==0):
		return a
	return gcd(b,a%b)

def type1(alpha,x,y,z):
	#AAB
	if(x<y):
		if(z<y):
			return y-1
		else:
			#return 180-((y+1)*alpha)
			return alpha-(y+1)
	else:
		if(z<y):
			#return 180-((y-1)*alpha)
			return alpha-(y-1)
		else:
			#return (y+1)*alpha
			return y+1

def type2(alpha,x,y,z):
	#type 2 and 4
	#return 180-(2*y*alpha)
	return alpha-(2*y)
def type3(alpha,x,y,z):
	if(y<x):
		if(z<y):
			return alpha-(y+1)
		else:
			return y+1
	else:
		if(z<y):
			return y-1
		else:
			return alpha-(y-1)
	
for _ in range(int(input())):
	n,t,x,y,z=list(map(int,input().split()))
	#alpha=180/(2*n+1)
	alpha=2*n+1
	if(t==2 or t==4):
		num=type2(alpha,x,y,z)
	elif(t==1):
		num=type1(alpha,x,y,z)
	else:
		num=type3(alpha,x,y,z)
	g=gcd(num,alpha)
	print(num//g,alpha//g)