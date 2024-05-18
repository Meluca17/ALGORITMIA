#include <iostream>
using namespace std;

const int N = 6;

int maxValor(int arreglo[N], int ini, int fin, int& indiceMax) {
    if (ini == fin) {
        indiceMax = ini;
        return arreglo[ini];
    }

    int med = (fin + ini) / 2;
    if (arreglo[med] < arreglo[med + 1]) {
        return maxValor(arreglo, med + 1, fin, indiceMax);
    } else {
        return maxValor(arreglo, ini, med, indiceMax);
    }
}

int main(int argc, char** argv) {
    int arreglo[N] = {10, 15, 20, 14, 3, 2};
    int indiceMax = 0;
    int max = maxValor(arreglo, 0, N - 1, indiceMax);
    cout << "El maximo valor es: " << max << " en el indice " << indiceMax << endl;
    return 0;
}

