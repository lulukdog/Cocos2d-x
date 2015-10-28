#pragma once

namespace util
{
    
    class RandomUtil
    {
    public:
        //通过输入概率计算是否发生
        static bool randomProbability(float fProbability);
        
        //取随机数
        static int randomNumber(int nFrom, int nTo);
        
    };
    
}

