#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int solve(vector<bool>& vis, vector<int>& stairs, int step){
            if(step==stairs.size()) return 0;

            vis[step] = true;
            int op1 = 1 + solve(vis,stairs,step+1);
            int op2 = 567890;
            int next = step + stairs[step];
            if(next<=vis.size() && vis[next]==false && next>=0){
                vis[step] = true;
                op2 = 1 + solve(vis,stairs,next);
                vis[step] = false;
            }

            return min(op1,op2);
        }
};

int main(){
    int t;
    cin>>t;

    while(t--){
        int n; cin>> n;

        vector<int> nums(n);
        
        for(int i=0;i<n;i++) cin>>nums[i];

        vector<bool> vis(n,false);
        Solution s;
        cout<<s.solve(vis,nums,0)<<endl;
    }
}