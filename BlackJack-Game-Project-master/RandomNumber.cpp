//
//  RandomNumber.cpp
//

#include "RandomNumber.h"

#include <random>
#include <utility>

using namespace std;

// save the desired min and max value for later use
RandomNumber::RandomNumber( int min, int max,
                            bool minInclusive, bool maxInclusive )
                            : mMinimum( min ), mMaximum( max )
{
    // in case the user messes up the order...
    if (mMinimum > mMaximum)
    {
        swap( mMinimum, mMaximum );
    }
    if (!minInclusive)
    {
        mMinimum++;
    }
    if (!maxInclusive)
    {
        mMaximum--;
    }
}

// pull a random number between the desired min and max
// value
int RandomNumber::random( )
{
    static random_device rd;
    static mt19937 generator(rd());
    uniform_int_distribution<> distro( mMinimum, mMaximum );
    
    return( distro( generator ) );
}

