
/* Do not edit below this line. */
/* Do not edit below this line. */
/* Do not edit below this line. */

#include <gtest/gtest.h>

#include <climits>
#include <cstdio>
#include <future>
#include <limits>

#include "datediff_functions.h"

// Thanks to Paul Inventado
// https://github.com/google/googletest/issues/348#issuecomment-431714269
#define MAX_DURATION_MS 500
// Fail immediately.
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

// Tests PromptForDouble()
TEST(PrintDateTest, CaptureStdout) {
  testing::internal::CaptureStdout();
  std::string captured_output;
  EXPECT_DURATION_LE(MAX_DURATION_MS, PrintDate(1, 1, 2023));
  std::cout.flush();
  captured_output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(captured_output, "1/1/2023");

  testing::internal::CaptureStdout();
  EXPECT_DURATION_LE(MAX_DURATION_MS, PrintDate(12, 14, 1943));
  std::cout.flush();
  captured_output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(captured_output, "12/14/1943");

  testing::internal::CaptureStdout();
  EXPECT_DURATION_LE(MAX_DURATION_MS, PrintDate(11, 2, 987));
  std::cout.flush();
  captured_output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(captured_output, "11/2/987");
}

// Tests JulianDay()

TEST(JulianDay, Positive) {
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_EQ(2459946, JulianDay(1, 1, 2023)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_EQ(1967227, JulianDay(12, 25, 673)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_EQ(2446007, JulianDay(11, 2, 1984)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_EQ(9100158, JulianDay(4, 15, 20203)));
  EXPECT_DURATION_LE(MAX_DURATION_MS, EXPECT_EQ(1722340, JulianDay(7, 4, 3)));
}

// Tests DateDifference()

TEST(DateDifference, Positive) {
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_EQ(365, DateDifference(1, 1, 2023, 1, 1, 2024)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_EQ(366, DateDifference(1, 1, 2024, 1, 1, 2025)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_EQ(7424, DateDifference(12, 8, 1980, 4, 6, 2001)));

  EXPECT_DURATION_LE(
      MAX_DURATION_MS,
      EXPECT_EQ(427453, DateDifference(7, 4, 738, 10, 31, 1908)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_EQ(254, DateDifference(4, 15, 2023, 12, 25, 2023)));
}

TEST(DateDifference, Negative) {
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_EQ(-365, DateDifference(1, 1, 2024, 1, 1, 2023)));
  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_EQ(-366, DateDifference(1, 1, 2025, 1, 1, 2024)));

  EXPECT_DURATION_LE(MAX_DURATION_MS,
                     EXPECT_EQ(-7424, DateDifference(4, 6, 2001, 12, 8, 1980)));

  EXPECT_DURATION_LE(
      MAX_DURATION_MS,
      EXPECT_EQ(-427453, DateDifference(10, 31, 1908, 7, 4, 738)));

  EXPECT_DURATION_LE(
      MAX_DURATION_MS,
      EXPECT_EQ(-254, DateDifference(12, 25, 2023, 4, 15, 2023)));
}

}  // namespace
