#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtWidgetsApplication4.h"

class QtWidgetsApplication4 : public QWidget
{
    Q_OBJECT

public:
    QtWidgetsApplication4(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtWidgetsApplication4Class ui;
};
