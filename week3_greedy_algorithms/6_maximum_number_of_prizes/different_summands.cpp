#include <iostream>
#include <vector>

using namespace std;

vector<int> optimal_summands(int n)
{
	vector<int> summands;
	//write your code here
	if (n <= 2)
	{
		summands.push_back(n);
		return summands;
	}
	summands.push_back(1);
	int incr = 2;
	n--;
	while (n > 0)
	{
		if (n - incr > incr || n - incr == 0)
		{
			summands.push_back(incr);
			n -= incr;
		}
		incr++;
	}

	return summands;
}

int main()
{
	int n;
	std::cin >> n;
	vector<int> summands = optimal_summands(n);
	std::cout << summands.size() << '\n';
	for (size_t i = 0; i < summands.size(); ++i)
	{
		std::cout << summands[i] << ' ';
	}
}
