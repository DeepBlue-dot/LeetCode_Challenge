#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map <int, int> indexTonum;
        for (int i = 0; i < nums.size(); i++)
        {
            int diff=target-nums[i];
            if(indexTonum.find(diff) != indexTonum.end())
                return {indexTonum[diff], i};
            indexTonum[nums[i]]=i;
        }
        
    }
};

int main(){
    return 0;
}