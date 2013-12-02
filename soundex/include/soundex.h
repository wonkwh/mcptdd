
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
        return "A";
    }
};

} //namespace soundex
#endif //_SOUNDEX_H_
