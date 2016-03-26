class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        string ans = A;
        while (k > 0) {
            ans = remove(ans);
            k -= 1;
        }
        
        // if (ans.length() > 0 && atoi(ans.c_str()) == 0) {
        //   return string("0");
        // } else {
        //   return removeLeadingZeros(ans);
        // }
        return removeLeadingZeros(ans);
    }
    
    string remove(string str) {
        if (str.size() <= 1) { return "";}
        
        int i = 0;
        while (i < str.size() - 1 && str[i] <= str[i+1]) {
            i += 1;
        }
        return str.substr(0, i) + str.substr(i + 1, str.length() - i - 1);
    }
    
     string removeLeadingZeros(string& str) {
      int i = 0;
      while (i < str.length() && str[i] == '0') {
        i += 1;
      }
      return str.substr(i, str.length() - i + 1);
    }

};
