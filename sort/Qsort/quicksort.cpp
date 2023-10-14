#include "quicksort.h"

void swap(int *a, int *b) {
    int tem = *a;
    *a = *b;
    *b = tem;
}

void BubbleSort(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        int flag = 0;
        for (int j = 1; j < n - i; ++j) {
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
}

int getMid(int *a, int left, int right) {
    int mid = (left + right) >> 1;
    if (a[left] < a[mid]) {
        if (a[left] > a[right]) {
            return left;
        } else if (a[mid] < a[right]) {
            return mid;
        } else {
            return right;
        }
    } else // a[left] >= a[mid]
    {
        if (a[mid] < a[right]) {
            return right;
        } else if (a[left] < a[right]) {
            return left;
        } else {
            return mid;
        }
    }
}

int PartSort1(int *a, int left, int right) {
    int index = getMid(a, left, right);

    swap(&a[left], &a[index]);

    int key = left;

    while (left < right) {
        while (left < right && a[right] >= a[key]) {
            --right;
        }

        while (left < right && a[left] <= a[key]) {
            ++left;
        }

        swap(&a[left], &a[right]);
    }
    swap(&a[left], &a[key]);
    return left;
}

int PartSort2(int *a, int left, int right) {
    int index = getMid(a, left, right);

    swap(&a[left], &a[index]);

    int key = a[left];

    while (left < right) {
        while (left < right && a[right] >= key) {
            --right;
        }

        a[left] = a[right];

        while (left < right && a[left] <= key) {
            ++left;
        }
        a[right] = a[left];
    }

    a[left] = key;
    return left;
}

int PartSort3(int *a, int left, int right) {
    int index = getMid(a, left, right);

    swap(&a[left], &a[index]);

    int keyi = left;

    int cur = left + 1;
    int prev = left;

    while (cur <= right) {
        if (a[cur] < a[keyi] && ++prev != cur)
            swap(&a[cur], &a[prev]);

        ++cur;
    }

    swap(&a[prev], &a[keyi]);
    return prev;
}

void QuickSort(int *a, int left, int right) {
    if (left > right)
        return;

    int keyi = PartSort3(a, left, right);

    QuickSort(a, left, keyi - 1);
    QuickSort(a, keyi + 1, right);
}

void QuickSortNonR(int *a, int left, int right) {
    std::stack<int> stk;
    stk.push(right);
    stk.push(left);

    while (!stk.empty()) {
        int lf = stk.top();
        stk.pop();
        int rg = stk.top();
        stk.pop();

        int keyi = PartSort3(a, lf, rg);

        if (keyi + 1 < right) {
            stk.push(keyi + 1);
            stk.push(rg);
        }

        if (left < keyi - 1) {
            stk.push(keyi - 1);
            stk.push(lf);
        }
    }
}
