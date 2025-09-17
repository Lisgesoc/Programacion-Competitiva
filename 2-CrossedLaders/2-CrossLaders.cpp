#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>

using namespace std;



// función que resuelve el problema
double resolver(const double x, const double y, double w) {
    double a = sqrt(y * y - w * w);
    double b = sqrt(x * x - w * w);
    return (b * a) / (b + a); //punto c

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    double x, y, c;
    while (cin >> x >> y >> c) {
        double l = 0.0, h = fmin(x, y), w, h1; //w ancho prueba, h1 altura con ese ancho donde interseccionan

        for (int i = 0; i < 100; i++) { 
            w = (l + h) / 2.0;
            h1 = resolver(x, y, w);

            if (h1 > c) l = w;
            else h = w;
        }

        cout << std::fixed << std::setprecision(3) << w <<endl;
    }
    return 0;

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
