#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    char time[10];
    int h = seconds/3600;
    int r = seconds%3600;
    int m = r/60;
    int s = r%60;
    sprintf(time, "%.2d:%.2d:%.2d",h,m,s);
    return time;
 }