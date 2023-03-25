
def main():
    
    a=[]
    while True:
        try:
            a.append(input())
        except:
            break;
 
    lens=0
    for i in range(len(a)):
        lens=max(lens,len(a[i]))
    
    for i in range(lens):
        
        # range(start,end,step)
        # because doesn't include the end index , need to put the num(-1) that after the index we want(0)
        for j in range(len(a)-1,-1,-1):
            if i>=len(a[j]):
                print(" ",end='')
            else:
                print(a[j][i],end='')
        print()

        
main()