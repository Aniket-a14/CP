//A. Goals of Victory
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while (t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n-1;i++){
            cin>>arr[i];
        }

        int sum=0;
        for(int i=0;i<n-1;i++){
            sum+=arr[i];
        }

        if(sum<0){
            cout<<abs(sum)<<"\n";
        }else{
            cout<<0-sum<<"\n";
        }
    }
    return 0; 
}