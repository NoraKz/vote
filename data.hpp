#ifndef STUDENT_DATA_DATABASE_HEADER
#define STUDENT_DATA_DATABASE_HEADER

#include "sqlite_orm/sqlite_orm.h"

namespace database {
    struct ClassList 
    {
        int id;
        std::string className;
    };

    auto OpenDB()
    {
        using namespace sqlite_orm;
        auto DB = make_storage( "data.db" ,
            make_table("class",
                make_column("id",&ClassList::id,primary_key().autoincrement()),
                make_column("class",&ClassList::className)
            )
        );
        DB.sync_schema();
        return DB;
    }
    
    void addClass(std::string className)
    {
        ClassList i;
        i.className = className;
        OpenDB().insert(i);
    }

    void deleteClass(std::string className)
    {
        using namespace sqlite_orm;
        OpenDB().remove_all<ClassList>(where(c(&ClassList::className) == className));
    }

    std::string getClassJSON()
    {
        auto classes = OpenDB().get_all<ClassList>();
        std::string start = "{\"data\":[";
        for(auto & i : classes)
        {
            start += "\"" + i.className + "\",";
        }
        start = start.substr(0,start.size()-1);
        start+="]}";
        return start;
    }
}

#endif