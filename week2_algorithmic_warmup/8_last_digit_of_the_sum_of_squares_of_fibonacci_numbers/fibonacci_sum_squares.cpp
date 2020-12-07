#include <iostream>
#include <vector>

using namespace std;

int fibonacci_sum_squares_naive(long long n);
int fibonacci_sum_squares_fast(long long n);
int fibonacci_sum_squares_very_fast(long long n);
int get_fibonacci_last_digit_fast(long long n);

int main()
{
    long long n = 0;
    cin >> n;
    cout << fibonacci_sum_squares_very_fast(n) << endl;

    // cout << fibonacci_sum_squares_very_fast(n) << " very fast" << endl;
    // cout << fibonacci_sum_squares_naive(n) <<" naive"<< endl;
    // cout << fibonacci_sum_squares_fast(n) << " fast " << endl;
    // 012650434056210098450676054890 sum squares pattern
}


int fibonacci_sum_squares_naive(long long n)
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
        sum += current * current;
    }

    return sum % 10;
}

int fibonacci_sum_squares_fast(long long n)
{
    // Determines fibonacci sum squares for n <= 20,000
    if (n <= 1)
        return n;
    vector<long long> arr(n + 1);
    arr[0] = 0;
    arr[1] = 1;
    long long i;
    int sum = 1;
    for (i = 2; i <= n; i++)
    {
        int last_fib = get_fibonacci_last_digit_fast(i);
        arr[i] =  (last_fib * last_fib) % 10;
        sum += arr[i];
        sum %= 10;
    }
    return sum;
}

int fibonacci_sum_squares_very_fast(long long n)
{
    // Determines fibonacci sum squares for any big number
    /// Idea: sum square values take pattern every 30 number.
    /// so we get this pattern from fib_fast and repeat it for any big number 
    
    int pattern[30];
    for (int i = 0; i < 30; i++)
    {
        pattern[i] = fibonacci_sum_squares_fast(i);
    }
    n %= 30;

    return pattern[n];
}

int get_fibonacci_last_digit_fast(long long n)
{
    if (n <= 1)
        return n;
    vector<long long> arr(n + 1);
    arr[0] = 0;
    arr[1] = 1;
    long long i;
    for (i = 2; i <= n; i++)
    {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10;
    }
    return arr[n];
}