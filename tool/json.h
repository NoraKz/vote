#ifndef VOTE_JSON_HEADER
#define VOTE_JSON_HEADER
#include <string>

// MakeStrAnswer 用于生成一个函数的结果-Str
std::string MakeStrAnswer(std::string text);

// MakeIntAnswer 用于生成一个函数的结果-Int
std::string MakeIntAnswer(int cnt);

std::string MakeStudentList(std::string className);
#endif