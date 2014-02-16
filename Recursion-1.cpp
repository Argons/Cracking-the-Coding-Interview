# include <iostream>
using namespace std;

// Write a method to generate the nth Fibonacci number.

int fib(int n) {
    if (n < 0)
        return -1;
    if (n < 2)
        return n;
    return fib(n-1) + fib(n-2);
}

int fib_2(int n) {
    if (n < 0)
        return -1;
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        int tmp = b;
        b += a;
        a = tmp;
    }
    return a;
}

int main () 
{
    int n;
    cin >> n;
    cout << fib(n) << " " << fib_2(n) << endl;
    return 0;
}    
