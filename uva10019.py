def dec_to_bin(num):
    if num!=0:
        ans = ""
        while num > 1:
            ans = str(num % 2)+ans
            num = num//2
        ans = '1'+ans
        return ans
    else:
        return '0'


def hex_to_bin(num):
    if num!=0:
        ans = ''
        for i in str(num):
            c=dec_to_bin(int(i))
            ans=ans+'0'*(4-len(c))+c
        return ans
    else:
        return '0'

def main():
    
    a=int(input())

    for i in range(a):
        b=int(input())
        b1=dec_to_bin(b).count('1')
        b2=hex_to_bin(b).count('1')
        
        print(f'{b1} {b2}')
main()

