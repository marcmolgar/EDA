/* P43859: Weighted shortest path (1) */

#include <iostream>
#include <vector>
#include <limits>
#include <queue>

#define INFINIT numeric_limits<int>::max()

using namespace std;

typedef pair<int,int> arc;		//arc with cost
typedef vector< vector<arc> > graph;	//graph with cost

void dijkstra(const graph &g, int x, vector<int> &d, vector<int> &p) {
  int n = g.size();
  d = vector<int>(n, INFINIT); d[x] = 0;
  p = vector<int>(n, -1);
  vector<bool> s(n, false);
  priority_queue< arc, vector<arc>, greater<arc> > q;
  q.push(arc(0,x));
  
  while (not q.empty()) {
    int u = q.top().second; //vertex we depart from
    q.pop();
    if (not s[u]) {
      s[u] = true;
      for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i].second;  //vertex we go to
		int c = g[u][i].first;   //cost of going to it
		if (d[v] > d[u] + c) {
		d[v] = d[u] + c;
		p[v] = u;
		q.push(arc(d[v],v));
		}
      }
    }
  }
}

int main() {
  int n, m, x, y;
  while (cin >> n >> m) {
    graph g(n);
    arc a;
    int k;
    for (int i = 0; i < m; ++i) {
      cin >> k;
      cin >> a.second >> a.first;
      g[k].push_back(a);
    }
    cin >> x >> y;
    if (x == y) cout << 0 << endl;
    else {
      vector<int> d;
      vector<int> p;
      dijkstra(g, x, d, p);
      if (p[y] == -1) cout << "no path from " << x << " to " << y << endl;
      else cout << d[y] << endl;
    }
  }
}