

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;


// funcioon que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioon, y escribiendo la respuesta
bool resuelveCaso() {
    string str;
    getline(cin, str);
    if (!std::cin) return false;

    stringstream ss(str);
    int n;
    stack<pair<int, int>> pila; // tam, suma de intervalos
    bool ok = true;

    while (ss >> n && ok) {
        if (n < 0) {
            // abrir una nueva muñeca
            pila.push({ -n, 0 });
        }
        else {
            if (pila.empty() || pila.top().first != n) {
                ok = false; break; //-5 -2 5 2
            }
            auto [tam, suma] = pila.top(); pila.pop();
            if (suma >= tam) { ok = false; break; }
            if (!pila.empty()) pila.top().second += tam;
        }
    }

    if (ok && pila.empty())
        cout << ":-) Matrioshka!" << endl;
    else
        cout << ":-( Try again." << endl;

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
