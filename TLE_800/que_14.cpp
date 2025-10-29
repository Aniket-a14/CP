//A. Buttons
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while (t--) {
        long long a, b, c;
        cin>>a>>b>>c;

        if (a>b) {
            cout << "First\n";
        }else if(b>a) {
            cout << "Second\n";
        }else{
            cout << (c % 2 ? "First\n" : "Second\n");
        }
    }
    return 0;
}
