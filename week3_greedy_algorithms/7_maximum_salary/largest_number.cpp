#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cstdlib>
#include <time.h>

using namespace std;

void swap(string *a, string *b);
bool isgreaterorequal(string a, string b);
void sortbiggest(vector<string> &a);
string largest_number(vector<string> a);
void stress();
void submit();

int main()
{
	// char ans;
	// do
	// {
	// 	stress();
	// 	cout<< "Play again? ";
	// 	cin >> ans;
	// } while (ans == 'y');
	submit();
	
	
}

void swap(string *a, string *b)
{
	string tmp = *a;
	*a = *b;
	*b = tmp;
}

bool isgreaterorequal(string a, string b)
{
	string x = a+b;
	string y = b+a;


	stringstream one(x);
	stringstream two(y);
	int num_a, num_b;

	one >> num_a;
	two >> num_b;
	if (num_a > num_b)
	{
		return true;
	}
	return false;


}

void sortbiggest(vector<string> &a)
{
	int size = a.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (!isgreaterorequal(a[j], a[j + 1]))
			{
				swap(&a[j], &a[j + 1]);
			}
		}
	}
}

string largest_number(vector<string> a)
{
	//write your code here

	sortbiggest(a);

	std::stringstream ret;
	for (size_t i = 0; i < a.size(); i++)
	{
		ret << a[i];
	}
	string result;
	ret >> result;
	return result;
}

void stress()
{
	srand(time(NULL));
	// int n = rand() % 8 + 2;
	int n;
	cin >> n;
	if (n == 0)
	{
		return;
	}
	
	// cout << n << endl;
	vector<string> a(n);
	for (size_t i = 0; i < a.size(); i++)
	{
		a[i] = to_string(rand() % 1000);
		cout << a[i] << " ";
	}
	cout << endl;
	cout << largest_number(a) <<endl;
}

void submit()
{
	int n;
	cin >> n;
	if (n < 1 || n > 100)
	{
		return;
	}
	
	vector<string> a(n);
	for (size_t i = 0; i < a.size(); i++)
	{
		cin >> a[i];
		if (a[i].length() > 4)
		{
			return;
		}
		
	}
	cout << largest_number(a);
}
