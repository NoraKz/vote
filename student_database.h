#include "sqlite_orm/sqlite_orm.h"
#include <string>
#include <vector>

struct Student {
    int id;
    std::string name;
};

auto OpenDB(std::string className);

auto GetAllStudents(std::string className);