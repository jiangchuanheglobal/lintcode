class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        // wirte your code here
        string int_part = getIntegerPart(n);
        string frac_part = getFractionPart(n);
        
        if (frac_part.length() == 0) {
            return "";
        }

        string f_s = fractionConvertToBinary(frac_part);
        if (f_s.compare("ERROR") == 0) {
            return "ERROR";
        } else {
            string i_s = IntegerConvertToBinary(int_part);
            if (f_s.length() == 0) {
                return i_s;
            } else {
                return i_s + "." + f_s;
            }
        }
    }
    
    
    string getIntegerPart(string n) {
        int i = 0;
        while (i < n.length() && n[i] != '.') {
            i += 1;
        }
        return n.substr(0, i);
    }
    string getFractionPart(string n) {
        int i = n.length() - 1;
        while (i >= 0 && n[i] != '.') {
            i -= 1;
        }
        if (i >= 0) {
            return n.substr(i + 1, n.length() - i - 1);
        } else {
            return "";
        }
    }
    string IntegerConvertToBinary(string n) {
        std::string::size_type sz;

        long num = std::stol (n, &sz);
        
        vector<int> shifts;
        while (num > 0) {
            int shift = 0;
            while (num >= (1 << shift)) {
                shift += 1;
            }
            shift -= 1;
            
            shifts.push_back(shift);
            num -= (1 << shift);
        }
        
        if (shifts.size() == 0) {
            return "0";
        } else {
            string ans;
            ans.resize(shifts[0] + 1, '0');
            
            for (auto& i : shifts) {
                ans[shifts[0] - i] = '1';
            }
            return ans;
        }
    }
    
    string fractionConvertToBinary(string n) {
        if (n.length() == 0) return "";
        
        string f = "0." + n;
        std::string::size_type sz;
        double num = std::stod (f, &sz);
        
        int i = 0;
        string ans = "";
        while (i < 32 && num != 0.0) {
            num = num * 2;
            if (num >= 1.0) {
                ans.push_back('1');
            } else {
                ans.push_back('0');
            }
            if (num >= 1.0) {
                num -= 1.0;
            }
            i += 1;
        }
        if (i < 32) {
            return ans;
        } else {
            return "ERROR";
        }
    }
};

