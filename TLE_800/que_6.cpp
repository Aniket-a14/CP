//Doremy's Paint 3
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while (t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }

        if(mp.size()>2) cout<<"NO"<<endl;
        else{
            int freq_1 = mp.begin()->second;
            int freq_2 = mp.rbegin()->second;

            if(freq_1==freq_2) cout<<"YES"<<endl;
            else if(n%2==1 && abs(freq_1 - freq_2)==1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}