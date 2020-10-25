//
// Created by liyang on 2020/10/25.
//

int longestMountain(int* A, int ASize){
    if (ASize < 3)
        return 0;

    int left[ASize];
    int right[ASize];

    left[0] = 0;
    for (int i = 1; i < ASize; ++i) {
        if (A[i] <= A[i - 1])
            left[i] = 0;
        else
            left[i] = left[i - 1] + 1;
    }

    right[ASize - 1] = 0;
    for (int i = ASize - 2; i >= 0; --i) {
        if (A[i] <= A[i + 1])
            right[i] = 0;
        else
            right[i] = right[i + 1] + 1;
    }

    int max_ridge_len = 0;
    for (int i = 1; i < ASize - 1; ++i) {
        int ridge_len = 0;
        if (left[i] > 0 && right[i] > 0)
            ridge_len = left[i] + right[i] + 1;
        if (ridge_len > max_ridge_len)
            max_ridge_len = ridge_len;
    }

    return max_ridge_len;
}