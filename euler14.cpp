#include <iostream>

using namespace std;

int solution()
{
    int maxLength = 0;
    int result = 0;
    for ( int i = 2; i < 1000000; ++i )
    {
        long long n = i;
        int length = 0;

        while ( n != 1 )
        {
            if ( n % 2 == 0 )
                n = n >> 1;
            else
                n = 3 * n + 1;

            ++length;
        }

        if ( length > maxLength )
        {
            maxLength = length;
            result = i;
        }
    }

    cout << "length: " << maxLength << endl;
    return result;
}

int main()
{
    cout << solution() << endl;
    return 0;
}





















