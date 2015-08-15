#include<vector>

struct StuInfo
{
	int total;
	int level;
	StuInfo()
	{
		total = 0;
		level = 0;
	}
};

int main()
{
	std::vector<StuInfo> pots;

	for (int i = 0; i < 10; i++)
	{
		StuInfo pot;
		pot.level = rand();
		pots.push_back(pot) ;
	}

	// 利用lambuda表达式排序
	std::sort(pots.begin(), pots.end(), [](const StuInfo& lpot, const StuInfo& rpot){ return lpot.level<rpot.level;});
}
