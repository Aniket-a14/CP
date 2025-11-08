//A. We need the Zero
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while (t--){
        long long n;
        cin>>n;

        vector<long long> arr(n);
        for(long long i=0;i<n;i++) cin>>arr[i];

        long long ans=0;

        for(long long i=0;i<n;i++){
            ans ^=arr[i];
        }

        if(n%2==1){
            cout<<ans<<endl;
        }else{
            if(ans==0) cout<<ans<<endl;
            else cout<<-1<<endl;
        }
    }
    return 0;
}