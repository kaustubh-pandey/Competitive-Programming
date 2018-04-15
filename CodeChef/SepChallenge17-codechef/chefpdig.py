t=int(input())
for z in range(t):
	s=input()
	a=""
	l=list(s)
	if(l.count('6')>=2):
		a+=chr(66)
	if(l.count('7')>=2):
		a+=chr(77)
	if(l.count('8')>=2):
		a+=chr(88)

	b=list(set(s))
	
	for i in range(len(b)-1):
		for j in range(i+1,len(b)):
			w=b[i]+b[j]
			q=b[j]+b[i]
			#print(w,q)
			if(int(w)>=65 and int(w)<=90):
				a+=chr(int(w))
				
			if(int(q)>=65 and int(q)<=90):
				a+=chr(int(q))
				
	a=list(set(a))
	a.sort()
	print("".join(a))