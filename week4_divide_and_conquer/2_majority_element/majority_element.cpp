#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

void display(vector<int> &a)
{
	int size = a.size();
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	
}


void Merge(vector<int> &left, vector<int> &right, vector<int> &bars)
{
	int nL = left.size();
	int nR = right.size();
	int i = 0, j = 0, k = 0;

	while (j < nL && k < nR)
	{
		if (left[j] < right[k])
		{
			bars[i] = left[j];
			j++;
		}
		else
		{
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
}
void MergeSort(vector<int> &bar)
{
	if (bar.size() <= 1)
		return;

	int mid = bar.size() / 2;
	vector<int> left;
	vector<int> right;

	for (size_t j = 0; j < mid; j++)
		left.push_back(bar[j]);
	for (size_t j = 0; j < (bar.size()) - mid; j++)
		right.push_back(bar[mid + j]);

	MergeSort(left);
	MergeSort(right);
	Merge(left, right, bar);
}

int getmajsorted(vector<int> &a)
{
	MergeSort(a);
	int size = a.size();
	if (a[size / 2] == a[0] || a[size / 2] == a[size - 1])
	{
		return a[size / 2];
	}
	return -1;
}

int get_majority_recursion(vector<int> &a, int left, int right)
{
	if (left == right)
	{
		return a[left];
	}

	// 10 512766168 717383758 5 126144732 5 573799007 5 5 5 405079772
	int countL = 0, countR = 0;
	int midindex = (left + right) / 2;
	int majorL = get_majority_recursion(a, left, midindex);
	int majorR = get_majority_recursion(a, midindex + 1, right);
	int size = a.size();
	int range = size / 2;

	for (size_t i = 0; i < size; i++)
	{
		if (majorL == -1 && majorR == -1)
		{
			return -1;
		}

		if (a[i] == majorL)
		{
			countL++;
		}
		if (a[i] == majorR)
		{
			countR++;
		}
	}
	if (countL > range)
	{
		return majorL;
	}

	if (countR > range)
	{
		return majorR;
	}

	return -1;
}

int MajoritySimplest(vector<int> arr)
{
	int count = 0, i, mElement;
	int size = arr.size();

	for (i = 0; i < size; i++)
	{
		if (count == 0)
			mElement = arr[i];

		if (arr[i] == mElement)
			count++;
		else
			count--;
	}

	count = 0;
	for (i = 0; i < size; i++)
	{
		if (arr[i] == mElement)
			count++;
	}

	if (count > size / 2)
		return mElement;
	return -1;
}

int MajorityElementMaps(vector<int> A)
{
	// create an empty map
	unordered_map<int, int> map;

	// get input size
	int n = A.size();

	// 1. store each element's frequency in a map
	for (int i = 0; i < n; i++)
	{
		map[A[i]]++;
	}

	// 2. return the element if its count is more than n/2
	for (auto pair : map)
	{
		if (pair.second > n / 2)
		{
			return pair.first;
		}
	}

	// Note that step 2 and step 3 can be merged into one
	/* for (int i = 0; i < n; i++)
	{
		if (++map[A[i]] > n/2)
			return A[i];
	} */

	// return -1 if no majority element is present
	return -1;
}

void submit()
{
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i)
	{
		std::cin >> a[i];
	}

	cout << (MajoritySimplest(a) != -1) << '\n';
}

void test()
{
	clock_t start, stop;
	double totalTime;

	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i)
	{
		std::cin >> a[i];
	}

	auto t1 = high_resolution_clock::now();
	cout << "MajorityElementMaps: " << (MajorityElementMaps(a) != -1) << '\n';
	auto t2 = high_resolution_clock::now();
	cout << "MajoritySimplest: " << (MajoritySimplest(a) != -1) << '\n';
	auto t3 = high_resolution_clock::now();
	cout << "getmajsorted: " << (getmajsorted(a) != -1) << '\n';
	auto t4 = high_resolution_clock::now();

	auto duration1st = duration_cast<microseconds>(t2 - t1).count();
	auto duration2nd = duration_cast<microseconds>(t3 - t2).count();
	auto duration3rd = duration_cast<microseconds>(t4 - t3).count();

	cout << "Time of correct: " << (double)duration1st / 1000.0 << "sec" << endl;
	cout << "Time of find: " << (double)duration2nd / 1000.0 << "sec" << endl;
	cout << "Time of yours: " << (double)duration3rd / 1000.0 << "sec" << endl;
}

int main()
{
	submit();
	// test();
}
