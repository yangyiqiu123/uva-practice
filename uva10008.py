while True:
    try:
        time = int(input())
        dic = {}
        
        for i in range(time):
            string = input()
            for c in string:
                c=c.lower()
                if not c.isalpha():
                    continue
                elif c not in dic.keys():
                    dic[c] = 1
                else:
                    dic[c] += 1
        for a,b in sorted(dic.items(), key=lambda x: (-x[1], ord(x[0]))):
            print( a.upper(),b)
    except:
        break
