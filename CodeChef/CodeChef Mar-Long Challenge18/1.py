def front(a,b,n):
	for i in range(n):
		if(a[i]>b[i]):
			return 0
	return 1
def back(a,b,n):
	b=b[::-1]
	for i in range(n):
		if(a[i]>b[i]):
			return 0
	return 1

t=int(input())
for z in range(t):
	n=int(input())
	a=list(map(int,input().split()))
	b=list(map(int,input().split()))

	if(front(a,b,n)==1 and back(a,b,n)==1):
		print("both")
	elif(front(a,b,n)):
		print("front")
	elif(back(a,b,n)):
		print("back")
	else:
		print("none")
