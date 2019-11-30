#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
/* #include <map> */

using namespace std;

typedef vector< vector<int> > Graph;

int n, m;
Graph graph;
vector<int> indegree;
list<int> result; // a dynamic structure needs to be used in order to satisfy the jutge efficiency requirements

void read_dependencies() {
	graph = Graph(n);
	indegree = vector<int>(n, 0);

    for (int j = 0; j < m; j++) {
		int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
		++indegree[v];
    }
}

void topological_sorting() {
	priority_queue< int, vector<int>, greater<int> > q;

	for (int u = 0; u < graph.size(); ++u) {
		if (indegree[u] == 0) {
			q.push(u);
		}
	}

	result = list<int>();
	while (not q.empty()) {
		int u = q.top(); // u: vertex we depart from
		q.pop();

		result.push_back(u);

		for (int i = 0; i < graph[u].size(); ++i) {
			int v = graph[u][i]; // v: vertex we want to go to
			if (--indegree[v] == 0) {
				q.push(v);
			}
		}
	}
}

void print_result() {
	if (!result.empty()) {
        cout << result.front();
        result.pop_front();
    }
    while (!result.empty()) {
        cout << ' ' << result.front();
        result.pop_front();
    }
	cout << endl;
}

int main() {
	while (cin >> n >> m) {
		read_dependencies();

		topological_sorting();

		print_result();
	}
}
