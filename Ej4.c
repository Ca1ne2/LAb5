#include <stdio.h>
#include <omp.h>

int main() {
    int n = 10;
    int variable1 = 0;  // Variable compartida
    int variable2 = 0;  // Variable privada

    // Uso de la cláusula 'shared' para variable1 y 'private' para variable2
    #pragma omp parallel for shared(variable1) private(variable2)
    for (int i = 0; i < n; i++) {
        // variable2 es privada para cada hilo, inicializada en 0 por cada hilo
        variable2 = i;  
        // variable1 es compartida, todos los hilos acceden a la misma variable
        variable1 += i;
        printf("Hilo %d, i = %d, variable1 = %d, variable2 = %d\n", omp_get_thread_num(), i, variable1, variable2);
    }

    printf("\nFinal:\n");
    printf("variable1 = %d\n", variable1);
    printf("variable2 (último valor, no relevante) = %d\n", variable2);

    return 0;
}
