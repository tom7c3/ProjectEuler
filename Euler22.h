#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file
containing over five-thousand first names, begin by sorting it into alphabetical order.
Then working out the alphabetical value for each name, multiply this value by its alphabetical
position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN,
which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So,
COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

class Euler22
{
  public:

    int solution();
};

int Euler22::solution()
{
    std::vector<std::string> names;

    ifstream in("p022_names.txt");

    char c;
    std::string name;
    while ( in.get(c) )
    {
        if ( c == ',' )
        {
            names.push_back( name );
            name.clear();
        }
        else
            name += c;
    }

    names.push_back( name );    // last name //

    std::sort( names.begin(), names.end(), [](std::string a, std::string b)
    {
        int size = std::min( a.length(), b.length() );
        for ( int i = 1; i < size - 1; ++i )
        {
            if ( a[i] < b[i] )
                return true;
            else if ( a[i] > b[i] )
                return false;
        }

        if ( a.length() < b.length() )
            return true;
        else
            return false;

    });

    long long total = 0;
    for ( int i = 0; i < names.size(); ++i )
    {
        int sum = 0;
        for ( int j = 1; j < names[i].size() - 1; ++j )
            sum += (int)(names[i][j] - 64);

        total += sum * (i + 1);
    }

    return total;
}




















