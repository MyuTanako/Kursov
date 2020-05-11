#include "minesweeper.h"
#include "ui_minesweeper.h"

Minesweeper::Minesweeper(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Minesweeper)
{
    ui->setupUi(this);
}

Minesweeper::~Minesweeper()
{
    delete ui;
}

