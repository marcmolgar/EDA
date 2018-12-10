#include <iostream>
#include <vector>

using namespace std;

void f(int i, int n, int z, int u, vector<int> &v) {
	if (z >= 0 and u >= 0) {
		if (n == i) {
			for (int j = 0; j < n; ++j) cout << (j ? " " : "") << v[j];
			cout << endl;
		}
		else {
			v[i] = 0;
			f(i+1, n, z-1, u, v);
			v[i] = 1;
			f(i+1, n, z, u-1, v);
		}
	}
}

int main() {
	int n, u;
	cin >> n >> u;
	vector<int> v(n);
  
	f(0, n, n-u, u, v);
}
