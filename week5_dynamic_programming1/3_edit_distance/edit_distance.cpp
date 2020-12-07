#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

int min(int a, int b, int c)
{
	return min(min(a, b), c);
}

int edit_distance(const string &str1, const string &str2)
{
	//write your code here
	const int n = str1.length();
	const int m = str2.length();
	vector<int> w(m + 1, 0);
	vector<vector<int>> v(n + 1, w);
	string tmp1, tmp2;

	int inst, del, mis, mat;

	int dist = 0;
	// editing
	// distance
	/* 
		editing
		-distance
	*/

	for (int i = 0; i <= n; i++)
	{
		v[i][0] = i;
	}
	for (int j = 0; j <= m; j++)
	{
		v[0][j] = j;
	}

	for (int i = 1; i <= n; i++)
	{
		for (size_t j = 1; j <= m; j++)
		{
			inst = v[i][j - 1];
			del = v[i - 1][j];
			mat = v[i - 1][j - 1];
			// mis = v[i - 1][j - 1] + 1;
			if (str1[i-1] == str2[j-1])
			{
				v[i][j] = mat;
			}
			else
			{
				v[i][j] = 1 + min(inst, del, mat);
			}
		}
	}
	return v[n][m];
}

int main()
{
	string str1;
	string str2;
	std::cin >> str1 >> str2;
	// str1 = "short";
	// str2 = "ports";
	std::cout << edit_distance(str1, str2) << std::endl;
	return 0;
}
