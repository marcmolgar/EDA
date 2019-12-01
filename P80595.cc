#include <iostream>
#include <vector>

using namespace std;

void readvector(vector<int> &v) {
	for (int i = 0; i < v.size(); ++i) 
		cin >> v[i];
}

/* Guardem el nombre d'inversions a x */
void merge(vector<int>& v, int l, int m, int r, int &x) {
	vector<int> b(r - l + 1);
	int i = l, j = m + 1, k = 0;
	while (i <= m and j <= r) {
		if (v[i] <= v[j]) b[k++] = v[i++];
		else {
			b[k++] = v[j++];
			x += m+1-i;
		}
	}
	while (i <= m) b[k++] = v[i++];
	while (j <= r) b[k++] = v[j++];
	for (k = 0; k <= r - l; ++k) v[l + k] = b[k];
}

void merge_sort_1(vector<int>& v, int l, int r, int &x) {
	if (l < r) {
		int m = (l + r) / 2;
		merge_sort_1(v, l, m, x);
		merge_sort_1(v, m + 1, r, x);
		merge(v, l, m, r, x);
	}
}

void merge_sort(vector<int>& v, int &x) {
	merge_sort_1(v, 0, v.size()-1, x);
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> v(n);
		readvector(v);
		int x = 0;
		merge_sort(v, x);
		cout << x << endl;
	}
}