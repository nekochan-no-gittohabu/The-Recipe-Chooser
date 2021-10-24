#pragma once

#include <QWidget>
#include "ui_DeleteDialog.h"

class DeleteDialog : public QWidget, public Ui::DeleteDialog
{
	Q_OBJECT

public:
	DeleteDialog(QWidget *parent = Q_NULLPTR);
	~DeleteDialog();

private slots:
	void on_yesdelete_clicked();

signals:
	void deleteselectedrecipe();
};
