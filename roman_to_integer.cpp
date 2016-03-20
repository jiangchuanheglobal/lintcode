class Solution {
public:
    /**
     * @param s Roman representation
     * @return an integer
     */
    int romanToInt(string& s) {
        // Write your code here
        
        map<char, int> translateTable;
        translateTable = 
        {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };    // list initilization
        
        int integer = 0;
        int i = 0; 
        while (i < s.length()) {
            if (canTranslateTwo(i, s, translateTable)) {
                integer += translateTwo(i, s, translateTable);
                i += 2;
            } else {
                integer += translateOne(i, s, translateTable);
                i += 1;
            }
        }
        return integer;
    }
    
    bool canTranslateTwo(int start, string& s, map<char, int>& tbl) {
        if (start == s.length() - 1) {
            return false;
        } else if ( tbl[s[start]] < tbl[s[start + 1]] ) {
            return true;
        } else {
            return false;
        }
    }
    
    int translateOne(int start, string& s, map<char, int>& tbl) {
        return tbl[s[start]];
    }
    
    int translateTwo(int start, string& s, map<char, int>& tbl) {
        return tbl[s[start + 1]] - tbl[s[start]];
    }
};
