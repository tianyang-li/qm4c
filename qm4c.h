#ifndef QM4C_H
#define QM4C_H

#include <QtGui/QMainWindow>
#include "ui_qm4c.h"

class QM4C : public QMainWindow
{
	Q_OBJECT

public:
	QM4C(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QM4C();

private:
	Ui::QM4CClass ui;
};

#endif // QM4C_H
