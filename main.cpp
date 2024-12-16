#include "webview/webview.h"
#include "ui/index.hpp"
#include "ui/student.hpp"
#include "ui/vote.hpp"
#include "tool/json.h"
#include "data.hpp"

#include <iostream>
int WINAPI WinMain(HINSTANCE /*hInst*/, HINSTANCE /*hPrevInst*/,
    LPSTR /*lpCmdLine*/, int /*nCmdShow*/) {
  try {
    webview::webview w(false, nullptr);
    w.set_title("vote - 上课抽签工具");
    w.set_size(880, 620, WEBVIEW_HINT_NONE);
    w.bind("changeToIndex",[&](const std::string &req) -> std::string {
      w.set_html(ui::IndexHTML);
      return "[]";
    });
    w.bind("changeToStudent",[&](const std::string &req) -> std::string {
      w.set_html(ui::StudentHTML);
      return "[]";
    });
    w.bind("changeToVote",[&](const std::string &req) -> std::string {
      w.set_html(ui::VoteHTML);
      return "[]";
    });
    w.bind("addClass",[&](const std::string &req) -> std::string {
      database::addClass(GetCallString(req,0));
      return "[]";
    });
    w.bind("getClass",[&](const std::string &req) -> std::string {
      return database::getClassJSON();
    });
    w.bind("removeClass",[&](const std::string &req) -> std::string {
      database::deleteClass(GetCallString(req,0));
      return "[]";
    });
    w.bind("getStudents",[&](const std::string &req) -> std::string {
      return MakeStudentList(GetAllStudents(GetCallString(req,0)));
    });
    w.bind("addStudent",[&](const std::string &req) -> std::string {
      AddStudent(GetCallString(req,0),GetCallString(req,1),GetCallString(req,2));
      return "[]";
    });
    w.bind("deleteStudent",[&](const std::string &req) -> std::string {
      DeleteStudent(GetCallString(req,0),GetCallString(req,1));
      return "[]";
    });
    w.bind("getRandomStudents",[&](const std::string &req) -> std::string {
      return MakeStudentList(GetRandomStudents(GetCallString(req,0),GetCallInt(req,1)));
    });
    w.set_html(ui::IndexHTML);
    w.run();
  } catch (const webview::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }

  return 0;
}