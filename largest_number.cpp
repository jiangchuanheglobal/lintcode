
struct {
  bool operator()(int a, int b) {
      string s_a = std::to_string(a);
      string s_b = std::to_string(b);
      string com1 = s_a + s_b;
      string com2 = s_b + s_a;
      int n1 = atoi(com1.c_str());
      int n2 = atoi(com2.c_str());
      return n1 > n2;
  }
}MyComparator;

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        // write your code here
        std::sort(num.begin(), num.end(), MyComparator);
        
        string ans = "";
        for (auto& n : num) {
            ans = ans + std::to_string(n);
        }
        
        if (atoi(ans.c_str()) == 0) {
            return string("0");
        } else {
            return ans;
        }
    }
    
};
