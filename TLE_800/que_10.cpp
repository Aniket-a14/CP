// C. Target Practice
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        vector<vector<char>> arr(10, vector<char>(10));

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cin >> arr[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (arr[i][j] == 'X'){
                    ans += min({i, j, 9 - i, 9 - j}) + 1;
                }
            }
        }

        cout << ans << endl;
    }
}