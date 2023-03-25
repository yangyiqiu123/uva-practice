while True:
    try:
        count_a=[0 for i in range(26)]
        count_b=[0 for i in range(26)]
        a=input()
        b=input()
        for i in a:
            count_a[ord(i)-ord('a')]+=1
        for j in b:
            count_b[ord(j)-ord('a')]+=1
            
        for i in range(26):
            print(chr(i+ord('a'))*min(count_a[i],count_b[i]),end='')
        print()
        
        
    except:
        break
