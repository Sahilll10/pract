#include <bits/stdc++.h>
using namespace std;
const int SIZE = 10;
int n;
char nodes[SIZE];
int adjMatrix[SIZE][SIZE];
vector<int> adjList[SIZE];
bool visited[SIZE];

void dfsMatrix(int v) {
    cout << nodes[v] << " ";
    visited[v] = true;
    for (int i = 0; i < n; i++)
        if (adjMatrix[v][i] && !visited[i])
            dfsMatrix(i);
}
void dfsList(int v, bool visitedDFS[]) {
    cout << nodes[v] << " ";
    visitedDFS[v] = true;
    for (int x : adjList[v])
        if (!visitedDFS[x])
            dfsList(x, visitedDFS);
}

void bfsMatrix(int start) {
    queue<int> q;
    bool visitedBFS[SIZE] = {false};
    q.push(start);
    visitedBFS[start] = true;

    while (!q.empty()) {
        int v = q.front();
           q.pop();
        cout << nodes[v] << " ";
        for (int i = 0; i < n; i++) {
            if (adjMatrix[v][i] && !visitedBFS[i]) {
                visitedBFS[i] = true;
                q.push(i);
            }
        }}}
void bfsList(int start) {
    queue<int> q;
    bool visitedBFS[SIZE] = {false};
    q.push(start);
    visitedBFS[start] = true;

    while (!q.empty()) {
        int v = q.front();
          q.pop();
        cout << nodes[v] << " ";
        for (int x : adjList[v]) {
            if (!visitedBFS[x]) {
                visitedBFS[x] = true;
                q.push(x);
            }
        }
    }
}

int main() {
    cout << "Enter number of locations: ";
    cin >> n;
    cout << "Enter names of locations (A, B, C...): ";
    for (int i = 0; i < n; i++) cin >> nodes[i];

    cout << "Enter adjacency matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
            if (adjMatrix[i][j]) 
               adjList[i].push_back(j);
        }

    cout << "\nDFS (Adjacency Matrix) starting from " << nodes[0] << ": ";
    for (int i = 0; i < n; i++) 
      visited[i] = false;
    dfsMatrix(0);

    cout << "\nBFS (Adjacency Matrix) starting from " << nodes[0] << ": ";
    bfsMatrix(0);

    bool visitedDFS[SIZE] = {false};
    cout << "\nDFS (Adjacency List) starting from " << nodes[0] << ": ";
    dfsList(0, visitedDFS);

    cout << "\nBFS (Adjacency List) starting from " << nodes[0] << ": ";
    bfsList(0);

    cout << endl;
}

void dfsMatrix(int v){
    cout<<nodes[v]<<" ";
    vis[v]=true;
    for(int i=0;i<N;i++){
        if(!adjMatrix[v][i] && !vis[i]){
            dfsMatrix(i);
        }
    }
}
void bfsMatrix(int start){
    queue<int>q;
    bool vis[SIZE]={false};
    q.push(start);
    vis[start]=true;
    whie(!q.empty){
        int v=q.front();
        q.pop();
        if(adjMatrix[v][i] && !visi[i])vis[i] =true;
        q.push(i);
    }
}