#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    // write your code here
    int position = 0;
    int refills = 0;
    stops.push_back(dist);
    int size = stops.size();
    if (!size)
    {
        return -1;
    }
    if (tank > dist)
    {
        return 0;
    }

    for (int i = 0; i < size; i++)
    {

        if (position + tank < stops[i])
        {
            return -1;
        }

        if (position + tank >= stops[i] && position + tank < stops[i + 1])
        {
            position = stops[i];
            refills++;
        }
    }

    return refills;
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
