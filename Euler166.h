#include <iostream>
#include <vector>

using std::cout;
using std::endl;

class Euler166
{

  public:

    Euler166()
    {
        for ( int i = 0; i < 4; ++i )
        {
            permuTab[i] = 0;
            t[i] = 0;
        }

        for ( int i = 0; i < 4; ++i )
            for ( int j = 0; j < 4; ++j )
                tab[i][j] = 0;
    }

    int solution();

  private:

    struct Permutation
    {
        Permutation( int t[4] )
        {
            tab[0] = t[0];
            tab[1] = t[1];
            tab[2] = t[2];
            tab[3] = t[3];
        }

        int tab[4];
    };

    bool addOne();
    bool addNextPermutation();
    bool isCorrectAll();
    bool isCorrectPermutation();

    int tab[4][4];
    int t[4];
    int permuTab[4];
    std::vector<Permutation> permutations;
    const static int SUM = 4;
};

bool Euler166::isCorrectPermutation()
{
    return t[0] + t[1] + t[2] + t[3] == SUM ? true : false;

    /*
    for ( int i = 0; i < 4; ++i )
    {
        int sum1 = 0;
        int sum2 = 0;

        for ( int j = 0; j < 4; ++j )
        {
            sum1 += tab[i][j];
            sum2 += tab[j][i];
        }

        if ( sum1 != 12 || sum2 != 12 )
            return false;
    }

    if ( tab[0][0] + tab[1][1] + tab[2][2] + tab[3][3] != 12 )
        return false;

    if ( tab[0][3] + tab[1][2] + tab[2][1] + tab[3][0] != 12 )
        return false;

    return true;
    */
}

bool Euler166::isCorrectAll()
{
    for ( int i = 0; i < 4; ++i )
    {
        int sum1 = 0;
        int sum2 = 0;

        for ( int j = 0; j < 4; ++j )
        {
            sum1 += tab[i][j];
            sum2 += tab[j][i];
        }

        if ( sum1 != SUM || sum2 != SUM )
            return false;
    }

    if ( tab[0][0] + tab[1][1] + tab[2][2] + tab[3][3] != SUM )
        return false;

    if ( tab[0][3] + tab[1][2] + tab[2][1] + tab[3][0] != SUM )
        return false;

    return true;

}

bool Euler166::addOne()
{
    int* value = &t[3];

    for ( int i = 0; i < 4; ++i )
    {
        ++(*value);
        if ( *value == 10 )
        {
            *value = 0;
            --value;
            continue;
        }

        return true;
    }

    /*
    int* value = &tab[3][3];

    for ( int i = 0; i < 16; ++i )
    {
        ++(*value);
        if ( *value == 10 )
        {
            *value = 0;
            --value;
            continue;
        }

        return true;
    }
    */
    return false;
}

bool Euler166::addNextPermutation()
{
    int* value = &permuTab[3];

    for ( int i = 0; i < 4; ++i )
    {
        ++(*value);
        if ( *value == permutations.size() )
        {
            *value = 0;

        //   for ( int j = 0; j < 4; ++j )
         //       tab[i][j] = permutations[ *value ].tab[j];

            --value;

            continue;
        }

       // for ( int j = 0; j < 4; ++j )
        //    tab[i][j] = permutations[ *value ].tab[j];


        for ( int i = 0; i < 4; ++i )
        {
            for ( int j = 0; j < 4; ++j )
            {
                tab[i][j] = permutations[ permuTab[i] ].tab[j];
            }
        }


        return true;
    }

    return false;
}

int Euler166::solution()
{
    do
    {
        if ( isCorrectPermutation() )
        {
            permutations.push_back( Permutation( t ) );
        }
    }
    while ( addOne() );

    int sum = 0;
/*
    int iterations = 0;
    do
    {
        if ( isCorrectAll() )
        {
/*
            for ( int i = 0; i < 4; ++i )
            {
                for ( int j = 0; j < 4; ++j )
                {
                    cout << tab[i][j] << " ";
                }
                cout << endl;
            }
            cout << sum << endl;

            ++sum;
        }

        ++iterations;

        //if ( iterations % 10 == 0 )
        if ( iterations < -10 )
        {
            for ( int i = 0; i < 4; ++i )
            {
                for ( int j = 0; j < 4; ++j )
                {
                    cout << tab[i][j] << " ";
                }
                cout << endl;
            }
            cout << sum << endl;
        }


        //cout << permuTab[0] << " " << permuTab[1] << " " << permuTab[2] << " " << permuTab[3] << endl;

        //cout << iterations << endl;

    }
    while ( addNextPermutation() );
*/

/*
    for ( Permutation p : permutations )
    {
        cout << p.tab[0] << " " << p.tab[1] << " " << p.tab[2] << " " << p.tab[3] << endl;
    }

    cout << permutations.size() << endl;
*/

        int asd = 0;
    for ( int i = 0; i < permutations.size(); ++i )
    {
        std::vector<Permutation> list1;
        std::vector<Permutation> list2;

        for ( Permutation p : permutations )
        {
            if ( p.tab[3] == permutations[i].tab[0] && p.tab[0] + permutations[i].tab[3] <= SUM )
            {
                //list1.push_back( p );

                for ( Permutation p2 : permutations )
                {
                    if ( p2.tab[0] == p.tab[0] &&
                        p2.tab[1] + permutations[i].tab[1] <= SUM &&
                        p2.tab[2] + permutations[i].tab[2] <= SUM &&
                        p2.tab[3] + permutations[i].tab[3] <= SUM &&
                        p2.tab[3] + permutations[i].tab[0] <= SUM)
                    {
                        //list2.push_back( p2 );

                        for ( Permutation p3 : permutations )
                        {
                            if ( p3.tab[0] == p2.tab[3] && p3.tab[3] == permutations[i].tab[3] &&
                                p3.tab[1] + p.tab[1] <= SUM &&
                                p3.tab[2] + p.tab[2] <= SUM )
                            {
                                ++asd;
                            }
                        }

                    }
                }

            }
        }



        //asd += list1.size();
    }
        cout << "per: " << asd << endl;

/*
    for ( int i = 0; i < permutations.size(); ++i )
    {
    int asd = 0;
        std::vector<Permutation> list1;
        std::vector<Permutation> list2;
        std::vector<Permutation> list3;
        std::vector<Permutation> list4;

        for ( Permutation p : permutations )
        {
            if ( permutations[i].tab[0] == p.tab[3] )
            {
                list1.push_back( p );
            }
        }

        //cout << "list1: " << list1.size() << endl;
        asd += list1.size();


        for ( Permutation p : permutations )
        {
            if ( permutations[i].tab[1] == p.tab[3] )
            {
                list2.push_back( p );
            }
        }

        //cout << "list2: " << list2.size() << endl;
        asd += list2.size();

        for ( Permutation p : permutations )
        {
            if ( permutations[i].tab[2] == p.tab[3] )
            {
                list3.push_back( p );
            }
        }

        //cout << "list3: " << list3.size() << endl;
        asd += list3.size();

        for ( Permutation p : permutations )
        {
            if ( permutations[i].tab[3] == p.tab[3] )
            {
                list4.push_back( p );
            }
        }

        //cout << "list4: " << list4.size() << endl;
        asd += list4.size();
    cout << "per: " << asd << endl;
    }
*/

/*
            for ( Permutation p2 : permutations )
            {
                if ( p1.tab[3] == p2.tab[0])
                {
                    for ( Permutation p3 : permutations )
                    {
                        if ( p2.tab[3] == p3.tab[3])
                        {
                            ++asd;
                        }
                    }
                }

            }
        }
    }
*/

    return sum;
}












