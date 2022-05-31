 // 20. Valid Parentheses
// String, Stack

class Solution {
public:
    bool isOpen(char c) {
        return (c == '(' || c == '{' || c == '[');
    }

    char closeBracket(char c) {
        switch (c) {
        case '(': return ')';
        case '[': return ']';
        case '{': return '}';
        }
        return ' ';
    }

    bool isValid(string s) {

        if (s.empty()) return true;
        if (s.length() == 1) return false;

        std::vector<char> bracketStack{ s[0] };

        for (int i = 1; i < s.length(); ++i) {
            char c = s[i];

            if (isOpen(c)) {
                bracketStack.push_back(c);
            }
            else {
                // c is closed
                if (bracketStack.empty())
                    return false;

                char lastBracket = bracketStack.back();
                if (!isOpen(lastBracket))
                    return false;

                if (closeBracket(lastBracket) != c)
                    return false;

                bracketStack.pop_back();
            }
        }

        return bracketStack.empty();
    }
};
