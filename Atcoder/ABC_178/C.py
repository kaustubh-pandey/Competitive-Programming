n=int(input())
MOD = (10**9)+7
res = (10**n)%MOD
res = (res - ((9**n)%MOD))%MOD
res = (res - ((9**n)%MOD))%MOD
res = ((res%MOD) + ((8**n)%MOD) )
if(res<0):
	res+= MOD
print(res%MOD)
