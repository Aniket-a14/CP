//A. Twin Permutations
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while (t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        for(int i=0;i<n;i++){
            cout<<n+1-arr[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}