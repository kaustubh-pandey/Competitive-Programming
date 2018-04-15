def check(s,i,j):
	a=s[i:j+1]
	if(a==a[::-1]):
		return 1
	return 0

t=int(input())
for z in range(t):
	s=list(input())
	l=1
	i=0
	j=len(s)-1
	while(i<j):
		if(s[i]!=s[j]):
			if(check(s,i+1,j)==0 and check(s,i,j-1)==0):
				print("NO")
				l=0
				break
		i+=1
		j-=1
	if(l):
		print("YES")
		
	
	
