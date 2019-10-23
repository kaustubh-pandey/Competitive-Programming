def constraint(a,b):
	if(a>b):
		return b
	return 0
n,I = list(map(int,input().split()))
a = list(map(int,input().split()))

K = 1<<(8*I//n)
d=dict()
for i in a:
	d[i]=0
for i in a:
	d[i]+=1
sorted_d = list(d.items())
sorted_d.sort()
num=constraint(len(sorted_d),K)
if(num>0):
	min_c=0
	i=0
	while(i<num):
		min_c+=sorted_d[i][1]
		i+=1
	count=min_c
	total=min_c
	while(i<len(sorted_d)):
		count+=sorted_d[i][1]
		count-=sorted_d[i-num][1]
		total+=sorted_d[i][1]
		if(count>min_c):
			min_c=count
		i+=1
	print(total-min_c)

else:
	print(0)
