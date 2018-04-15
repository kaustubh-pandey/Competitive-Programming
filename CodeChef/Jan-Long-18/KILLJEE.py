def get_all_substrings(input_string):
  length = len(input_string)
  return [input_string[i:j+1] for i in xrange(length) for j in xrange(i,length)]

s=raw_input()
q=int(raw_input())
a=get_all_substrings(s)
a.sort()
a="".join(a)
g=0
for i in range(q):
	p,m=map(int,raw_input().split())
	k=((p*g)%m)
	g+=ord(a[k])
	print a[k]