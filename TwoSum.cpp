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

int main()
{
    int numbers[] = {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82};

    int* res = twoSum(numbers, 42, 8);
    //std::cout<<*res<<" "<<*(++res)<<std::endl;
    std::cout<<*res;
    std::cout<<*(++res)<<std::endl;
}
