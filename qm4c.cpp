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
#include <QString>

#include "qm4c.h"
#include "ui_about_QM4C_dlg.h"
#include "ui_QM4C_help_dlg.h"
#include "ui_please_wait_dlg.h"
#include "ui_input_error_dlg.h"

#include "simplify_bool_expr.h"

QM4C::QM4C(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	connect(ui.simplifyButton, SIGNAL(clicked()), this, SLOT(SimplifyExpr()));
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

void QM4C::SimplifyExpr() {

	input_expr_ = (ui.boolExprInput->toPlainText()).toStdString();

	// remove returns
	int ret_loc = input_expr_.find('\n');
	if (ret_loc != std::string::npos) {
		input_expr_.erase(ret_loc);
	}

	Ui::PleaseWaitDlg please_wait_dlg_ui;
	QDialog please_wait;
	please_wait_dlg_ui.setupUi(&please_wait);
	please_wait.show();

	// TODO: add simplification here

	please_wait.close();

	SimplifyBoolExpr simplify_input;
	if (!simplify_input.MakeSimple(input_expr_, output_expr_)) {
		// TODO: make errors more informative?
		QDialog error_dlg;
		Ui::InputErrorDlg error_dlg_ui;
		error_dlg_ui.setupUi(&error_dlg);
		error_dlg.exec();
		return;
	}

	ui.boolExprOutput->setPlainText(QString::fromStdString(output_expr_));

}

