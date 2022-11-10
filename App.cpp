#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // result to be returned
        vector<string> list;

        // size of nums
        int size_of_nums = nums.size();

        // iterate through vector
        for (int i = 0; i < size_of_nums; i++) {

            // start of the range
            int start = nums[i];

            // checking to make sure there is a next element / number available
            // and
            // checking if the next element is a continuation of our range
            while (i + 1 < size_of_nums && nums[i + 1] == nums[i] + 1) {
                // increment i
                i++;
            }

            // if there are multiple numbers within our range
            if (start != nums[i]) {

                // add to range vector
                list.push_back("" + std::to_string(start) + "->" + std::to_string(nums[i]));
            }

            // if there is just a single number for the range
            else {
                // add to range vector
                list.push_back("" + std::to_string(start));
            }
        }

        // return ranges
        return list;
    }
};
int main()
{
    Solution solution;
    vector<int> example_one = { 0, 1, 2, 4, 5, 7 };
    vector<string> answer = solution.summaryRanges(example_one);

    cout << "Example One: ";

    for (string s : answer) {
        cout << s + " ";
    }

	return 0;
}
