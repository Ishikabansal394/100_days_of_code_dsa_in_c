#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;

    // Step 1: count frequency
    for (int x : nums) {
        freq[x]++;
    }

    // Min heap (pair: freq, element)
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > minHeap;

    // Step 2: push into heap
    for (auto it : freq) {
        minHeap.push({it.second, it.first});

        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // Step 3: extract result
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return result;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    vector<int> ans = topKFrequent(nums, k);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}