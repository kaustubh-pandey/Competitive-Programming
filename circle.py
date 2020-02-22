import math
def drawOctant(x,y,d):
	while(y>=x):
		x+=1
		if(d>0):
			y-=1
			d=d+4*(x-y)+10
		else:
			d = d + 4*x +6
		print(x,y)
x=0
y=4
r=4
d= 3 - (2*r)
drawOctant(0,4,d)
drawOctant(round(r*math.cos(math.pi/4)),round(r*math.sin(math.pi/4)),d)
drawOctant(4,0,d)
drawOctant(r*math.cos(math.pi/4),-r*math.sin(math.pi/4),d)
drawOctant(0,-4,d)
drawOctant(-r*math.cos(math.pi/4),-r*math.sin(math.pi/4),d)
drawOctant(-1,0,d)
drawOctant(-r*math.cos(math.pi/4),r*math.sin(math.pi/4),d)