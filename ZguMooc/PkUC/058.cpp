#include <iostream>
#include <iomanip>
using namespace std;
double GetDoubleFromString(char *str)
{
	static char *p;
	if(str){
		p = str;
	}
	double num = 0.0, dec = 0.1;
	int flag = 1;
	while (*p && !(*p >= '0' && *p <= '9'))
	{
		p++;
	}

	if (*p == 0)
	{
		return -1;
	}
	while (*p >= '0' && *p <= '9' || *p == '.')
	{
		if (*p == '.')
		{
			flag = 0;
			p++;
		}
		if (flag)
		{
			num = num * 10 + *p - '0';
			p++;
		}
		else if (flag == 0)
		{
			num = num + (*p - '0') * dec;
			dec *= 0.1;
			p++;
		}

	}
	return num;
}

int main()
{
	char line[300];
	while (cin.getline(line, 280))
	{
		double n;
		n = GetDoubleFromString(line);
		while (n > 0)
		{
			cout << fixed << setprecision(6) << n << endl;
			n = GetDoubleFromString(NULL);
		}
	}
	return 0;
}