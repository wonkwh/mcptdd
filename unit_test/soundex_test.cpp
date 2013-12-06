
#include "soundex_test.h"

#include "gmock/gmock.h"

#include "soundex/include/soundex.h"

using ::testing::Eq;

TEST_F( Soundex_Encoding, retains_Sole_Letter_Of_One_Letter_Word)
{
    auto encoded = soundex_.encode("A");
    ASSERT_THAT(encoded, Eq("A000"));
}

TEST_F( Soundex_Encoding, pad_With_Zeros_To_Ensure_Three_Digit)
{
    auto encoded = soundex_.encode("I");
    ASSERT_THAT( encoded, Eq("I000") );
}

TEST_F( Soundex_Encoding, replace_Constant_With_Appropriate_Digits)
{
    /*
    * b, f, p, v = 1
    * c, g, j, k, q, s, x, z = 2
    * d, t = 3
    * l = 4
    * m, n = 5
    * r = 6
    */

    ASSERT_THAT( soundex_.encode("Ab"), Eq("A100") );
    ASSERT_THAT( soundex_.encode("Ac"), Eq("A200") );
    ASSERT_THAT( soundex_.encode("Ad"), Eq("A300") );
    ASSERT_THAT( soundex_.encode("Ax"), Eq("A200") );
}

TEST_F( Soundex_Encoding, replace_Multiple_Constants_With_Digit)
{
    ASSERT_THAT( soundex_.encode("Acdl"), Eq("A234") );
    ASSERT_THAT( soundex_.encode("Acd"), Eq("A230") );
}

