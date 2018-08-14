
/**
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
Input: 121  Output: true
Input: -121 Output: false
Input: 10   Output: false
*/
class Solution {
public:
    bool isPalindrome(int x) {
        std::stringstream sin;
        sin << x;
        
        std::string s = sin.str();
        
        int half_size = (s.size() / 2) + 1;
        for (int i = 0; i < half_size; ++i) {
            int i2 = s.size() - i - 1;
            if (s[i] != s[i2])
                return false;
        }
        
        return true;
    }
};