#pragma once
#include <qabstractitemmodel.h>
#include "controller.h"
#include <qfont.h>
#include <qdebug.h>

class CustomTableModel : public QAbstractTableModel{
	private:
		const int TABLE_FONT_SIZE = 14;
		const std::string TABLE_FONT_NAME = "Candara";

		int elementCount;
		Controller& actionController;

	public:
		CustomTableModel(Controller& actionController, QObject* parent = NULL);
		~CustomTableModel();
		int rowCount(const QModelIndex& parent = QModelIndex{}) const override;
		int columnCount(const QModelIndex& parent = QModelIndex{}) const override;
		QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
		QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
		bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
		Qt::ItemFlags flags(const QModelIndex& index) const override;
};

