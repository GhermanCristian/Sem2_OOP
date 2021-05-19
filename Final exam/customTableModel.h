#pragma once
#include <qabstractitemmodel.h>
#include "controller.h"
#include <qfont.h>
#include <qdebug.h>
#include <qcolor.h>
#include <qbrush.h>
#include "Observer.h"

class CustomTableModel : public QAbstractTableModel, public Observer{
	private:
		const int TABLE_FONT_SIZE = 14;
		const std::string TABLE_FONT_NAME = "Candara";

		const int STAR_NAME_HEADER_COLUMN = 0;
		const int CONSTELLATION_HEADER_COLUMN = 1;
		const int RIGHT_ASCENSION_HEADER_COLUMN = 2;
		const int DECLINATION_HEADER_COLUMN = 3;
		const int DIAMETER_HEADER_COLUMN = 4;
		const int NUMBER_OF_COLUMNS = 5;

		Controller& actionController;

	public:
		CustomTableModel(Controller& actionController, QObject* parent = NULL);
		~CustomTableModel();
		int rowCount(const QModelIndex& parent = QModelIndex{}) const override;
		int columnCount(const QModelIndex& parent = QModelIndex{}) const override;
		QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
		QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
		Qt::ItemFlags flags(const QModelIndex& index) const override;
		void update() override;
};

