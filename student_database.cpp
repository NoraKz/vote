#include "student_database.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

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

std::vector<Student> GetRandomStudents(std::string className, size_t count) {
    auto db = OpenDB(className);
    std::vector<Student> students = db.get_all<Student>();

    if (students.size() < count) {
        throw std::runtime_error("Not enough students in the class.");
    }

    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    
    std::random_shuffle(students.begin(), students.end());

    
    std::vector<Student> randomStudents;
    for (size_t i = 0; i < count; ++i) {
        randomStudents.push_back(students[i]);
    }

    return randomStudents;
}

