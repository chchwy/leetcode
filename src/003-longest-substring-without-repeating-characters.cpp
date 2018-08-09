#include <vector>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::vector< int > kCountMap( 256 );
        int start = 0, end = 1;
        
        if ( s.size() == 0 ) { return 0; }
        if ( s.size() == 1 ) { return 1; }
        
        kCountMap[ s[0] ] = 1;
        
        int maxLen = 1;
        while( end < s.size() )
        {
            if ( kCountMap[ s[end] ] > 0 ) // find duplicated char
            {
                for ( int i = start; i < end; ++i )
                {
                    if ( s[i] == s[end] )
                    {
                        start = i + 1;   
                        break;
                    }
                    kCountMap[ s[ i ] ] = 0;    
                }
            }
            else
            {
                int curLen = end - start + 1;
                maxLen = ( curLen > maxLen ) ? curLen : maxLen;
                
                kCountMap[ s[end] ] = 1;
            }
            
            end++;
        }
        return maxLen;
    }
};