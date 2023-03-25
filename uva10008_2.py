# while True:
#     try:
dict={}
time=int(input())
for i in range(time):
    sentence=input()
    for j in sentence:
        
        if j.isalpha():
            c=j.lower()
            if c  in dict.keys():
                dict[c]+=1
            else :
                dict[c]=1
for keys,value in sorted(dict.items(),key=lambda x:(-x[1],ord(x[0]))):
    print(f"{keys.upper()} {value}")
    # except:
    #     break

