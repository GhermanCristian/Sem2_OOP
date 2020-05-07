#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab5.h"

class Lab5 : public QMainWindow
{
	Q_OBJECT

public:
	Lab5(QWidget *parent = Q_NULLPTR);

private:
	Ui::Lab5Class ui;
};
