#include <stdio.h>

#define MAX 1000

struct MedianFinder {
    int maxHeap[MAX];
    int minHeap[MAX];
    int maxSize;
    int minSize;
};

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapifyUp(struct MedianFinder *mf, int i) {
    while (i > 0 && mf->maxHeap[(i - 1) / 2] < mf->maxHeap[i]) {
        swap(&mf->maxHeap[(i - 1) / 2], &mf->maxHeap[i]);
        i = (i - 1) / 2;
    }
}

void maxHeapifyDown(struct MedianFinder *mf, int i) {
    while (1) {
        int largest = i;
        int l = 2 * i + 1, r = 2 * i + 2;

        if (l < mf->maxSize && mf->maxHeap[l] > mf->maxHeap[largest]) largest = l;
        if (r < mf->maxSize && mf->maxHeap[r] > mf->maxHeap[largest]) largest = r;

        if (largest == i) break;

        swap(&mf->maxHeap[i], &mf->maxHeap[largest]);
        i = largest;
    }
}

void minHeapifyUp(struct MedianFinder *mf, int i) {
    while (i > 0 && mf->minHeap[(i - 1) / 2] > mf->minHeap[i]) {
        swap(&mf->minHeap[(i - 1) / 2], &mf->minHeap[i]);
        i = (i - 1) / 2;
    }
}

void minHeapifyDown(struct MedianFinder *mf, int i) {
    while (1) {
        int smallest = i;
        int l = 2 * i + 1, r = 2 * i + 2;

        if (l < mf->minSize && mf->minHeap[l] < mf->minHeap[smallest]) smallest = l;
        if (r < mf->minSize && mf->minHeap[r] < mf->minHeap[smallest]) smallest = r;

        if (smallest == i) break;

        swap(&mf->minHeap[i], &mf->minHeap[smallest]);
        i = smallest;
    }
}

void pushMax(struct MedianFinder *mf, int val) {
    mf->maxHeap[mf->maxSize] = val;
    mf->maxSize++;
    maxHeapifyUp(mf, mf->maxSize - 1);
}

void pushMin(struct MedianFinder *mf, int val) {
    mf->minHeap[mf->minSize] = val;
    mf->minSize++;
    minHeapifyUp(mf, mf->minSize - 1);
}

int popMax(struct MedianFinder *mf) {
    int val = mf->maxHeap[0];
    mf->maxHeap[0] = mf->maxHeap[mf->maxSize - 1];
    mf->maxSize--;
    maxHeapifyDown(mf, 0);
    return val;
}

int popMin(struct MedianFinder *mf) {
    int val = mf->minHeap[0];
    mf->minHeap[0] = mf->minHeap[mf->minSize - 1];
    mf->minSize--;
    minHeapifyDown(mf, 0);
    return val;
}

void init(struct MedianFinder *mf) {
    mf->maxSize = 0;
    mf->minSize = 0;
}

void addNum(struct MedianFinder *mf, int num) {
    if (mf->maxSize == 0 || num <= mf->maxHeap[0]) {
        pushMax(mf, num);
    } else {
        pushMin(mf, num);
    }

    if (mf->maxSize > mf->minSize + 1) {
        pushMin(mf, popMax(mf));
    } else if (mf->minSize > mf->maxSize) {
        pushMax(mf, popMin(mf));
    }
}

double findMedian(struct MedianFinder *mf) {
    if (mf->maxSize > mf->minSize) {
        return mf->maxHeap[0];
    }
    return (mf->maxHeap[0] + mf->minHeap[0]) / 2.0;
}

int main() {
    struct MedianFinder mf;
    init(&mf);

    addNum(&mf, 2);
    addNum(&mf, 3);
    printf("%.1f\n", findMedian(&mf));

    addNum(&mf, 4);
    printf("%.1f\n", findMedian(&mf));

    return 0;
}