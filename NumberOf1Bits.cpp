/****************************************************/
*问题：判断一个无符号整数在二进制中有多少个1
/****************************************************/
#include<iostream>

//! 我的代码
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bit = 1;
	    unsigned int count = 0;
	    for (int i = 0; i < sizeof(n)*8; ++i)
	    {
		    if ( (bit<<i) & n )  count++;
	    }
	    return count;
    }
};

//！ 别人的代码
class Solution_1
{
public:
	//! 通过对n位移并判断n的值，节省一些循环
	int hammingWeight(uint32_t n)
	{
		int res= 0;
 		for(; n; n >>=1) res += n & 1;
 		return res;
	}
	
};
int main()
{
	Solution sol;
	std::cout<<sol.hammingWeight(11)<<std::endl;
	
}
