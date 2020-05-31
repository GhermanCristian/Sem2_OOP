#pragma once
#include <qstyleditemdelegate.h>
#include <QPixmap>
#include <QPainter>
#include <qdebug.h>
#include "controller.h"

class CustomDelegate : public QStyledItemDelegate{
	private:
		const int PHOTOGRAPH_COLUMN = 3;
		const int PHOTOGRAPH_HEIGHT = 130;
		const int PHOTOGRAPH_WIDTH = 130;

		const QString IMAGES_FOLDER = "Images\\";
		const QString DEFAULT_IMAGE_PATH = "Images\\default_photo.jpg";

	public:
		CustomDelegate(QWidget* parent = 0);
		void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
		QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const override;
};

