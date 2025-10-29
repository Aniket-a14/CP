//A. How much does Daytona cost?
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while (t--){
        int n,k;
        cin>>n>>k;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        bool found = false;
        for(int i=0;i<n;i++){
            if(arr[i]==k){
                found = true;
                cout<<"YES\n";
                break;
            }
        }

        if(!found){
            cout<<"NO\n";
        }
    }
    return 0;
}