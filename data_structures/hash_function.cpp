class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        long sum = 0;
        for (int i = 0; i < key.length(); i++) {
            sum = sum*33 + (int)key[i];
            sum = sum % HASH_SIZE;
        }
        return sum;
    }
};
