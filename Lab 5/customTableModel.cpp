#include "customTableModel.h"

CustomTableModel::CustomTableModel(Controller& actionController, QObject* parent) : QAbstractTableModel{ parent }, actionController{ actionController }{
	this->victimCount = this->actionController.getSavedVictims().size();
}

CustomTableModel::~CustomTableModel(){
	;
}

int CustomTableModel::rowCount(const QModelIndex& parent) const{
	return this->victimCount;
}

int CustomTableModel::columnCount(const QModelIndex& parent) const{
	return NUMBER_OF_COLUMNS;
}

QVariant CustomTableModel::data(const QModelIndex& index, int role) const{
	int row = index.row();
	int column = index.column();
	
	if (role == Qt::DisplayRole) {
		std::vector<Victim> mylist = this->actionController.getSavedVictims();
		Victim currentVictim = mylist[row];

		if (column == VICTIM_NAME_HEADER_COLUMN) {
			return QString::fromStdString(currentVictim.getName());
		}
		if (column == PLACE_OF_ORIGIN_HEADER_COLUMN) {
			return QString::fromStdString(currentVictim.getPlaceOfOrigin());
		}
		if (column == VICTIM_AGE_HEADER_COLUMN) {
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
			if (section == VICTIM_NAME_HEADER_COLUMN) {
				return QString{ "Victim name" };
			}
			if (section == PLACE_OF_ORIGIN_HEADER_COLUMN) {
				return QString{ "Place of origin" };
			}
			if (section == VICTIM_AGE_HEADER_COLUMN) {
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

Qt::ItemFlags CustomTableModel::flags(const QModelIndex& index) const{
	return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

void CustomTableModel::updateInternalData(){
	this->victimCount = this->actionController.getSavedVictims().size(); // update the row count
	endResetModel(); // this emits the signal that the model has been updated
}
