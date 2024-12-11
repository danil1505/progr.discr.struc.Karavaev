#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include <random>

using namespace std;
using namespace chrono;

//перебор от 1 до мин(M, N)
int gcdBruteForceAsc(int M, int N) {
    int nod = 1;
    for (int i = 1; i <= min(M, N); i++) {
        if (M % i == 0 && N % i == 0) {
            nod = i;
        }
    }
    return nod;
}

//полный перебор от мин(M, N) до 1
int gcdBruteForceDesc(int M, int N) {
    for (int i = min(M, N); i >= 1; i--) {
        if (M % i == 0 && N % i == 0) {
            return i;
        }
    }
    return 1; 
}

//евклид
int gcdEuclid(int M, int N) {
    while (N != 0) {
        int temp = N;
        N = M % N;
        M = temp;
    }
    return M;
}



int main() {
    cout << fixed << setprecision(6);
    const int TRIALS = 1000; 
    random_device rd;
    mt19937 gen(rd());
    vector<int> test_sizes = {10000, 50000, 100000, 500000, 1000000};
    cout << "Размер данных\tот 1 до мин(M, N) (мс)\tот min(M, N) до 1 (мс)\tЕвклид (мс)\n";
    
    
    
    for (int n : test_sizes) {
        vector<double> times(3, 0.0);
        
        
        for (int i = 0; i < TRIALS; i++) {
            int M = uniform_int_distribution<>(n, n * 2)(gen);
            int N = uniform_int_distribution<>(n, n * 2)(gen);
            
            //Измерение времени для Brute Force Asc
            auto start = high_resolution_clock::now();
            gcdBruteForceAsc(M, N);
            auto end = high_resolution_clock::now();
            times[0] += duration<double, milli>(end - start).count();


            //для Brute Force Desc
            start = high_resolution_clock::now();
            gcdBruteForceDesc(M, N);
            end = high_resolution_clock::now();
            times[1] += duration<double, milli>(end - start).count();

            //для Euclid
            start = high_resolution_clock::now();
            gcdEuclid(M, N);
            end = high_resolution_clock::now();
            times[2] += duration<double, milli>(end - start).count();
        }
        cout << n << "\t\t";
        for (double time : times) {
            cout << time / TRIALS << "\t\t";
        }
        cout << endl;
    }

    return 0;
}
