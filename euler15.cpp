#include <iostream>

using namespace std;

/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down,
there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
*/

/*
252 126  56  21   6   1
126  70  35  15   5   1
 56  35  20  10   4   1
 21  15  10   6   3   1
  6   5   4   3   2   1
  1   1   1   1   1   0
*/

long long solution(int n)
{
	long long tab[n + 1];
    for ( int i = 0; i < n + 1; ++i )
        tab[i] = 1;

    for ( int i = 0; i < n; ++i )
        for ( int j = 1; j < n + 1; ++j )
            tab[j] += tab[j - 1];

	return tab[n];
}

int main()
{
    cout << "solution: " << solution(20) << endl;
    return 0;
}





















