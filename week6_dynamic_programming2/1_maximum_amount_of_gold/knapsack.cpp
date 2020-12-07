#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <set>
using namespace std;

int optimal_weight(int W, vector<int> &wt)
{
	// write your code here
	int m = W;
	int n = wt.size();
	vector<int> a(m + 1, 0);
	vector<vector<int>> k(n + 1, a);

	// sort(w.begin(), w.end(), greater<>());
	set<int> maxes;

	int current_weight = 0;
	for (size_t i = 0; i <= n; i++)
	{
		// current_weight = 0;
		for (size_t w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
			{
				k[i][w] = 0;
			}
			else if (wt[i - 1] <= w)
			{
				k[i][w] = max(wt[i - 1] + k[i - 1][w - wt[i - 1]], k[i - 1][w]);
			}
			else
			{
				k[i][w] = k[i - 1][w];
			}
		}
	}

	return k[n][W];
}

int main()
{
	int n, W;
	std::cin >> W >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> w[i];
	}
	std::cout << optimal_weight(W, w) << '\n';
}
