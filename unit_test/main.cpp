
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
    ù��° ���ڴ� ������ ������� �����Ѵ� (��, �������� ���)
    2. �ι�° ���ں��� a, e, h, i, o, u, w, y �� ������ �����ϰ�, ���� ���ڷ� �Ѿ��.
    3. ���ڸ� ���� �Ʒ��� ���̺��� �����Ͽ� ���� ġȯ�Ѵ�.
    �Ʒ� ���̺��� �����Ҷ� ���� ����� �������� ������ ���̴�. �ñ��ϸ� ������ ����. 
    * b, f, p, v = 1
    * c, g, j, k, q, s, x, z = 2
    * d, t = 3
    * l = 4
    * m, n = 5
    * r = 6
    4. ���� ���� ���� 2�� ���� ������, �������ڰ� �� ���̺� ���Ե� ���ڶ�� �����ϰ�,
    ���ӵ� ���ڰ� �ƴϸ� ������� �����Ѵ�.
    5. 4������ ������� �����ϴµ�, ���ڰ� �����Ҷ��� "0"���� �е����� �����Ѵ�.

    �� �˰����� ����ϸ� , 
    "Robert" �� "Rupert" �� "R163" �̶�� ���� ���� �����Ѵ�.
    "Rubin" �� ������� 3�� �̹Ƿ�, "0" �� �е��� "R150" �� �����Ѵ�.
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
