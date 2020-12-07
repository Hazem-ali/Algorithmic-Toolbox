#include <iostream>
#include <cassert>
#include <math.h>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x, int left, int right)
{
	if (abs(right - left) == 1)
	{
		if (a[left] == x)
		{
			return left;
		}
		if (a[right] == x)
		{
			return right;
		}
		return -1;
	}
	int mid = (left + right) / 2;
	if (a[mid] == x)
	{
		return mid;
	}
	else if (a[mid] < x)
	{
		return binary_search(a, x, mid + 1, right);
	}
	else
	{
		return binary_search(a, x, left, mid - 1);
	}

	// 5 1 5 8 12 13
	// 5 8 1 23 1 11
	/////
	// 2 0 -1 0 -1
}
int binary_search_wrap(const vector<int> &a, int x)
{
	int left = 0, right = (int)a.size() - 1;
	return binary_search(a, x, left, right);
}

int linear_search(const vector<int> &a, int x)
{
	for (size_t i = 0; i < a.size(); ++i)
	{
		if (a[i] == x)
			return i;
	}
	return -1;
}

int main()
{
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++)
	{
		std::cin >> a[i];
	}
	int m;
	std::cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; ++i)
	{
		std::cin >> b[i];
	}
	for (int i = 0; i < m; ++i)
	{
		//replace with the call to binary_search when implemented
		std::cout << binary_search_wrap(a, b[i]) << ' ';
	}
}
