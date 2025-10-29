//B. Sequence Game
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while (t--){
        int m;
        cin>>m;

        vector<int> arr(m);
        for(int i=0;i<m;i++){
            cin>>arr[i];
        }

        vector<int> ans;
        ans.push_back(arr[0]);

        for(int i=1;i<arr.size();i++){
            if(arr[i]>=arr[i-1]){
                ans.push_back(arr[i]);
            }else{
                ans.push_back(arr[i]);
                ans.push_back(arr[i]);
            }
        }

        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}