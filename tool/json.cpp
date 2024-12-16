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

std::string MakeStudentList(std::vector<Student> students)
{
    if(students.size() == 0)
    {
        return R"JSON({"data":[]})JSON";
    }
    std::string start = R"JSON({"data":[)JSON";
    for(auto & i : students)
    {
        std::string item = "{\"name\":\"" + i.name +"\",";
        item += "\"id\":" + std::to_string(i.id) + ",";
        item += "\"sex\":\"" + i.sex +"\"},";
        start += item;
    }
    start = start.substr(0,start.size()-1);
    start += "]}";
    return start;
}

std::string GetCallString(std::string src , int index)
{
    yyjson_doc *doc = yyjson_read(src.c_str(), src.length() , 0);
    yyjson_val *root = yyjson_doc_get_root(doc);
    auto val = yyjson_arr_get(root , index);
    return yyjson_get_str(val);
}

int GetCallInt(std::string src , int index)
{
    yyjson_doc *doc = yyjson_read(src.c_str(), src.length() , 0);
    yyjson_val *root = yyjson_doc_get_root(doc);
    auto val = yyjson_arr_get(root , index);
    return yyjson_get_int(val);
}