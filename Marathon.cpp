#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int abc[41][601];
int Energy;
int dist;
int gears[5][2];

int min(int x, int g)
{
	int mina = 99999;
	for (int i = 0; i < 5; i++)
	{
		if (g - gears[i][1] > 0)
		if ((abc[x - 1][g - gears[i][1]] + gears[i][0]) < mina)
			mina = abc[x - 1][g - gears[i][1]] + gears[i][0];
	}
	return mina;
}

int main()
{
	int tc;
	int a, b;
	int minb = 99999;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		minb = 99999;
		cin >> Energy >> dist;
		for (int i = 0; i < 5; i++)
		{
			cin >> a >> b >> gears[i][1];
			gears[i][0] = a * 60 + b;
		}
		for (int i = 1; i <= Energy; i++)
		for (int j = 0; j <= dist; j++)
		{
			abc[j][i] = 99999;
		}
		for (int i = 1; i <= 5; i++)
		{
			abc[1][gears[i - 1][1]] = gears[i - 1][0];
		}
		for (int i = 2; i <= dist; i++)
		{
			for (int j = 1; j <= Energy; j++)
			{
				abc[i][j] = min(i, j);
			}
		}
		for (int i = 1; i <= Energy; i++)
		{
			if (abc[dist][i] < minb)
				minb = abc[dist][i];
		}
		cout << "#" << t + 1 << " " << minb / 60 << " " << minb % 60 << endl;
	}
	return 0;
}
