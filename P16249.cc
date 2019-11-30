#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>

using namespace std;

typedef vector< vector<int> > Graph;

int n, m;
Graph graph;
vector<int> indegree;
vector<string> task_names;
map<string, int> task_index;
list<string> result; // a dynamic structure needs to be used in order to satisfy the jutge efficiency requirements

void read_tasks() {
	for (int i = 0; i < n; ++i) {
		string task;
		cin >> task;
		task_names[i] = task;
		task_index[task] = i; //M.insert(make_pair(s[i]), i);
	}
}

void read_dependencies() {
	cin >> m;

	graph = Graph(n);
	indegree = vector<int>(n, 0);

	for (int i = 0; i < m; ++i) {
		string task1, task2;
		cin >> task1 >> task2;
		graph[task_index[task1]].push_back(task_index[task2]);
		++indegree[task_index[task2]];
	}
}

void topological_sorting() {
	priority_queue< string, vector<string>, greater<string> > q;

	for (int i = 0; i < graph.size(); ++i) {
		if (indegree[i] == 0) {
			q.push(task_names[i]);
		}
	}

	result = list<string>();
	while (not q.empty()) {
		int u = task_index[q.top()]; // u: vertex we depart from
		q.pop();

		result.push_back(task_names[u]);

		for (int i = 0; i < graph[u].size(); ++i) {
			int v = graph[u][i]; // v: vertex we want to go to
			if (--indegree[v] == 0) {
				q.push(task_names[v]);
			}
		}
	}
}

void print_result() {
	if (result.size() == task_names.size()) {
		list<string>::iterator it;
		for (it = result.begin(); it != result.end(); ++it) {
			cout << *it;
		}
	} else {
		cout << "NO VALID ORDERING";
	}
	cout << endl;
}

int main() {
	while (cin >> n) {
		task_index = map<string, int>();
		task_names = vector<string>(n);

		read_tasks();

		read_dependencies();

		topological_sorting();

		print_result();
	}
}
