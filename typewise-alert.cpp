#include "typewise-alert.h"
#include <stdio.h>
#include <unordered_map>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

std::unordered_map<CoolingType, std::pair<int, int>> coolingLimits = {
  {PASSIVE_COOLING, {0, 35}},
  {HI_ACTIVE_COOLING, {0, 45}},
  {MED_ACTIVE_COOLING, {0, 40}}
};

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
  int lowerLimit = 0;
  int upperLimit = 0;
  
  if (coolingLimits.find(coolingType) != coolingLimits.end()) 
  {
    std::tie(lowerLimit, upperLimit) = coolingLimits[coolingType];
  }
  
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  switch(alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  
  if (breachType == TOO_LOW) {
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is too low\n");
  } else if (breachType == TOO_HIGH) {
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is too high\n");
  }
}
