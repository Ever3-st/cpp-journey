#include <iostream>

enum class VendingState {
    WELCOME,
    CHOOSING_DRINK,
    DISPENSING,
    RETURN_CHANGE
};

int main() {
    VendingState currentState = VendingState::WELCOME;
    
    int userBalance = 0;
    int userSelection = 0;
    bool keepRunning = true;

    std::cout << "=== SATURDAY CAFE: INTERACTIVE VENDING MACHINE ===\n";

    while (keepRunning) {
        switch (currentState) {

            case VendingState::WELCOME:
                std::cout << "\n[WELCOME] Current Balance: $" << userBalance << "\n";
                std::cout << "1. Insert $1\n";
                std::cout << "2. Insert $2\n";
                std::cout << "3. Proceed to Drink Selection\n";
                std::cout << "4. Exit & Walk Away\n";
                std::cout << "Enter Choice: ";
                
                std::cin >> userSelection;

                if (userSelection == 1) {
                    userBalance += 1;
                } else if (userSelection == 2) {
                    userBalance += 2;
                } else if (userSelection == 3) {
                    if (userBalance > 0) {
                        currentState = VendingState::CHOOSING_DRINK;
                    } else {
                        std::cout << "  ! You need to insert money first !\n";
                    }
                } else if (userSelection == 4) {
                    std::cout << "Goodbye!\n";
                    keepRunning = false;
                } else {
                    // Defensive validation inside the if-else chain
                    std::cout << "  ! Invalid option. Try again. !\n";
                }
                break;

            case VendingState::CHOOSING_DRINK:
                std::cout << "\n[DRINK MENU] Balance: $" << userBalance << "\n";
                std::cout << "1. Cola ($2)\n";
                std::cout << "2. Water ($1)\n";
                std::cout << "3. Cancel & Get Refund\n";
                std::cout << "Enter Choice: ";
                
                std::cin >> userSelection;

                if (userSelection == 1) {
                    if (userBalance >= 2) {
                        userBalance -= 2;
                        currentState = VendingState::DISPENSING;
                    } else {
                        std::cout << "  ! Insufficient funds for Cola. !\n";
                    }
                } else if (userSelection == 2) {
                    if (userBalance >= 1) {
                        userBalance -= 1;
                        currentState = VendingState::DISPENSING;
                    } else {
                        std::cout << "  ! Insufficient funds for Water. !\n";
                    }
                } else if (userSelection == 3) {
                    std::cout << "   Cancelling selection...\n";
                    currentState = VendingState::RETURN_CHANGE;
                } else {
                    std::cout << "  ! Invalid drink option. !\n";
                }
                break;

            case VendingState::DISPENSING:
                std::cout << "\n[DISPENSING] *Clunk, whirrrrrr, drop!*\n";
                std::cout << ">> Your refreshing drink has been dispensed! <<\n";
                
                // Transition automatically to return any leftover change
                currentState = VendingState::RETURN_CHANGE;
                break;

            case VendingState::RETURN_CHANGE:
                if (userBalance > 0) {
                    std::cout << "\n[CHANGER] *Ching-ching!* Returning your change: $" << userBalance << "\n";
                    userBalance = 0;
                } else {
                    std::cout << "\n[CHANGER] No change to return.\n";
                }
                
                // Reset back to the beginning for the next customer
                std::cout << "--------------------------------------------\n";
                currentState = VendingState::WELCOME;
                break;

            // Defensive Shield for the switch block
            default:
                std::cout << "[ERROR] Core machine malfunction. Emergency refunding...\n";
                currentState = VendingState::RETURN_CHANGE;
                break;
        }
    }

    return 0;
}
