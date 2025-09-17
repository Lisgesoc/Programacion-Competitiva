

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
int resolver(int prim, int ult, vector<bool> jugadores, int &cont ) {

    if (ult - prim == 1) {
        if (jugadores[prim] && jugadores[ult]) {
            return prim;
        }
        cont++;
        if (jugadores[prim]) {
            return prim;
        }
        else if (jugadores[ult]) {
            return ult;
        }
        return 0;
    }
    else {
        int mitad = prim + ult;
        int p1 = resolver(prim, mitad, jugadores, cont);
        int p2 = resolver(mitad, prim, jugadores, cont);

        if (jugadores[p1] && jugadores[p2]) {
            return p1;
        }
        cont++;
        if (jugadores[p1]) {
            return p1;
        }
        else if (jugadores[p2]) {
            return p2;
        }
        return 0;

    }





}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int m, n, aux;

    cin >> n >> m;

    vector<bool> jugadores(pow(2,n) + 1, true);



    for (int i = 0; i < m; i++) {
        cin >> aux;
        jugadores[aux] = false;
    }
    jugadores[0] = false;

    int sol = 0 ;
    resolver(1, pow(2, n), jugadores, sol);
    // escribir sol

    cout << sol<<endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    /*
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif */


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    /*
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif*/

    return 0;
}
