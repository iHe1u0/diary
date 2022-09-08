#pragma once

#include <qobject.h>
#include <sqlite3.h>

#include <cstring>

constexpr const auto* dbName = "diary.sqlite";
constexpr const auto appVersion = 1;

class SqliteHelper : public QObject {
  Q_OBJECT
 public:
  explicit SqliteHelper(QObject* parent = nullptr);
  ~SqliteHelper();

  /**
   * @brief get Sqlite3 Version
   * @return version
   */
  auto* getSqlite3Version();

  /**
   * @brief exec execute a sql
   * @param sql
   * @return code of result
   */
  int exec(const std::string& sql) const;

 private:
  sqlite3* database;
 signals:
};
