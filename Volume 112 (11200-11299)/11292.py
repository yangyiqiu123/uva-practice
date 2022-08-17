# num in list a
# list b
def find(an, b):
    for i in range(len(b)):
        if b[i] >= an:
            return b[i]
def main():
    while(True):
        total=0
        m, n = map(int, input().split())
        data = []
        if m == 0 and n == 0:
            break
        for i in range(m+n):
            data.append(int(input()))
        if m > n:
            print('Loowater is doomed')
        else:
            a = data[:m]
            b = data[m:]
            b.sort()
            for j in range(len(a)):
                total=total+find(a[j],b)
            print(total)
main()
