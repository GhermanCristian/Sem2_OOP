#include "customDelegate.h"

CustomDelegate::CustomDelegate(QWidget* parent){
	;
}

void CustomDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const{
	QString victim = index.model()->data(index).toString();

	if (index.column() != PHOTOGRAPH_COLUMN) { //we only care about the photograph column
		QStyledItemDelegate::paint(painter, option, index);
		return;
	}

	QString imagePath;
	if (victim.contains("photo")) {
		imagePath = IMAGES_FOLDER + victim; // this is just a workaround, I need something la os.path.join from python
	}
	else {
		imagePath = DEFAULT_IMAGE_PATH;
	}
	QPixmap pixMap(imagePath);
	painter->drawPixmap(option.rect, pixMap);
}

QSize CustomDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const{
	if (index.column() != PHOTOGRAPH_COLUMN) {//we only care about the photograph column
		return QStyledItemDelegate::sizeHint(option, index);
	}
	return QSize(PHOTOGRAPH_WIDTH, PHOTOGRAPH_HEIGHT);
}
