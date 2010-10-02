/*
 *  Copyright (C) 2010 Tianyang Li
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author Tianyang Li 
 * E-Mail tmy1018 gmail com
 */

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

	void setupActions();  // setup actions in menu, Help, About, etc.

private slots:
	void AboutQM4COpen();
	void QM4CHelpOpen();
};

#endif // QM4C_H
