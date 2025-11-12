//A. Extremely Round
#include<bits/stdc++.h>
using namespace std;

bool check(int num){
    int non_zero=0;

    while(num>0){
        int r = num%10;
        if(r!=0) non_zero++;
        num/=10;
    }

    if(non_zero==1) return true;
    return false;
}

int main(){
    int t;
    cin>>t;

    vector<int> nums;
    for(int i=1;i<=999999;i++){
        if(check(i)) nums.push_back(i);
    }

    while (t--){
        int n;
        cin>>n;

        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=n){
                ans++;
            }else{
                break;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}