
//=======================================================================
// 
//  [12/2/2013 kwanghyun won]
//                                            
//  Modern CPP Programming with Test-Driven Development
//  https://github.com/jlangr
//======================================================================= 




#include "gmock/gmock.h"

#include "soundex/include/soundex.h"

int main(int argc, char** argv) 
{
   testing::InitGoogleMock(&argc, argv);
   return RUN_ALL_TESTS();
}

using ::testing::Eq;

TEST( SoundexEncoding, retains_Sole_Letter_Of_One_Letter_Word)
{
    soundex::Soundex soundex_;
    auto encoded = soundex_.encode("A");

    ASSERT_THAT(encoded, Eq("A"));
}
