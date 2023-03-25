#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    while(a--){
        int num;
        cin>>num;
        int x1=num;

        int b1=0;
        int b2=0;
        while(x1){
            b1+=x1&1;
            x1>>=1;
        }

        x1=num;
        int d=0;

        int mul=1;
        while(x1){
            d+=(x1%10)*mul;
            x1/=10;
            mul*=16;
        }
        

        while(d){
            b2+=d&1;
            d>>=1;
        }

        cout<<b1<<' '<<b2<<endl;


    }
}





























// #include <iostream>
// using namespace std;
 
// int main() {
//     int T, N;
//     cin >> T;
//     while (T--){
//         cin >> N;
//         int X1 = N;
//         int b1 = 0;
//         while (X1){
//             b1 += X1 & 1;
//             X1 >>= 1;
//         }
//         int X2 = 0;
//         int mul = 1;
//         X1 = N;
//         while (X1){
//             X2 += (X1 % 10) * mul;
//             X1 /= 10;
//             mul *= 16;
//         }
//         int b2 = 0;
//         while (X2){
//             b2 += X2 & 1;
//             X2 >>= 1;
//         }
//         cout << b1 << " " << b2 << "\n";
//     }
//     return 0;
// }