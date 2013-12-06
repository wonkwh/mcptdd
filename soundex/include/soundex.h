
//=======================================================================
// 
//  [12/2/2013 kwanghyun won]
//                                                     
//======================================================================= 

#ifndef _SOUNDEX_H_
#define _SOUNDEX_H_

#include <string>
#include <unordered_map>

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
        //if (word.length() > 1)
        //    return encoded_Digit( word[1] );

        std::string encoding;

        for(auto letter: word)
        {
            encoding += encoded_Digit(letter);
        }
        return encoding;
    }

    std::string Soundex::encoded_Digit(char letter) const 
    {
#if 0  // vs2012 not support initalizer_list 
        // http://msdn.microsoft.com/en-us/library/hh567368.aspx
        const std::unordered_map<char, std::string> encodings {
            {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
            {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
            {'s', "2"}, {'x', "2"}, {'z', "2"},
            {'d', "3"}, {'t', "3"},
            {'l', "4"},
            {'m', "5"}, {'n', "5"},
            {'r', "6"}
        };
#else
        std::unordered_map<char, std::string> encodings;
        encodings.insert( std::make_pair('b', "1"));
        encodings.insert( std::make_pair('f', "1"));
        encodings.insert( std::make_pair('p', "1"));
        encodings.insert( std::make_pair('v', "1"));

        encodings.insert( std::make_pair('c', "2"));
        encodings.insert( std::make_pair('g', "2"));
        encodings.insert( std::make_pair('j', "2"));
        encodings.insert( std::make_pair('k', "2"));
        encodings.insert( std::make_pair('q', "2"));
        encodings.insert( std::make_pair('s', "2"));
        encodings.insert( std::make_pair('x', "2"));
        encodings.insert( std::make_pair('z', "2"));

        encodings.insert( std::make_pair('d', "3"));
        encodings.insert( std::make_pair('t', "3"));

        encodings.insert( std::make_pair('l', "4"));

        encodings.insert( std::make_pair('m', "5"));
        encodings.insert( std::make_pair('n', "3"));

        encodings.insert( std::make_pair('r', "6"));


        auto it = encodings.find( letter );
        return it == encodings.end() ? "" : it->second;
#endif
    }

    std::string zero_Padding(const std::string& word) const
    {
        auto zero_needed = kMaxCodeLength - word.length();
        return word + std::string( zero_needed , '0' );
    }
};

} //namespace soundex
#endif //_SOUNDEX_H_
