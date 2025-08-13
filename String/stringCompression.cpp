// Leetcode q no. - 443 (String Compression)

// 1st Approach - Two pointer Approach
class Solution {
public:
    int compress(vector<char>& chars) {         // T.C. - O(n)  & S.C. - O(1)
        int ans = 0;
        int i = 0;
        while (i < chars.size()) {
            char letter = chars[i];
            int count = 0;
            while (i < chars.size() && chars[i] == letter) {
                count++;
                i++;
            }
            chars[ans++] = letter;
            if (count > 1) {
                for (char ch : to_string(count)) {
                    chars[ans++] = ch;
                }
            }
        }
        return ans;
    }
};