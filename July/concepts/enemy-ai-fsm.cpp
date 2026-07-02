#include <iostream>

enum class EnemyState {
    IDLE,
    PATROLLING,
    CHASING
};

int main() {
  
    EnemyState guardState = EnemyState::IDLE;

    int distanceToPlayer = 25; 
    int patrolTimer = 2; // How long the guard stays idle before starting a walk

    std::cout << "[GAME ENGINE] Spawning Level 1 Guard AI...\n";
    std::cout << "--------------------------------------------------\n";

    for (int frame = 1; frame <= 5; frame++) {
        std::cout << "[FRAME " << frame << "] Player is " << distanceToPlayer << " meters away.\n";
      
        switch (guardState) {

            case EnemyState::IDLE:
                std::cout << ">> AI State: IDLE. Guard is yawning.\n";
                patrolTimer--;
                
                if (patrolTimer <= 0) {
                    std::cout << "   [EVENT] Guard grew bored. Shifting behavior...\n";
                    guardState = EnemyState::PATROLLING;
                }
                break;

            case EnemyState::PATROLLING:
                std::cout << ">> AI State: PATROLLING. Guard is pacing along the castle wall.\n";
                
                if (distanceToPlayer <= 15) {
                    std::cout << "   [EVENT] Visual contact! Guard spots the intruder!\n";
                    guardState = EnemyState::CHASING;
                }
                break;

            case EnemyState::CHASING:
                std::cout << ">> AI State: CHASING. Guard draws sword and sprints toward player!\n";
                break;
        }

        std::cout << "--------------------------------------------------\n";
      
        if (frame >= 2) {
            distanceToPlayer -= 5;
        }
    }

    return 0;
}
