while True:
    try:
        n1=int(input())
        num=[]
        for i in range(n1):
            num.append(int(input()))
        num.sort()

        ans2=0
        n=len(num)
        if n%2==0:
            ans1=num[n//2-1]
            ans3=num[n//2]-num[n//2-1]+1
            for i in num:
                if i==num[n//2] or i==num[n//2-1]:
                    ans2+=1
        else:
            ans1=num[n//2]
            ans3=1
            for i in num:
                if i==num[n//2]:
                    ans2+=1
                    
        print(f'{ans1} {ans2} {ans3}')
            
        
        
    except:
        break
