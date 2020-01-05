
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<char> consonants; //mida n
vector<char> vocals; //mida n

vector<bool> marcats_consonants; //mida n
vector<bool> marcats_vocals; //mida n

vector<char> solucio; //mida 2*n

void escriure_solucio() {
	for (int i = 0; i < 2*n; ++i) {
		cout << solucio[i];
	}
	cout << endl;
}

void backtracking(int punter) {
	//si mhe passat de la mida es que ja he emplenat el vector solució
	if (punter >= solucio.size()) {
		escriure_solucio();
	}
	else {
		// he de distingir si em toca colocar consonant o vocal
		// si el punter es parell -> toca consonant, sino toca vocal
		
		if (punter%2 == 0) { //toca consonant
			for (int i = 0; i < n; ++i) {
				// aqui miro la consonant 'i'
				if (not marcats_consonants[i]) {
					solucio[punter] = consonants[i]; // coloco la consonant que toca
					
					marcats_consonants[i] = true;
					backtracking(punter+1);
					marcats_consonants[i] = false;
				}
			}
		} else { //toca vocal
			for (int i = 0; i < n; ++i) {
				// aqui miro la vocal 'i'
				if (not marcats_vocals[i]) {
					solucio[punter] = vocals[i]; // coloco la vocal que toca
					
					marcats_vocals[i] = true;
					backtracking(punter+1);
					marcats_vocals[i] = false;
				}
			}
		}
	}
}

int main() {
	cin >> n;
	
	consonants = vector<char>(n);
	vocals = vector<char>(n);
	
	marcats_consonants = vector<bool>(n, false);
	marcats_vocals = vector<bool>(n, false);
	
	solucio = vector<char>(2*n);
	
	// llegir consonants
	for (int i = 0; i < n; ++i) cin >> consonants[i];
	
	// llegir vocals
	for (int i = 0; i < n; ++i) cin >> vocals[i];

	backtracking(0);
}
