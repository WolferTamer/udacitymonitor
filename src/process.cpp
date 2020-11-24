#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) : pid_(pid), command_(LinuxParser::Command(pid)), user_(LinuxParser::User(pid)){};

int Process::Pid() const { return pid_; }

float Process::CpuUtilization() const { 
    float totaltime = LinuxParser::ActiveJiffies(Pid());
    float uptime = LinuxParser::UpTime();
    float seconds = uptime- (Process::UpTime()/sysconf(_SC_CLK_TCK));
    float cpuusage = (totaltime/sysconf(_SC_CLK_TCK))/seconds;
    return cpuusage;
 }

string Process::Command() { return command_; }

string Process::Ram() const { return LinuxParser::Ram(Pid()); }

string Process::User() const { return user_; }

long int Process::UpTime() const { return LinuxParser::UpTime(Pid()); }

bool Process::operator<(Process const& a) const { return CpuUtilization() > a.CpuUtilization(); }