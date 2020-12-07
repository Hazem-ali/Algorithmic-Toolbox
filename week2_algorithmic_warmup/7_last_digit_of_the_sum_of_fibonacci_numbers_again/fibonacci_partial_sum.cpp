#include <iostream>
#include <vector>

using namespace std;

long long get_fibonacci_partial_sum_naive(long long from, long long to);
int get_fibonacci_partial_sum_fast(long long from, long long to);
long long pisanolength(long long m);
int fibonacci_sum_fast(long long n);

int main()
{
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}

long long get_fibonacci_partial_sum_naive(long long from, long long to)
{
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i)
    {
        if (i >= from)
        {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long pisanolength(long long m)
{
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++)
    {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1)
            return i + 1;
    }
    return 0;
}

int get_fibonacci_partial_sum_fast(long long from, long long to)
{

    if (to <= 1)
        return to;
    long long ps = pisanolength(10);
    int from_tiny = from % ps;
    int to_tiny = from_tiny + (to - from_tiny) % ps;
    vector<long long> arr(to_tiny + 1);
    arr[0] = 0;
    arr[1] = 1;
    long long i;
    int sum = 0;

    for (i = 2; i <= to_tiny; i++)
    {

        arr[i] = (arr[i - 1] + arr[i - 2]) % 10;
    }
    for (i = from_tiny; i <= to_tiny; i++)
    {
        sum += arr[i];
        sum %= 10;
    }

    return sum;
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
