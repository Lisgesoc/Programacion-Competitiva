// Nombre del alumno David Diaz
// Usuario del Juez PC15


#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>

using namespace std;



// función que resuelve el problema
double resolver(const double x, const double y, const double c, double min, double max, const long double val) {

    double w = (max + min) / 2;

    if (max - min < 0.0001) {
        return w;
    }



    long double aux = (1.0 / (sqrt(pow(x, 2) - pow(w, 2)))) + (1.0 / (sqrt(pow(y, 2) - pow(w, 2))));

    if (aux==val) {
        return w;
    }
    else if (aux > val){
        return resolver(x, y, c, min, w, val);
    }
    else {
        return resolver(x, y, c, w, max, val);
    }


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    double x, y, c;
    cin >> x >> y >> c;

    if (!std::cin)
        return false;

    double min = 0.0, max = fmin(x, y);
    long double val = 1 / c;

    double sol = resolver(x, y, c, min, max, val);

    // escribir sol

    cout << std::fixed << std::setprecision(3) << sol;


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    /*
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
    */


    while (resuelveCaso())
        ;

    /*
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    */

    return 0;
}