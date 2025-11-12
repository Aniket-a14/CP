//
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

        sort(nums.begin(), nums.end());
        bool ok = true;
        for (int j = 1; j < n - 1; j += 2) {
            if (nums[j] != nums[j + 1]) {
                ok = false;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}