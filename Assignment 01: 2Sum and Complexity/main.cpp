#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
//using hash map to find needed values
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
// brute force: iterate for pairs in array to see if those sums match a target
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

//complexity: 
// hash - time is O(n) because it involves a single loop, and space is O(n) because of hash map storage
// brute force - time is O(n^2) because of the nested loop containing 2 for-loops, and space is O(1) since it does not use any extra space 
// hash is more efficient since you do not have to compare pairs until you find the target 

//test 
int main() {
    // test 1
    vector<int> nums = {2, 7, 11, 15}; //create int vector 
    int target = 9;  //works with index 0,1
    Solution sol; //create object in solution class 
    vector<int> hashanswer1 = sol.twoSumHash(nums, target); //declare int vector for hash answer 
    vector<int> bruteanswer1 = sol.twoSumBrute(nums, target); //declare int vector for brute answer
    if (!hashanswer1.empty()) { //prints out answer through vector indices if there is an answer
        cout << "Hash sol 1 - Indices: [" << hashanswer1[0] << ", " << hashanswer1[1] << "]\n";
    } else {
        cout << "No solution\n"; //prints no solution if there is no solution in hash/brut eanswer
    }
    if (!bruteanswer1.empty()) {
        cout << "Brute sol 1 - Indices: [" << bruteanswer1[0] << ", " << bruteanswer1[1] << "]\n";
    } else {
        cout << "No solution\n";
    }
    cout << "\n";

    
    
    //test 2 
    
    nums = {0, 4, 1, 3}; 
    //both pairs would have sum of 4. test to see it identifies the first pair 
    target = 4;  
    vector<int> hashanswer2 = sol.twoSumHash(nums, target); 
    vector<int> bruteanswer2 = sol.twoSumBrute(nums, target);
    if (!hashanswer2.empty()) {
        cout << "Hash sol 2 - Indices: [" << hashanswer2[0] << ", " << hashanswer2[1] << "]\n";
    } else {
        cout << "No solution\n";
    }
      if (!bruteanswer2.empty()) {
        cout << "Brute sol 2 - Indices: [" << bruteanswer2[0] << ", " << bruteanswer2[1] << "]\n";
    } else {
        cout << "No solution\n";
    }
    cout << "\n";
    
    //test 3 
    nums = {4, 2, 7, 8};
    target = 1;
    //no solution
    vector<int> hashanswer3 = sol.twoSumHash(nums, target); 
    vector<int> bruteanswer3 = sol.twoSumBrute(nums, target);
    if (!hashanswer3.empty()) {
        cout << "Hash sol 2 - Indices: [" << hashanswer3[0] << ", " << hashanswer3[1] << "]\n";
    } else {
        cout << "No solution\n";
    }
      if (!bruteanswer2.empty()) {
        cout << "Brute sol 2 - Indices: [" << bruteanswer3[0] << ", " << bruteanswer3[1] << "]\n";
    } else {
        cout << "No solution\n";
    }
    return 0;

    
    
}
