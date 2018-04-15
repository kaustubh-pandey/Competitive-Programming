def check(a):
	g=list(set(list(a)))
	a=list(a)
	#print(g)
	c=0
	for i in range(len(g)):
		if(a.count(g[i])==1 and i!=len(g)-1):
			c+=1
			continue
		elif(a.count(g[i])==1 and i==len(g)-1 and c==len(g)-1):
			return 0
	return 1

t=int(input())
for z in range(t):
	a=input()
	if(check(a)):
		print("yes")
	else:
		print("no")

