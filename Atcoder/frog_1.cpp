#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int solve(vector<int>& dp, vector<int>& nums, int n){
        if(n==0) return 0;

        if(dp[n] != 1e9) return dp[n];

        for(int i=1;i<=2;i++){
            if(n-i >= 0){
                dp[n] = min(dp[n], solve(dp, nums, n-i) + abs(nums[n] - nums[n-i]));
            }
        }
        return dp[n];
    }
};

int main(){
    int n;cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    vector<int> dp(n,1e9);
    dp[0]=0;

    Solution s;
    cout << s.solve(dp,nums,n-1) << endl;
    return 0;
}