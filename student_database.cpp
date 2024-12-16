#include "student_database.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "sqlite_orm/sqlite_orm.h"

auto OpenDB(std::string className)
{
    using namespace sqlite_orm;

    auto Db = make_storage(className + ".db",
        make_table("students",
            make_column("id", &Student::id, primary_key().autoincrement()),
            make_column("name", &Student::name),
            make_column("sex",&Student::sex)));
    Db.sync_schema();
    return Db;
}


std::vector<Student> GetAllStudents(std::string className)
{
    auto DB = OpenDB(className);
    return DB.get_all<Student>();
}

void AddStudent(std::string className, std::string name, std::string sex)
{
    auto DB = OpenDB(className);
    Student i;
    i.name = name;
    i.sex = sex;
    DB.insert(i);
}

void DeleteStudent(std::string className, std::string name)
{
    using namespace sqlite_orm;

    auto DB = OpenDB(className);
    DB.remove<Student>(where(c(&Student::name) == name));
}

std::vector<Student> GetRandomStudents(std::string className, size_t count) {
    auto db = OpenDB(className);
    std::vector<Student> students = db.get_all<Student>();
    if (students.size() < count) {
        return students;
    }
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::random_shuffle(students.begin(), students.end());
    std::vector<Student> randomStudents;
    for (size_t i = 0; i < count; ++i) {
        randomStudents.push_back(students[i]);
    }
    return randomStudents;
}

