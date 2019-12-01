/* P43859: Weighted shortest path (1) */

#include <iostream>
#include <vector>
#include <limits>
#include <queue>

#define INFINIT numeric_limits<int>::max()

using namespace std;

typedef pair<int,int> arc;              //arc with cost
typedef vector< vector<arc> > Graph;    //Graph with cost

int n, m, x, y;
Graph g;
vector<int> d;
vector<int> p;

void read_graph() {
    g = Graph(n);
    for (int i = 0; i < m; ++i) {
      int origin, destiny, cost;
      cin >> origin >> destiny >> cost;
      arc a;
      a.first = cost;
      a.second = destiny;
      g[origin].push_back(a);
    }
}

void dijkstra() {
  int n = g.size();
  d = vector<int>(n, INFINIT);
  d[x] = 0;
  p = vector<int>(n, 1);
  vector<bool> visited(n, false);
  priority_queue< arc, vector<arc>, greater<arc> > q;
  q.push(arc(0, x)); // push the initial vertex
  
  while (not q.empty()) {
    int u = q.top().second; // vertex we depart from
    q.pop();
    if (not visited[u]) {
      visited[u] = true;
      for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i].second;  //vertex we go to
        int c = g[u][i].first;   //cost of going to it
        if (d[u] + c < d[v]) {
          d[v] = d[u] + c;
		  p[v] = p[u];
          q.push(arc(d[v],v));
        } else if (d[u] + c == d[v]) {
          p[v] += p[u];
		}
      }
    }
  }
}

int main() {
  while (cin >> n >> m) {
    read_graph();
    cin >> x >> y;
    if (x == y) cout << "cost 0, 1 way(s)" << endl;
    else {
      dijkstra();
      if (d[y] == INFINIT) cout << "no path from " << x << " to " << y << endl;
      else cout << "cost " << d[y] << ", " << p[y] << " way(s)" << endl;
    }
  }
}
