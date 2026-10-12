class Solution{
    public:
        int subarraysWithXorK(vector<int> &nums, int k) {
            int xr = 0;
            map<int, int> hash;
    
            hash[xr]++;  // {0, 1}
            int cnt = 0;
    
            for (int i = 0; i < a.size(); i++)
            {
                xr = xr ^ a[i];
                int x = xr ^ k;
    
                cnt += hash[x];
                hash[xr]++;
            }
    
            return cnt;
        }
    };