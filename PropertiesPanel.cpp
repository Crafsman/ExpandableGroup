#include "PropertiesPanel.h"
#include "frameBtn.h"
#include <QPushButton>
#include <QVBoxLayout>

PropertiesPanel::PropertiesPanel(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	
	//ui.pushButton->setDisabled(true);
	//ui.widget->setGeometry(QRect(0, 0, 258, 100));
	expandButton = new ExpanderButton(ui.widget);
	QRect widgetRect= ui.widget->geometry();
	ui.verticalLayout_5->addWidget(expandButton);
	int h = expandButton->height();
	int widgetHeiht = ui.widget->height();
	//framRect.width();
	//expandButton->setText("132323");
	
	//expandButton->setGeometry(0, 0, 276, 30);

	expandButton2 = new ExpanderButton(ui.widget_2);
	ui.verticalLayout_2->addWidget(expandButton2);
	//expandButton2->setAutoFillBackground(true);
	//expandButton2->setBackgroundRole(pal)
	//ui.frame->hide();
// 	QPushButton * btn = new QPushButton(ui.frame);
// 	ui.frame->setGeometry(0, 100, 258, 100);
	QRect rect = ui.frame->geometry();
// 	ui.frame->show();
// 	ui.frame->hide();
	/*ui.widget->seta*/
	creatConnect();
}

PropertiesPanel::~PropertiesPanel()
{

}

void PropertiesPanel::creatConnect()
{
	QObject::connect(expandButton, SIGNAL(toggled(bool)),
		ui.frame, SLOT(setVisible(bool)));
	QObject::connect(expandButton2, SIGNAL(toggled(bool)),
		ui.frame_2, SLOT(setVisible(bool)));
}
