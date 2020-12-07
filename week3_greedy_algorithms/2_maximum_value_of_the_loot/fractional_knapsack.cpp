#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortsimult(vector<int> &weights, vector<int> &values)
{
    int size = weights.size();
    vector<double> value_perweight(size);
    for (int i = 0; i < size; i++)
    {
        value_perweight[i] = (double)values[i] / weights[i];
    }

    // 1 4 9 2 3 6 5 4
    // 4 9 2 3 6 5 4 1
    // 9 4 3 6 5 4 2 1
    // 9 4 6 5 4 3 2 1
    // 9 6 5 4 4 3 2 1

    // sort by largest value_perweight
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (value_perweight[j] < value_perweight[j + 1])
            {
                swap(value_perweight[j], value_perweight[j + 1]);
                swap(&weights[j], &weights[j + 1]);
                swap(&values[j], &values[j + 1]);
            }
        }
    }
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
    double value = 0.0;
    int size = weights.size();
    vector<double> value_perweight(size);
    sortsimult(weights, values);

    for (int i = 0; i < size; i++)
    {
        value_perweight[i] = (double)values[i] / weights[i];
    }

    for (int i = 0; i < size; i++)
    {

        if (!capacity)
        {
            break;
        }

        // inserting item into the bag
        int min;
        if (capacity <= weights[i])
        {
            min = capacity;
        }
        else
        {
            min = weights[i];
        }
        value += double(min) * value_perweight[i];
        capacity -= min;
    }

    return value;
}

int main()
{
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
