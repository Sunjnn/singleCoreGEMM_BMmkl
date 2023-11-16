#include <iostream>
#include <chrono>

#include <cstdlib>

#include <mkl.h>
#include <string.h>

using INTEGER = MKL_INT;
using std::cout, std::endl;
using std::chrono::system_clock, std::chrono::duration_cast;
using std::chrono::microseconds;

template<class T>
void initMatrix(T* matrix, size_t m, size_t n) {
    for (size_t i = 0; i < m * n; ++i) matrix[i] = rand() % 10;
}

void testPerformanceMKL(INTEGER m, INTEGER k, INTEGER n) {
    double *A = new double[m * k];
    double *B = new double[k * n];
    double *C = new double[m * n];

    initMatrix(A, m, k);
    initMatrix(B, k, n);

    cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, m, n, k,
                1.0, A, m, B, k, 0.0, C, m);

    delete[] A;
    delete[] B;
    delete[] C;
}

template<class CHAR, class INT>
INT convertChartoInt(CHAR* str, INT size) {
    INT res = 0;
    size_t len = strlen(str);

    for (int i = 0; i < len; ++i) {
        res = res * 10 + (str[i] - '0');
    }
    return res;
}

int main(int argc, char** argv)
{
    INTEGER size = 8192;
    if (argc > 1) {
        size = convertChartoInt(argv[1], size);
        cout << "Set size of matrix to " << size << endl;
    }

    cout << "---------------------------------------------------------" <<endl;
    cout << "Test performance of MKL" << endl;
    auto start = system_clock::now();
    testPerformanceMKL(size, size, size);
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "openblas with size " << size << " time (ms): ";
    cout << duration.count() << endl;

    double num_flop = 2.0 * size * size * size;
    double flops = num_flop / duration.count() * 1000;
    cout << "openblas with size " << size << " flops (flops): ";
    cout << flops << endl << endl << endl;

    return 0;
}
