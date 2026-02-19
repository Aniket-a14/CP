#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> grid[i][j];

    queue<pair<int, int>> q;
    vector<vector<int>> stepMonst(n, vector<int> (m, 1e8));
    pair<int, int> cord;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'M') {
                q.push({i, j});
                stepMonst[i][j] = 0;
            }
            if(grid[i][j] == 'A') cord = {i, j};
        }
    }
    while(q.size()) {
        int i = q.front().first;
        int j = q.front().second;

        q.pop();
        if(i + 1 < n && grid[i + 1][j] != '#' && stepMonst[i + 1][j] == 1e8) {
            stepMonst[i + 1][j] = 1 + stepMonst[i][j];
            q.push({i + 1, j});
        }
        if(i - 1 >= 0 && grid[i - 1][j] != '#' && stepMonst[i - 1][j] == 1e8) {
            stepMonst[i - 1][j] = 1 + stepMonst[i][j];
            q.push({i - 1, j});
        }
        if(j + 1 < m && grid[i][j + 1] != '#' && stepMonst[i][j + 1] == 1e8) {
            stepMonst[i][j + 1] = 1 + stepMonst[i][j];
            q.push({i, j + 1});
        }
        if(j - 1 >= 0 && grid[i][j - 1] != '#' && stepMonst[i][j - 1] == 1e8) {
            stepMonst[i][j - 1] = 1 + stepMonst[i][j];
            q.push({i, j - 1});
        }
    }
    queue<pair<int, pair<int, int>>> q1;
    q1.push({0, cord});
    vector<vector<char>> moves(n, vector<char> (m, '.'));
    string ans = "NO\n";
    pair<int, int> endCell = {-1, -1};
    while(q1.size()) {
        int currTime = q1.front().first;
        int i = q1.front().second.first;
        int j = q1.front().second.second;
        q1.pop();
        if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
            ans = "YES\n";
            endCell = {i, j};
            break;
        }

        if(i + 1 < n && grid[i + 1][j] != '#' && 1 + currTime < stepMonst[i + 1][j] && moves[i + 1][j] == '.') {
            moves[i + 1][j] = 'D';
            q1.push({currTime + 1, {i + 1, j}});
        }
        if(i - 1 >= 0 && grid[i - 1][j] != '#' && 1 + currTime < stepMonst[i - 1][j] && moves[i - 1][j] == '.') {
            moves[i - 1][j] = 'U';
            q1.push({currTime + 1, {i - 1, j}});
        }
        if(j + 1 < m && grid[i][j + 1] != '#' && 1 + currTime < stepMonst[i][j + 1] && moves[i][j + 1] == '.') {
            moves[i][j + 1] = 'R';
            q1.push({currTime + 1, {i, j + 1}});
        }
        if(j - 1 >= 0 && grid[i][j - 1] != '#' && 1 + currTime < stepMonst[i][j - 1] && moves[i][j - 1] == '.') {
            moves[i][j - 1] = 'L';
            q1.push({currTime + 1, {i, j - 1}});
        }
    }

    cout << ans;
    if(endCell.first != -1) {
        string path = "";
        while(!(endCell.first == cord.first && endCell.second == cord.second)) {
            path += moves[endCell.first][endCell.second];
            if(moves[endCell.first][endCell.second] == 'R') {
                endCell.second -= 1;
            }else if(moves[endCell.first][endCell.second] == 'L') {
                endCell.second += 1;
            }else if(moves[endCell.first][endCell.second] == 'D') {
                endCell.first -= 1;
            }else if(moves[endCell.first][endCell.second] == 'U') {
                endCell.first += 1;
            }
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        cout << path << endl;
    }
}