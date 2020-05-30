#include "customTableModel.h"

CustomTableModel::CustomTableModel(Controller& actionController, QObject* parent) : QAbstractTableModel{ parent }, actionController{ actionController }{
	this->elementCount = this->actionController.getSavedVictims().size();
}

CustomTableModel::~CustomTableModel(){
	;
}

int CustomTableModel::rowCount(const QModelIndex& parent) const{
	return this->actionController.getSavedVictims().size();
}

int CustomTableModel::columnCount(const QModelIndex& parent) const{
	return 4;
}

QVariant CustomTableModel::data(const QModelIndex& index, int role) const{
	int row = index.row();
	int column = index.column();
	
	if (role == Qt::DisplayRole) {
		std::vector<Victim> mylist = this->actionController.getSavedVictims();
		Victim currentVictim = mylist[row];

		if (column == 0) {
			return QString::fromStdString(currentVictim.getName());
		}
		if (column == 1) {
			return QString::fromStdString(currentVictim.getPlaceOfOrigin());
		}
		if (column == 2) {
			return QString::number(currentVictim.getAge());
		}
		return QString::fromStdString(currentVictim.getPhotographLink());
	}

	if (role == Qt::FontRole){
		QFont tableFont(QString::fromStdString(TABLE_FONT_NAME), TABLE_FONT_SIZE);
		tableFont.setBold(true);
		return tableFont;
	}

	return QVariant();
}

QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const{
	if (role == Qt::DisplayRole) {
		if (orientation == Qt::Horizontal) {
			if (section == 0) {
				return QString{ "Victim name" };
			}
			if (section == 1) {
				return QString{ "Place of origin" };
			}
			if (section == 2) {
				return QString{ "Age" };
			}
			return QString{ "Photograph" };
		}
	}

	if (role == Qt::FontRole) {
		QFont tableFont(QString::fromStdString(TABLE_FONT_NAME), TABLE_FONT_SIZE);
		tableFont.setBold(true);
		return tableFont;
	}

	return QVariant{};
}

bool CustomTableModel::setData(const QModelIndex& index, const QVariant& value, int role){
	return false;
}

Qt::ItemFlags CustomTableModel::flags(const QModelIndex& index) const{
	return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}
