#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>
using namespace std;

int lcs2(vector<int> &a, vector<int> &b)
{
	//write your code here

	int sizea = a.size();
	int sizeb = b.size();

	vector<int> w(sizeb + 1, 0);
	vector<vector<int>> v(sizea + 1, w);

	int flag = 0;
	int iindex = 0;
	int jindex = 0;
	set<int> x;

	if (sizea == 1 && sizeb == 1)
	{
		return (a[0] == b[0]);
	}

	for (int i = 0; i <= sizea; i++)
	{
		v[i][0] = 0;
	}
	for (int j = 0; j <= sizeb; j++)
	{
		v[0][j] = 0;
	}

	for (size_t i = 1; i <= sizea; i++)
	{
		for (size_t j = 1; j <= sizeb; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				v[i][j] = 1 + v[i - 1][j - 1]; 
			}
			else
			{
				v[i][j] = max(v[i][j - 1], v[i - 1][j]); 
			}
			
		}
	}

	// for (size_t i = iindex; i < sizea; i++)
	// {
	// 	for (size_t j = jindex; j < sizeb; j++)
	// 	{
	// 		if (a[i] == b[j])
	// 		{
	// 			flag++;
	// 			jindex = j;
	// 			iindex = i;
	// 			break;
	// 		}
	// 	}
	// 	// x.insert(flag);
	// 	// flag = 0;
	// }

	// return *x.end();
	return v[sizea][sizeb];
	return flag;
}

int main()
{
	size_t n;
	cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	size_t m;
	cin >> m;
	vector<int> b(m);
	for (size_t i = 0; i < m; i++)
	{
		cin >> b[i];
	}

	cout << lcs2(a, b) << endl;
}
