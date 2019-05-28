#include <iostream>
#include <math.h>
#include <omp.h>
#include <time.h>
#define n 4000

using namespace std;

double omp_get_wtime() throw();
double A[n][n], B[n], C[n];

double parallel() {
    double t1, t2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = j * tan(i);
        }
        B[i] = i * sqrt(i * cos(i));
    }

    int i, j;
    t1 = omp_get_wtime();

#pragma omp parallel private(i, j) num_threads(4)
    {
#pragma omp for
        for (int i = 0; i < n; i++) {
            C[i] = 0;
            for (int j = 0; j < n; j++) {
                C[i] = C[i] + A[i][j] * B[j];
            }
        }
    }

    t2 = omp_get_wtime();
    //    for (int i = 0; i < n; i++) {
    //        cout << i + 1 << ". " << C[i] << endl;
    //    }
    cout << "Execution time of parallel: " << t2 - t1;
}

double consistent() {
    double t1, t2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = j * tan(i);
        }
        B[i] = i * sqrt(i * cos(i));
    }
    t1 = omp_get_wtime();
    for (int i = 0; i < n; i++) {
        C[i] = 0;
        for (int j = 0; j < n; j++) {
            C[i] += A[i][j] * B[j];
        }
    }
    t2 = omp_get_wtime();
    //    for (int i = 0; i < n; i++) {
    //        cout << i + 1 << ". " << C[i] << endl;
    //    }
    cout << "Execution time of consistent: " << t2 - t1;
}

int main() {
    parallel();
    cout << "\n";
    consistent();
}