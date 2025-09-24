#include <bits/stdc++.h>
using namespace std;

class SpecialQueue {
    queue<int> q1;   // normal queue
    deque<int> q2;   // monotonic queue for min
    deque<int> q3;   // monotonic queue for max

public:
    // Insert element into the queue
    void enqueue(int x) {
        q1.push(x);

        // maintain increasing order for min
        while (!q2.empty() && q2.back() > x) {
            q2.pop_back();
        }
        q2.push_back(x);

        // maintain decreasing order for max
        while (!q3.empty() && q3.back() < x) {
            q3.pop_back();
        }
        q3.push_back(x);
    }

    // Remove element from the queue
    void dequeue() {
        if (q1.empty()) {
            cout << "Queue is empty\n";
            return;
        }

        int frontVal = q1.front();
        if (!q2.empty() && frontVal == q2.front()) {
            q2.pop_front();
        }
        if (!q3.empty() && frontVal == q3.front()) {
            q3.pop_front();
        }
        q1.pop();
    }

    // Get minimum element
    int getMin() {
        if (q1.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return q2.front();
    }

    // Get maximum element
    int getMax() {
        if (q1.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return q3.front();
    }

    // Get front element
    int getFront() {
        if (q1.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return q1.front();
    }
};
