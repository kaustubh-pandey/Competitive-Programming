n=input().strip()
flag=0
for i in range(2,len(n)+1):
	s=n[0:len(n)-i+1]
	if(int(s)%i!=0):
		flag=1
		break
if(flag==1):
	print("No")
else:
	print("Yes")
