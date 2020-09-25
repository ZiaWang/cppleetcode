#include <iostream>
#include <vector>
#include <map>

using namespace std;


/*
 * 给定一个整数数组 nums和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
 * 示例:
 *      给定 nums = [2, 7, 11, 15], target = 9
 *      因为 nums[0] + nums[1] = 2 + 7 = 9
 *      所以返回 [0, 1]
 *      来源：力扣（LeetCode）
 *      链接：https://leetcode-cn.com/problems/two-sum
 */

class Solution {
public:
    static vector<int> two_sum(vector<int>& nums, int target){
        vector<int> ret;

        map<int, int> val_to_idx;
        for(int i=0; i<nums.size();i++)
        {
            val_to_idx[nums[i]] = i;
        }

        int target_val;
        int idx;
        for(int i=0; i<nums.size();i++)
        {
            target_val = target - nums[i];

            try
            {
                idx = val_to_idx.at(target_val);

                if (i != idx)
                {
                    ret.push_back(i);
                    ret.push_back(idx);
                    break;
                }
            }
            catch (out_of_range &e)
            {
                continue;
            }
        }

        return ret;
    }
};


void test(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ret = Solution::two_sum(nums, target);
    std::cout << ret[0] << ", " << ret[1] << std::endl;
}


int main() {
    test();
    return 0;
}
