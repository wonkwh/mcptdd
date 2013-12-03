
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

class Soundex
{
public:
    std::string encode(const std::string& word) const 
    {
        return zero_Padding(word);
    }

    std::string zero_Padding(const std::string& word) const
    {
        return word + "000";
    }
};

} //namespace soundex
#endif //_SOUNDEX_H_
