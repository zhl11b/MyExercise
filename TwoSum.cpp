#include<iostream>
#include<memory.h>

int *twoSum(int numbers[], int n, int target) {
    static int result[2];
    memset(result, 0, sizeof(result));
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if((numbers[i]+numbers[j]) == target)
            {
                result[0] = i+1;
                result[1] = j+1;
                return result;
            }
        }
    }
    return result;
}

int *twoSum(int numbers[], int n, int target) {
    int i,j;
    static int result[2] = {};
    int bucket[100000] = {};
     for(i = 0;i < n;i++){
        bucket[numbers[i]] += 1;
    }
    for(i = 0;i < n;i++){
        if(bucket[target - numbers[i]])
            for(j = n - 1;j > i;j--){
                if(numbers[i] + numbers[j] == target){
                    result[0] = i + 1,result[1] = j + 1;
                }
            }
    }
    return result;
}
