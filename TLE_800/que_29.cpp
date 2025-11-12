//A. Everybody Likes Good Arrays!
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while (t--){
        int n;
        cin>>n;

        vector<long long> nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];

        long long ans=0;

        for(int i=0;i<n-1;i++){
            if(nums[i]%2==nums[i+1]%2) ans++;
        }

        cout<<ans<<endl;
    }
    return 0;
}