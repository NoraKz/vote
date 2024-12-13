#include "webview/webview.h"
#include "ui/index.hpp"
#include "ui/student.hpp"

#include <iostream>
int main() {
  try {
    webview::webview w(true, nullptr);
    w.set_title("vote - 上课抽签工具");
    w.set_size(480, 320, WEBVIEW_HINT_NONE);
    w.bind("changeToStudent",[&](const std::string &req) -> std::string {
      w.set_html(ui::StudentHTML);
      return "[]";
    });
    w.set_html(ui::IndexHTML);
    w.run();
  } catch (const webview::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }

  return 0;
}