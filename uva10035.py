while True:
    a,b=map(str,input().split())
    if a=='0' and b=='0':
        break
    a=a[::-1]
    b=b[::-1]
    if len(b)>len(a):
        a,b=b,a
    
    carry=0
    ans=0
    for i in range(len(a)):
        temp=int(a[i])+carry
        if i<len(b):
            temp+=int(b[i])
        carry=temp//10
        ans+=carry
    
    if ans == 0:
        print("No carry operation.")
    elif ans == 1:
        print("1 carry operation.")
    else:
        print(f"{ans} carry operations.")
    
    
    
    
    
    
    
# AC

# while True:
#     a,b=map(int ,input().split())
#     if a==0 and b==0 :
#         break
#     ans=0
#     c=0
#     while a or b:
#         if a%10+b%10+c>9:
#             ans=ans+1
#             c=1
#         else:
#             c=0

#         a=a//10
#         b=b//10

#     if ans==0:
#         print("No carry operation.")
#     elif ans==1:
#         print(f'{ans} carry operation.')
#     else:
#         print(f'{ans} carry operations.')
    
    