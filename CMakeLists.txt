cmake_minimum_required(VERSION 3.16)
project(vote LANGUAGES C CXX)

include(FetchContent)

FetchContent_Declare(
    webview
    GIT_REPOSITORY https://github.com/webview/webview
    GIT_TAG 0.12.0)
FetchContent_MakeAvailable(webview)

find_package(SqliteOrm REQUIRED)

add_executable(vote)
target_sources(vote PRIVATE tool/yyjson.c tool/json.cpp main.cpp)
target_link_libraries(vote PRIVATE webview::core sqlite_orm::sqlite_orm)