#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> graph[100];
bool visited[100];
void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int next : graph[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);}
        }
    }
}
int main() {
    int nodes, edges;
    cout << "Enter number of nodes: ";
    cin >> nodes;
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);}
    int start;
    cout << "Enter starting node: ";
    cin >> start;
    cout << "BFS Traversal: ";
    bfs(start);
    return 0;}

