t=int(input())
for i in range(t):
	n,a,b=list(map(int,input().split()))
	a=list("{0:b}".format(a))
	b=list("{0:b}".format(b))
	#count which has greater no. of 1s
	a_1,a_0,b_1,b_0=a.count('1'),a.count('0'),b.count('1'),b.count('0')
	if(a_1+a_0<n):
		a_0+=n-(a_1+a_0)
	if(b_1+b_0<n):
		b_0+=n-(b_1+b_0)
		
	x=min(a_1,b_0)
	y=min(a_0,b_1)
	binary='1'*(x+y)+'0'*(n-(x+y))
	print(int(binary,2))