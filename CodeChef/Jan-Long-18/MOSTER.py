# "{0:b}".format()
def generate(x,bx,w,n):
	bx1,bx2='0'+bx,'1'+bx
	if(int(bx1,2)<n and int(bx1,2)&x==int(bx1,2) and int(bx1,2) not in w):
		w.append(int(bx1,2))
		generate(x,bx1,w,n)
	if(int(bx2,2)<n and int(bx2,2)&x==int(bx2,2) and int(bx2,2) not in w):
		w.append(int(bx2,2))
		generate(x,bx2,w,n)
	return 0
def allOne(w,n,bx,x):
	if(len(set(list(bx)))==1):
		for i in range(x):
			if(i not in w):
				w.append(i)
def lower(w,n,bx):
	if(int(bx,2)==0):
		return 0
	if(int(bx,2)<n and int(bx,2)&x==int(bx,2) and int(bx,2) not in w):
				w.append(int(bx,2))
	for i in range(len(bx)-1,-1,-1):
		if(bx[i]=='1'):
			bx=list(bx)
			bx[i]='0'
			bx="".join(bx)
			if(int(bx,2)<n and int(bx,2)&x==int(bx,2) and int(bx,2) not in w):
				w.append(int(bx,2))
			lower(w,n,bx)
			bx=list(bx)
			bx[i]='1'
			bx="".join(bx)
	return 0


n=int(input())
h=list(map(int ,input().split()))
q=int(input())
for r in range(q):
	x,y=list(map(int,input().split()))
	bx="{0:b}".format(x)
	w=[0]
	if(int(bx,2)<n):
		w.append(int(bx,2))
	generate(x,bx,w,n)
	#print(w)
	allOne(w,n,bx,x)
	#print(w)
	lower(w,n,bx)
	#print(w)
	for i in w:
		h[i]-=y
	#print(h)
	count=0
	for i in range(n):
		if(h[i]>0):
			count+=1
	print(count)
