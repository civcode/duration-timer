#include <iostream>

#include "duration_timer.h"

using namespace std::chrono;

DurationTimer::DurationTimer(const std::chrono::milliseconds interval) : 
    interval_(duration_cast<microseconds>(interval)),
    target_(high_resolution_clock::now() + interval)
{};

DurationTimer::DurationTimer(const std::chrono::seconds interval) : 
    interval_(duration_cast<microseconds>(interval)),
    target_(high_resolution_clock::now() + interval)
{};

DurationTimer::DurationTimer(const std::chrono::microseconds interval) : 
    interval_(duration_cast<microseconds>(interval)),
    target_(high_resolution_clock::now() + interval)
{};


void DurationTimer::set_interval(const std::chrono::microseconds interval) {
    interval_ = duration_cast<microseconds>(interval);
    target_ = high_resolution_clock::now() + interval; 
}

void DurationTimer::set_interval(const std::chrono::milliseconds interval) {
    set_interval(duration_cast<microseconds>(interval));
}
    
void DurationTimer::set_interval(const std::chrono::seconds interval) {
    set_interval(duration_cast<microseconds>(interval));
}

bool DurationTimer::is_expired() {
    //auto dt_us = duration_cast<microseconds>(high_resolution_clock::now()-target_);
    auto dt = (high_resolution_clock::now()-target_);
    if (dt.count() >= 0) {
        //std::cout << "\n now (" << dt_us.count()/1000 << ")\n";
        //std::cout << " / " << target_.count()
        target_ += interval_;

        return true;
    } else {
        //std::cout << "(" << dt_us.count()/1000 << ")";
    }
   return false; 
}

void DurationTimer::restart() {
    target_ = high_resolution_clock::now() + interval_;
}

