

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int num_caso = 1;
const int MAXIMO = 101;

// función que resuelve el problema
int resolver(int n1, int n2, vector<int> t1, vector<int> t2) {
    int matrix[MAXIMO];
    for (int i = 0; i < MAXIMO; i++) {
        matrix[i] = 0;
    }
    int j = 1, aux=0, inter;
    for (int i = 1; i <= n1; i++) {


        if(t1[i - 1] == t2[j - 1]) {
            inter = aux;
            aux = matrix[i];
            matrix[i] = inter + 1;
        }
        else {
            aux = matrix[i];
            matrix[i] = max(matrix[i], matrix[i - 1]);
        }

        if (i == n1 && j!=n2) {
            j++;
            aux = matrix[0];
            i = 0;
        }
    }

    return matrix[n1];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n1, n2, r;
    cin >> n1 >> n2;

    if (n1==n2 && n2==0)
        return false;

    vector<int> t1(n1,0), t2(n2,0);

    for (int i = 0; i < n1; i++) {
        cin >> r;
        t1[i] = r;
    }
    for (int i = 0; i < n2; i++) {
        cin >> r;
        t2[i] = r;
    }


    int sol = resolver(n1,n2,t1,t2);

    // escribir sol

    cout << "Twin Towers #" << num_caso << endl;
    cout << "Number of Tiles : " << sol << endl;
    num_caso++;
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    /*
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif */


    while (resuelveCaso())
        ;

    /*
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif*/

    return 0;
}
