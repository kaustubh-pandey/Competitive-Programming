for _ in range(int(input())):
	s=input().split()
	flag=True
	for w in s:
		if(w=='not'):
			flag=False
			break
	if(flag):
		print("regularly fancy")
	else:
		print("Real Fancy")
