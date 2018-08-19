/*
找出最長的不包含重複字母的子字串
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3.
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include <iostream>
#include <vector>
#include <string>

int max(int a, int b) {
    return (a > b) ? a : b;
}

class Solution {
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::vector<int> dict(256, -1); // dict: 該字母上次出現的位置
        int maxLen = 0;
        int start = -1;

        for (int i = 0; i != s.length(); i++)
        {
            char c = s[i];
            if (dict[c] > start)
                start = dict[c]; // start 最近一次重複字母出現的位置

            dict[c] = i;

            // 概念就是: 長度就是目前字母a跟上一次字母a出現地方的差
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};

#ifdef LEETCODE_003
int main()
{
    Solution sln;
    std::cout << sln.lengthOfLongestSubstring("abcabcd");
}
#endif