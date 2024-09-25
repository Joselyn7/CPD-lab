#include <iostream>
#include <vector>
#include <chrono>  // Usaremos chrono para medir el tiempo

const int MAX = 12000; 

int main() {
    // Inicialización de matrices y vectores
    std::vector<std::vector<double>> A(MAX, std::vector<double>(MAX));
    std::vector<double> x(MAX);
    std::vector<double> y(MAX);

    // Llenado inicial de los valores de A, x y y
    for (int i = 0; i < MAX; i++) {
        x[i] = 1.0;
        y[i] = 0.0;
        for (int j = 0; j < MAX; j++) {
            A[i][j] = 1.0;
        }
    }

    // Medir tiempo para el primer conjunto de bucles
    auto start = std::chrono::high_resolution_clock::now();  // Inicia cronómetro

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j];
        }
    }

    auto end = std::chrono::high_resolution_clock::now();  // Termina cronómetro
    std::chrono::duration<double> elapsed = end - start;   // Calcula duración en segundos
    std::cout << "Tiempo para el primer par de bucles: " << elapsed.count() << " segundos" << std::endl;

    // Reiniciar el vector y para el segundo conjunto de bucles
    for (int i = 0; i < MAX; i++) {
        y[i] = 0.0;
    }

    // Medir tiempo para el segundo conjunto de bucles
    start = std::chrono::high_resolution_clock::now();  // Inicia cronómetro

    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];
        }
    }

    end = std::chrono::high_resolution_clock::now();  // Termina cronómetro
    elapsed = end - start;  // Calcula duración en segundos
    std::cout << "Tiempo para el segundo par de bucles: " << elapsed.count() << " segundos" << std::endl;

    return 0;
}
