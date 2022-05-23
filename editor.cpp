#include "editor.h"
#include "./ui_editor.h"
#include "farmacycontroller.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QKeyEvent>
#include <string>

Editor::Editor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Editor)
{
    ui->setupUi(this);
    QObject::connect(ui->addButton,&QPushButton::clicked,this,[&](){
        repo.addMedicine(ui->NameLineEdit->text().toStdString(),ui->PriceLineEdit->text().toFloat());
        refreshTable();
    });
    QObject::connect(ui->removeButton,&QPushButton::clicked,this,[this](){
        repo.removeMedicine(ui->NameLineEdit->text().toStdString());
        refreshTable();
    });
    refreshTable();
}

Editor::~Editor()
{
    delete ui;
}

void Editor::refreshTable()
{
    ui->tableWidget->clear();
    //ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(repo.nr_meds());
    for(int i = 0;i<repo.nr_meds();i++){
        QTableWidgetItem *name =
                new QTableWidgetItem(QString::fromStdString(repo.get_at(i)->get_name()));
            QTableWidgetItem *price =
                new QTableWidgetItem(QString::fromStdString(std::to_string(repo.get_at(i)->get_price())));
            ui->tableWidget->setItem(i, 0, name);
            ui->tableWidget->setItem(i, 1, price);
    }
}

void Editor::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_S && e->modifiers().testAnyFlag(Qt::ControlModifier)){
        repo.saveCSV("save.csv");
    }
}

