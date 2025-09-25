

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


oferta calculaOf(oferta of, int k) {
    oferta sol;
    if (k % of.cant == 0) {
        sol.cant = k;
        sol.precio = of.precio * (k / of.cant);
        return sol;
    }
    else {
        sol.cant = k;
        sol.precio = of.precio * ((k / of.cant)+1);
        return sol;
    }

}


// función que resuelve el problema
oferta resolver(vector<oferta>ofertas, int k) {
    oferta of;
    of.cant = 0; of.precio = 0;
    vector<oferta>matrix(ofertas.size(),of);

    matrix[0].precio = ofertas[0].precio * k;
    matrix[0].cant = k;

    for (int i = 1; i < ofertas.size(); i++) {
        of = calculaOf(ofertas[i], k);
        if (of.precio < matrix[i - 1].precio) {
            matrix[i] = of;
        }
        else if (of.precio > matrix[i - 1].precio) {
            matrix[i] = matrix[i - 1];
        }
        else {
            if (matrix[i - 1].cant > of.cant) {
                matrix[i] = matrix[i - 1];
            }
            else {
                matrix[i] = of;
            }
        }
    }

    return matrix[ofertas.size() - 1];
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
        cout << "Buy " << sol.cant << " for $";
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