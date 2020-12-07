#include <iostream>

long long lcm_naive(int a, int b)
{
	for (long l = 1; l <= (long long)a * b; ++l)
		if (l % a == 0 && l % b == 0)
			return l;

	return (long long)a * b;
}

long long gcd_fast(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	int tmpa = a % b;
	return gcd_fast(b, tmpa);
}

long long lcm_fast(int a, int b)
{
	long long gcd = gcd_fast(a, b);
	long long mult = (long long)a * b;
	return  mult / gcd;

	/*bool a_even = bool(a % 2 == 0);
	bool b_even = bool(b % 2 == 0);

	if (a == b)
	{
		return a;
	}
	

	// if both are evens, we can optimize before getting result
	if (a_even && b_even)
	{
		return lcm_fast((a / 2), b);
	}

	// else, just multiply them
	return (long long)a * b;*/
}



int main()
{
	int a, b;
	std::cin >> a >> b;
	std::cout << lcm_fast(a, b) << std::endl;
	return 0;
}
