// Jemin Song
// jeminsong0119@csu.fullerton.edu
// @jeminsong
// Partners: @jeminsong

#include "parking_functions.h"

bool CanParkOnAsh(const std::string& day, int hour) {
  if (day == "wed") {
    if ((hour >= 10) && (hour < 12)) {
      return false;
    } else {
      return true;
    }
  } else {
    return true;
  }
  return false;
}

bool CanParkOnBeech(const std::string& day, int hour) {
  if (day == "fri") {
    if ((hour >= 8) && (hour < 12)) {
      return false;
    } else {
      return true;
    }
  } else {
    return true;
  }
  return false;
}

bool CanParkOnCedar(const std::string& day, int hour) {
  if ((day == "mon") || (day == "wed") || (day == "thu") || (day == "fri") ||
      (day == "sat") || (day == "sun")) {
    return (hour >= 7 && hour < 19);
  } else if (day == "tue") {
    return (hour >= 10 && hour < 19) || hour == 7;
  } else {
    return false;
  }
}

bool CanParkOnDate(const std::string& day, int hour, int min) {
  if ((day == "mon") || (day == "tue") || (day == "wed") || (day == "thu") ||
      (day == "fri")) {
    if ((hour >= 7) && (hour < 16)) {
      return false;
    } else if (hour == 6) {
      if (min > 29) {
        return false;
      } else {
        return true;
      }
    } else {
      return true;
    }
  } else {
    return true;
  }
  return false;
}

bool CanParkOnElm(const std::string& day, int hour) {
  if ((day == "mon") || (day == "wed") || (day == "thu")) {
    if ((hour >= 8) && (hour < 20)) {
      return false;
    } else {
      return true;
    }
  } else if (day == "fri") {
    if ((hour < 8) || (hour >= 17)) {
      return true;
    }
  } else if (day == "tue") {
    return false;
  } else {
    return true;
  }
  return false;
}