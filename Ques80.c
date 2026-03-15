#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temp) {
    int n = temp.size();
    vector<int> ans(n, 0);
    stack<int> st; // stores indices

    for (int i = 0; i < n; i++) {

        while (!st.empty() && temp[i] > temp[st.top()]) {
            int prev = st.top();
            st.pop();
            ans[prev] = i - prev;
        }

        st.push(i);
    }

    return ans;
}

int main() {
    vector<int> temperatures = {73,74,75,71,69,72,76,73};

    vector<int> result = dailyTemperatures(temperatures);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}