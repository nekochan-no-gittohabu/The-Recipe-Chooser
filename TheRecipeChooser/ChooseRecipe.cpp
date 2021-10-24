#include "ChooseRecipe.h"
#include "Database_Manager.h"
#include <QTableWidgetItem>
#include <sstream>

ChooseRecipe::ChooseRecipe(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
	connect(&Database_Manager::Get(), &Database_Manager::NameListLoaded, this, &ChooseRecipe::NameListLoaded);
	connect(&Database_Manager::Get(), &Database_Manager::RecipeLoaded, this, &ChooseRecipe::RecipeLoaded);
	connect(deleting, &DeleteDialog::deleteselectedrecipe, this, &ChooseRecipe::deleteselectedrecipe);
	QPixmap bkgnd("back2.jpg");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);
}

ChooseRecipe::~ChooseRecipe()
{
	delete viewing; 
	delete deleting;
}

void ChooseRecipe::on_OKc_clicked() {
	if (srchresult->isItemSelected(srchresult->currentItem())) {
		QString searchname = srchresult->currentItem()->text();
		Database_Manager::Get().selectData(1, searchname.toStdString());
		viewing->show();
	}
}

void ChooseRecipe::on_srchbtn_clicked() {
	srchresult->clear();
	QString keyword = srchtext->toPlainText();
	//databaseden output al
	Database_Manager::Get().selectData(0, keyword.toStdString());
	srchtext->setText("");
	int nor = srchresult->model()->rowCount();
	nofrecipes->setText(QString::number(nor) + " Recipes Listed:");
}

void ChooseRecipe::on_dltbtn_clicked() {
	if (srchresult->isItemSelected(srchresult->currentItem()))
		deleting->show();
}


void ChooseRecipe::deleteselectedrecipe() {
	QString dltname = ChooseRecipe::srchresult->currentItem()->text();
	Database_Manager::Get().deleteData(dltname.toStdString());
}

void ChooseRecipe::NameListLoaded(QVector<QString> Values)
{
	for (auto value : Values) {
		srchresult->addItem(value);
	}
}

void ChooseRecipe::RecipeLoaded(QVector<QString> Values)
{
	int vsize = Values.size();
	viewing->choosentitle->setText(Values.at(0) + " Recipe");
	std::string iname, amo, unt;
	std::istringstream ingvector{ Values.at(1).toStdString() };
	std::istringstream amovector{ Values.at(2).toStdString() };
	
	viewing->ingtable->setRowCount(0);
	while(ingvector>>iname && amovector>> amo >> unt){
		QTableWidgetItem* ingitem = new QTableWidgetItem(QIcon(), QString::fromStdString(iname), 0);
		QTableWidgetItem* amoitem = new QTableWidgetItem(QIcon(), QString::fromStdString(amo + " " + unt), 0);
		viewing->ingtable->insertRow(viewing->ingtable->rowCount());
		viewing->ingtable->setItem(viewing->ingtable->rowCount() - 1, 0, ingitem);
		viewing->ingtable->setItem(viewing->ingtable->rowCount() - 1, 1, amoitem);
	}

	viewing->howtotext->setText(Values.at(3));
}