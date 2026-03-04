#include <stdio.h>
#include <limits.h>

int main() {
    int n, num;
    int min_val = INT_MAX;
    int max_val = INT_MIN;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &num) != 1) break;

        if (num < min_val) min_val = num;
        if (num > max_val) max_val = num;
    }

    printf("%d\n", min_val);
    printf("%d\n", max_val);

    return 0;
}