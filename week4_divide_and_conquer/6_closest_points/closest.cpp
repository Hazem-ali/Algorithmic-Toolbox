#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <utility>
#include <random>
#include <cstdlib>
#include <time.h>

using namespace std;

class Points
{
private:
public:
	pair<int, int> pt;
	Points(int x, int y)
	{
		pt.first = x;
		pt.second = y;
	}

	// bool operator<(const Points &rhs) const
	// {
	// 	double dist1 = sqrt(pow(pt.first, 2) + pow(pt.second, 2));
	// 	double dist2 = sqrt(pow(rhs.pt.first, 2) + pow(rhs.pt.second, 2));
	// 	return (dist1 < dist2);
	// }
	// bool operator<(const Points &rhs) const
	// {
	// 	return ((pt.first + pt.second) < (rhs.pt.first + rhs.pt.second));
	// }
	bool operator<(const Points &rhs) const
	{

		return ((pt.first) < (rhs.pt.first));
		// return (abs(pt.first - rhs.pt.first) < 10 && abs(rhs.pt.second - pt.second) < 10);
	}
	// bool operator<(const Points &rhs) const
	// {
	// 	return (abs(pt.first - rhs.pt.first) < abs(pt.second - rhs.pt.second));
	// }
	void insert(int x, int y)
	{
		pt.first = x;
		pt.second = y;
	}
};

struct point
{
	int x, y;
};

struct point_pair
{
	point a, b;
};

void display(multiset<Points> &points);
double GetDist(Points a, Points b);
double minimal_distance(vector<int> x, vector<int> y, multiset<Points> &points);
void submit();
void stress_loop();

// Correct Functions
double calc_distance(point_pair pair);
double minimal_distance_correct(vector<int> x, vector<int> y);
int getval(int size);
bool compare_x(point &a, point &b);
bool compare_y(point &a, point &b);
point_pair minimal_distance_naive(vector<point> points);

int main()
{
	// submit();
	stress_loop();
}

void submit()
{
	size_t n;
	cin >> n;
	multiset<Points> points;
	vector<int> x(n);
	vector<int> y(n);

	for (size_t i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		Points tmp(x[i], y[i]);
		// pair<int, int> tmp_point;
		// cin >> tmp_point.first >> tmp_point.second;
		points.insert(tmp);
	}
	cout << std::fixed;
	cout << std::setprecision(9) << minimal_distance(x, y, points) << "\n";
}

void display(multiset<Points> &points)
{
	cout << "======= Printing Sorted Points =======" << endl;
	for (auto &e : points)
	{
		cout << e.pt.first << " " << e.pt.second << endl;
	}
	cout << "======= Printed Successfully =======" << endl;
}

double GetDist(Points a, Points b)
{
	double dist = sqrt(pow(a.pt.first - b.pt.first, 2) + pow(a.pt.second - b.pt.second, 2));
	return dist;
}

double minimal_distance(vector<int> x, vector<int> y, multiset<Points> &points)
{

	// display(points);

	// set<pair<int, int>>::iterator it = points.begin();
	set<Points>::iterator it = points.begin();
	set<Points>::iterator first_point = points.begin();

	double min = 9000.0;
	double dist;
	while (it != points.end())
	{
		if (it != points.begin())
		{
			dist = GetDist(*first_point, *it);
			if (dist < min)
			{
				min = dist;
			}
		}

		// difference swapping idea

		set<Points>::iterator tmp_it = it;
		it++;

		// it++;
		// set<Points>::iterator tmp2_it = it;
		// it--;

		if (it == points.end())
		{
			break;
		}
		dist = GetDist(*tmp_it, *it);
		if (dist < min)
		{
			min = dist;
		}

		// if (tmp2_it != points.end())
		// {
		// 	double dist2 = GetDist(*tmp_it, *tmp2_it);
		// 	if (dist2 < min)
		// 	{
		// 		min = dist;
		// 	}
		// }

		// int x1 = tmp_it->pt.first;
		// int y1 = tmp_it->pt.second;
		// int x2 = it->pt.first;
		// int y2 = it->pt.second;
		// double x_sq = (x1 - x2) * (x1 - x2);
		// double y_sq = (y1 - y2) * (y1 - y2);
		// double dist = sqrt(x_sq + y_sq);
	}

	return min;
}

void stress_loop()
{
	int loop = 1;
	int checks;
	cout << "Enter Number of Checks: ";
	cin >> checks;
	while (loop)
	{
		srand(time(NULL));
		int n = rand() % 5 + 2;

		multiset<Points> points;
		vector<int> x(n);
		vector<int> y(n);
		for (size_t i = 0; i < n; i++)
		{
			x[i] = rand() % 100;
			y[i] = rand() % 100 + 2;
			Points tmp(x[i], y[i]);
			// pair<int, int> tmp_point;
			// cin >> tmp_point.first >> tmp_point.second;
			points.insert(tmp);
		}

		double ans1 = minimal_distance_correct(x, y);
		double ans2 = minimal_distance(x, y, points);

		if (loop == checks)
		{
			cout << "Checked " << loop << " Cases Successfully!" << endl;
			break;
		}
		if (ans1 != ans2)
		{
			cout << "**** Found after " << loop << " Checks ****" << endl;
			cout << "Number of Points: " << n << endl;
			display(points);
			cout << endl;
			cout << "Correct Ans: " << ans1 << endl;
			cout << "Your Ans: " << ans2 << endl;
			cout << endl;
			break;
		}
		if (loop)
		{
			cout << "=== Check " << loop << " Success ===" << endl;
			loop++;
		}
	}
}

double calc_distance(point_pair pair)
{
	int k1 = abs(pair.a.x - pair.b.x);
	int k2 = abs(pair.a.y - pair.b.y);
	size_t k3 = k1 * k1;
	size_t k4 = k2 * k2;
	size_t k5 = k3 + k4;
	return sqrt(k5);
}

point_pair minimal_distance_naive(vector<point> points)
{
	point_pair min;
	min.a = points[0];
	min.b = points[1];

	for (int i = 0; i < points.size(); i++)
	{
		point_pair temp;
		temp.a = points[i];

		for (int j = i + 1; j < points.size(); j++)
		{
			temp.b = points[j];

			if (calc_distance(temp) < calc_distance(min))
			{
				min = temp;
			}
		}
	}
	return min;
}

int getval(int size)
{
	if (size < 15)
		return size;
	else
		return 15;
}

bool compare_x(point &a, point &b)
{
	if (a.x < b.x)
		return true;
	else
		return false;
}

bool compare_y(point &a, point &b)
{
	if (a.y < b.y)
		return true;
	else
		return false;
}

point_pair minimal_distance_rec(vector<point> points_x, vector<point> points_y)
{

	if (points_x.size() <= 3)
	{
		return minimal_distance_naive(points_x);
	}

	else
	{
		int mid = points_x.size() / 2;
		vector<point> left_x, left_y;
		vector<point> right_x, right_y;

		for (int i = 0; i < mid; i++)
		{
			left_x.push_back(points_x[i]);
		}
		for (int i = mid; i < points_x.size(); i++)
		{
			right_x.push_back(points_x[i]);
		}

		int middle = points_x[mid - 1].x;

		for (int i = 0; i < points_y.size(); i++)
		{
			if (points_y[i].x <= middle)
			{
				left_y.push_back(points_y[i]);
			}
			else
			{
				right_y.push_back(points_y[i]);
			}
		}

		point_pair left = minimal_distance_rec(left_x, left_y);
		point_pair right = minimal_distance_rec(right_x, right_y);

		double d_left = calc_distance(left);
		double d_right = calc_distance(right);
		point_pair min;
		double min_distance;
		if (d_left <= d_right)
		{
			min_distance = d_left;
			min = left;
		}
		else
		{
			min_distance = d_right;
			min = right;
		}
		vector<point> middle_set;
		for (int i = 0; i < points_y.size(); i++)
		{
			if (abs(points_y[i].x - middle) <= min_distance)
			{
				middle_set.push_back(points_y[i]);
			}
		}

		if (middle_set.size() < 2)
		{
			return min;
		}

		point_pair init;
		init.a = middle_set[0];
		init.b = middle_set[1];
		double k = 0, m = calc_distance(init);
		point_pair tmp, min_tmp = init;

		for (int i = 0; i < middle_set.size(); i++)
		{
			tmp.a = middle_set[i];
			for (int j = i + 1; j <= getval(middle_set.size() - 1); j++)
			{
				tmp.b = middle_set[j];
				k = calc_distance(tmp);
				if (k < m)
				{
					m = k;
					min_tmp = tmp;
				}
			}
		}
		if (min_distance < m)
			return min;
		else
			return min_tmp;
	}
}

double minimal_distance_correct(vector<int> x, vector<int> y)
{
	vector<point> points(x.size());
	for (int i = 0; i < x.size(); i++)
	{
		points[i].x = x[i];
		points[i].y = y[i];
	}

	sort(points.begin(), points.end(), compare_x);
	vector<point> points_x = points;

	sort(points.begin(), points.end(), compare_y);
	vector<point> points_y = points;

	point_pair p = minimal_distance_rec(points_x, points_y);
	return calc_distance(p);
}