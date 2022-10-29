/*2443. Sum of Number and Its Reverse*/

/*Given a non-negative integer num, return true if num can be expressed as the sum of any non-negative integer and its reverse, or false otherwise.
 */

// Test cases
/*
1.)
Input: num = 443
Output: true
2.)
Input: num = 63
Output: false
3.)
Input: num = 181
Output: true
*/
class Solution
{
public:
    int rev(int d)
    {
        int c = 0;
        while (d != 0)
        {
            int l = d % 10;
            c = c * 10 + l;
            d /= 10;
        }
        return c;
    }
    bool sumOfNumberAndReverse(int num)
    {
        for (int i = 0; i <= num; i++)
        {
            if (i + rev(i) == num)
                return true;
        }
        return false;
    }
};