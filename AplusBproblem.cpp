class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        int sum = 0;
        int carry = 0;
        while (true) {
            sum = a ^ b;
            carry = a & b;
            carry = carry << 1;
            if (carry == 0) {
                break;
            }
            a = sum;
            b = carry;
        }
        return sum;
    }
};


// 0x 11
// 0x 11
// ----------
// 0x110
//       sum = 00
//       carry = 110
//       sum = 110

///    0 x 101
//     0 x 111
// ------------
// 0 x 1100

// sum =    010
// // carry =  101

// carry = 1010

// sum =    1000
// // carry = 010

// carry = 0100
// sum = 1100

// 0
// 0
// -
// 0

// 0
// 1
// -
// 1

// 1
// 0
// -
// 1

// 1
// 1
// -
// 0

// xor 

// 1&1 = 1

// carry << 1
