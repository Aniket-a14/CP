// A. Ambitious Kid
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            mini = 0;
            break;
        }
        else
        {
            mini = min(mini, abs(arr[i]));
        }
    }

    cout << mini << endl;
}