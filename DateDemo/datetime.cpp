#include "datetime.h"

DateTime::DateTime(int dd, int mm, int yyyy) {
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    timeinfo->tm_mday = dd;
    timeinfo->tm_mon = mm - 1;
    timeinfo->tm_year = yyyy - 1900;
    rawtime = mktime(timeinfo);
}

DateTime::DateTime(const DateTime &copiedDateTime) {
    rawtime = copiedDateTime.getRawtime();
    timeinfo = localtime(&rawtime);
}

DateTime::DateTime() {
    time (&rawtime);
    timeinfo = localtime(&rawtime);
}

void DateTime::printToday() {
    printSomeDay(0);
}

void DateTime::printYesterday() {
    printSomeDay(-1);
}

void DateTime::printTomorrow() {
    printSomeDay(1);
}

void DateTime::printFuture(int days) {
    printSomeDay(days);
}

void DateTime::printPast(int days) {
    printSomeDay(-days);
}

void DateTime::printMonth() {
    std::cout << std::put_time(timeinfo, "%B") << std::endl;
}

void DateTime::printWeekDay() {
    std::cout << std::put_time(timeinfo, "%A") << std::endl;
}

int DateTime::calcDifference(DateTime date) {
    double difference = difftime(rawtime,date.getRawtime());
    difference = (int) (difference/secsPerDay);
    return difference;
}

time_t DateTime::getRawtime() const {
    return rawtime;
}

void DateTime::printSomeDay(int days){
     time_t rawtimeSomeDay = rawtime + days * secsPerDay;
     struct tm * timeinfoSomeDay = localtime(&rawtimeSomeDay);
     std::cout << std::put_time(timeinfoSomeDay, "%D") << std::endl;
}
