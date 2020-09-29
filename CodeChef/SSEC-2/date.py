def preprocess(date):
	arr = date.split('/')
	return list(map(int,arr[::-1]))
n=int(input().strip())
con=[]
for _ in range(n):
	d=input().strip()
	con.append(preprocess(d))
con.sort()
#print(con)
for i in con:
	i=list(map(str,i))
	print("/".join(i[::-1]))

