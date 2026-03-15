#include <iostream>
using namespace std;

class MyCircularDeque {
    int *arr;
    int front, rear, size;

public:
    MyCircularDeque(int k) {
        size = k;
        arr = new int[k];
        front = -1;
        rear = -1;
    }

    // Insert at front
    bool insertFront(int value) {
        if (isFull()) return false;

        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front--;
        }

        arr[front] = value;
        return true;
    }

    // Insert at rear
    bool insertLast(int value) {
        if (isFull()) return false;

        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = value;
        return true;
    }

    // Delete from front
    bool deleteFront() {
        if (isEmpty()) return false;

        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }

        return true;
    }

    // Delete from rear
    bool deleteLast() {
        if (isEmpty()) return false;

        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }

        return true;
    }

    // Get front
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    // Get rear
    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    // Check empty
    bool isEmpty() {
        return front == -1;
    }

    // Check full
    bool isFull() {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }
};

int main() {
    MyCircularDeque dq(5);

    dq.insertLast(10);
    dq.insertLast(20);
    dq.insertFront(5);

    cout << dq.getFront() << endl; // 5
    cout << dq.getRear() << endl;  // 20

    dq.deleteFront();
    cout << dq.getFront() << endl; // 10

    return 0;
}