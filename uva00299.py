# bubble sort
# ºâ¥æ´«´X¦¸

def main():
    f = int(input())
    for q in range(f):
        count = 0
        lend = int(input())
        num = list(map(int, input().split()))

        for i in range(lend-1):
            for j in range( lend-i-1):
                if num[j] > num[j+1]:
                    num[j], num[j+1] = num[j+1], num[j]
                    count += 1
        print("Optimal train swapping takes", count, "swaps.")


main()
