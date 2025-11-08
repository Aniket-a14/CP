//A. Serval and Mocha's Array
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while (t--){
        int n;
        cin>>n;

        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        int flag=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(__gcd(arr[i],arr[j])<=2){
                    flag=1;
                    break;
                }
            }
        }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}