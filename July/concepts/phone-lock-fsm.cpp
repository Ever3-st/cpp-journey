#include <iostream>

enum class LockState {
  LOCKED,
  AUTHENTICATING,
  UNLOCKED,
  SECURITY_LOCKOUT
};

int main()
{
    LockState currentLock = LockState::LOCKED;
    
    int remainingAttempts = 3;
    bool systemGlitchTriggered = false;
    
    std::cout << "[OS] Secure Enclave Booted. Device Status: Secured.\n";
    std::cout << "--------------------------------------------------\n";
    
    for (int cycle = 1; cycle <=5; cycle++) {
      std::cout << "[CYCLE " << cycle << "] Checking hardware interrupts...\n";
      
      switch (currentLock) {
        
        case LockState::LOCKED:
            std::cout << ">> State: LOCKED. Screen sleeping. Awaiting PIN entry...\n";
            currentLock = LockState::AUTHENTICATING;
            break;
            
        case LockState::AUTHENTICATING:
            std::cout << ">> State: AUTHENTICATING. Verifying cryptographic signature...\n";
            remainingAttempts--;
            
            std::cout << "   [WARNING] Incorrect PIN code detected! Attempts remaining: "
                      << remainingAttempts << "\n";
                      
            if (remainingAttempts <= 0) {
              std::cout << "  [CRITICAL] Security threshold breached!\n";
              currentLock = LockState::SECURITY_LOCKOUT;
            } else {
              currentLock = LockState::LOCKED;
            }
            break;
            
        case LockState::UNLOCKED:
            std::cout << ">> State: UNLOCKED. Welcome to the home screen.\n";
            break;
            
        case LockState::SECURITY_LOCKOUT:
            std::cout << ">> State: SECURITY_LOCKOUT. Device disabled for 30 minutes.\n";
            break;
            
        default:
            std::cout << ">> [CRITICAL ERROR] Corrupt state dectected! Resetting to SAFE mode.\n";
            currentLock = LockState::LOCKED;
            break;
      }
      
      std::cout << "--------------------------------------------------\n";
      
      if (cycle == 3) {
        std::cout << "!! [HARDWARE SIMULATION] Spiking voltage to corrupt memory state !!\n";
        currentLock = static_cast<LockState>(99);
      }
      
    }

    return 0;
}
