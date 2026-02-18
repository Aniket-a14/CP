#include <bits/stdc++.h>
using namespace std;

#define int long long

int base;

void buildTree(vector<int> &tree) {
    for(int i = base - 1; i > 0; i--) {
        tree[i] = tree[2*i] + tree[2*i + 1];
    }
}

void updateTree(vector<int> &tree, int pos, int delta) {
    pos += base;
    tree[pos] += delta;

    while(pos > 1) {
        pos /= 2;
        tree[pos] = tree[2*pos] + tree[2*pos + 1];
    }
}

int query(vector<int> &tree, int l, int r) {
    l += base;
    r += base;
    int sum = 0;

    while(l <= r) {
        if(l % 2 == 1) sum += tree[l++];
        if(r % 2 == 0) sum += tree[r--];
        l /= 2;
        r /= 2;
    }

    return sum;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> salary(n);
    vector<pair<char, pair<int,int>>> queries(q);
    vector<int> values;

    for(int i = 0; i < n; i++) {
        cin >> salary[i];
        values.push_back(salary[i]);
    }

    for(int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second.first >> queries[i].second.second;
        if(queries[i].first == '!') {
            values.push_back(queries[i].second.second);
        }
    }

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    auto getId = [&](int x) {
        return lower_bound(values.begin(), values.end(), x) - values.begin();
    };

    int m = values.size();
    base = 1;
    while(base < m) base <<= 1;

    vector<int> tree(2 * base, 0);
    for(int i = 0; i < n; i++) {
        int id = getId(salary[i]);
        tree[base + id] += 1;
    }

    buildTree(tree);

    for(auto &qq : queries) {
        char type = qq.first;
        int a = qq.second.first;
        int b = qq.second.second;

        if(type == '!') {
            int idx = a - 1;
            updateTree(tree, getId(salary[idx]), -1);
            salary[idx] = b;
            updateTree(tree, getId(b), 1);
        }
        else {
            int l = lower_bound(values.begin(), values.end(), a) - values.begin();
            int r = upper_bound(values.begin(), values.end(), b) - values.begin() - 1;

            if(l > r) {
                cout << 0 << "\n";
            } else {
                cout << query(tree, l, r) << "\n";
            }
        }
    }
}
