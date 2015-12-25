#ifndef MYFRAME_H
#define MYFRAME_H

#include <QFrame>
#include "ui_frameBtn.h"

class ExpanderButton : public QFrame
{
	Q_OBJECT
	typedef QFrame Superclass;

	Q_PROPERTY(QString text READ text WRITE setText)
	Q_PROPERTY(bool checked READ checked WRITE setChecked)


public:
	ExpanderButton(QWidget *parent = 0);
	~ExpanderButton();

public slots:
	//Toggles the state of the checkable button
	void toggle();


	//This property holds whether the button is checked.By default ,the button is unchecked
	void setChecked(bool);
	bool checked() const
	{
		return this->isChecked;
	}
	
	//This property holds the text shown on the button
	void setText(const QString& text);
	QString text() const;

	//
signals:
	//This signals is emitted whenever a button changes its state.
	//checked is true if the button is checked, or false if the button is unchecked
	void toggled(bool checked);

protected:
	void mousePressEvent(QMouseEvent *evt);
	void mouseReleaseEvent(QMouseEvent *evt);

private:

	Q_DISABLE_COPY(ExpanderButton)
 	Ui::MyFrame ui;
	
	bool isChecked;
	bool flag;

};

#endif // MYFRAME_H
