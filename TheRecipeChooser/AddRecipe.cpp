#include "AddRecipe.h"
#include "Database_Manager.h"

AddRecipe::AddRecipe(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
	QPixmap bkgnd("back2.jpg");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);
}

AddRecipe::~AddRecipe()
{
	delete adddia;
}

void AddRecipe::on_OKa_clicked() {
	QString recipename = rname->toPlainText();
	QString howtomake = howto->toPlainText();
	QString ingredientandamount;
	std::string iname, type, amount;
	int i = 0;
	std::map<Ingredient, Amount> rec;
	while (ingrlist->item(i) != NULL) {
		ingredientandamount = ingrlist->item(i++)->text();
		std::istringstream iss{ ingredientandamount.toStdString() };
		iss >> iname >> amount >> type;
		std::unique_ptr<Ingredient> in{ new Ingredient {iname} };
		std::unique_ptr<Amount> amo{ new Amount {amount, type} };
		rec.insert(std::make_pair(*in, *amo));
	}

	if (recipename != NULL && ingredientandamount != NULL && howtomake != NULL) {
		std::unique_ptr<Recipe> recipe{ new Recipe {recipename.toStdString(), howtomake.toStdString(), rec} };
		Database_Manager::Get().insertData(recipe->makestring());
		adddia->dialogname->setText(recipename + "\nRecipe Added");
		ingrlist->clear();
		ingrname->setText("");
		rname->setText("");
		howto->setText("");
	}
	else {
		adddia->dialogname->setText("Please Fill \nAll Fields");
	}
	adddia->show();
}

void AddRecipe::on_addingr_clicked() {
	QString i_name = ingrname->toPlainText();
	ingrlist->addItem(i_name);
	ingrname->setText("");
}

void AddRecipe::on_deleteingr_clicked() {
	QListWidgetItem* it = ingrlist->currentItem();
	delete ingrlist->takeItem(ingrlist->row(it));
}
