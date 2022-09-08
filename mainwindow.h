#pragma once

#include <qmainwindow.h>
#include <qstandarditemmodel.h>

#include "sqlitehelper.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  SqliteHelper *dbHelper;
  QStandardItemModel listModel;
  QStandardItem *rootItem;

 private:
  Ui::MainWindow *ui;
};
