//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>
//
//extern void asmhello(); // c call
//
//int main() {
//	asmhello(); // assembly file
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void saxpy_c(float A, float* X, float* Y, float* Z, int n) {
    for (int i = 0; i < n; ++i) {
        Z[i] = A * X[i] + Y[i];
    }
}

void manual_input() {
    int n;
    float A;

    printf("Enter the length of the vectors (N): ");
    scanf_s("%d", &n);

    printf("Enter the scalar value (A): ");
    scanf_s("%f", &A);

    float* X = (float*)malloc(n * sizeof(float));
    float* Y = (float*)malloc(n * sizeof(float));
    float* Z = (float*)malloc(n * sizeof(float));

    if (X == NULL || Y == NULL || Z == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter the elements of vector X: ");
    for (int i = 0; i < n; ++i) {
        scanf_s("%f", &X[i]);
    }

    printf("Enter the elements of vector Y: ");
    for (int i = 0; i < n; ++i) {
        scanf_s("%f", &Y[i]);
    }

    clock_t start, end;
    double time_elapsed;

    start = clock();
    saxpy_c(A, X, Y, Z, n);
    end = clock();

    time_elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nResults of C version:\n");
    int display_count = (n > 10) ? 10 : n;
    for (int i = 0; i < display_count; ++i) {
        printf("%.2f ", Z[i]);
    }
    printf("\n");

    printf("Time Elapsed: %.2f seconds\n", time_elapsed);

    free(X);
    free(Y);
    free(Z);
}

void maximum_tests() {
    int exponent;
    float A;

    printf("Enter the scalar value (A): ");
    scanf_s("%f", &A);

    printf("\nSelect an option for maximum test:\n");
    printf("[1] 2^20\n");
    printf("[2] 2^24\n");
    printf("[3] 2^30\n\n");
    printf("Enter your choice: ");
    scanf_s("%d", &exponent);

    int n;
    if (exponent == 1)
        n = 1 << 20;
    else if (exponent == 2)
        n = 1 << 24;
    else if (exponent == 3)
        n = 1 << 30;
    else {
        printf("Invalid choice. Exiting maximum test.\n");
        return;
    }

    float* X = (float*)malloc(n * sizeof(float));
    float* Y = (float*)malloc(n * sizeof(float));
    float* Z = (float*)malloc(n * sizeof(float));

    if (X == NULL || Y == NULL || Z == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    for (int j = 0; j < n; ++j) {
        X[j] = (float)rand() / RAND_MAX;
        Y[j] = (float)rand() / RAND_MAX;
    }

    clock_t start, end;
    double time_elapsed;

    start = clock();
    saxpy_c(A, X, Y, Z, n);
    end = clock();

    time_elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nResults for N = %d:\n", n);
    int display_count = (n > 10) ? 10 : n;
    for (int j = 0; j < display_count; ++j) {
        printf("%.2f ", Z[j]);
    }
    printf("\n");

    printf("Time Elapsed: %.2f seconds\n", time_elapsed);

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
        printf("[2] Maximum Tests (2^20, 2^24, 2^30)\n\n");
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
