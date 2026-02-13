#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

int main(){
    int n; cin>>n;
    int q; cin>>q;

    vector<vector<int>> binaryLifting(n+1,vector<int>(31,-1));

    for(int i=2;i<=n;i++){
        int a;cin>>a;

        binaryLifting[i][0] = a;
    }

    for(int j= 1;j<=30;j++){
        for(int i=1;i<=n;i++){
            int first = binaryLifting[i][j-1];
           if(first!=-1) binaryLifting[i][j] = binaryLifting[first][j-1];
        }
    }



    while(q--){
        int x,k; cin>>x>>k;

        for(int j=30;j>=0;j--){
            int curr;
            if(k&(1<<j)){
                x = binaryLifting[x][j];
            }
            if(x==-1){  
                break;
            }
        }
        cout<<x<<endl;
    }
}