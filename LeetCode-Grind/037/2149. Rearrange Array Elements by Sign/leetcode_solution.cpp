class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector <int > positive ;
        vector <int > negative ;

        for (int i = 0 ; i < nums.size() ; i++)
        {
            if (nums[i] > 0)
            {
                positive.push_back(nums[i]) ;
            }
            else
            {
                negative.push_back(nums[i]) ;
            }
        }
        vector <int> answer ;
        for (int i = 0 ; i < positive.size() ; i++ )
        {
            answer.push_back(positive[i]) ;
            answer.push_back(negative[i]) ;
        }

        return answer ;
    }
};