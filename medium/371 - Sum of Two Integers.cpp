// O(1)
class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            // calculate the carry
            int t = (unsigned int)(a & b) << 1;
            // add the numbers without the carry
            a = a ^ b;
            // set one of the numbers to the carry
            b = t;
        }
        return a;
    }
};