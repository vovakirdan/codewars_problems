#include <stddef.h>
#include <stdio.h>

int maxSequence(const int *arr, size_t n) {
    int max_so_far = 0;
    int max_ending_here = 0;

    for (int i = 0; i < n; i++) {
        max_ending_here += arr[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }

    return max_so_far;
}