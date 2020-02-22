/*最大连续子数组
一个数组A[0,...,n-1],求A的连续子数组的和最大,如
A:1,-2,3,10,-4,7,2,-5
最大子数组:3,10,-4,7,2
*/

#include <iostream>

/*暴力法，求array[i,j]的和,复杂度O(n^3)*/
int maxSubArray(int *pArray, int size) {
    if(size == 0 || nullptr == pArray) {
        return 0;
    }

    int maxSum = pArray[0];
    int currSum = 0;
    for(int i = 0; i < size; i++) {
        /*以i为首的连续子数组*/
        for(int j = i; j < size; j++) {
            currSum = 0;
            /*求解连续子数组array[i,j]的最大和*/
            for(int k = i; k <= j; k++) {
                currSum += pArray[k];
            }
            maxSum = max(maxSum, currSum);
        }
    }

    return maxSum;
}

/*分治法，最大连续子数组和分三种：
1.在右边的子数组
2.在左边的子数组
3.跨中间的子数组
求三者中最大的值即可
复杂度：O(nlogn)
*/

int maxSubArray(int *pArray, int size) {
    if(size == 0 || nullptr == pArray) {
        return 0;
    }
    return subArrayAdd(pArray, 0, size - 1);
}

int subArrayAdd(int *pArray, int from, int to) {
    if(from == to) {
        return pAarray[from];
    }
    int middle = (from + to) / 2;
    int maxRightSum = subArrayAdd(pArray, middle+1, to);
    int maxLeftSum = subArrayAdd(pArray, from, middle);

    int i = 0, currMaxLeftSum = 0, currMaxRightSum = 0;
    int currLeft = 0, currRight = 0;
    int maxMiddleSum = 0
    /*扫描左边的数组*/
    currMaxLefSum = pArray[middle];
    currLeft = pArray[middle];
    for(i = from; i < middle; i++) {
        currLeft += pArray[i];
        currMaxLefSum = max(currLeft, currMaxLefSum);
    }
    /*扫描右边的数组*/
    currMaxRightSum = pArray[middle+1];
    currRight = pArray[middle+1];
    for(i = middle+2; i <= to; i++) {
        currRight += pArray[i];
        currMaxRightSum = max(currRight, currMaxRightSum);
    }
    maxMiddleSum = currMaxRightSum + currMaxLeftSum;
    return max(maxRightSum, maxLeftSum, maxMiddleSum);
}

/*动态规划的方法
记S[i+1]为以a[i+1]结尾的数组
S[i+1] = max(S[i]+a[i+1], a[i+1])
算法复杂度O(n)
*/
int maxSubArray(int *pArray, int size) {
    if(size == 0 || nullptr == pArray) {
        return 0;
    }

    int maxSum = pArray[0];
    int currSum = pArray[0];
    for(int i = 1; i < size; i++) {
        if(currSum > 0) {
            currSum += pArray[i];
        } else {
            currSum = pArray[i];
        }
        maxSum = max(maxSum, currSum);   
    }
    return maxSum;
}

/*返回最大子数组和的数组本身*/
int maxSubArray(int *pArray, int size， int &from, int &to) {
    if(size == 0 || nullptr == pArray) {
        from = to = -1;
        return 0;
    }

    int maxSum = pArray[0];
    int currSum = pArray[0];
    from = to = 0;
    for(int i = 1; i < size; i++) {
        if(currSum > 0) {
            currSum += pArray[i];
        } else {
            /*之前的和少于0，则从当前值重新开始*/
            currSum = pArray[i];
            from = i;
        }

        if(currSum > maxSum) {
            maxSum = currSum;
            to = i;
        }
    }
    return maxSum;
}
