# 要找的數字扣掉 <= 他的肺波納氣數 ， 一定不是與該樹相鄰的數
# 所以不用判斷相鄰項

feb=[1,2]
for i in range(40):
    feb.append(feb[-1]+feb[-2])

feb.reverse()
for o in range(int(input())):
    
    num=int(input())
    num_copy=num
    ans=''
    flag=False

    for i in range(len(feb)):
        if feb[i]<=num:
            num=num-feb[i]
            ans=ans+'1'
            flag=True
        elif flag:
            ans+='0'
    print('%d = '%num_copy,end='')
    print(ans,end='')
    print(' (fib)')
    
            
    


# ---------------------------------------------------

# 找出最大的扣掉，直接跳一項
# 就不會出現相鄰的
# AC

# for i in range(int(input())):
#     num=int(input())
#     num_copy=num
#     feb=[1,2]
#     for i in range(40):
#         feb.append(feb[-1]+feb[-2])
#     feb.reverse()
#     i=0
#     n=feb[0]
#     ans=[]
#     bans=''
    
#     # 找出最大的扣掉，直接跳一項
#     # 就不會出現相鄰的
#     while num!=0:
#         while feb[i]>num:
#             i+=1
            
        
#         num-=feb[i]
#         ans.append(feb[i])
#         i+=2
    
#     # 對應項轉成 0 1
#     # 直到第一個 1 出現後才開始寫進 bans 裡
#     y=0
#     flag=False
#     for h in range(len(feb)):
        
#         if ans[y]==feb[h]:
#             flag=True
#             bans+='1'
#             if y<len(ans)-1:
#                 y+=1
#         elif flag:
#             bans+='0'
                
            
    
#     print('{} = '.format(num_copy),end='')
#     # print("%s (fib)"%bans)
#     print("%s (fib)"%bans[bans.index('1'):])
#     # print(ans)
    
    
#---------------------------------------------------------
# WA
# 沒辦法判斷兩個是否是相鄰的兩項
# seq = []

# ans = ''


# def main():
#     global seq
#     num = int(input())

#     # for i in range(1,num+1):

#     #     findf(i)

#     #     print("{} = ".format(i),end='')
#     #     seq.reverse()

#     #     g(seq)

#     #     seq=[]
#     findf(5)

#     print("{} = ".format(3), end='')
#     seq.reverse()

#     g(seq)


# def findf(num):

#     if num == 0:

#         return
#     else:
#         a = 1
#         b = 2
#         if num == 1:
#             seq.append(1)

#         elif num == 2:
#             seq.append(2)

#         else:

#             while a+b < num :
#                 temp = b
#                 b = a+b
#                 a = temp

          
#             seq.append(b)

#             findf(num-b)


# def g(seq=[]):
#     ans = ''
#     lens = 0
#     a = 1
#     b = 2
#     if seq[0] != 1:
#         ans += '0'
#     while lens < len(seq):
#         if seq[lens] == 1:
#             ans = ans+'1'
#             lens += 1

#         elif seq[lens] == b:
#             ans = ans+'1'
#             lens += 1
#             temp = b
#             b = a+b
#             a = temp
#         else:
#             temp = b
#             b = a+b
#             a = temp

#             ans = ans+'0'
#     print(ans, end='')
#     print(" (fib)")


# main()
