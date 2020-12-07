#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <cstdlib>
#include <time.h>

using namespace std;

// A STL Set based approach for inversion count

// Returns inversion count in arr[0..n-1]
int getInvCount(vector<int> &arr)
{
	int n = arr.size();
	// Create an empty set and insert first element in it
	multiset<int> set1;
	set1.insert(arr[0]);

	int invcount = 0; // Initialize result

	multiset<int>::iterator itset1; // Iterator for the set

	// Traverse all elements starting from second
	for (int i = 1; i < n; i++)
	{
		// Insert arr[i] in set (Note that set maintains
		// sorted order)
		set1.insert(arr[i]);

		// Set the iterator to first greater element than arr[i]
		// in set (Note that set stores arr[0],.., arr[i-1]
		itset1 = set1.upper_bound(arr[i]);

		// Get distance of first greater element from end
		// and this distance is count of greater elements
		// on left side of arr[i]
		invcount += distance(itset1, set1.end());
	}

	return invcount;
}

int Merge(vector<int> &left, vector<int> &right, vector<int> &bars)
{
	int inv = 0;
	int nL = left.size();
	int nR = right.size();
	int i = 0, j = 0, k = 0;

	while (j < nL && k < nR)
	{
		if (left[j] <= right[k])
		{
			bars[i] = left[j];
			j++;
		}
		else
		{
			if (left[j] > right[k])
			{
				inv += nL - j;
			}

			bars[i] = right[k];
			k++;
		}
		i++;
	}
	while (j < nL)
	{
		bars[i] = left[j];
		j++;
		i++;
	}
	while (k < nR)
	{
		bars[i] = right[k];
		k++;
		i++;
	}

	return inv;
}

long long get_number_of_inversions(vector<int> &a)
{
	long long number_of_inversions = 0;
	if (a.size() == 1)
		return 0;
	int mid = a.size() / 2;
	vector<int> leftarr;
	vector<int> rightarr;

	for (size_t j = 0; j < mid; j++)
		leftarr.push_back(a[j]);
	for (size_t j = 0; j < (a.size()) - mid; j++)
		rightarr.push_back(a[mid + j]);

	number_of_inversions += get_number_of_inversions(leftarr);
	number_of_inversions += get_number_of_inversions(rightarr);
	//write your code here
	number_of_inversions += Merge(leftarr, rightarr, a);
	return number_of_inversions;
}

void submit()
{
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << get_number_of_inversions(a) << '\n';
}
void test()
{
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<int> b;
	cout << "Correct: " << getInvCount(a) << endl;
	cout << "Your Ans: " << get_number_of_inversions(a) << '\n';
}

void stress()
{
	int x = 1;
	while (x)
	{

		srand(time(NULL));
		int n = rand() % 8 + 2;
		cout << "Value is: " << n << endl;
		// cin >> n;
		vector<int> a(n);
		for (size_t i = 0; i < a.size(); i++)
		{
			a[i] = rand() % 100;
			cout << a[i] << " ";
		}
		cout << endl;

		cout << "Correct: " << getInvCount(a) << endl;
		cout << "Your Ans: " << get_number_of_inversions(a) << '\n';

		cout << "Press 1 to Play Again, 0 To Close" << endl;
		cin >> x;
	}
}

int main()
{
	submit();
	// stress();
	// test();
}
