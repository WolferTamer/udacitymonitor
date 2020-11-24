#include "processor.h"
#include "linux_parser.h"

using std::string;
using std::stoi;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 
    string line, blank, blank2, blank3, idle, idle2, used, used2, used3, used4, used5, used6;
    std::ifstream stream(LinuxParser::kProcDirectory + LinuxParser::kStatFilename);
    if(stream.is_open()) {
        std::getline(stream,line);
        std::istringstream linestream(line);
        linestream >>blank>>used>>used2>>used3>>idle>>idle2>>used4>>used5>>used6>>blank2>>blank3;
    }

    int const idletotal = stoi(idle) + stoi(idle2);
    int const nonidletotal = stoi(used) + stoi(used2) + stoi(used3) + stoi(used4) + stoi(used5) + stoi(used6);
    float const totaltime = idletotal+nonidletotal;

    return nonidletotal/totaltime;
 }