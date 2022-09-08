#include "sqlitehelper.h"

#include <sqlite3.h>

#include <cstring>
#include <iostream>

SqliteHelper::SqliteHelper(QObject *parent) : QObject(parent) {
  auto resultCode = sqlite3_open(dbName, &database);
  if (resultCode) {
    std::cerr << "open database failed: " << sqlite3_errmsg(database);
    exit(resultCode);
  }
  std::string sql =
      "create table data("
      "id int primary key not null, "
      "date text not null, "
      "weather text not null, "
      "content text not null, "
      "mark text);";
  resultCode = exec(sql);
  if (resultCode) {
    std::cerr << "open database failed: " << sqlite3_errmsg(database);
    // exit(resultCode);
  }
}

SqliteHelper::~SqliteHelper() {
  if (database != nullptr) {
    sqlite3_close(database);
  }
}

auto *SqliteHelper::getSqlite3Version() { return sqlite3_libversion(); }

int SqliteHelper::exec(const std::string &sql) const {
  if (database == nullptr) {
    return -1;
  }
  char *errMessage;
  int resultCode = sqlite3_exec(database, sql.c_str(), 0, nullptr, &errMessage);
  return resultCode;
}
