//
// Created by liyang on 2020/10/24.
//

int removeElement(int* nums, int numsSize, int val){
    // last指向i之后的最后一个不是val的值
    int last = numsSize - 1;
    int new_len = numsSize;

    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == val) {
            new_len--;
            while (last > i && nums[last] == val)
                last--;

            // 此时i之后全都是val
            if (last <= i) {
                new_len = i + 1;
                return new_len;
            }

            nums[i] = nums[last--];
        }
    }

    return new_len;
}