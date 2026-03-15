#include <iostream>
using namespace std;

#define MAX 100

class Deque {
    int arr[MAX];
    int front, rear, size;

public:
    Deque() {
        front = -1;
        rear = -1;
        size = 0;
    }

    // Check empty
    bool empty() {
        return (size == 0);
    }

    // Get size
    int getSize() {
        return size;
    }

    // Push front
    void push_front(int x) {
        if (size == MAX) {
            cout << "Overflow\n";
            return;
        }

        if (empty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1;
        } else {
            front--;
        }

        arr[front] = x;
        size++;
    }

    // Push back
    void push_back(int x) {
        if (size == MAX) {
            cout << "Overflow\n";
            return;
        }

        if (empty()) {
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = x;
        size++;
    }

    // Pop front
    void pop_front() {
        if (empty()) {
            cout << "Underflow\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }

        size--;
    }

    // Pop back
    void pop_back() {
        if (empty()) {
            cout << "Underflow\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1;
        } else {
            rear--;
        }

        size--;
    }

    // Front element
    int getFront() {
        if (empty()) return -1;
        return arr[front];
    }

    // Back element
    int getBack() {
        if (empty()) return -1;
        return arr[rear];
    }

    // Clear deque
    void clear() {
        front = rear = -1;
        size = 0;
    }

    // Display
    void display() {
        if (empty()) {
            cout << "Deque is empty\n";
            return;
        }

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;

    dq.push_back(10);
    dq.push_front(5);
    dq.push_back(20);

    dq.display();          // 5 10 20
    cout << dq.getFront() << endl; // 5
    cout << dq.getBack() << endl;  // 20

    dq.pop_front();
    dq.display();          // 10 20

    dq.pop_back();
    dq.display();          // 10

    cout << dq.getSize() << endl;  // 1

    dq.clear();
    dq.display();          // empty

    return 0;
}