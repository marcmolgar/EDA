/* P70690: Tresors en un mapa (4) */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef vector< vector<char> > Matrix;
typedef vector< vector<bool> > Matrix_bool;

struct position {
	int r;
	int c;
	int d;
};

int n, m, r, c;
Matrix field;
Matrix_bool stacked;

int mov_x[] = { 1, -1, 0, 0 };
int mov_y[] = { 0, 0, 1, -1 };

void read_field() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> field[i][j];
}

bool valid_position(int i, int j) {
    	return (i >= 0 and i < n and j >= 0 and j < m and field[i][j] != 'X' and not stacked[i][j]);
}

bool bfs() {
	stacked = Matrix_bool(field.size(), vector<bool>(m, false));
	
	position initial_pos;
	initial_pos.r = r-1;
	initial_pos.c = c-1;
	initial_pos.d = 0;

	stack<position> s;
	s.push(initial_pos);
	stacked[r-1][c-1] = true;

	while (not s.empty()) {
		position current = s.top();
		s.pop();

		if (field[current.r][current.c] == 't')
            return true;

		for (int i = 0; i < 4; i++) {
			if (valid_position(current.r + mov_x[i], current.c + mov_y[i])) {
				position adjacent;
				adjacent.r = current.r + mov_x[i];
				adjacent.c = current.c + mov_y[i];
				adjacent.d = current.d + 1;
				s.push(adjacent);
				stacked[adjacent.r][adjacent.c] = true;
			}
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	field = Matrix(n, vector<char>(m));
	read_field();
	cin >> r >> c;
	bool found = bfs();
	if (found) cout << "yes" << endl;
	else cout << "no" << endl;
}
