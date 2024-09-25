#include <iostream>
#include <vector>
#include <chrono>

// Función para la multiplicación por bloques (seis bucles)
void multiply_matrices_block(const std::vector<std::vector<double>>& A, 
                             const std::vector<std::vector<double>>& B, 
                             std::vector<std::vector<double>>& C, int size, int block_size) {
    for (int i_block = 0; i_block < size; i_block += block_size) {
        for (int j_block = 0; j_block < size; j_block += block_size) {
            for (int k_block = 0; k_block < size; k_block += block_size) {
                for (int i = i_block; i < std::min(i_block + block_size, size); i++) {
                    for (int j = j_block; j < std::min(j_block + block_size, size); j++) {
                        for (int k = k_block; k < std::min(k_block + block_size, size); k++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    // Probamos con diferentes tamaños de matrices
    //std::vector<int> sizes = {500, 1000, 1500, 2000};  // Tamaños de las matrices
    std::vector<int> sizes = {500};  // Tamaños de las matrices
    
    for (int size : sizes) {
        std::cout << "Tamaño de la matriz: " << size << " x " << size << std::endl;

        // Inicializar matrices
        std::vector<std::vector<double>> A(size, std::vector<double>(size, 1.0));
        std::vector<std::vector<double>> B(size, std::vector<double>(size, 1.0));
        std::vector<std::vector<double>> C(size, std::vector<double>(size, 0.0));


        // Multiplicación por bloques
        start = std::chrono::high_resolution_clock::now();
        multiply_matrices_block(A, B, C, size, block_size);
        end = std::chrono::high_resolution_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Tiempo para multiplicación por bloques: " << elapsed.count() << " ms" << std::endl;
        
        std::cout << "-----------------------------" << std::endl;
    }

    return 0;
}
