#include "RecipeGUI.h"
#include "Database_Manager.h"

RecipeGUI::RecipeGUI(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this); 
    QPixmap bkgnd("background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

RecipeGUI::~RecipeGUI()
{
    delete adding;
    delete choosing;
}


void RecipeGUI::on_addbtn_clicked() {
    adding->show();
}

void RecipeGUI::on_chsbtn_clicked() {
    choosing->srchresult->clear();
    Database_Manager::Get().selectData(0, "");
    int nor = choosing->srchresult->model()->rowCount();
    choosing->nofrecipes->setText(QString::number(nor) + " Recipes Listed:");
    choosing->show();
}

