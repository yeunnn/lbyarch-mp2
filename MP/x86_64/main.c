// Argamosa, Daniel Cedric S. (S12)
// Donato, Adriel Joseph Y. (S12)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// Declaration of x86-64 assembly function
extern void saxpy_asm(int n, float* X, float* Y, float* Z, float A);

// C implementation of SAXPY function
void saxpy_c(int n, float* X, float* Y, float* Z, float A) {
    for (int i = 0; i < n; ++i) {
        Z[i] = A * X[i] + Y[i];
    }
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Function for manual input
void manual_input() {
    int n;
    float A;

    printf("Enter the length of the vectors (N): ");
    if (scanf_s("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        clear_input_buffer();
        return;
    }

    printf("Enter the float scalar value (A): ");
    if (scanf_s("%lf", &A) != 1) {
        printf("Invalid input. Please enter a float.\n");
        clear_input_buffer();
        return;
    }

    float* X = (float*)malloc(n * sizeof(float));
    float* Y = (float*)malloc(n * sizeof(float));
    float* Z = (float*)malloc(n * sizeof(float));
    int display_count = (n > 10) ? 10 : n;

    if (X == NULL || Y == NULL || Z == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("\nFormat: if n is = 5 then input the float vector values seperated by space (1.0 2.0 3.0 4.0 5.0)\n");
    printf("Enter the elements of vector X: ");
    for (int i = 0; i < n; ++i) {
        scanf_s("%f", &X[i]);
    }

    printf("Enter the elements of vector Y: ");
    for (int i = 0; i < n; ++i) {
        scanf_s("%f", &Y[i]);
    }

    clock_t start, end;
    double time_elapsed_c, time_elapsed_asm;

    start = clock();
    saxpy_c(n, X, Y, Z, A);
    end = clock();

    time_elapsed_c = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nResults of C version:\n");

    for (int i = 0; i < display_count; ++i) {
        printf("%.2f ", Z[i]);
    }
    printf("\n");

    printf("Processing Time (C version): %.2f seconds\n", time_elapsed_c);

    start = clock();
    saxpy_asm(n, X, Y, Z, A);
    end = clock();

    time_elapsed_asm = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nResults of Assembly version:\n");

    for (int i = 0; i < display_count; ++i) {
        printf("%.2f ", Z[i]);
    }
    printf("\n");

    printf("Processing Time (x86-64 Assembly version): %.2f seconds\n", time_elapsed_asm);

    free(X);
    free(Y);
    free(Z);
}

// Function for maximum tests
void maximum_tests() {
    int exponent, runs = 30;
    float A;

    printf("Enter the scalar value (A): ");
    scanf_s("%f", &A);

    printf("\nSelect an option for maximum test:\n");
    printf("[1] 2^20\n");
    printf("[2] 2^24\n");
    printf("[3] 2^28\n\n");
    printf("Enter your choice: ");
    scanf_s("%d", &exponent);

    int n;
    if (exponent == 1)
        n = 1 << 20;
    else if (exponent == 2)
        n = 1 << 24;
    else if (exponent == 3)
        n = 1 << 28;
    else {
        printf("Invalid choice. Exiting maximum test.\n");
        return;
    }

    float* X = (float*)malloc(n * sizeof(float));
    float* Y = (float*)malloc(n * sizeof(float));
    float* Z = (float*)malloc(n * sizeof(float));
    int display_count = (n > 10) ? 10 : n;

    if (X == NULL || Y == NULL || Z == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    for (int j = 0; j < n; ++j) {
        X[j] = (float)rand() / RAND_MAX;
        Y[j] = (float)rand() / RAND_MAX;
    }

    LARGE_INTEGER frequency, start, end;
    double time_elapsed_c = 0.0, time_elapsed_asm = 0.0;

    QueryPerformanceFrequency(&frequency);

    // Run C version 30 times
    printf("\nC Version Execution Times (in ms):\n");
    for (int i = 0; i < runs; i++) {
        memset(Z, 0, n * sizeof(float)); // Clear Z before each run
        QueryPerformanceCounter(&start);
        saxpy_c(n, X, Y, Z, A);
        QueryPerformanceCounter(&end);
        double time = (double)(end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;
        time_elapsed_c += (double)(end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;
        printf("Run %d: %.6f ms\n", i + 1, time);
    }

    printf("\nResults of C version (last run):\n");
    for (int i = 0; i < display_count; ++i) {
        printf("%.2f ", Z[i]);
    }
    printf("\n");

    // Clear Z for the assembly version
    memset(Z, 0, n * sizeof(float));

    // Run assembly version 30 times
    printf("\nAssembly Version Execution Times (in ms):\n");
    for (int i = 0; i < runs; i++) {
        memset(Z, 0, n * sizeof(float)); // Clear Z before each run
        QueryPerformanceCounter(&start);
        saxpy_asm(n, X, Y, Z, A);
        QueryPerformanceCounter(&end);
        double time = (double)(end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;
        time_elapsed_asm += (double)(end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;
        printf("Run %d: %.6f ms\n", i + 1, time);
    }

    printf("\nResults of Assembly version (last run):\n");
    for (int i = 0; i < display_count; ++i) {
        printf("%.2f ", Z[i]);
    }
    printf("\n");

    // Calculate and print average times in ms
    printf("\nAverage Processing Time (C version): %.6f ms\n", time_elapsed_c / runs);
    printf("Average Processing Time (x86-64 Assembly version): %.6f ms\n", time_elapsed_asm / runs);

    free(X);
    free(Y);
    free(Z);
}

int main() {
    int choice;

    do {
        printf("\nSelect an option:\n");
        printf("[0] End Program\n");
        printf("[1] Manual Input\n");
        printf("[2] Maximum Tests (2^20, 2^24, 2^28)\n\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 0:
            printf("Ending program.\n");
            break;
        case 1:
            manual_input();
            break;
        case 2:
            maximum_tests();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
