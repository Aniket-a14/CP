#include <bits/stdc++.h>
using namespace std;

#define int long long int

int n;
int mod = 1e9+7;

vector<vector<int>> matrix(vector<vector<int>> &A, vector<vector<int>> &B) {
    vector<vector<int>> ans(n, vector<int>(n,0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                ans[i][j] += (A[i][k] * B[k][j] ) % mod;
                ans[i][j] %= mod;
            }
        }
    }
    return ans;
}

vector<vector<int>> maxtExponentiate(vector<vector<int>> &A, int k) {
    if(k == 1) return A;
    vector<vector<int>> B = maxtExponentiate(A, k/2);
    B = matrix(B, B);
    if(k & 1) {
        return matrix(A, B);
    }
    return B;
}

int32_t main(){
    cin>> n;
    int k; cin>> k;
    vector<vector<int>> A(n, vector<int>(n,0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>> A[i][j];
        }
    }

    vector<vector<int>> ans = maxtExponentiate(A, k);
    int sum = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            sum += ans[i][j];
            sum %= mod;
        }
    }
    cout<< sum << "\n";
}