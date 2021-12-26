#include"global.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int>result(nums.size(), 0); //�洢��
        vector<int>T_result(nums.size(), 0); //�洢����
        result[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            //����Ȩֵ����
            result[i] = max(result[i - 1] * nums[i], nums[i]);
            result[i] = max(result[i], T_result[i - 1] * nums[i]);

            //�Ը�Ȩֵ����
            T_result[i] = min(result[i - 1] * nums[i], nums[i]);
            T_result[i] = min(T_result[i], T_result[i-1] * nums[i]);
        }
        return *max_element(result.begin(), result.end());
    }
};

int main()
{
    vector<int> test = { 2,3,-2,4 ,-2};
    Solution().maxProduct(test);
}