#pragma once
#include "Gageturi.h"
#include <QAbstractTableModel>
#include <vector>
#include <qdebug.h>
#include<vector>
#include <qbrush.h>
using std::vector;

class Table_model :public QAbstractTableModel {
private:
	vector<Gadgets> vector_of_types_of_gadgets;
public:
	Table_model(const vector<Gadgets> vector_medicament) : vector_of_types_of_gadgets{ vector_medicament } {};
	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		parent.row();
		return int(vector_of_types_of_gadgets.size());
	}
	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		parent.row();
		return 4;
	}
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
		qDebug() << "row:" << index.row() << " col:" << index.column() << " role" << role;
		if (role == Qt::ForegroundRole) {
			Gadgets gadget = vector_of_types_of_gadgets[index.row()];
		}
		if (role == Qt::DisplayRole) {

			Gadgets gadget = vector_of_types_of_gadgets[index.row()];
			if (index.column() == 0) {
				return QString::fromStdString(gadget.get_type());
			}
			else if (index.column() == 1)
			{
				return QString::fromStdString(gadget.get_name());
			}
			else if (index.column() == 2) {
				return QString::number(gadget.get_price());
			}
			else if (index.column() == 3) {
				return QString::fromStdString(gadget.get_store());
			}
		}

		return QVariant{};
	}

	void setData(const vector<Gadgets>& gadget) {
		this->vector_of_types_of_gadgets = gadget;
		auto topLeft = createIndex(0, 0);
		auto bottomR = createIndex(rowCount(), columnCount());
		emit dataChanged(topLeft, bottomR);
		emit layoutChanged();
	}
};