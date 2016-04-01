class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        //wirte your code here
        int n = str.length();
        if (n < 2) return;
        
        offset = offset % n; // [0, n - 1]
        
        string p1 = str.substr(0, n - offset);
        string p2 = str.substr(n - offset, offset);
        
        str = p2 + p1;
    }
};
