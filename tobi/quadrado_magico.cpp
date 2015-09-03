#include <cstdio>
#include <algorithm>

using namespace std;

int A[4][4];

void preenche () {
	if (A[0][0] == 0 && A[1][1] == 0 && A[2][2] == 0) {
		int f = A[1][1] + 1, s = A[0][0], t = A[2][2];
		while (1) {
			int soma = f + A[0][1] + A[2][1];
			s = soma - A[0][1] - A[0][2];
			t = soma - A[2][0] - A[2][1];
			if (s != 0 && t != 0 && s + t + f == soma) {
				A[0][0] = s;
				A[1][1] = f;
				A[2][2] = t;
				break;
			}
			f++; 
		}
	}
	else if (A[0][2] == 0 && A[1][1] == 0 && A[2][0] == 0) {
		int f = A[1][1] + 1, s = A[0][2], t = A[2][0];
		while (1) {
			int soma = f + A[0][1] + A[2][1];
			s = soma - A[0][0] - A[0][1];
			t = soma - A[2][1] - A[2][2];
			if (s != 0 && t != 0 && s + t + f == soma) {
				A[0][2] = s;
				A[1][1] = f;
				A[2][0] = t;
				break;
			} 
			f++;
		}
	}
	else {
		int maior = 0, somac, somal;
		for (int i = 0; i < 3; i++) {
			somac = 0, somal = 0;
			for (int j = 0; j < 3; j++) {
				somal += A[i][j];
				somac += A[j][i];
			}
			if (somal > maior) maior = somal;
			if (somac > maior) maior = somac;
		}
		somac = A[0][0] + A[1][1] + A[2][2];
		if (somac > maior) maior = somac;
		somac = A[0][2] + A[1][1] + A[2][0];
		if (somac > maior) maior = somac;

		int soma;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (A[i][j] == 0) {
					soma = 0, somal = 0, somac = 0; 
					
					for (int l = 0; l < 3; l++) 
						somal += A[i][l];
					if (somal > soma) soma = somal;
					
					for (int c = 0; c < 3; c++)
						somac += A[c][j];
					if (somac > soma) soma = somac;
					
					if (i == j) {
						somac = A[0][0] + A[1][1] + A[2][2];
						if (somac > soma) soma = somac;
						if (i == 1)
							somac = A[0][2] + A[1][1] + A[2][0];	
						if (somac > soma) soma = somac;
					}
					else if (i + j == 2) {
						somac = A[0][2] + A[1][1] + A[2][0];
						if (somac > soma) soma = somac;
					}
					
					A[i][j] = maior - soma;
				}
			}
		}

	}
}

int main () {
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++) 
			scanf ("%d", &A[i][j]);
	preenche ();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) 
			printf ("%d ", A[i][j]);
		printf ("\n");
	}
}

/*		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (A[i][j] == 0) {
					int p = 0;
					p = max (p, A[i][0] + A[i][1] + A[i][2]);
					p = max (p, A[0][j] + A[1][j] + A[2][j]);
					if (i == j) p = max (p, A[0][0] + A[1][1] + A[2][2]);
					if (i + j == 2) p = max (p, A[2][0] + A[1][1] + A[0][2]);

					A[i][j] = maior - p;
				}
			}
		}*/