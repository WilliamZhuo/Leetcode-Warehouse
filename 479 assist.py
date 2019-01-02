import math
finish=0
for a in range (9,0,-1):
    for b in range (9,-1,-1):
        for c in range (9,-1,-1):
            val=100001*a+10010*b+1100*c
            for gg in range(990,math.sqrt(val),-11):
                if((val%gg==0)&(val/gg<1000)):
                    print("val=",val)
                    print("gg=",gg)
                    finish=1
                    break;
            if(finish):
                break;
        if(finish):
            break;
    if(finish):
        break;