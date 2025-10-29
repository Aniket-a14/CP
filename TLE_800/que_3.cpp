//A. Cover in Water
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;

        int consecutive=0;
        int ans=0;
        int total=0;

        for(int i=0;i<n;i++){
            if(s[i]=='.') {
                total++;
                consecutive++;
                ans=max(ans,consecutive);
            }else{
                consecutive=0;
            }
        }
        
        if(ans>=3){
            cout<<2<<endl;
        }else{
            cout<<total<<endl;
        }
    }
}