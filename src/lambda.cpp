#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    std::vector<int> nums1 = {1, 4, 2, 8, 5, 7};

    std::sort(nums1.begin(), nums1.end(), [](int a, int b) {
        // 偶数优先逻辑
        if (a % 2 == 0 && b % 2 != 0)
            return true;
        if (a % 2 != 0 && b % 2 == 0)
            return false;
        return a > b; // 否则按大小排
    });

    for (auto it = nums1.begin(); it != nums1.end(); ++it) {
        std::cout << *it << "  ";
    }
    std::cout << "\n";

    std::vector<int> nums2 = {1, 2, 3, 4, 5, 6};
    int threshold = 3;
    int count = std::count_if(nums2.begin(), nums2.end(), [threshold](int a) {
        return (a > threshold) && (a % 2 == 0);
    });
    std::cout << "count = " << count << std::endl;
  return 0;
}
