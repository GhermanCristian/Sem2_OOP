#include "customTableModel.h"

CustomTableModel::CustomTableModel(Controller& actionController, QObject* parent) : QAbstractTableModel{ parent }, actionController{ actionController }{
	;
}

CustomTableModel::~CustomTableModel(){
	;
}

int CustomTableModel::rowCount(const QModelIndex& parent) const{
	return this->actionController.getAllStars().size();
}

int CustomTableModel::columnCount(const QModelIndex& parent) const{
	return NUMBER_OF_COLUMNS;
}

QVariant CustomTableModel::data(const QModelIndex& index, int role) const{
	int row = index.row();
	int column = index.column();
	
	if (role == Qt::DisplayRole) {
		std::vector<Star> items = this->actionController.getAllStars();
		Star currentStar = items[row];

		if (column == STAR_NAME_HEADER_COLUMN) {
			return QString::fromStdString(currentStar.getName());
		}
		if (column == CONSTELLATION_HEADER_COLUMN) {
			return QString::fromStdString(currentStar.getConstellation());
		}
		if (column == RIGHT_ASCENSION_HEADER_COLUMN) {
			return QString::number(currentStar.getRA());
		}
		if (column == DECLINATION_HEADER_COLUMN) {
			return QString::number(currentStar.getDec());
		}
		return QString::number(currentStar.getDiameter());
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
			if (section == STAR_NAME_HEADER_COLUMN) {
				return QString{ "Star name" };
			}
			if (section == CONSTELLATION_HEADER_COLUMN) {
				return QString{ "Constellation" };
			}
			if (section == RIGHT_ASCENSION_HEADER_COLUMN) {
				return QString{ "RA" };
			}
			if (section == DECLINATION_HEADER_COLUMN) {
				return QString{ "Declination" };
			}
			return QString{ "Diameter" };
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
