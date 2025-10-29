//C. Isamatdin and His Magic Wand!
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while (t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for (auto &x : arr) cin>>x;

        int even_count = 0;
        int odd_count = 0;

        for(int i=0; i<n; i++){
            if (arr[i] % 2 == 0) even_count++;
            else odd_count++;
        }

        if(even_count!=0 && odd_count!=0){
            sort(arr.begin(),arr.end());
        }

        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }

        cout<<"\n";
    }
    return 0;
}