class Solution {
    public:
        bool isArmstrong(int n) {
            int count = 1;
            int temp = n;
    
            while (temp >= 10) {
                temp = temp / 10;
                count++;
            }
    
            temp = n;
            int sum = 0;
    
            while (temp > 0) {
                int store = temp % 10;
                temp = temp / 10;
    
                sum = sum + pow(store, count);
            }
    
            return sum == n;
        }
    };