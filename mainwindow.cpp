#include "mainwindow.h"

#include <sqlite3.h>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  dbHelper = new SqliteHelper(this);

  rootItem = listModel.invisibleRootItem();
  // init data
  for (auto row = 0; row < 4; ++row) {
    auto* item = new QStandardItem(QString("根节点 %1").arg(row));
    // rootItem->appendRow(item);
    rootItem = item;
  }
  ui->mainTreeView->setModel(&this->listModel);
}

MainWindow::~MainWindow() { delete ui; }
