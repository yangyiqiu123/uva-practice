t=True
while True:
    try:
        s=input()
        b=s.count("\"")
        for i in range(len(s)+b):
            if s[i]=="\"":
                if t==True:
                    s=s[:i ]+ "``" + s[i+1:]
                if t==False:
                    s=s[:i ]+ "''" + s[i+1:]
                t=not t  
                
            
        print(s)
    except EOFError:
        break