#include <gtest/gtest.h>
#include "typewise-alert.h"

TEST(TypeWiseAlertTestSuite,InfersBreachAccordingToLimits) {


}

TEST(TypeWiseAlertTestSuite,PassiveCoolingHighTempToController) 
{
  BatteryCharacter batteryChar1;
  batteryChar1.coolingType = PASSIVE_COOLING;
  checkAndAlert(TO_CONTROLLER,batteryChar1,38);
}

TEST(TypeWiseAlertTestSuite,PassiveCoolingLowTempToEmail) 
{
  BatteryCharacter batteryChar1;
  batteryChar1.coolingType = PASSIVE_COOLING;
  checkAndAlert(TO_EMAIL,batteryChar1,-1);
}

TEST(TypeWiseAlertTestSuite,PassiveCoolingHighTempToEmail) 
{
  BatteryCharacter batteryChar1;
  batteryChar1.coolingType = PASSIVE_COOLING;
  checkAndAlert(TO_EMAIL,batteryChar1,38);
}
