#include "GUI_Gadget.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <qheaderview.h>

void GUI_Gadget::initilize_the_window()
{
	main_layout = new QVBoxLayout;
	setLayout(main_layout);
	QWidget* up_widget = new QWidget;
	QFormLayout* layout_up_widget = new QFormLayout;
	up_widget->setLayout(layout_up_widget);
	line_for_search = new QLineEdit;
	layout_up_widget->addRow(new QLabel("Search type of gadget: "), line_for_search);
	search_gadget = new QPushButton("Search");
	layout_up_widget->addWidget(search_gadget);
	button_of_all_gadgets_in_app = new QPushButton("Show all gadgets type in the store");
	layout_up_widget->addWidget(button_of_all_gadgets_in_app);
	table = new QTableView;
	table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	layout_up_widget->addWidget(table);
	main_layout->addWidget(up_widget);

}

void GUI_Gadget::connect_the_buttons()
{
	QObject::connect(search_gadget, &QPushButton::clicked, [&]() {
		try {
				vector<Gadgets> filtred_vector = service_gadget.search_gadgets_by_name(line_for_search->text().toStdString());
				reload_the_table(filtred_vector);
			}
		catch (exception error)
		{
			QMessageBox::warning(this, "Error!", QString::fromStdString(error.what()));
		}
	});
	QObject::connect(button_of_all_gadgets_in_app, &QPushButton::clicked, [&]() {
		gadget_type.show();
	});
}

void GUI_Gadget::reload_the_table(vector<Gadgets> vector_of_gadgets)
{
	std::sort(vector_of_gadgets.begin(), vector_of_gadgets.end(), [&](Gadgets gadget1, Gadgets gadget2)
		{
			return gadget1.get_price() < gadget2.get_price();
		});
	table_model->setData(vector_of_gadgets);
}
