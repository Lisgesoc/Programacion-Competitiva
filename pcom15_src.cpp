//TODO Hay q hacer equis
//! y ai que es lo que palas?
// este es normal 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int cont_caso = 0;

typedef struct oferta{
    int cant;
    double precio;

};

double densidad(oferta of) {
    double d;
    d = of.precio / of.cant;
    return d;
}


oferta sumaOf(oferta of1, oferta of2) {
    oferta ofSol;
    ofSol.precio = of1.precio + of2.precio;
    ofSol.cant = of1.cant + of2.cant;
    return ofSol;
}

// función que resuelve el problema
oferta resolver(vector<oferta>ofertas, int k) {
    oferta of;
    of.cant = 0; of.precio = 0;
    vector<oferta>matrix(k+1,of);
    for (int i = 1; i <= k; i++) {
        matrix[i].precio = i * ofertas[0].precio;
        matrix[i].cant = i;
    }

    for (int j = 1; j < ofertas.size(); j++) {
        for (int i = 1; i <= k; i++) {
            of = ofertas[j];
            if (i >= of.cant) {
                of = sumaOf(of, matrix[i - of.cant]);

            }
            
            if (of.precio < matrix[i].precio) {
                matrix[i] = of;
            }
            else if (of.precio == matrix[i].precio) {
                if (densidad(of) == min(densidad(of), densidad(matrix[i]))) {
                    matrix[i] = of;
                }
            }
            
        }
    }

    return matrix[k];
}




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    cont_caso++;

    if (!std::cin)
        return false;

    oferta of;
    of.cant = 0; of.precio = 0.0;


    double precio_u;
    int m;
    cin >> precio_u >> m;

    vector<oferta> ofertas(m+1,of);

    of.cant = 1;
    of.precio = precio_u;
    ofertas[0] = of;

    for (int i = 1; i <= m; i++) {
        cin >> of.cant >> of.precio;
        ofertas[i] = of;
    }
    vector<int> num(100,0);
    int cont = 0, numero;
    string linea;
    cin.ignore();
    getline(std::cin,linea);
    stringstream ss(linea);

    while (ss>>numero) {

        num[cont]=numero;
        cont++;
    }

    cout << "Case " << cont_caso << ":" << endl;


    for(int i=0;i<cont;i++){
        oferta sol = resolver(ofertas, num[i]);
        // escribir sol
        cout << "Buy " << num[i] << " for $";
        cout << std::fixed << std::setprecision(2) << sol.precio << endl;
    }

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