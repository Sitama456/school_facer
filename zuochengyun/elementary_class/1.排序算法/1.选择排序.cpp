
#include <vector>
#include <unistd.h>
using namespace std;
void selectSort(vector<int>& nums) {
    int size = nums.size();
    if (size < 2) {
        return;
    }
    int min = 0;
    for (size_t i = 0; i < size - 1; ++i) {
        min = i;
        for (size_t j = i + 1; j < size; ++j) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        swap(nums[i], nums[min]);
    }
}