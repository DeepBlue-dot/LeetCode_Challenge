# 1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 
# Soluiton
In order to solve this problem i use a hash table to store each element of the array along with its index. while creating the hash table i calulated the complement of each element and checked if it already exists in the hash table.If the complement exists, it means we have found the pair that sums up to the target, and we return their indices.

## Complexity Analysis:
### Time Complexity: O(n)
We traverse the array once, and for each element, we perform constant time operations (lookup in the hash table).

### Space Complexity: O(n)
We use a hash table to store each element of the array along with its index. In the worst case, we may need to store all elements of the array.