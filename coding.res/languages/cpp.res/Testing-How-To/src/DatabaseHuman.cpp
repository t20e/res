#include "DatabaseHuman.h"
#include <iostream>

DatabaseHuman::DatabaseHuman(std::string name) : name_(name) {}

void DatabaseHuman::Eat() {
    // In a real app, this might write to a database.
    std::cout << this->name_ << " is eating.\n";
}

void DatabaseHuman::Sleep() {
    // In a real app, this might query a database.
    std::cout << this->name_ << " is sleeping.\n";
}