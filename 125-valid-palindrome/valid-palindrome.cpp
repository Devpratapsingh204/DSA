class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned = "";

        // keep only letters/numbers
        for(char ch : s) {
            if(isalnum(ch)) {
                cleaned += tolower(ch);
            }
        }

        string reversed = cleaned;
        reverse(reversed.begin(), reversed.end());

        if(cleaned == reversed)
            return true;
        else
            return false;
    }
};