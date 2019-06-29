#include <iostream>
#include <vector>

using namespace std;

/* typedef long long LL; */

int t, n, q;

int main() {
  int n;
  vector<int> mushrooms(100001);
  for (int i = 1; cin >> n; ++i) {
    cout << '#' << i << endl;
    mushrooms[0] = 0;
    for (int k = 1; k <= n; ++k) {
      cin >> mushrooms[k];
      mushrooms[k] += mushrooms[k-1];
    }
    cin >> q;
    for (int k = 0; k < q; ++k) {
      int f, h;
      cin >> f >> h;
      if (f > h) swap(f, h);
      cout << mushrooms[h] - mushrooms[f-1] << endl;
    }
  }
}