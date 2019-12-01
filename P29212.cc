#include <iostream>

using namespace std;

// Iterative
/* int powermod(int base, int exp, int mod) {
	int res = 1;
	while (exp > 0) {
		if (exp % 2 == 1) {
			res = (res * base) % mod;
		}
		base = (base * base) % mod;
		exp /= 2;
	}
	return res;
} */

// Divide and conquer
int powermod(int base, int exp, int mod) {
	if (exp == 0) return 1;
	int aux = powermod(base, exp/2, mod) % mod;
	int result = (aux * aux) % mod;
	if (exp % 2 == 0) return result;
	else return (result * (base % mod)) % mod;
}

int main() {
	int n, m, k;
	while (cin >> n >> m >> k) {
		cout << powermod(n, m, k) << endl;
	}
}