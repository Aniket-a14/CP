//A. Round Trip
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while (t--){
        int r0,x,d,n;
        cin>>r0>>x>>d>>n;

        string s;
        cin>>s;

        int l=r0;
        int r=r0;
        int ans=0;

        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ans+=1;
                l= max(0,l-d);
                r=r+d;
            }else{
                if(l>=x){
                    continue;
                }
                ans+=1;
                l=max(0,l-d);
                r=min(x-1,r+d);
            }
        }

        cout<<ans<<endl;
        
    }
    return 0;
}