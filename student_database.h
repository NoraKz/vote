#ifndef VOTE_DATABASE_HEADER
#define VOTE_DATABASE_HEADER

#include "sqlite_orm/sqlite_orm.h"
#include <string>
#include <vector>

struct Student {
    int id;
    std::string name;
    std::string sex;
};

auto OpenDB(std::string className);

std::vector<Student> GetAllStudents(std::string className);

std::vector<Student> GetRandomStudents(std::string className, size_t count);
#endif