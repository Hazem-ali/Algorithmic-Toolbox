#include <iostream>
#include <vector>

using namespace std;

long long pisanolength(long long m);
long long get_fibonacci_huge_fast(long long n, long long m);
long long get_fibonacci_huge_naive(long long n, long long m);

int main() {
    long long n, m;
    cin >> n >> m;
    cout << get_fibonacci_huge_fast(n, m) << '\n';
}


long long get_fibonacci_huge_naive(long long n, long long m) 
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long pisanolength(long long m)
{
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
    return 0;
}

long long get_fibonacci_huge_fast(long long n, long long m) 
{

    if (n <= 1)
        return n;
    long long ps = pisanolength(m);
    n %= ps;
    vector<long long> arr(n + 1);
    arr[0] = 0;
    arr[1] = 1;
    long long i;
    for (i = 2; i <= n; i++)
    {
        arr[i] = (arr[i - 1] + arr[i - 2]) % m;
    }
    return arr[n];

}
