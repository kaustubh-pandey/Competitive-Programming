def f(a,rev):
    if(len(a)==0):
        return ""
    a.sort(reverse=True)
    # print(a)
    flag=True
    for i in range(len(a[0])):
        for j in range(1,len(a)):
            if(i<len(a[j]) and a[0][i]!=a[j][i] and a[j][i]!="*"):
                flag=False
                break
        if(not flag):
            break
    if(flag):
        if(rev):
            res = a[0][::-1]
        else:
            res = a[0]
    else:
        res="*"
    return res
def uniq(a):
  o = []
  for x in a:
    if x not in o:
      o.append(x)
  return o
def breakStar(s):
    a=s.split("*")
    # print(a)
    return [a[0]+"*","*"+a[len(a)-1],a[1:-1]]
def sant(s):
    tmp = s.split('*')
    res=[]
    for i in tmp:
        if i != '':
            res.append(i)
    return "*".join(res)
t=int(input())
for _ in range(t):
    n=int(input())
    start,endi,between=[],[],[]
    for i in range(n):
        s=input()
        # print(s)
        if(s[0]=="*" and s[len(s)-1]!="*"):
            wer = s[::-1].split('*')
            endi.append(wer[0]+'*')
            for k in range(1,len(wer)):
                if(wer[k]!=''):
                    between.append(wer[k][::-1])
        elif(s[0]!="*" and s[len(s)-1]=="*"):
            wer = s.split('*')
            start.append(wer[0]+'*')
            for k in range(1,len(wer)):
                if(wer[k]!=''):
                    between.append(wer[k])
        else:
            val1,val2,trp = breakStar(s)
            if(val1!="*"):
                start.append(val1)
            if(val2!="*"):
                endi.append(val2[::-1])
            between  = between+trp
    # print(start,endi,between)
    pat1 = f(start,False)
    pat2 = f(endi,True)
    # print(pat1,pat2)
    if(pat1=="*" or pat2=="*"):
        res="*"
    else:
        # print(uniq(between))
        tmp = "".join(uniq(between))
        res = pat1[:-1] + tmp +pat2[1:]
        if(res==""):
            res="*"
    print("Case #"+str(_+1)+": "+str(res))