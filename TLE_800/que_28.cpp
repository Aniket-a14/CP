//A. Make it Beautiful
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while (t--){
        int n;
        cin>>n;

        vector<int> nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];

        sort(nums.begin(),nums.end());
        
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());

        if(maxi == mini) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            cout<<maxi<<" ";
            for(int i=0;i<n-1;i++){
                cout<<nums[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}