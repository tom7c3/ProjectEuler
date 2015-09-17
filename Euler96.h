#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <chrono>

using std::cout;
using std::endl;

/*
Su Doku (Japanese meaning number place) is the name given to a popular puzzle concept. Its origin is unclear, but credit must be attributed to Leonhard Euler who invented a similar, and much more difficult, puzzle idea called Latin Squares. The objective of Su Doku puzzles, however, is to replace the blanks (or zeros) in a 9 by 9 grid in such that each row, column, and 3 by 3 box contains each of the digits 1 to 9. Below is an example of a typical starting puzzle grid and its solution grid.
A well constructed Su Doku puzzle has a unique solution and can be solved by logic, although it may be necessary to employ "guess and test" methods in order to eliminate options (there is much contested opinion over this). The complexity of the search determines the difficulty of the puzzle; the example above is considered easy because it can be solved by straight forward direct deduction.

The 6K text file, sudoku.txt (right click and 'Save Link/Target As...'), contains fifty different Su Doku puzzles ranging in difficulty, but all with unique solutions (the first puzzle in the file is the example above).

By solving all fifty puzzles find the sum of the 3-digit numbers found in the top left corner of each solution grid; for example, 483 is the 3-digit number found in the top left corner of the solution grid above.
*/

class Euler96
{
  public:

    int solution();

    int checker = 0;
    int counter = 0;

  private:

    struct Field
    {
        int getNext()
        {
            if ( index < list.size() )
                return list[index++];

            // else reset index and return 0 //
            index = 0;
            return 0;
        }

        int i;
        int j;
        int index = 0;
        std::vector<int> list;
    };

    int tab[9][9];
    int comb[9][9];
    std::vector<Field> fields;

    void reset();
    bool numberNotPresent( int i, int j, int number );
    bool notPresentH( int i, int number );
    bool notPresentV( int j, int number );
    bool notPresentSquare( int i, int j, int number );
    void buildCombinations();
};

void Euler96::reset()
{
    for ( int j = 0; j < 9; ++j )
        for ( int k = 0; k < 9; ++k )
            comb[j][k] = 0;

    fields.clear();
}

bool Euler96::notPresentH( int i, int number )
{
    for ( int k = 0; k < 9; ++k )
    {
        ++checker;
        if ( tab[i][k] == number )
            return false;
    }
    return true;
}

bool Euler96::notPresentV( int j, int number )
{
    for ( int k = 0; k < 9; ++k )
    {
        ++checker;
        if ( tab[k][j] == number )
            return false;
    }
    return true;
}

bool Euler96::notPresentSquare( int i, int j, int number )
{
    auto correctIndex = []( int& coord )
    {
        if ( coord < 3 )
            coord = 0;
        else if ( coord < 6 )
            coord = 3;
        else
            coord = 6;
    };

    correctIndex( i );
    correctIndex( j );

    for ( int k = 0; k < 3; ++k )
    {
        for ( int l = 0; l < 3; ++l )
        {
            ++checker;
            if ( tab[k + i][l + j] == number )
                return false;
        }
    }
    return true;
}

bool Euler96::numberNotPresent( int i, int j, int number )
{
    return notPresentH( i, number ) && notPresentV( j, number ) && notPresentSquare( i, j, number );
}

void Euler96::buildCombinations()
{
    for ( int i = 0; i < 9; ++i )
    {
        for ( int j = 0; j < 9; ++j )
        {
            if ( tab[i][j] != 0 )
                continue;

            int count = 0;

            Field field;
            field.i = i;
            field.j = j;

            for ( int k = 1; k <= 9; ++k )
            {
                if ( numberNotPresent( i, j, k ) )
                {
                    ++count;
                    field.list.push_back(k);
                }
            }

            comb[i][j] = count;
            fields.push_back( field );
        }
    }

    // without sort it runs faster //
//    std::sort( fields.begin(), fields.end(), [](Field a, Field b) { return a.list.size() < b.list.size(); } );
}

int Euler96::solution()
{
    std::ifstream in("p096_sudoku.txt");
    std::string line;
    int sum = 0;
    for ( int i = 0; i < 1; ++i )
    {
        reset();

        std::getline( in, line );
        cout << line << endl;
        for ( int j = 0; j < 9; ++j )
        {
            std::getline( in, line );
            for ( int k = 0; k < 9; ++k )
            {
                tab[j][k] = (int)line[k] - 48;
            }
        }

        buildCombinations();

        for ( int i = 0; i < fields.size(); )
        {
            Field* field = &fields[i];
            int number = field->getNext();

            if ( number == 0 )  // we don't have next number -> step back //
            {
                tab[field->i][field->j] = 0;
                --i;
                ++counter;
            }
            else if ( numberNotPresent( field->i, field->j, number ) )
            {
                tab[field->i][field->j] = number;
                ++i;
            }
        }

        sum += tab[0][2] + tab[0][1] * 10 + tab[0][0] * 100;
    }

    return sum;
}












