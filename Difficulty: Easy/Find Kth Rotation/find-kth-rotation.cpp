#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int start = 0;
        int end = arr.size() - 1;

        int index = 0;
        int mini = INT_MAX;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // If the current search space is completely sorted
            if (arr[start] <= arr[end]) {
                if (arr[start] < mini) {
                    mini = arr[start];
                    index = start;
                }
                break;
            }

            // If left side is sorted
            if (arr[start] <= arr[mid]) {
                if (arr[start] < mini) {
                    mini = arr[start];
                    index = start;
                }
                start = mid + 1;

            } else { // If right side is sorted
                if (arr[mid] < mini) {
                    mini = arr[mid];
                    index = mid;
                }
                end = mid - 1;
            }
        }

        return index;
    }
}; // Don't forget this closing brace and semicolon!