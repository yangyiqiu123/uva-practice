while True:
    try:
        a=list(map(int,input().split()))
        f=0
        g=[i+1 for i in range(a[0]-1)]
        g2 =[]
        for i in range(1,len(a)-1):
            b=abs(a[i]-a[i+1])
            if  b> a[0]-1 or b<1:
                f=1
                break
            else:
                g2.append(b)
        h=sorted(g2)
        if f==0 and g==h:
            print("Jolly")
        else:
            print("Not jolly")
    except:
        break