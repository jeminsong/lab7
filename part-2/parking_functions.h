// TODO: Add the required header

#ifndef PARKING_FUNCTIONS_H
#define PARKING_FUNCTIONS_H

#include <string>

// Returns true if parking is allowed on Ash Street at the given time, or
// false otherwise.
//
// The sign on Ash street reads:
// NO PARKING 10AM TO 12PM WEDNESDAY STREET SWEEPING
//
// day must be the name of a day of the week, using the first three letters in
// lower case, so one of: "mon", "tue", "wed", "thu", "fri", "sat", or "sun".
//
// hour must be the hour number using 24-hour notation (military time),
// so 7 means 7 AM and 19 means 7 PM.
bool CanParkOnAsh(const std::string& day, int hour);

// Returns true if parking is allowed on Beech Street at the given time, or
// false otherwise.
//
// The sign on Beech street reads:
// Street Cleaning Every Friday of EACH MONTH, 8 am - 12 noon
//
// day must be the name of a day of the week, using the first three letters in
// lower case, so one of: "mon", "tue", "wed", "thu", "fri", "sat", or "sun".
//
// hour must be the hour number using 24-hour notation (military time),
// so 7 means 7 AM and 19 means 7 PM.
bool CanParkOnBeech(const std::string& day, int hour);

// Returns true if parking is allowed on Cedar Street at the given time, or
// false otherwise.
//
// The signs on Cedar street read:
// NO PARKING NIGHTTIME 7PM - 7AM EVERYDAY
// NO PARKING 8 AM to 10 AM TUESDAY STREET SWEEPING
//
// day must be the name of a day of the week, using the first three letters in
// lower case, so one of: "mon", "tue", "wed", "thu", "fri", "sat", or "sun".
//
// hour must be the hour number using 24-hour notation (military time),
// so 7 means 7 AM and 19 means 7 PM.
bool CanParkOnCedar(const std::string& day, int hour);

// Returns true if parking is allowed on Date Street at the given time, or
// false otherwise.
//
// The signs on Date street read:
// NO PARKING 6:30 AM TO 4 PM EXCEPT SATURDAY & SUNDAY
//
// day must be the name of a day of the week, using the first three letters in
// lower case, so one of: "mon", "tue", "wed", "thu", "fri", "sat", or "sun".
//
// hour must be the hour number using 24-hour notation (military time),
// so 7 means 7 AM and 19 means 7 PM.
//
// minute must be the minute number, 0 through 59, so at 3:25 PM, minute
// would be 25.
bool CanParkOnDate(const std::string& day, int hour, int minute);

// Returns true if parking is allowed on Elm Street at the given time, or
// false otherwise.
//
// The signs on Elm street read:
// NO PARKING
// 8 AM TO 8 PM
// MONDAY THRU THURSDAY
// 8 AM TO 5 PM
// FRIDAY
//
// NO PARKING TUESDAY
//
// day must be the name of a day of the week, using the first three letters in
// lower case, so one of: "mon", "tue", "wed", "thu", "fri", "sat", or "sun".
//
// hour must be the hour number using 24-hour notation (military time),
// so 7 means 7 AM and 19 means 7 PM.
bool CanParkOnElm(const std::string& day, int hour);

#endif
