// TODO: Add the required header

/* Do not edit below this line. */
/* Do not edit below this line. */
/* Do not edit below this line. */

#include <gtest/gtest.h>

#include <climits>
#include <cstdio>
#include <future>

#include "parking_functions.h"

// Thanks to Paul Inventado
// https://github.com/google/googletest/issues/348#issuecomment-431714269
#define MAX_DURATION_MS 500
// Fail immediately.
// NOLINT(cppcoreguidelines-macro-usage)
#define ASSERT_DURATION_LE(millisecs, stmt)                                 \
  {                                                                         \
    std::promise<bool> completed;                                           \
    auto stmt_future = completed.get_future();                              \
    std::thread(                                                            \
        [&](std::promise<bool>& completed) {                                \
          stmt;                                                             \
          completed.set_value(true);                                        \
        },                                                                  \
        std::ref(completed))                                                \
        .detach();                                                          \
    if (stmt_future.wait_for(std::chrono::milliseconds(millisecs)) ==       \
        std::future_status::timeout)                                        \
      GTEST_FATAL_FAILURE_("\tExecution time greater than " #millisecs      \
                           " milliseconds.\n\tRevise algorithm for better " \
                           "performance and check for "                     \
                           "infinite loops.");                              \
  }

// Defer failure
// NOLINT(cppcoreguidelines-macro-usage)
#define EXPECT_DURATION_LE(millisecs, stmt)                                    \
  {                                                                            \
    std::promise<bool> completed;                                              \
    auto stmt_future = completed.get_future();                                 \
    std::thread(                                                               \
        [&](std::promise<bool>& completed) {                                   \
          stmt;                                                                \
          completed.set_value(true);                                           \
        },                                                                     \
        std::ref(completed))                                                   \
        .detach();                                                             \
    if (stmt_future.wait_for(std::chrono::milliseconds(millisecs)) ==          \
        std::future_status::timeout)                                           \
      GTEST_NONFATAL_FAILURE_("\tExecution time greater than " #millisecs      \
                              " milliseconds.\n\tRevise algorithm for better " \
                              "performance and check for "                     \
                              "infinite loops.");                              \
  }

#define FP_DELTA 0.001
namespace {

TEST(Parking, CanParkOnAsh) {
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("mon", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("tue", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnAsh("wed", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnAsh("wed", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("wed", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("thu", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("fri", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sat", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnAsh("sun", 23)));
}

TEST(Parking, CanParkOnBeech) {
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("mon", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("tue", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("wed", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("thu", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("fri", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("fri", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("fri", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("fri", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("fri", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("fri", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("fri", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("fri", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnBeech("fri", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnBeech("fri", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnBeech("fri", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnBeech("fri", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("fri", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("fri", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("fri", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("fri", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("fri", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("fri", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("fri", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("fri", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("fri", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("fri", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("fri", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("fri", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sat", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnBeech("sun", 23)));
}

TEST(Parking, CanParkOnCedar) {
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("mon", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("mon", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("mon", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("mon", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("mon", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("mon", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("mon", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("mon", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("mon", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("mon", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("mon", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("mon", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("mon", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("mon", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("mon", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("mon", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("mon", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("mon", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("mon", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("mon", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("mon", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("mon", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("mon", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("mon", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("tue", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("tue", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("tue", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("tue", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("tue", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("tue", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("tue", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("tue", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("tue", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("tue", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("tue", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("tue", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("tue", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("tue", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("tue", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("tue", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("tue", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("tue", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("tue", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("tue", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("tue", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("tue", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("tue", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("tue", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("wed", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("wed", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("wed", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("wed", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("wed", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("wed", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("wed", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("wed", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("wed", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("wed", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("wed", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("wed", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("wed", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("wed", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("wed", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("wed", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("wed", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("wed", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("wed", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("wed", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("wed", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("wed", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("wed", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("wed", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("thu", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("thu", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("thu", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("thu", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("thu", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("thu", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("thu", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("thu", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("thu", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("thu", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("thu", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("thu", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("thu", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("thu", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("thu", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("thu", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("thu", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("thu", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("thu", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("thu", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("thu", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("thu", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("thu", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("thu", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("fri", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("fri", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("fri", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("fri", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("fri", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("fri", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("fri", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("fri", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("fri", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("fri", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("fri", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("fri", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("fri", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("fri", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("fri", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("fri", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("fri", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("fri", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("fri", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("fri", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("fri", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("fri", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("fri", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("fri", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sat", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sat", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sat", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sat", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sat", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sat", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sat", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sat", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sat", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sat", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sat", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sat", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sat", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sat", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sat", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sat", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sat", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sat", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sat", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sat", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sat", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sat", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sat", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sat", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sun", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sun", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sun", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sun", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sun", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sun", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sun", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sun", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sun", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sun", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sun", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sun", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sun", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sun", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sun", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sun", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sun", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sun", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnCedar("sun", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sun", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sun", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sun", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sun", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnCedar("sun", 23)));
}

TEST(Parking, CanParkOnDateMinuteZero) {
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 0, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 1, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 2, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 3, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 4, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 5, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 6, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("mon", 7, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("mon", 8, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("mon", 9, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("mon", 10, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("mon", 11, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("mon", 12, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("mon", 13, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("mon", 14, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("mon", 15, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 16, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 17, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 18, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 19, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 20, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 21, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 22, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 23, 0)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 0, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 1, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 2, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 3, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 4, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 5, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 6, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("tue", 7, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("tue", 8, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("tue", 9, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("tue", 10, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("tue", 11, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("tue", 12, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("tue", 13, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("tue", 14, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("tue", 15, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 16, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 17, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 18, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 19, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 20, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 21, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 22, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 23, 0)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("wed", 0, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("wed", 1, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("wed", 2, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("wed", 3, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("wed", 4, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("wed", 5, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("wed", 6, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("wed", 7, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("wed", 8, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("wed", 9, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("wed", 10, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("wed", 11, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("wed", 12, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("wed", 13, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("wed", 14, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("wed", 15, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("wed", 16, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("wed", 17, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("wed", 18, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("wed", 19, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("wed", 20, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("wed", 21, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("wed", 22, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("wed", 23, 0)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 0, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 1, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 2, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 3, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 4, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 5, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 6, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("thu", 7, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("thu", 8, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("thu", 9, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("thu", 10, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("thu", 11, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("thu", 12, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("thu", 13, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("thu", 14, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("thu", 15, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 16, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 17, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 18, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 19, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 20, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 21, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 22, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 23, 0)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("fri", 0, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("fri", 1, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("fri", 2, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("fri", 3, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("fri", 4, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("fri", 5, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("fri", 6, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("fri", 7, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("fri", 8, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("fri", 9, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("fri", 10, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("fri", 11, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("fri", 12, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("fri", 13, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("fri", 14, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("fri", 15, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("fri", 16, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("fri", 17, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("fri", 18, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("fri", 19, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("fri", 20, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("fri", 21, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("fri", 22, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("fri", 23, 0)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 0, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 1, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 2, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 3, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 4, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 5, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 6, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 7, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 8, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 9, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 10, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 11, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 12, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 13, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 14, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 15, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 16, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 17, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 18, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 19, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 20, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 21, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 22, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 23, 0)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 0, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 1, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 2, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 3, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 4, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 5, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 6, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 7, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 8, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 9, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 10, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 11, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 12, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 13, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 14, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 15, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 16, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 17, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 18, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 19, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 20, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 21, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 22, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 23, 0)));
}

TEST(Parking, CanParkOnDateOtherMinutes) {
  // around 6:30 AM

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 6, 28)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 6, 29)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("mon", 6, 30)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("mon", 6, 31)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("mon", 6, 32)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 6, 28)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 6, 29)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("tue", 6, 30)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("tue", 6, 31)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("tue", 6, 32)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("wed", 6, 28)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("wed", 6, 29)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("wed", 6, 30)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("wed", 6, 31)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("wed", 6, 32)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 6, 28)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 6, 29)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("thu", 6, 30)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("thu", 6, 31)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("thu", 6, 32)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("fri", 6, 28)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("fri", 6, 29)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("fri", 6, 30)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("fri", 6, 31)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("fri", 6, 32)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 6, 28)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 6, 29)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 6, 30)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 6, 31)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 6, 32)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 6, 28)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 6, 29)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 6, 30)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 6, 31)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 6, 32)));

  // around 4 PM

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("mon", 15, 58)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("mon", 15, 59)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 16, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 16, 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 16, 2)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("tue", 15, 58)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("tue", 15, 59)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 16, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 16, 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 16, 2)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("wed", 15, 58)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("wed", 15, 59)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("wed", 16, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("wed", 16, 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("wed", 16, 2)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("thu", 15, 58)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("thu", 15, 59)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 16, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 16, 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 16, 2)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("fri", 15, 58)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("fri", 15, 59)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("fri", 16, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("fri", 16, 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("fri", 16, 2)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 15, 58)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 15, 59)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 16, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 16, 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 16, 2)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 15, 58)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 15, 59)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 16, 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 16, 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 16, 2)));

  // assorted times
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("mon", 20, 35)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("tue", 16, 59)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("wed", 15, 51)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("thu", 21, 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnDate("fri", 15, 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sat", 7, 52)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnDate("sun", 1, 23)));
}

TEST(Parking, CanParkOnElm) {
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("mon", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("mon", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("mon", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("mon", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("mon", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("mon", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("mon", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("mon", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("mon", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("mon", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("mon", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("mon", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("mon", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("mon", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("mon", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("mon", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("mon", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("mon", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("mon", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("mon", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("mon", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("mon", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("mon", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("mon", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("tue", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("wed", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("wed", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("wed", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("wed", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("wed", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("wed", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("wed", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("wed", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("wed", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("wed", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("wed", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("wed", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("wed", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("wed", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("wed", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("wed", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("wed", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("wed", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("wed", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("wed", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("wed", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("wed", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("wed", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("wed", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("thu", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("thu", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("thu", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("thu", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("thu", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("thu", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("thu", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("thu", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("thu", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("thu", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("thu", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("thu", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("thu", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("thu", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("thu", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("thu", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("thu", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("thu", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("thu", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("thu", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("thu", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("thu", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("thu", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("thu", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("fri", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("fri", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("fri", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("fri", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("fri", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("fri", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("fri", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("fri", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("fri", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("fri", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("fri", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("fri", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("fri", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("fri", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("fri", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("fri", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_FALSE(CanParkOnElm("fri", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("fri", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("fri", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("fri", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("fri", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("fri", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("fri", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("fri", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sat", 23)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 0)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 1)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 2)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 3)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 4)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 5)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 6)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 7)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 8)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 9)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 10)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 11)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 12)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 13)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 14)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 15)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 16)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 17)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 18)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 19)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 20)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 21)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 22)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_TRUE(CanParkOnElm("sun", 23)));
}

}  // namespace
