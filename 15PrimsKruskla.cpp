#include <iostream>
using namespace std;

#define SIZE 10
#define INF 999
int parent[SIZE];
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[a] = b;
}
void prims(int g[SIZE][SIZE], int n) {
    bool vis[SIZE] = {false};
    int edges = 0, total = 0;
    vis[0] = true;
    cout << "\nPrim's Algorithm:\n";
    while (edges < n - 1) {
        int min = INF, u = 0, v = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                for (int j = 0; j < n; j++) {
                    if (!vis[j] && g[i][j] && g[i][j] < min) {
                        min = g[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        cout << "Location " << u << " -> " << v << "  Time: " << g[u][v] << " mins\n";
        total += g[u][v];
        vis[v] = true;
        edges++;
    }
    cout << "Total Minimum Time (Prim's): " << total << " mins\n";
}
void kruskal(int g[SIZE][SIZE], int n) {
    for (int i = 0; i < n; i++)
       parent[i] = i;
    int edges = 0, total = 0;
    cout << "\nKruskal's Algorithm (DSU):\n";
    while (edges < n - 1) {
        int min = INF, u= -1, v= -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] && g[i][j] < min) {
                    min = g[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        int pa = find(u);
        int pb = find(v);
        if (pa != pb) {
            unite(u, v);
            cout << "Location " << u << " -> " << v << "  Time: " << min << " mins\n";
            total += min;
            edges++;
        }

        g[u][v] = g[v][u] = INF;
    }
    cout << "Total Minimum Time (Kruskal's): " << total << " mins\n";
}
int main() {
    int n;
    cout<<"Enter number of locations: ";
    cin>>n;
    int g[SIZE][SIZE];
    cout<<"Enter time matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    prims(g, n);

    cout << "\nRe-enter same matrix for Kruskal:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    kruskal(g, n);
}
