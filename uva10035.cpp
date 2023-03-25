#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    while (cin>>a>>b)
    {
        if(a==0&&b==0){
            break;
        }

        int ans=0;
        int carry =0;
        while(a!=0||b!=0){
            int temp=a%10+b%10+carry;
            carry=temp/10;
            if(carry==1){
                ans+=1;
            }
            a=a/10;
            b=b/10;
           
        }

        // cout<<ans<<endl;

        if(ans==0){
            cout<<"No carry operation."<<endl;
        }
        else if(ans==1){

            cout<<"1 carry operation."<<endl;
        }
        else{
            cout<<ans<<" carry operations."<<endl;
        }
    }
    
}