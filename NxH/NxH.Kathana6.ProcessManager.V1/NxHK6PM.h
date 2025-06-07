#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_NxHK6PM.h"

class NxHK6PM : public QMainWindow
{
    Q_OBJECT

public:
    NxHK6PM(QWidget *parent = nullptr);
    ~NxHK6PM();

private:
    Ui::NxHK6PMClass ui;
};

