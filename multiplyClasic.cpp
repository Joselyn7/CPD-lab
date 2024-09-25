#include <iostream>
#include <vector>
#include <chrono>

// Función para la multiplicación clásica (tres bucles)
void multiply_matrices_classic(const std::vector<std::vector<double>>& A, 
                               const std::vector<std::vector<double>>& B, 
                               std::vector<std::vector<double>>& C, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    // Probamos con diferentes tamaños de matrices
    //std::vector<int> sizes = {500, 1000, 1500, 2000};  // Tamaños de las matrices
    std::vector<int> sizes = {500};  // Tamaños de las matrices
    int block_size = 100;  // Tamaño de los bloques
    
    for (int size : sizes) {
        std::cout << "Tamaño de la matriz: " << size << " x " << size << std::endl;

        // Inicializar matrices
        std::vector<std::vector<double>> A(size, std::vector<double>(size, 1.0));
        std::vector<std::vector<double>> B(size, std::vector<double>(size, 1.0));
        std::vector<std::vector<double>> C(size, std::vector<double>(size, 0.0));

        // Multiplicación clásica
        auto start = std::chrono::high_resolution_clock::now();
        multiply_matrices_classic(A, B, C, size);
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Tiempo para multiplicación clásica: " << elapsed.count() << " ms" << std::endl;

    }

    return 0;
}

