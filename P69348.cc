#include <iostream>
#include <vector>

using namespace std;

void f(int i, int n, vector<int> &v, vector<bool> &b) {
  if (i == n) {
    for (int j = 0; j < n; ++j) cout << (j ? ',' : '(') << v[j];
    cout << ')' << endl;
  }
  else {
    for (int j = 0; j < n; ++j) {
      if (not b[j]) {
	b[j] = true;
	v[i] = j+1;
	f(i+1, n, v, b);
	b[j] = false;
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  vector<bool> b(n, false);
  f(0, n, v, b);
}