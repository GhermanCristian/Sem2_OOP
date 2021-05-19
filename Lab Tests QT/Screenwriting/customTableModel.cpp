#include "customTableModel.h"

CustomTableModel::CustomTableModel(Controller& actionController, QObject* parent) : QAbstractTableModel{ parent }, actionController{ actionController }{
	;
}

CustomTableModel::~CustomTableModel(){
	;
}

int CustomTableModel::rowCount(const QModelIndex& parent) const{
	return this->actionController.getAllIdeas().size();
}

int CustomTableModel::columnCount(const QModelIndex& parent) const{
	return NUMBER_OF_COLUMNS;
}

QVariant CustomTableModel::data(const QModelIndex& index, int role) const{
	int row = index.row();
	int column = index.column();
	
	if (role == Qt::DisplayRole) {
		std::vector<Idea> mylist = this->actionController.getAllIdeas();
		Idea currentIdea = mylist[row];

		if (column == DESCRIPTION_HEADER_COLUMN) {
			return QString::fromStdString(currentIdea.getDescription());
		}
		if (column == STATUS_HEADER_COLUMN) {
			return QString::fromStdString(currentIdea.getStatus());
		}
		if (column == CREATOR_HEADER_COLUMN) {
			return QString::fromStdString(currentIdea.getCreator());
		}
		return QString::number(currentIdea.getAct());
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
			if (section == DESCRIPTION_HEADER_COLUMN) {
				return QString{ "Description" };
			}
			if (section == STATUS_HEADER_COLUMN) {
				return QString{ "Status" };
			}
			if (section == CREATOR_HEADER_COLUMN) {
				return QString{ "Creator" };
			}
			return QString{ "Act" };
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

void CustomTableModel::update(){
	endResetModel(); // this emits the signal that the model has been updated
}
