#include <stdbool.h>
#include <string.h>

int videoStitching(int** clips, int clipsSize, int* clipsColSize, int T){
    int cur_time = 0;
    int cnt = 0;

    bool is_chosen[clipsSize];
    memset(is_chosen, 0, sizeof(is_chosen));


    int available = clipsSize;
    while (available > 0 && cur_time < T) {
        int max = -1;
        int maxi;

        for (int i = 0; i < clipsSize; ++i) {
            if (is_chosen[i])
                continue;

            if (clips[i][0] <= cur_time && clips[i][1] > max) {
                max = clips[i][1];
                maxi = i;
            }
        }


        if (max == -1)
            return -1;

        is_chosen[maxi] = true;
        ++cnt;

        cur_time = max;
        --available;
    }

    if (cur_time < T)
        return -1;
    return cnt;
}