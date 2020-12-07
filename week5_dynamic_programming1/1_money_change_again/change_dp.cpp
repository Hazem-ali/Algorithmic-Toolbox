#include <iostream>
#include <vector>

using namespace std;

int get_change(int m)
{
	vector<int> mincoins(m + 1);
	vector<int> coins = {1, 3, 4};
	int numcoins;

	mincoins[0] = 0;

	// looping through money
	for (size_t i = 1; i < m + 1; i++)
	{
		mincoins[i] = 9000000;
		//looping through each coin
		for (size_t j = 0; j < coins.size(); j++)
		{
			if (i >= coins[j])
			{
				numcoins = mincoins[i - coins[j]] + 1;
				if (numcoins < mincoins[i])
				{
					mincoins[i] = numcoins;
				}
			}
		}
	}

	return mincoins[m];
}

int main()
{
	int m;
	cin >> m;
	cout << get_change(m) << '\n';
}
