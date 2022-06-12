#include <vector>

using namespace std;
void bubbleSort(vector<int>& nums) {
    int size = nums.size();
    if (size < 2) {
        return;
    }
    for (size_t i = size - 1; i > 0; --i) {
        for (size_t j = 1; j <= i; ++j) {
            if (nums[j] < nums[j - 1]) {
                swap(nums[j - 1], nums[j]);
            }
        }
    }
    return;
}