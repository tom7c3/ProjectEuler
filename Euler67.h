#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/*
By starting at the top of the triangle below and moving to adjacent numbers on the row below,
the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'),
a 15K text file containing a triangle with one-hundred rows.

NOTE: This is a much more difficult version of Problem 18.
It is not possible to try every route to solve this problem, as there are 299 altogether!
If you could check one trillion (1012) routes every second it would
take over twenty billion years to check them all. There is an efficient algorithm to solve it. ;o)
*/

class Euler67
{
  public:

    int solution();
};


int Euler67::solution()
{
    int tab[100][100] = {};

    ifstream in("p067_triangle.txt");
    for ( int i = 0; i < 100; ++i )
    {
        string line;
        getline(in, line);
        stringstream ss;
        ss << line;
        for ( int j = 0; j <= i; ++j )
            ss >> tab[i][j];
    }

    for ( int i = 98; i >= 0; --i )
        for ( int j = 0; j <= i; ++j )
            tab[i][j] += ( tab[i+1][j] > tab[i+1][j+1] ? tab[i+1][j] : tab[i+1][j+1] );

    return tab[0][0];
}




















