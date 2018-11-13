/* P60796: Tresors en un mapa (2) */

#include <iostream>
#include <vector>
#include <queue>

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
Matrix_bool enqueued;

int mov_x[] = { 1, -1, 0, 0 };
int mov_y[] = { 0, 0, 1, -1 };

void read_field() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> field[i][j];
		}
	}
}

bool valid_position(int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < m and field[i][j] != 'X' and not enqueued[i][j]);
}

int bfs() {
    enqueued = Matrix_bool(field.size(), vector<bool>(m, false));
	
	position initial_pos;
	initial_pos.r = r-1;
	initial_pos.c = c-1;
	initial_pos.d = 0;

	queue<position> q;
	q.push(initial_pos);
	enqueued[r-1][c-1] = true;

	while (not q.empty()) {
		position current = q.front();
		q.pop();

        if (field[current.r][current.c] == 't')
            return current.d;
        
        for (int i = 0; i < 4; i++) {
            if (valid_position(current.r + mov_x[i], current.c + mov_y[i])) {
                position adjacent;
                adjacent.r = current.r + mov_x[i];
                adjacent.c = current.c + mov_y[i];
                adjacent.d = current.d + 1;
                q.push(adjacent);
                enqueued[adjacent.r][adjacent.c] = true;
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
