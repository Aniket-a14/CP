#include<bits/stdc++.h>
using namespace std;

int find_parent(vector<int> &parent, int node){
    if(parent[node] == node) return node;
    return parent[node] = find_parent(parent, parent[node]);
}

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> edges(m, vector<int>(3,0));

    for(int i=0; i<m; i++){
        cin>>edges[i][1]>>edges[i][2]>>edges[i][0];
    }
    sort(edges.begin(), edges.end());

    vector<int> parent(n+1), size(n+1, 1);
    for(int i=0; i<=n; i++) parent[i] = i;

    int count = 0, cost = 0;
    for(int i=0; i<m; i++){
        int parent1 = find_parent(parent, edges[i][1]);
        int parent2 = find_parent(parent, edges[i][2]);

        if(parent1 == parent2) continue;

        if(size[parent1] < size[parent2]){
            size[parent2] += size[parent1];
            parent[parent1] = parent2;
        }
        else{
            size[parent1] += size[parent2];
            parent[parent2] = parent1;
        }
        count++;
        cost += edges[i][0];
    }
    if(count != n-1) cout<<"IMPOSSIBLE"<<endl;
    else cout<<count<<" "<<cost<<endl;
}

// In this code, we implement the Disjoint Set Union (DSU) data structure to find the Minimum Spanning Tree (MST) of a graph using Kruskal's algorithm. The `find_parent` function is used to find the representative parent of a node, and we use path compression to optimize it. The main function reads the edges of the graph, sorts them by weight, and then iteratively adds edges to the MST while ensuring that no cycles are formed by checking if the parents of the two nodes are different. The total cost and count of edges in the MST are printed at the end. 
//Dry run example: 
// Input:
// 4 5
// 1 2 10
// 1 3 15
// 2 3 5
// 2 4 10
// 3 4 10
// Output:
// 3 25

// Explanation:
// The graph has 4 nodes and 5 edges. The edges are:
// 1. (1, 2) with weight 10
// 2. (1, 3) with weight 15
// 3. (2, 3) with weight 5
// 4. (2, 4) with weight 10
// 5. (3, 4) with weight 10
// After sorting the edges by weight, we get:
// 1. (2, 3) with weight 5
// 2. (1, 2) with weight 10
// 3. (2, 4) with weight 10
// 4. (3, 4) with weight 10
// 5. (1, 3) with weight 15
// We start with the first edge (2, 3) and add it to the MST since it does not form a cycle. The total cost is now 5.
// Next, we add the edge (1, 2) to the MST since it does not form a cycle. The total cost is now 15.
// Next, we add the edge (2, 4) to the MST since it does not form a cycle. The total cost is now 25.
// We skip the edge (3, 4) since it forms a cycle with the edges already in the MST.
// Finally, we skip the edge (1, 3) since it also forms a cycle with the edges already in the MST.
// The final MST consists of the edges (2, 3), (1, 2), and (2, 4) with a total cost of 25. The count of edges in the MST is 3.