// Lab 1 - Recursive Fibonacci
// Enter n; the program prints fib(n) and the execution time.
// Stop the program (Ctrl+C) if it runs longer than 30 seconds.
#include <iostream>
#include <chrono>
using namespace std;

long long fib(int n);   // prototype

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    if (n < 0) { cout << "n must be 0 or more" << endl; return 1; }

    auto start = chrono::steady_clock::now();
    long long result = fib(n);
    auto end = chrono::steady_clock::now();

    double seconds = chrono::duration<double>(end - start).count();
    cout << "fib(" << n << ") = " << result << endl;
    cout << "Time = " << seconds << " seconds" << endl;
    return 0;
}

long long fib(int n) {
    if (n == 0) return 0;                 // base case
    if (n == 1) return 1;                 // base case
    return fib(n - 1) + fib(n - 2);       // two recursive calls
}
