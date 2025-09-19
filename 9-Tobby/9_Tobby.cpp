
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <map>

using namespace std;

map<string, int>prioridades;

struct comparator {
    bool operator() (const pair<int,string>&a, const pair<int,string>&b){
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return prioridades.at(a.second) > prioridades.at(b.second);
    }
};

// función que resuelve el problema
queue<pair<int, string>> resolver(int k, priority_queue<pair<int, string>, vector<pair<int, string>>, comparator>pastis, map<string, int> drugs) {
    queue<pair<int, string>> sol;
    pair<int, string>par;
    for (int i = 0; i < k; i++) {
        par = pastis.top();
        pastis.pop();
        int t = par.first + drugs.at(par.second);
        pastis.push(pair<int, string>(t, par.second));
        sol.push(par);
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int n, k;
    cin >> n >> k;

    pair<int, string>par;
    priority_queue<pair<int, string>,vector<pair<int,string>>,comparator>pastis;
    map<string, int> drugs;

    int t;
    string name;
    for (int i = 0; i < n; i++) {
        cin >> name >> t;
        prioridades.insert(pair<string, int>(name, i));
        par = pair<int, string>(t, name);
        pastis.push(par);
        drugs.insert(pair<string,int>(name, t));
    }
    queue<pair<int, string>> sol = resolver(k,pastis, drugs);
    // escribir sol

        for (int i = 0; i < k; i++) {
            par = sol.front();
            sol.pop();
            cout << par.first << " " << par.second << endl;
        }
    
    prioridades.clear();
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
