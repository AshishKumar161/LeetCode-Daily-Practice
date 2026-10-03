class Solution {
    public:
        int countPrimes(int n) {
    
            if (n <= 2) {
                return 0;
            }
    
            vector<bool> prime(n, true);
    
            prime[0] = false;
            prime[1] = false;
    
            for (int i = 4; i < n; i += 2) {
                prime[i] = false;
            }
    
            for (int i = 3; 1LL * i * i < n; i += 2) {
    
                if (prime[i]) {
    
                    for (int j = i * i; j < n; j += 2 * i) {
                        prime[j] = false;
                    }
                }
            }
    
            int count = 1; 
    
            for (int i = 3; i < n; i += 2) {
    
                if (prime[i]) {
                    count++;
                }
            }
    
            return count;
        }
    };