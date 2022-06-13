// 125. Valid Palindrome
// String
#include <ctype.h>
#include <string>
#include <iostream>
using std::string;

class Solution {
public:

	bool isAlphanumeric(char c) {
		if (c >= 'A' && c <= 'Z') {
			return true;
		}
		else if (c >= 'a' && c <= 'z') {
			return true;
		}
		else if (c >= '0' && c <= '9') {
			return true;
		}
		return false;
	}

	bool isPalindrome(string s) {

		int start = 0;
		int end = s.size() - 1;

		while (start < end) {

			while (!isAlphanumeric(s[start]) && start < end)
				start++;

			while (!isAlphanumeric(s[end]) && start < end)
				end--;

			char c1 = tolower(s[start]);
			char c2 = tolower(s[end]);
			if (c1 != c2) {
				return false;
			}

			start++;
			end--;
		}
		return true;

	}
};

int main() {

	Solution sln;
	bool result = sln.isPalindrome("A man, a plan, a canal: Panama");
	std::cout << result;
	return 0;
}
