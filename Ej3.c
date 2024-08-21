#include <stdio.h>
#include <omp.h>

// Función para calcular el factorial de un número
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Función para generar la serie de Fibonacci hasta un número dado
void fibonacci(int n) {
    unsigned long long fib[n];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    printf("Serie de Fibonacci: ");
    for (int i = 0; i < n; i++) {
        printf("%llu ", fib[i]);
    }
    printf("\n");
}

// Función para encontrar el máximo en un arreglo
int find_max(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n_factorial = 10;  // Número para calcular el factorial
    int n_fibonacci = 10;  // Longitud de la serie de Fibonacci
    int arr[] = {1, 5, 3, 9, 2, 8, 4};  // Arreglo para encontrar el máximo
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    // Iniciar paralelismo con secciones
    #pragma omp parallel sections
    {
        // Sección para calcular el factorial
        #pragma omp section
        {
            unsigned long long fact = factorial(n_factorial);
            printf("Factorial de %d es %llu\n", n_factorial, fact);
        }

        // Sección para generar la serie de Fibonacci
        #pragma omp section
        {
            fibonacci(n_fibonacci);
        }

        // Sección para encontrar el máximo en un arreglo
        #pragma omp section
        {
            int max = find_max(arr, arr_size);
            printf("El máximo en el arreglo es %d\n", max);
        }
    }

    return 0;
}
