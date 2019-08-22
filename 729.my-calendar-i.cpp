/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */
class MyCalendar
{
    std::vector<std::pair<int, int>> events;

public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        for (const auto &i : events)
        {
            if (start < i.second && end > i.first)
                return false;
        }
        events.emplace_back(start, end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
