#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

int toMinutes(const std::string& inTime) 
{
    // 00:00
    int hours = std::stoi(inTime.substr(0, 2));
    int minutes = std::stoi(inTime.substr(3, 2));
    return hours * 60 + minutes;
}

int main() 
{
    std::string start_meeting_time;
    std::string end_meeting_time;
    std::string end_streaming_time;

    std::cin >> start_meeting_time >> end_meeting_time >> end_streaming_time;
    std::cin.ignore();

    int start_meeting_minutes = toMinutes(start_meeting_time);
    int end_meeting_minutes = toMinutes(end_meeting_time);
    int end_streaming_minutes = toMinutes(end_streaming_time);

    std::string chat;
    std::string time, name;
    std::unordered_map<std::string, int> m;

    int result = 0;

    while (std::getline(std::cin, chat)) 
    {
        std::istringstream iss(chat);
        iss >> time >> name;

        int chat_time_minutes = toMinutes(time);

        if (chat_time_minutes > end_streaming_minutes) 
        {
            break;
        }

        if (chat_time_minutes <= start_meeting_minutes) 
        {
            m[name]++;
            continue;
        }

        if (chat_time_minutes >= end_meeting_minutes) 
        {
            if (m.find(name) != m.end()) 
            {
                m.erase(name);
                result++;
            }
        }
    }

    std::cout << result << std::endl;

    return 0;
}