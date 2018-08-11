/*
找出最長的不包含重複字母的子字串
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3.
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include <vector>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s)
    {
        // start to end 表示目前檢查的字串區間
        int start = 0, end = 1;

        // countMap 則是
        std::vector<int> countMap(256);
        
        if (s.size() == 0) { return 0; }
        if (s.size() == 1) { return 1; }
        
        countMap[ s[0] ] = 1;
        
        int maxLen = 1;
        while (end < s.size())
        {
            if (countMap[ s[end] ] > 0) // find duplicated char
            {
                for (int i = start; i < end; ++i)
                {
                    if (s[i] == s[end])
                    {
                        start = i + 1;   
                        break;
                    }
                    countMap[ s[i] ] = 0;    
                }
            }
            else
            {
                int curLen = end - start + 1;
                maxLen = (curLen > maxLen) ? curLen : maxLen;
                
                countMap[ s[end] ] = 1;
            }
            end++;
        }
        return maxLen;
    }
};