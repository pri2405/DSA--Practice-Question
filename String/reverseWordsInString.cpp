// Leetcode q no. - 151

// 1st Approach 
class Solution {
public:
    string reverseWords(string s) {   // T.C. - O(n)
        string ans = "";
        string word = "";
        for(int i=0; i<s.length(); i++) {
            if(s[i] != ' ') word += s[i];
            else {
                if(ans == "") ans += word;
                else {
                    if(word != "") ans = word + " " + ans;
                }
                word = "";
            }

            if(i == s.length() - 1 && word != "") {
                if(ans == "") ans += word;
                else ans = word + " " + ans;
            }
        }
        return ans;
    }
};

// 2nd Approach
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while(ss >> word) {
            words.push_back(word);
        }
        string ans = "";
        for(int i=words.size()-1; i>=0; i--) {
            if(i != words.size() - 1) ans += " ";
            
            ans += words[i];
        }
        return ans;
    }
};

// 3rd Approach
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans = "";
        while(ss >> word) {
            if(ans == "") ans += word;
            else ans = word + " " + ans;
        }
        
        return ans;
    }
};

// 4th Approach
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string ans = "";
        
        for(int i = 0 ; i < s.length() ; i++){
            string word = "";
            while(i < s.length() && s[i] !=' '){
                word += s[i] ;
                i++;
            }
            reverse(word.begin(),word.end());
            if(word.length()>0){
                if(ans != "") ans += " ";
                ans += word;
            }
        }
        return ans;
    }
};