#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortbiggest(vector<int> &a)
{
    int size = a.size();
    
    // 1 4 9 2 3 6 5 4
    // 4 9 2 3 6 5 4 1
    // 9 4 3 6 5 4 2 1
    // 9 4 6 5 4 3 2 1
    // 9 6 5 4 4 3 2 1
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}




long long max_dot_product(vector<int> a, vector<int> b)
{
    // write your code here
    long long result = 0;
    int size = a.size();

    sortbiggest(a);
    sortbiggest(b);

    for (size_t i = 0; i < size; i++)
    {
        result += ((long long)a[i]) * b[i];
    }
    return result;
}

int main()
{
    size_t n;
    std::cin >> n;
    vector<int> a(n), b(n);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> b[i];
    }
    std::cout << max_dot_product(a, b) << std::endl;
}
