#include "RandomUtil.h"
#include "TimeUtil.h"

namespace util
{
	static bool s_bIsSrand = false;
	const int g_nDenominator = RAND_MAX;
    
	bool RandomUtil::randomProbability(float fProbability)
	{
		if (!s_bIsSrand)
		{
			s_bIsSrand = true;
			srand(TimeUtil::MillisecondToNow());
		}
        
		int nRandNum = rand() % g_nDenominator;
        
		if (nRandNum < g_nDenominator * fProbability)
		{
			return true;
		}
		return false;
	}
	
	int RandomUtil::randomNumber(int nFrom, int nTo)
	{
		if (nFrom == nTo)
		{
			return nFrom;
		}
		else if (nFrom > nTo)
		{
			int nTem = nFrom;
			nFrom = nTo;
			nTo = nTem;
		}
        
		if (!s_bIsSrand)
		{
			s_bIsSrand = true;
			srand(TimeUtil::MillisecondToNow());
		}
        
		int nRange = nTo - nFrom + 1;
		int nRandNum = rand() % nRange + nFrom;
        
		return nRandNum;
	}
}
