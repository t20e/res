#include "WorkManager.h"

WorkManager::WorkManager(IHuman& human) : human_(human) {}

void WorkManager::manageDay() {
    // The manager tells the human to perform actions.
    human_.Eat();
    human_.Sleep();
}