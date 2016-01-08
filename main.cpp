#include "expandablegroup.h"
#include <QtGui/QApplication>

#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QDockWidget>
#include <QLabel>
//#include "ui_mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	ExpandableWidget *w= new ExpandableWidget(4);
	///////////////////// Group1 /////////////////////////////////////////////////////
 	w->setTilteName(0, "hhh");
	QPushButton *btn = new QPushButton;
	btn->setText("btn");
	w->addWidget(0, btn);
	QRadioButton *radioButn = new QRadioButton;
	radioButn->setText("radioBtn1");
	w->addWidget(0, radioButn);
	QRadioButton *radioButn2 = new QRadioButton;
	radioButn2->setText("radioBtn2");
	w->addWidget(0, radioButn2);
	QCheckBox *checkBox = new QCheckBox;
	checkBox->setText("checkBox");
	w->addWidget(0, checkBox);

	
	/////////////////// Group2 ///////////////////////////////////////////////////////
	QLabel *label = new QLabel("label");
	QSpinBox *spin2 = new QSpinBox;
	w->addWidget(1, label, spin2);

	//////////////////// GroupN //////////////////////////////////////////////////////
	//w->setTilteName(4, "www");

	w->show();

	return a.exec();
}
