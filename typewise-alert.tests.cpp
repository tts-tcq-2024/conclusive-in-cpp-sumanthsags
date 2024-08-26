#include <gtest/gtest.h>
#include "typewise-alert.h"

TEST(TypeWiseAlertTestSuite,InfersBreachAccordingToLimits) {


}

TEST(TypeWiseAlertTestSuite,PassiveCoolingHighTemp) 
{
  BatteryCharacter batteryChar1;
  batteryChar1.coolingType = PASSIVE_COOLING;
  checkAndAlert(TO_CONTROLLER,batteryChar1,38);
}

TEST(TypeWiseAlertTestSuite,PassiveCoolingLowTemp) 
{
  BatteryCharacter batteryChar1;
  batteryChar1.coolingType = PASSIVE_COOLING;
  checkAndAlert(TO_EMAIL,batteryChar1,-1);
}
