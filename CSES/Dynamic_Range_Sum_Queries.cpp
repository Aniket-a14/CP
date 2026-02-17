#include <bits/stdc++.h>
using namespace std;

#define int long long int

void buildTree(int arr[], int tree[], int treeNode, int start, int end) {

    if(start == end) {
        tree[treeNode] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    buildTree(arr, tree, 2 * treeNode, start, mid);
    buildTree(arr, tree, 2 * treeNode + 1, mid + 1, end);

    tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

void updateTree(int arr[], int tree[], int treeNode, int start, int end, int idx, int val) {
    if(start == end && start == idx) {
        arr[idx] = val;
        tree[treeNode] = val;
        return;
    }
    int mid = (start + end) / 2;
    if(idx <= mid) {
        updateTree(arr, tree, 2 * treeNode, start, mid, idx, val);
    }else {
        updateTree(arr, tree, 2 * treeNode + 1, mid + 1, end, idx, val);
    }

    tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

int query(int tree[], int treeNode, int start, int end, int left, int right) {
    if(start > right || end < left) {
        return 0;
    }
    if(start >= left && end <= right) {
        return tree[treeNode];
    }

    int mid = (start + end) / 2;
    int leftAns = query(tree, 2 * treeNode, start, mid, left, right);
    int rightAns = query(tree, 2 * treeNode + 1, mid + 1, end, left, right);
    return leftAns + rightAns;
}

int32_t main() {
    int n; cin >> n;
    int q; cin >> q;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int tree[4 * n];
    buildTree(arr, tree, 1, 0, n - 1);
    for(int i = 0; i < q; i++) {
        int type; cin >> type;
        if(type == 1) {
            int idx, val; cin >> idx >> val;
            updateTree(arr, tree, 1, 0, n - 1, idx - 1, val);
        }else {
            int left, right; cin >> left >> right;
            cout << query(tree, 1, 0, n - 1, left - 1, right - 1) << endl;
        }
    }
}