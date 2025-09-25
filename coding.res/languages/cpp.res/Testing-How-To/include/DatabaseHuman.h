#ifndef DATABASE_HUMAN_H
#define DATABASE_HUMAN_H

#include "IHuman.h" // include the interface header
#include <string>

class DatabaseHuman : public IHuman {
public:
    DatabaseHuman(std::string name);
    void Eat() override;
    void Sleep() override;

private:
    std::string name_;
};

#endif