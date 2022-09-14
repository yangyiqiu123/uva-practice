#include <iostream>
#include <cstdio>
using namespace std;


int r=0;
int Move(int n,char a,char b,char c){
    if(n==0){
        return 0;
    }
    Move(n-1,a,c,b);

    printf("%c->%c\n",a,c);
    r+=1;

    Move(n-1,b,a,c);
    return r;

}
int main(){
    cout<<"how many disk from a move c : ";
    int n;
    scanf("%d",&n);
    printf("Totally Move : %d times\n",Move(n,'A','B','C'));
}
