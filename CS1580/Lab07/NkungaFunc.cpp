#include "NkungaLab07.h"

using namespace std;

Time operator+(Time time1, Time time2) {
  int totalTime1 = (3600 * time1.hours) + (60 * time1.minutes) + time1.seconds;
  int totalTime2 = (3600 * time2.hours) + (60 * time2.minutes) + time2.seconds;
  int totalTime = totalTime1 + totalTime2;

  Time sum;

  sum.hours = totalTime / 3600;
  totalTime = totalTime % 3600;
  sum.minutes = totalTime / 60;
  sum.seconds = totalTime % 60;
  return sum;
}

Time operator-(Time time1, Time time2) {
  int totalTime1 = (3600 * time1.hours) + (60 * time1.minutes) + time1.seconds;
  int totalTime2 = (3600 * time2.hours) + (60 * time2.minutes) + time2.seconds;
  int totalTime = totalTime1 - totalTime2;

  Time sum;

  sum.hours = totalTime / 3600;
  totalTime = totalTime % 3600;
  sum.minutes = totalTime / 60;
  sum.seconds = totalTime % 60;
  return sum;
}

bool operator>(Time time1, Time time2) {
  int totalTime1 = (3600 * time1.hours) + (60 * time1.minutes) + time1.seconds;
  int totalTime2 = (3600 * time2.hours) + (60 * time2.minutes) + time2.seconds;

  if (totalTime1 > totalTime2) {
    return true;
  } else {
    return false;
  }
}

std::ostream &operator<<(std::ostream &os, const Time &time) {
  os << time.hours << ":" << time.minutes << ":" << time.seconds;
  return os;
}