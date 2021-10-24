#pragma once

#include <QWidget>
#include "ui_AddRecDialog.h"

class AddRecDialog : public QWidget, public Ui::AddRecDialog
{
	Q_OBJECT

public:
	AddRecDialog(QWidget *parent = Q_NULLPTR);
	~AddRecDialog();

private slots:
	void on_OKad_clicked();
};
