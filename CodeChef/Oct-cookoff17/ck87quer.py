import math
t=int(input())
for z in range(t):
	y=int(input())
	count=0
	a=0
	for i in range(1,min(y,701)):
			a=int(math.sqrt(y-i))
			count+=a
	print(count)

