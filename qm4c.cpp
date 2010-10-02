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

#include <QtGui/QDialog>

#include "qm4c.h"
#include "ui_about_QM4C_dlg.h"
#include "ui_QM4C_help_dlg.h"

QM4C::QM4C(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	setupActions();
}

QM4C::~QM4C()
{

}

void QM4C::setupActions() {
	connect(ui.actionAbout_QM4C, SIGNAL(triggered(bool)), this, SLOT(AboutQM4COpen()));
	connect(ui.actionQM4C_Help, SIGNAL(triggered(bool)), this, SLOT(QM4CHelpOpen()));
}

void QM4C::AboutQM4COpen() {
	Ui::AboutQM4CDlg about_dlg_ui;
	QDialog about_dlg;
	about_dlg_ui.setupUi(&about_dlg);
	about_dlg.exec();
}

void QM4C::QM4CHelpOpen() {
	Ui::QM4CHelpDlg help_dlg_ui;
	QDialog help_dlg;
	help_dlg_ui.setupUi(&help_dlg);
	help_dlg.exec();
}

