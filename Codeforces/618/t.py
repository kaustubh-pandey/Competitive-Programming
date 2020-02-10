def g(n,i,j):
	return (((n|i)-i)|j)-j
def f(n):
	for i in range(1,n+1):
		for j in range(1,n+1):
			if(g(n,i,j)!=g(n,j,i)):
				print(i,j,n,g(n,i,j))

for i in range(500):
	f(i)