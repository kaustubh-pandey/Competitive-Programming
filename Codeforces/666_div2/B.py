import math
n=int(input())
a=list(map(int,input().split()))
a.sort()
maxm = a[len(a)-1]
val = maxm **(1/(len(a)-1))
a1 = int(val)
a2 = math.ceil(val)
sum1=0
sum2=0
for i in range(len(a)):
	sum1+= abs(a[i]-(a1**i))
	sum2+= abs(a[i]-(a2**i))
print(min(sum1,sum2))