//A. Line Trip
#include<bits/stdc++.h> 
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        long long n,x;
        cin>>n>>x;

        vector<long long> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        long long ans=arr[0];

        for(int i=1;i<n;i++){
            ans=max(ans,arr[i]-arr[i-1]);
        }
        ans=max(ans,2*(x-arr[n-1]));
        cout<<ans<<endl;
    }
    return 0;
}