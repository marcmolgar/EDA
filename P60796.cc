/* P60796: Tresors en un mapa (2) */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector< vector<char> > Matrix;
typedef vector< vector<bool> > Matrix_bool;

struct position {
	int r; // row
	int c; // column
	int d; // distance to this position from starting coordinates
};

/* 
 * Statement variables
 */
int n, m, r, c;
Matrix field;
Matrix_bool queued;

/*
 * Auxiliar arrays used to loop through the 4 adjacent positions of a cell
 */
const int mov_x[] = { 1, -1, 0, 0 };
const int mov_y[] = { 0, 0, 1, -1 };

/*
 * Reads a matrix of characters
 */
void read_field() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> field[i][j];
}

/*
 * A position is considered valid iff it lies within the limits of the
 * matrix, does not contain an 'X', and has not been queued yet
 */
bool valid_position(int i, int j) {
	return i >= 0
	   and i < n
	   and j >= 0
	   and j < m
	   and field[i][j] != 'X'
	   and not queued[i][j];
}

/*
 * Returns the distance to the nearest treasure starting from
 * initial position. If no treasure can be reached, returns 0.
 * Time complexity: Θ(n·m)
 */
int bfs() {
	queued = Matrix_bool(field.size(), vector<bool>(m, false));
	
	position initial_pos;
	initial_pos.r = r-1;
	initial_pos.c = c-1;
	initial_pos.d = 0;

	queue<position> q;
	q.push(initial_pos);
	queued[r-1][c-1] = true;

	while (not q.empty()) {
		position current = q.front();
		q.pop();

		if (field[current.r][current.c] == 't')
		    return current.d;

		for (int i = 0; i < 4; i++) { // loops through the 4 adjacent positions
			if (valid_position(current.r + mov_x[i], current.c + mov_y[i])) {
				position adjacent;
				adjacent.r = current.r + mov_x[i];
				adjacent.c = current.c + mov_y[i];
				adjacent.d = current.d + 1;
				q.push(adjacent);
				queued[adjacent.r][adjacent.c] = true;
			}
		}
	}
	return 0;
}

int main() {
	cin >> n >> m;
	field = Matrix(n, vector<char>(m));
	read_field();
	cin >> r >> c;
	int dist = bfs();
	if (dist > 0) cout << "minimum distance: " << dist << endl;
	else cout << "no treasure can be reached" << endl;
}
