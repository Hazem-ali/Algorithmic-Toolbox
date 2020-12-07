#include <iostream>
#include <vector>

using namespace std;


int fibonacci_sum_naive(long long n);
int fibonacci_sum_fast(long long n);
long long pisanolength(long long m);


int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
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

int fibonacci_sum_naive(long long n)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n) 
{

    if (n <= 1)
        return n;
    long long ps = pisanolength(10);
    n %= ps;
    vector<long long> arr(n + 1);
    arr[0] = 0;
    arr[1] = 1;
    long long i;
    int sum = 0;
    for (i = 2; i <= n; i++)
    {
        if (i == 2)
        {
            sum = 1;
        }
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10;
        sum += arr[i];
        sum %= 10;
    }
    return sum;
}
