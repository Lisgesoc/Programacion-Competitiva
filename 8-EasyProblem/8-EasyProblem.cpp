#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

bool resuelveCaso() {
    map<int, vector<int>> ocurrencias;
    int n, m, k, v, e;
    cin >> n >> m;
    if (!cin) return false;

    for (int i = 0; i < n; i++) {
        cin >> e;
        ocurrencias[e].push_back(i + 1); 
    }

    for (int j = 0; j < m; j++) {
        cin >> k >> v;
        if (ocurrencias.find(v) == ocurrencias.end()) {
            cout << 0 << endl;
        }
        else {
            vector<int>& p = ocurrencias[v];
            if (k <= p.size()) cout << p[k - 1] << endl;
            else cout << 0 << endl;
        }
    }

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
