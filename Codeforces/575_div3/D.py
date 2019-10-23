def add(s):
	if(s[len(s)-1]=='R'):
		s+='G'
	if(s[len(s)-1]=='G'):
		s+='B'
	if(s[len(s)-1]=='B'):
		s+='R'
	return s
for _ in range(int(input())):
	n,k=list(map(int,input().split()))
	a=input()
	r='R'
	g='G'
	b='B'
	for i in range(k):
		r=add(r)
		g=add(g)
		b=add(b)
	


