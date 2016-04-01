class Solution {
public:
    /**
     * param n: As description.
     * return: A list of strings.
     */
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        int i = 1;
       
        while (i <= n) {
           if (i % 3 == 0 && i % 5 == 0) {
               ans.push_back("fizz buzz");
           } else if (i % 3 == 0) {
               ans.push_back("fizz");
           } else if (i % 5 == 0) {
               ans.push_back("buzz");
           } else {
               ans.push_back(std::to_string(i));
           }
           i += 1;
        }
       
        return ans;
    }
};
