#include <iostream>
#include <queue>
using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    // Constructor
    KthLargest(int k, int nums[], int n) {
        this->k = k;

        for (int i = 0; i < n; i++) {
            minHeap.push(nums[i]);

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    // Add new value
    int add(int val) {
        minHeap.push(val);

        if (minHeap.size() > k) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};

int main() {
    int nums[] = {4, 5, 8, 2};
    int n = 4;

    KthLargest obj(3, nums, n);

    cout << obj.add(3) << endl;  // 4
    cout << obj.add(5) << endl;  // 5
    cout << obj.add(10) << endl; // 5
    cout << obj.add(9) << endl;  // 8
    cout << obj.add(4) << endl;  // 8

    return 0;
}