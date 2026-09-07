#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSumHash(vector<int>& nums, int target) {
     unordered_map<int, int> index; 
        
    for(int i = 0; i < nums.size(); ++i){
        int needed = target - nums[i];
        if(index.count(needed)){
            return{index[needed], i};
        }
        
        index[nums[i]] = i;
    }
    return {};   
    }

    vector<int> twoSumBrute(vector<int>& nums, int target){
        for(int i = 0; i < nums.size(); i++){ // 
            for(int j = i + 1; j < nums.size(); j++) { 
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};


int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;  
    Solution sol; 
    vector<int> answer = sol.twoSumHash(nums, target); 
    if (!answer.empty()) {
        cout << "Indices: [" << answer[0] << ", " << answer[1] << "]\n";
    } else {
        cout << "No solution\n";
    }
    return 0;
}
