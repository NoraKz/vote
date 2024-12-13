#include "json.h"
#include "yyjson.h"
#include "../student_database.h"

std::string MakeStrAnswer(std::string text)
{
    auto doc = yyjson_mut_doc_new(NULL);
    auto data = yyjson_mut_obj(doc);
    yyjson_mut_doc_set_root(doc,data);
    yyjson_mut_obj_add_str(doc,data,"data",text.c_str());
    std::string ans = yyjson_mut_write(doc,0,NULL);
    yyjson_mut_doc_free(doc);
    return ans;
}

std::string MakeIntAnswer(int cnt)
{
    auto doc = yyjson_mut_doc_new(NULL);
    auto data = yyjson_mut_obj(doc);
    yyjson_mut_doc_set_root(doc,data);
    yyjson_mut_obj_add_int(doc,data,"data",cnt);
    std::string ans = yyjson_mut_write(doc,0,NULL);
    yyjson_mut_doc_free(doc);
    return ans;
}

std::string MakeStudentList(std::string className)
{
    auto students = GetAllStudents(className);
}