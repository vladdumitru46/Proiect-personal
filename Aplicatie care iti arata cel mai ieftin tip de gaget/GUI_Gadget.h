#pragma once

#include "Service.h"
#include "Table_model.h"
#include <QListWidget>
#include <QWidget>
#include <QHBoxLayout>
#include <QTableView>
#include <qpushbutton.h>


class Gadget_type : public QWidget
{
private: 
	QListWidget* list;
	Service& service;
public:
	Gadget_type(Service& service) : service{ service } {
		QHBoxLayout* main_layout = new QHBoxLayout;
		setLayout(main_layout);
		QWidget* widget = new QWidget;
		QHBoxLayout* layout_widget = new QHBoxLayout;
		widget->setLayout(layout_widget);
		list = new QListWidget;
		layout_widget->addWidget(list);
		main_layout->addWidget(widget);
		connect_the_buttons();
		reload_list(service.all_gadgets_type_in_the_store());
	}
	void connect_the_buttons()
	{
		QObject::connect(list->selectionModel(), &QItemSelectionModel::selectionChanged, [&]() {
			auto selection = list->selectionModel()->selectedIndexes();
			if (selection.isEmpty())
				return;
			auto type = selection[0];
			auto type_of_gadget = type.data(Qt::DisplayRole).toString();
			vector<string> list_of_gadgtes_names = service.all_gadgtes_name_with_a_type_in_the_store(type_of_gadget.toStdString());
			if (list_of_gadgtes_names.size() != 0)
			{
				reload_list(service.all_gadgtes_name_with_a_type_in_the_store(type_of_gadget.toStdString()));
			}
			else
			{
				reload_list_for_gadget_name(type_of_gadget.toStdString());
			}
		});
	}
	void reload_list(vector<string> gadget_types)
	{
		list->clear();
		for (auto gadget_type : gadget_types)
		{
			list->addItem(QString::fromStdString(gadget_type));
		}
	}
	void reload_list_for_gadget_name(string gadget_name)
	{
		list->clear();
		vector<Gadgets> gadget = service.search_gadgets_by_name(gadget_name);
		for (auto gadget_type : gadget)
		{
			list->addItem(QString::fromStdString("Name: " + gadget_type.get_name() + ", Store: " + gadget_type.get_store() + ", Price: " + std::to_string(gadget_type.get_price())));
		}
	}
};


class GUI_Gadget : public QWidget
{
private:
	Service& service_gadget;
	Gadget_type& gadget_type;
	QVBoxLayout* main_layout;
	Table_model* table_model;
	QTableView* table;
	QTableView* table_of_gadgets = new QTableView;
	QPushButton* search_gadget;
	QLineEdit* line_for_search;
	QPushButton* button_of_all_gadgets_in_app;
	void initilize_the_window();
	void connect_the_buttons();
	void reload_the_table(vector<Gadgets> vector_of_gadgets);
public:
	GUI_Gadget(Service& service_gadget, Gadget_type& gadget_type) : service_gadget{ service_gadget }, gadget_type{ gadget_type } {
		initilize_the_window();
		connect_the_buttons();
		table_model = new Table_model(service_gadget.get_all_gadgets_from_store());
		table->setModel(table_model);
		reload_the_table(service_gadget.get_all_gadgets_from_store());
	}
};
