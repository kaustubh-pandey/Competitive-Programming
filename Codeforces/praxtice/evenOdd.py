for i in range(1,151):
    if(i==1):
        print("if num == 1 : \n \t print(\"odd\")\n")
    elif(i&1):
        print("elif num == "+str(i)+" :\n \t print(\"odd\")\n")
    else:
        print("elif num == "+str(i)+" :\n \t print(\"even\")\n")