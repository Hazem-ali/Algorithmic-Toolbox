#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include <time.h>

using namespace std;

void partition3new(vector<int> &a, int l, int r, int &ml, int &mr);
void partition3(vector<int> &a, int l, int r, int &ml, int &mr);
int partition2(vector<int> &a, int l, int r);
void quick_sort3(vector<int> &a, int l, int r);
void randomized_quick_sort(vector<int> &a, int l, int r);
void submit();
void stress_loop();
void stress_show();

int main()
{
	submit();
	// stress_loop();
}

void submit()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (size_t i = 0; i < a.size(); ++i)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	quick_sort3(a, 0, a.size() - 1);
	for (size_t i = 0; i < a.size(); ++i)
	{
		cout << a[i] << ' ';
	}
}

void stress_loop()
{
	// INCLUDE THESE LIBRARIES FIRST
	/*
		#include <random>
		#include <cstdlib>
		#include <time.h>
	*/
	// TAKE CARE OF YOUR FUNCTION NAMES AND FUNCTIONS WRITTEN HERE
	// ENJOY
	// RBNA M3ANA :)

	int x = 1;
	while (x)
	{
		srand(time(NULL));
		int n = rand() % 4 + 2;
		vector<int> a(n);
		vector<int> b(n);
		vector<int> c(n);
		for (size_t i = 0; i < n; i++)
		{
			a[i] = rand() % 100;
			b[i] = a[i];
			c[i] = a[i];
		}

		quick_sort3(a, 0, n - 1);
		randomized_quick_sort(b, 0, n - 1);

		// Checking Two Arrays are same
		for (size_t i = 0; i < n; ++i)
		{
			if (a[i] != b[i])
			{
				x = 0;
				break;
			}
		}

		if (x)
		{
			cout << "=== OK ===" << endl;
		}
		else
		{

			cout << "Array Size: " << n << endl;

			cout << "===== Array NOT Sorted ======" << endl;
			for (size_t i = 0; i < n; ++i)
			{
				cout << c[i] << ' ';
			}

			cout << endl;
			cout << "===== Your Array Sorted ======" << endl;
			for (size_t i = 0; i < n; ++i)
			{
				cout << a[i] << ' ';
			}
			cout << endl;
			cout << "===== Correct Array Sorted ======" << endl;
			for (size_t i = 0; i < n; ++i)
			{
				cout << b[i] << ' ';
			}
		}
	}
}

void stress_show()
{
	int x = 1;
	while (x)
	{

		srand(time(NULL));
		int n = rand() % 8 + 2;
		cout << "Array Size: " << n << endl;
		// cin >> n;
		vector<int> a(n);
		vector<int> b(n);
		for (size_t i = 0; i < a.size(); i++)
		{
			a[i] = rand() % 100;
			b[i] = a[i];
			cout << a[i] << " ";
		}
		cout << endl;

		quick_sort3(a, 0, a.size() - 1);
		randomized_quick_sort(b, 0, b.size() - 1);

		cout << "=====Array a Sorted======" << endl;
		for (size_t i = 0; i < a.size(); ++i)
		{
			cout << a[i] << ' ';
		}
		cout << endl;
		cout << "=====Array b Sorted======" << endl;
		for (size_t i = 0; i < a.size(); ++i)
		{
			cout << b[i] << ' ';
		}

		cout << endl
			 << "Press 1 to Play Again, 0 To Close" << endl;
		cin >> x;
	}
}

void partition3new(vector<int> &a, int l, int r, int &ml, int &mr)
{
	int x = a[l];
	ml = l;
	mr = r;

	for (int i = l; i <= r; i++)
	{
		if (i > mr)
		{
			break;
		}

		if (a[i] < x)
		{
			swap(a[ml], a[i]);
			ml++;
		}
		else if (a[i] > x)
		{
			swap(a[mr], a[i]);
			mr--;
			i--;
		}
	}
}
void partition3(vector<int> &a, int l, int r, int &ml, int &mr)
{
	int x = a[l];
	int j = l;
	ml = mr = l;
	bool flag = false;

	// 6 >> 2 3 1 9 2 2
	// 8 >> 4 1 3 4 4 5 4 9
	// two indicators ml, mr
	// if < swap below ml
	// if > swap above mr
	// else i++
	for (int i = l + 1; i <= r; i++)
	{
		if (a[i] < x)
		{
			if (flag)
			{
				j++;
			}
			else
			{
				flag = true;
			}

			mr++;
			ml++;

			swap(a[i], a[j]);
		}
		else if (a[i] == x)
		{
			mr++;
			// swap(a[i], a[j]);
			swap(a[mr], a[i]);
		}
	}

}

int partition2(vector<int> &a, int l, int r)
{
	int x = a[l];
	int j = l;
	for (int i = l + 1; i <= r; i++)
	{
		if (a[i] <= x)
		{
			j++;
			swap(a[i], a[j]);
		}
	}
	swap(a[l], a[j]);
	return j;
}

void quick_sort3(vector<int> &a, int l, int r)
{
	if (l >= r)
	{
		return;
	}

	int ml, mr;

	// int k = l + rand() % (r - l + 1);
	// swap(a[l], a[k]);
	partition3new(a, l, r, ml, mr);

	quick_sort3(a, l, ml - 1);
	quick_sort3(a, mr + 1, r);
}
void randomized_quick_sort(vector<int> &a, int l, int r)
{
	if (l >= r)
	{
		return;
	}

	int k = l + rand() % (r - l + 1);
	swap(a[l], a[k]);
	int m = partition2(a, l, r);

	randomized_quick_sort(a, l, m - 1);
	randomized_quick_sort(a, m + 1, r);
}