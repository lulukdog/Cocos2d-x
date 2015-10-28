#include "TimeUtil.h"
#include "MacroUtil.h"

USING_NS_CC;
using namespace std;

// 忘记调用Start的提醒信息
const string kTipForgetToCallStartMsg = "may forgot to call Start() first.";

namespace util
{
    
    TimeUtil::TimeUtil():begin_time_(kInvalidValue)
    {
    }
    
    void TimeUtil::Start()
    {
        begin_time_ = MillisecondToNow();
        pause_resume_note_.clear();  // 重置记录
    }
    
    void TimeUtil::Pause()
    {
        // 确保调用Start了
        CCAssert(begin_time_ != kInvalidValue, kTipForgetToCallStartMsg.c_str());
        // 确保没有重复调用Pause， 比如Pause后没有Resume或End然后又Pause了
        CCAssert(pause_resume_note_.empty() || pause_resume_note_.back().second != kInvalidValue,
                 "may continue call Pause() 2 times without call Resume().");
        int cur_time = MillisecondToNow();
        pause_resume_note_.push_back(make_pair(cur_time, kInvalidValue));
    }
    
    void TimeUtil::Resume()
    {
        // 确保调用Start了
        CCAssert(begin_time_ != kInvalidValue, kTipForgetToCallStartMsg.c_str());
        // 确保没有还未Pause就Resume，确保没有重复调用Resume（比如Resume后又Resume了）
        CCAssert(!pause_resume_note_.empty() && pause_resume_note_.back().second == kInvalidValue, "");
        pause_resume_note_.back().second = MillisecondToNow();
    }
    
    void TimeUtil::Restart()
    {
        Start();
    }
    
    pair<int, string> TimeUtil::CalculateSpentTime()
    {
        // 确保调用Start了
        CCAssert(begin_time_ != kInvalidValue, kTipForgetToCallStartMsg.c_str());
        // 确保上次调用的是Pause
        CCAssert(!pause_resume_note_.empty() && pause_resume_note_.back().second == kInvalidValue, "");
        const int kTotalSpentTime = pause_resume_note_.back().first - begin_time_;
        int total_pause_time = 0;
        for (int i = 0; i < pause_resume_note_.size() - 1; i++)
        {
            total_pause_time += pause_resume_note_[i].second - pause_resume_note_[i].first;
        }
        const int kRealSpentTime = kTotalSpentTime - total_pause_time;
        return make_pair(kRealSpentTime, GetHHMMSSStrFromMillisecond(kRealSpentTime));
    }
    
    int TimeUtil::MillisecondToNow()
    {
        struct timeval now;
        gettimeofday(&now, NULL);
        return (now.tv_sec * 1000 + now.tv_usec / 1000);
    }
    
    string TimeUtil::GetHHMMSSStrFromMillisecond(long spent_time)
    {
        CCAssert(spent_time >= 0, "");
        long millisecond = spent_time / 1000;
        const long kHour = millisecond / (60 * 60);
        millisecond -= kHour * (60 * 60);
        const long kMinute = millisecond / 60;
        millisecond -= kMinute * 60;
        const long kSecond = millisecond;
        return str_format("%02ld:%02ld:%02ld", kHour, kMinute, kSecond);
    }
    
    string TimeUtil::GetHHMMSSStrFromSecond(long spent_time)
    {
        return GetHHMMSSStrFromMillisecond(spent_time * 1000);
    }
    
    string TimeUtil::GetMMSSStrFromMillisecond(long spent_time)
    {
        CCAssert(spent_time >= 0, "");
        long millisecond = spent_time / 1000;
        const long kMinute = millisecond / 60;
        millisecond -= kMinute * 60;
        const long kSecond = millisecond;
        return str_format("%02ld:%02ld", kMinute, kSecond);
    }
    
    string TimeUtil::GetMMSSStrFromSecond(long spent_time)
    {
        return GetMMSSStrFromMillisecond(spent_time * 1000);
    }
    
    string TimeUtil::GetYYYYMMDDStr()
    {
        time_t time_now;
        time(&time_now);
        tm *t = localtime(&time_now);
        const int kYear = t->tm_year + 1900;
        const int kMonth = t->tm_mon + 1;
        const int kDay = t->tm_mday;
        return str_format("%04d-%02d-%02d", kYear, kMonth, kDay);
    }
    
}
