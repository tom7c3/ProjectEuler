#include <fstream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;

class Euler81
{
  public:

    int solution();
};


int Euler81::solution()
{
    int tab[80][80] = {};

    std::ifstream in("p081_matrix.txt");
    for ( int i = 0; i < 80; ++i )
    {
        std::string line;
        getline(in, line);
        std::stringstream ss;
        ss << line;
        for ( int j = 0; j < 80; ++j )
        {
            getline(ss, line, ',');
            std::stringstream stream;
            stream << line;
            stream >> tab[i][j];
        }
    }

    for ( int i = 78; i >= 0; --i )
    {
        tab[i][79] += tab[i + 1][79];
        tab[79][i] += tab[79][i + 1];
    }

    for ( int j = 78; j >= 0; --j )
    {
        for ( int i = 78; i >= 0; --i )
        {
            tab[i][j] += ( tab[i][j + 1] < tab[i + 1][j] ? tab[i][j + 1] : tab[i + 1][j] );
        }
    }

    return tab[0][0];
}








