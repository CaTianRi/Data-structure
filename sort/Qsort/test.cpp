#include "quicksort.h"

void test() {
    int a[] = {0, 9, 8, 7, 6, 5, 3, 4, 2, 1, 12, 15};
    QuickSortNonR(a, 0, sizeof(a) / sizeof(int)-1);

    for (int i = 0; i < 12; ++i)
        printf("%d ", a[i]);
}

int main() {
    test();
    return 0;
}
