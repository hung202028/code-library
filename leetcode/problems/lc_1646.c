// https://leetcode.com/problems/get-maximum-in-generated-array/

#include <stdio.h>

int solve(int n)
{
    int arr[100];
    arr[0] = 0;
    arr[1] = 1;
    int max = 1;

    for (int i = 2; i <= n; ++i) {
        if (i % 2 == 0) {
            arr[i] = arr[i / 2];
        } else {
            arr[i] = arr[i / 2] + arr[(i / 2) + 1];
        }

        int arr_i = arr[i];
        if (arr_i > max) {
            max = arr_i;
        }
    }

    return max;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}