//A. One and Two
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

        int tot_two=0;
        for(int i=0;i<n;i++){
            if(arr[i]==2) tot_two++;
        }

        int curr_two=0;
        int ans=-1;

        for(int i=0;i<n;i++){
            if(arr[i]==2){
                curr_two++;
            }

            if(curr_two == (tot_two-curr_two)){
                ans = i+1;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}