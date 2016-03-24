class Solution {
 public:
  /**
   * @param s: A string
   * @param p: A string includes "." and "*"
   * @return: A boolean
   */
  bool isMatch(const char *s, const char *p) {
    // write your code here
    return helper(s, p);
  }

  bool helper(string s, string p) {
    if (s.length() == 0 && p.length() == 0) {
      return true;
    } else if (s.length() > 0 && p.length() == 0) {
      return false;
    } else if (s.length() == 0 && p.length() > 0) {
      if (p.length() == 2 && p[1] == '*') {
        return true;
      } else {
        return false;
      }
    }

    if (p.length() >= 2 && p[1] == '*') {
      return matchHelper(s, p.substr(2, p.length() - 2), p[0]);
    } else {
      if (p[0] == '.') {
        return helper(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1));
      } else {
        return s[0] == p[0] &&
            helper(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1));
      }
    }
  }

  bool matchHelper(string s, string p, char c) {
    if (helper(s, p)) {
      return true;
    } else {
      if (c == '.') {
        int i = 0;
        while ( i < s.length() && !helper(s.substr(i + 1, s.length() - i - 1), p) ) {
          i += 1;
        }
        if (i < s.length()) {
          return true;
        } else {
          return false;
        }
      } else {
        int i = 0;
        while (i < s.length() && !helper(s.substr(i + 1, s.length() - i - 1), p) && c == s[i]) {
          i += 1;
        }
        if (i < s.length() && c == s[i]) {
          return true;
        } else {
          return false;
        }
      }
    }
  }
};
