//A. Desorting
#include<bits/stdc++.h>
using namespace std;

bool sorted(vector<long long> arr){
    vector<long long> temp(arr);
    sort(arr.begin(),arr.end());

    if(temp==arr){
        return true;
    }

    return false;
}

int main(){
    int t;
    cin>>t;

    while (t--){
        int n;
        cin>>n;

        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        if(sorted(arr)){
            long long mini=INT_MAX;
            for(int i=1;i<n;i++){
                mini = min(mini,arr[i]-arr[i-1]);
            }

            cout<<(mini/2)+1<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}