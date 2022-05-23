#include"global.h"

class Solution {
public:
    int index = -1;
    int search(vector<int>& nums, int target) {
        binarymath(nums, target, 0, nums.size() - 1);
        return index;
    }
    void binarymath(vector<int>& nums, int target, int min, int max)
    {
        if (max < min)
            return;
        int mid = (max + min) / 2;
        if (nums[mid] == target)
        {
            index = mid;
            return;
        }
        //˵���м��ڵ��򲿷�
        if (nums[mid] >= nums[min] && nums[mid] > nums[max])
        {
            //��߲����������ֲ���
            if (target < nums[mid] && target >= nums[min])
                binarymath(nums, target, min, mid - 1);
            //�ұ߲���ֱ�ӵݹ�
            binarymath(nums, target, mid+1, max);
        }
        //˵���м䲻�ڵ��򲿷�
        else
        {
            //�ұ߲����������ֲ���
            if (target > nums[mid] && target <= nums[max])
                binarymath(nums, target, mid + 1, max);
            //��߲��ֵݹ�
            binarymath(nums, target, min, mid - 1);
        }

    }
};

int main()
{
    vector<int> nums = { 3,1 };
    int target = 1;
    Solution().search(nums, target);
}