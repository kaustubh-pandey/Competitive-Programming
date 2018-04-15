def sub(a,b):
	#a>b
	a=list(a)
	b=list(b)
	c=""
	for i in range(len(a)-1,-1,-1):
		if(int(a[i])>=int(b[i])):
			c=str(int(a[i])-int(b[i]))+c
		else:
			c=str(10+int(a[i])-int(b[i]))+c
			a[i-1]=str(int(a[i-1])-1)
	return c

n=int(input())
for z in range(n):
    a=input()
    b=input()
    m=0
    if(len(a)>len(b)):
        b='0'*(len(a)-len(b))+b
    elif(len(b)>len(a)):
        a='0'*(len(b)-len(a))+a
        m=1
    else:
        for i in range(len(a)):
            if(b[i]>a[i]):
                m=1
                break
            elif(b[i]<a[i]):
                break
    if(m==0):
        c=sub(a,b)
    else:
        c=sub(b,a)
    for i in range(len(c)):
    	if(c[i]=='0'):
    		continue
    	else:
    		break
    c=list(c)
    c=c[i:]
    c=''.join(c)
    s=len(c)*'9'
    print(sub(s,c))
        