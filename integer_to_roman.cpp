class Solution {
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        // Write your code here
        map<int, string, std::greater<int> > translateTable = 
        {
          {1000, "M"},
          {900, "CM"},
          {500, "D"},
          {400, "CD"},
          {100, "C"},
          {90, "XC"},
          {50, "L"},
          {40, "XL"},
          {10, "X"},
          {9, "IX"},
          {5, "V"},
          {4, "IV"},
          {1, "I"}
        };
        
        string roman = "";
        for (auto& i : translateTable) {
            int num = n / i.first;
            while (num) {
                roman += i.second;
                num -= 1;
            }
            n = n % i.first;
        }
        
        return roman;
    }
};
