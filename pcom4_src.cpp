// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
bool  resolver(int n, int m,const vector<pair<int, int>> piezas, pair<int, int> iz, pair<int, int> der, vector<pair<int, int>> solucion, int k) {

    bool sol = false;


        if (k == n) {
            if (solucion[k-1].second == der.first)
                return true;
            else
                return false;
        }
        if (k == 0) {
            int num = iz.second;
            int i = 0;
            while (!sol && i < m) {
                if (piezas[i].first == num || piezas[i].second == num) {
                    if(piezas[i].first == num){
                        solucion[k] = piezas[i];
                    }
                    else {
                        pair<int, int> par;
                        par.first = piezas[i].second;
                        par.second = piezas[i].first;
                        solucion[k] = par;
                    }
                    vector<pair<int, int>> piezas_r(14);piezas_r = piezas;
                    piezas_r.erase(piezas_r.begin() + i);
                    sol = resolver(n, m, piezas_r, iz, der, solucion, k + 1);
                }
                i++;
            }
        }
        else {
            int i = 0, num = solucion[k-1].second;
            while (!sol && i < m - k ) {
              

                if (piezas[i].first == num || piezas[i].second == num) {
                    if (piezas[i].first == num) {
                        solucion[k] = piezas[i];
                    }
                    else {
                        pair<int, int> par;
                        par.first = piezas[i].second;
                        par.second = piezas[i].first;
                        solucion[k] = par;
                    }
                    vector<pair<int, int>> piezas_r(14); piezas_r = piezas;
                    piezas_r.erase(piezas_r.begin() + i);
                    sol = resolver(n, m, piezas_r, iz, der, solucion, k + 1);
                }
                i++;
            }
            
        }
    return sol;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, m;

    pair<int,int> par, iz, der;
    vector<pair<int, int>> piezas(14), solucion(14);

    cin >> n;

    if (n == 0)
        return false;

    cin >> m >> iz.first>>iz.second;
    cin >> der.first >> der.second;


    
    for (int i = 0; i < m ; i++) {
        cin >> par.first >> par.second;
        piezas[i] = par;
    }


    bool sol = resolver(n, m, piezas, iz, der, solucion,0);

    // escribir sol


    if (sol == true)
        cout << "YES" << endl; 
    else 
        cout << "NO" << endl;
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
