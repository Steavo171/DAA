#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct DisjointSet {
    int *parent, *rank;
    int n;

    DisjointSet(int n) {
        this->n = n;
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Find the root of the set containing element x
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by rank
    void Union(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);

        if (rank[xRoot] < rank[yRoot])
            parent[xRoot] = yRoot;
        else if (rank[xRoot] > rank[yRoot])
            parent[yRoot] = xRoot;
        else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};

// Function to compare two edges based on their weight
bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void Kruskal(vector<Edge> &edges, int V) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), compareEdges);

    // Create a disjoint set
    DisjointSet ds(V);

    cout << "Minimum Spanning Tree Edges:" << endl;

    // Iterate through all sorted edges
    for (Edge edge : edges) {
        int srcRoot = ds.find(edge.src);
        int destRoot = ds.find(edge.dest);

        // If including this edge does not cause a cycle, include it in the MST
        if (srcRoot != destRoot) {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
            ds.Union(srcRoot, destRoot);
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter source, destination and weight of each edge:" << endl;
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    Kruskal(edges, V);

    return 0;
}
