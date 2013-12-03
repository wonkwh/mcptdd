
//=======================================================================
// 
//  [12/2/2013 kwanghyun won]
//                                                     
//======================================================================= 

#ifndef _SOUNDEX_H_
#define _SOUNDEX_H_

#include <string>

namespace soundex
{

static const size_t kMaxCodeLength = 4;
class Soundex
{
public:
    std::string encode(const std::string& word) const 
    {
        return zero_Padding(head(word) + encoded_Digits(word));
    }

    std::string head(const std::string& word) const
    {
        return word.substr(0, 1);
    }

    std::string encoded_Digits(const std::string& word) const 
    {
        if (word.length() > 1)
            return encoded_Digit();

        return "";
    }

    std::string encoded_Digit() const 
    {
        return "1";
    }

    std::string zero_Padding(const std::string& word) const
    {
        auto zero_needed = kMaxCodeLength - word.length();
        return word + std::string( zero_needed , '0' );
    }
};

} //namespace soundex
#endif //_SOUNDEX_H_
