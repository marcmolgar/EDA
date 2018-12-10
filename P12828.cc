#include <iostream>
#include <vector>

using namespace std;

void f(int n, int i, vector<int> &v) {
	if (n == i) {
		for (int j = 0; j < n; ++j) cout << (j ? " " : "") << v[j];
		cout << endl;
	}
	else {
		v[i] = 0;
		f(n, i+1, v);
		v[i] = 1;
		f(n, i+1, v);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
  
	f(n, 0, v);
}
