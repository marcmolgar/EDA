#include <iostream>
#include <vector>
using namespace std;
 
typedef vector<vector<int> > Matrix;

Matrix multiply_matrix(const Matrix& M1, const Matrix& M2,int m) {
    Matrix Res(2,vector<int>(2));
   
    Res[0][0] = ((M1[0][0] * M2[0][0]) % m + (M1[0][1]*M2[1][0]) % m) % m;
    Res[0][1] = ((M1[0][0] * M2[0][1]) % m + (M1[0][1]*M2[1][1]) % m) % m;
    Res[1][0] = ((M1[1][0] * M2[0][0]) % m + (M1[1][1]*M2[1][0]) % m) % m;
    Res[1][1] = ((M1[1][0] * M2[0][1]) % m + (M1[1][1]*M2[1][1]) % m) % m;
   
    return Res;
}

Matrix expo(const Matrix& M, int n, int m) {
    Matrix Res(2,vector<int>(2));
    if (n == 0) {
		// Identity matrix
        Res[0][0] = Res[1][1] = 1;
        Res[1][0] = Res[0][1] = 0;
		return Res;
    }
    else if (n == 1) {
		// Same matrix modulo n
        Res[0][0] = M[0][0] % m;
        Res[0][1] = M[0][1] % m;
        Res[1][0] = M[1][0] % m;
        Res[1][1] = M[1][1] % m;

		return Res;
    }
    else {
		Res = expo(M, n/2, m);
		Res = multiply_matrix(Res, Res, m);
        if (n%2 == 0) { // n even
            return Res;
        }
        else { // n odd
            return multiply_matrix(Res, M, m);
        }
    }
}

int main() {
    int n, m;
    Matrix M(2,vector<int>(2));
   
    while (cin >> M[0][0] >> M[0][1] >> M[1][0] >> M[1][1] >> n >> m) {
        M = expo(M,n,m);
        cout << M[0][0] << " " << M[0][1] << endl;
        cout << M[1][0] << " " << M[1][1] << endl;
        cout << "----------" << endl;
    }
}