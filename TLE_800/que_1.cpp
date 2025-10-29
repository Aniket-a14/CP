//A. Halloumi Boxes
#include<bits/stdc++.h> 
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        long long n,k;
        cin>>n>>k;

        vector<long long> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        vector<long long> temp = arr;
        sort(temp.begin(), temp.end());

        if(temp==arr || k>1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;   
        }
    }
    return 0;
}