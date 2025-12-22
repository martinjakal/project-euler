#include <iostream>

// Project Euler - Problem 19
// https://projecteuler.net/problem=19
// Counting Sundays
// Result: 171

class Date
{
public:
    Date(int day, int month, int year) : day_(day), month_(month), year_(year) { updateLeapYear(); }

    bool operator==(const Date& other) const { return year_ == other.year_ && month_ == other.month_ && day_ == other.day_; }

    bool operator!=(const Date& other) const { return !(*this == other); }

    void addDay()
    {
        ++day_;

        if (day_ <= 28)
            return;

        if ((day_ > 31 && (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12)) ||
            (day_ > 30 && (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11)) || (day_ > 29 && month_ == 2 && leapYear_) ||
            (day_ > 28 && month_ == 2 && !leapYear_))
        {
            day_ = 1;
            ++month_;
        }

        if (month_ > 12)
        {
            month_ = 1;
            ++year_;
            updateLeapYear();
        }
    }

    int getDay() const { return day_; }

private:
    int day_;
    int month_;
    int year_;
    bool leapYear_;

    void updateLeapYear() { leapYear_ = year_ % 4 == 0 && (year_ % 100 != 0 || year_ % 400 == 0); }
};

int countSundaysFirstBetweenDates(const Date& startDate, const Date& endDate, int dayOfWeek)
{
    int sundays = 0;

    for (Date curDate = startDate; curDate != endDate; curDate.addDay())
    {
        ++dayOfWeek;

        if (curDate.getDay() == 1 && dayOfWeek % 7 == 0)
            ++sundays;
    }

    return sundays;
}

int main()
{
    Date startDate(1, 1, 1901);
    Date endDate(31, 12, 2000);
    int startDayOfWeek = 2;  // 01-01-1901 was Tuesday

    auto result = countSundaysFirstBetweenDates(startDate, endDate, startDayOfWeek);
    std::cout << result << std::endl;

    return 0;
}
