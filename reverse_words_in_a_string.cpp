class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        vector<string> tokens = split(s);
        std::reverse(tokens.begin(), tokens.end());
        
        string ans = "";
        for (int i = 0; i < tokens.size(); i++) {
            if (i == 0) {
                ans = tokens[i];
            } else {
                ans = ans + " " + tokens[i];
            }
        }
        return ans;
    }
    
    vector<string> split(string str) {
        string buf; // Have a buffer string
        stringstream ss(str); // Insert the string into a stream
        vector<string> tokens; // Create vector to hold our words

        while (ss >> buf) {
            tokens.push_back(buf);
        }
        return tokens;
    }
};
