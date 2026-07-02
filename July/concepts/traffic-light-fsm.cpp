#include <iostream>

enum class LightState {
	RED,
  YELLOW,
  GREEN
};

int main()
{
  LightState currentLight = LightState::RED;
  
  int clockTicks = 6;
  
  std::cout << "[TRAFFIC SYSTEM] Powering on intersection signals...\n\n";
  
  while (clockTicks > 0){
    
    switch (currentLight) {
      
      case LightState::RED:
          std::cout << "[SIGNAL] Light is RED. All cars must STOP.\n";
          currentLight = LightState::GREEN;
          break;
          
      case LightState::GREEN:
          std::cout << "[SIGNAL] Light is GREEN.Drives may GO.\n";
          currentLight = LightState::YELLOW;
          break;
          
      case LightState::YELLOW:
          std::cout << "[SIGNAL] Light is YELLOW.Clear the intersection.\n";
          currentLight = LightState::RED;
          break;
    }
    
    std::cout << "-------- Clock Tick. Changing State --------\n";
    clockTicks--;
  }
  
  std::cout << "\n[TRAFFIC SYSTEM] Powering down signals for maintenance.\n";
	return 0;
}
