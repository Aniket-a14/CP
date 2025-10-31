//A. Unit Array
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while (t--){
        long long n;
        cin>>n;

        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        long long ops=0;
        long long neg_count=0;
        long long pos_count=0;

        for(int i=0;i<n;i++){
            if(arr[i]==-1) neg_count++;
            else pos_count++;
        }

        while(pos_count<neg_count || neg_count%2==1){
            ops++;
            neg_count--;
            pos_count++;
        }

        cout<<ops<<endl;
    }
    return 0;
}