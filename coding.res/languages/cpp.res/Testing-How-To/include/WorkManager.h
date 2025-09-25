#ifndef WORK_MANAGER_H
#define WORK_MANAGER_H

#include "IHuman.h"

class WorkManager {
public:
    // We "inject" (dependency injection) the database dependency here.
    WorkManager(IHuman& human);
    // This is the function we want to test.
    void manageDay();

private:
    IHuman& human_;
};

#endif