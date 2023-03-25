// bubble sort
// ºâ¥æ´«´X¦¸

#include <iostream>
using namespace std;

int main()
{
    

    int f = 0;
    cin >> f;
    for (int ii = 0; ii < f; ii++)
    {
        int arr[50];
        int num = 0;
        int count=0;

        cin >> num;
        for(int i=0;i<num;i++){
            cin>>arr[i];
        }
        for(int i=0;i<num-1;i++){
            for(int j=0;j<num-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    count++;
                }
            }

        }
        cout<<"Optimal train swapping takes "<<count<<" swaps."<<endl;
    }

   
}