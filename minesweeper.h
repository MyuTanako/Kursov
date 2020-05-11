#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Minesweeper; }
QT_END_NAMESPACE

class Minesweeper : public QMainWindow
{
    Q_OBJECT

public:
    Minesweeper(QWidget *parent = nullptr);
    ~Minesweeper();

private:
    Ui::Minesweeper *ui;
};
#endif // MINESWEEPER_H
