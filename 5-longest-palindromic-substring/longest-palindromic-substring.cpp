class Solution {
public:
    string longestPalindrome(string s) {
        int maxi = 0;
        string ans = "";

        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {

                int left = i;
                int right = j;
                bool palindrome = true;

                while(left < right) {
                    if(s[left] != s[right]) {
                        palindrome = false;
                        break;
                    }
                    left++;
                    right--;
                }

                if(palindrome) {
                    int len = j - i + 1;

                    if(len > maxi) {
                        maxi = len;
                        ans = s.substr(i, len);
                    }
                }
            }
        }

        return ans;
    }
};