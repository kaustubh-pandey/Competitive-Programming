def gcd(a,b):
	if(b==0):
		return a
	return gcd(b,a%b)
def GCD(a):
	gc=a[0]
	for i in range(1,len(a)):
		gc=gcd(gc,a[i])
	return gc
n=int(input())
a=list(map(int,input().split()))
G=GCD(a)
#print(G)
d=[0]*(G+1)
while(G%2==0):
	d[2]+=1
	G=G//2
G_copy=G
for i in range(3,G_copy+1,2):
	if(i>G):
		break
	while(G%i==0):
		d[i]+=1
		G=G//i
pro=1
for x in d:
	if(x!=0):
		pro = pro *(x+1)
print(pro)