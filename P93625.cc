#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> IntVec;
typedef vector<IntVec> IntMat;


void dynamic_binomial(int n, int k, IntMat &pascal_triangle) {
    if (pascal_triangle[n][k] < 0) {
        int nn = n - 1;
        int kk = k - 1;
        dynamic_binomial(nn, k, pascal_triangle);
        dynamic_binomial(nn, kk, pascal_triangle);
        pascal_triangle[n][k] = pascal_triangle[nn][k] + pascal_triangle[nn][kk];
    }
}

int main() {
    IntMat pascal_triangle;
    for (int i = 0; i < 31; ++i) {
        int vsize = i + 1;
        IntVec pascal_row(vsize, -1);
        pascal_row[0] = 1;
        pascal_row[i] = 1;
        pascal_triangle.push_back(pascal_row);
    }

    int n, k;
    while (cin >> n >> k) {
        dynamic_binomial(n, k, pascal_triangle);
        cout << pascal_triangle[n][k] << endl;
    }
}