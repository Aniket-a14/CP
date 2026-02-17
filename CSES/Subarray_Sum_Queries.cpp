#include <bits/stdc++.h>
using namespace std;

#define int long long int

struct Node {
    int ans = 0,pref = 0,suff = 0,sum = 0;
};

Node merge(Node left, Node right) {
    Node ans;
    ans.sum = left.sum + right.sum;
    ans.pref = max(left.pref, left.sum + right.pref);
    ans.suff = max(right.suff, right.sum + left.suff);
    ans.ans = max({left.ans, right.ans, left.suff + right.pref});
    return ans;
}

void buildTree(int arr[], Node tree[], int treeNode, int start, int end) {

    if(start == end) {
        tree[treeNode].sum = arr[start];
        tree[treeNode].pref = max(0LL, arr[start]);
        tree[treeNode].suff = max(0LL, arr[start]);
        tree[treeNode].ans = max(0LL, arr[start]);
        return;
    }

    int mid = (start + end) / 2;
    buildTree(arr, tree, 2 * treeNode, start, mid);
    buildTree(arr, tree, 2 * treeNode + 1, mid + 1, end);

    tree[treeNode] = merge(tree[2 * treeNode], tree[2 * treeNode + 1]);
}

void updateTree(int arr[], Node tree[], int treeNode, int start, int end, int idx, int val) {
    if(start == end && start == idx) {
        arr[idx] = val;
        tree[treeNode].sum = val;
        tree[treeNode].pref = max(0LL, val);
        tree[treeNode].suff = max(0LL, val);
        tree[treeNode].ans = max(0LL, val);
        return;
    }
    int mid = (start + end) / 2;
    if(idx <= mid) {
        updateTree(arr, tree, 2 * treeNode, start, mid, idx, val);
    }else {
        updateTree(arr, tree, 2 * treeNode + 1, mid + 1, end, idx, val);
    }

    tree[treeNode] = merge(tree[2 * treeNode], tree[2 * treeNode + 1]);
}

int32_t main() {
    int n; cin >> n;
    int q; cin >> q;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    Node tree[4 * n];
    buildTree(arr, tree, 1, 0, n - 1);
    for(int i = 0; i < q; i++) {
        int idx, val; cin >> idx >> val;
        updateTree(arr, tree, 1, 0, n - 1, idx - 1, val);
        cout << tree[1].ans << endl;
    }
}