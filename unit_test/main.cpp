
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

/*
    //http://sokum.tistory.com/47
    첫번째 문자는 무조건 결과값에 포함한다 (단, 영문자인 경우)
    2. 두번째 문자부터 a, e, h, i, o, u, w, y 가 나오면 무시하고, 다음 문자로 넘어간다.
    3. 문자를 다음 아래의 테이블을 참조하여 값을 치환한다.
    아래 테이블은 발음할때 입의 모양을 기준으로 정리한 것이다. 궁금하면 발음해 보라. 
    * b, f, p, v = 1
    * c, g, j, k, q, s, x, z = 2
    * d, t = 3
    * l = 4
    * m, n = 5
    * r = 6
    4. 만약 같은 값이 2개 연속 나오면, 이전문자가 위 테이블에 포함된 글자라면 무시하고,
    연속된 글자가 아니면 결과값에 포함한다.
    5. 4글자의 결과값을 리턴하는데, 글자가 부족할때는 "0"으로 패딩한후 리턴한다.

    위 알고리즘을 사용하면 , 
    "Robert" 와 "Rupert" 는 "R163" 이라는 같은 값을 리턴한다.
    "Rubin" 은 결과값이 3자 이므로, "0" 을 패딩한 "R150" 을 리턴한다.
*/

using ::testing::Eq;

TEST( SoundexEncoding, retains_Sole_Letter_Of_One_Letter_Word)
{
    soundex::Soundex soundex_;
    auto encoded = soundex_.encode("A");

    ASSERT_THAT(encoded, Eq("A000"));
}

TEST( SoundexEncoding, pad_With_Zeros_To_Ensure_Three_Digit)
{
    soundex::Soundex soundex_;
    auto encoded = soundex_.encode("I");

    ASSERT_THAT( encoded, Eq("I000") );
}
