#ifndef PROPERTIESPANEL_H
#define PROPERTIESPANEL_H

#include <QWidget>
#include "ui_PropertiesPanel.h"
class ExpanderButton;

class PropertiesPanel : public QWidget
{
	Q_OBJECT

public:
	PropertiesPanel(QWidget *parent = 0);
	~PropertiesPanel();

private:
	Ui::PropertiesPanel ui;

	void creatConnect();

	bool m_isDisplay1;
	bool m_isDisplay2;
	bool m_isDisplay3;
	ExpanderButton *expandButton;
	ExpanderButton *expandButton2;

	private slots:
// 		void echobutton3();
// 		void on_pushButton1_clicked();
// 		void on_pushButton2_clicked();
		//void on_pushButton3_clicked();
};

#endif // PROPERTIESPANEL_H
