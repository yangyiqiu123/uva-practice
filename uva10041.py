while True:
    try:
        a=int(input())

        for i in range(a):
            num=list(map(int,input().split()))[1:]
            num=sorted(num)
            n=len(num)
            ans=0
            mid=num[n//2]
            for i in range(n):
                ans+=abs(num[i]-mid)
            print(ans)
    except:
        break