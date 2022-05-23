#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include <QKeyEvent>
#include "farmacycontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Editor; }
QT_END_NAMESPACE

class Editor : public QMainWindow
{
    Q_OBJECT

public:
    Editor(QWidget *parent = nullptr);
    ~Editor();

    void refreshTable();

    void keyPressEvent(QKeyEvent *e);
private:
    Ui::Editor *ui;
    FarmacyController repo;
};
#endif // EDITOR_H
