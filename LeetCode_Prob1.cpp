/*7. Reverse Integer
Medium

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
Ex1.
Input: x = 123
Output: 321

Ex2. 
Input: x = -123
Output:-321
*/

class Solution {
public:
    int reverse(int x) {

    

        int ans = 0;
        while(x != 0) {
            int digit = x % 10;

            if((ans > INT_MAX/10) || (ans < INT_MIN/10)) {
                return 0;
            }        
            ans = (ans * 10) + digit;
            x = x / 10;
         }
        return ans;
    }
};