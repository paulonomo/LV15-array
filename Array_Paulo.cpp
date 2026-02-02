// Array_Paulo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void zadatak_a();
void zadatak_b();
void zadatak_c();
void zadatak_c();
void zadatak_d();
void zadatak_e();

int main()
{
	zadatak_e();
	return 0;
}
void zadatak_a() {
	int arr_F1[3] = { 2,4,5 };
	int arr_G1[3] = { 3,4,4 };
	int i = 0;
	for (i = 0; i < 3; i++) {
		if (arr_F1[i] > arr_G1[i]) {
			cout << " 1.F " << "\n";
		}
		else if (arr_F1[i] < arr_G1[i]) {
			cout << " 1.G " << "\n";
		}
		else {
			cout << " Isto " << "\n";
		}
	}
}

void zadatak_b() {
	int N, K;
	cin >> N >> K;  // Unos broja natjecatelja (N) i Patrikove oznake (K)

	int bodovi[100];  // Niz za pohranu bodova svih natjecatelja

	// Unos bodova svih natjecatelja
	for (int i = 0; i < N; ++i) {
		cin >> bodovi[i];
	}

	int patrikov_bod = bodovi[K - 1];  // Patrikov rezultat (K je 1-based, pa oduzimamo 1)

	// Provodimo petlju kroz sve natjecatelje i ispisujemo oznake onih koji imaju više bodova
	for (int i = 0; i < N; ++i) {
		if (bodovi[i] > patrikov_bod) {
			cout << (i + 1) << " ";  // Ispisujemo oznaku natjecatelja (i + 1 je oznaka natjecatelja)
		}
	}

}
void zadatak_c() {
	int N;
	cin >> N;  // Unos broja trgovaca

	int ponude[10];  // Niz za pohranu ponuda (max N = 10)
	int brojPonuda[101] = { 0 };  // Niz za brojanje ponuda (max ponuda = 100)

	// Unos ponuda trgovaca
	for (int i = 0; i < N; ++i) {
		cin >> ponude[i];
		brojPonuda[ponude[i]]++;  // Poveæavamo broj ponude koja se pojavila
	}

	int najmanjaJedinstvenaPonuda = 0;

	// Tražimo najmanju jedinstvenu ponudu
	for (int i = 0; i < N; ++i) {
		if (brojPonuda[ponude[i]] == 1) {
			najmanjaJedinstvenaPonuda = ponude[i];
			break;
		}
	}

	// Provodimo još jedan krug kako bismo osigurali da nema drugih manjih jedinstvenih ponuda
	for (int i = 0; i < N; ++i) {
		if (brojPonuda[ponude[i]] == 1 && ponude[i] < najmanjaJedinstvenaPonuda) {
			najmanjaJedinstvenaPonuda = ponude[i];
		}
	}

	// Ispis rezultata
	if (najmanjaJedinstvenaPonuda == 0) {
		cout << 0 << endl;
	}
	else {
		cout << najmanjaJedinstvenaPonuda << endl;
	}

}
void zadatak_d() {
	int l, n, p, k; cin >> l >> n;
	int orehnjaca[1000] = { 0 };
	int izlaza = 0, najvecia = 0, izlazb = 0, najvecib = 0, brojac;

	for (int i = 1;i <= n;i++) {
		cin >> p >> k;
		if (k - p > najvecia) {
			najvecia = k - p;
			izlaza = i;
		}

		brojac = 0;
		for (int j = p - 1;j < k;j++) {
			if (orehnjaca[j] == 0) {
				brojac++;
				orehnjaca[j] = i;
			}
		}

		if (brojac > najvecib) {
			najvecib = brojac;
			izlazb = i;
		}
	}
	cout << izlaza << endl << izlazb;
}
void zadatak_e() {
	int N,x;
	int najveci = 0;
	int skoro_najveci = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x > najveci) {
			skoro_najveci = najveci;
			najveci = x;
		}
		else if (x > skoro_najveci && x != najveci) {
			skoro_najveci = x;
		}
	}
	cout << skoro_najveci;
}
	


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
