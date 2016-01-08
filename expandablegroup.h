#ifndef EXPANDABLEGROUP_H
#define EXPANDABLEGROUP_H

#include <QtGui/QWidget>
#include "ui_expandablegroup.h"

class QHBoxLayout;
class QScrollArea;
class QVBoxLayout;
class QSpacerItem;
class DIYBtn;
class ExpandableWidget : public QWidget
{
	Q_OBJECT

public:
	ExpandableWidget(int nr_Group, QWidget *parent = 0, Qt::WFlags flags = 0);
	~ExpandableWidget();

	/*设置第n个group组件的名字，下标从0开始*/
	void setTilteName(int groupIndex, const QString &name = "title");
	
	void addWidget(int groupIndex, QWidget* widget);
	void addWidget(int groupIndex, QWidget* leftWidget, QWidget* rightWidget);


private:

	struct GROUP
	{
		int      ID;
		DIYBtn *btn; 
		QVBoxLayout *frame_VL;
		//cell
		QHBoxLayout *cell_HL;
		std::string groupName;
	};

	void createGroup();

	Ui::ExpandableGroupClass ui;
	void setupUi(QWidget* ExpandableGroupClass);

	std::vector<GROUP> groups;
	int m_nrGroup;
	
	//////////////////////////////////////////////////////////////////////////
	QHBoxLayout *m_expandableGroupClass_HL;
	QScrollArea *m_scrollArea;
	QWidget *m_scrollAreaWidgetContents;
	QVBoxLayout *m_scrollAreaWidgetContents_VL;
	QSpacerItem *m_verticalSpacer;
	

};

#endif // EXPANDABLEGROUP_H
