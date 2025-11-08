//C. Prepend and Append
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while (t--){
        int n;
        cin>>n;

        string s;
        cin>>s;

        int i=0;
        int j=s.size()-1;
        int ans=0;

        while(i<j){
            if(s[i]!=s[j]) ans+=2;
            else break;
            i++;
            j--;
        }

        cout<<s.size()-ans<<endl;
    }
    return 0;
}