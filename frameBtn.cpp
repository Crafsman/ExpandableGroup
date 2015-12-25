#include "frameBtn.h"
#include <QMouseEvent>
#include <QPalette>


ExpanderButton::ExpanderButton(QWidget *parent)
	: QFrame(parent),
	isChecked(false),
	flag(false)
{
	
	ui.setupUi(this);
	/*QPalette pal = palette();
	pal.setColor(QPalette::Background, QColor(187, 227,202,255));
	setPalette(pal);*/
	setAutoFillBackground(true);
	//Set Style Sheet
 	//QString styleSheet("border-radius: 5px;background-color: #FFFFFF; background-color: #05B8CC;border-radius: 5px;");
	QString styleSheet("border-radius: 5px;background-color:rgb(187, 227,202)");
 	setStyleSheet(styleSheet);

}

ExpanderButton::~ExpanderButton()
{

}

void ExpanderButton::mousePressEvent(QMouseEvent *evt)
{
	if (evt->button() == Qt::LeftButton && evt->buttons() == Qt::LeftButton)
	{
		this->isChecked = true;
	}

}

void ExpanderButton::mouseReleaseEvent(QMouseEvent *evt)
{

	if (this->isChecked && evt->button() == Qt::LeftButton)
	{
		
		this->toggle();
		this->isChecked = false;
	}
}

void ExpanderButton::toggle()
{
	this->setChecked(flag);
}

void ExpanderButton::setChecked(bool val)
{
	QPixmap CheckedPixmap("pqMinus16.png");
	QPixmap UnchekedPixmap("pqPlus16.png");

// 	if (this->checked() == val)
// 	{
// 		return;
// 	}
	//this->isChecked = val;
	if (val)
	{
		ui.icon->setPixmap(CheckedPixmap);
		flag = false;
	}
	else
	{
		ui.icon->setPixmap(UnchekedPixmap);
		flag = true;
	}
	emit toggled(flag);
}

void ExpanderButton::setText(const QString& text)
{
	ui.label->setText(text);
}

QString ExpanderButton::text() const
{
	return ui.label->text();
}