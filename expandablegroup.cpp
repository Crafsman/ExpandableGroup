#include "expandablegroup.h"
#include "DIYBtn.h"
#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>
#include <QScrollArea>
#include <QDial>
#include "DIYBtn.h"


ExpandableWidget::ExpandableWidget(int nr_Group, QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
// 	ui.setupUi(this);
// 	DIYBtn *btn = new DIYBtn(ui.widget);
//     ui.verticalLayout_5->addWidget(btn);
	m_nrGroup = nr_Group;
	if (parent == NULL)
	{
		setupUi(this);
	}else
	{
		setupUi(parent);
	}
	
	

}

ExpandableWidget::~ExpandableWidget()
{
	
}


void ExpandableWidget::setupUi( QWidget* ExpandableGroupClass )
{
	#if 1
	//this->setGeometry(300)
// 	QHBoxLayout *ExpandableGroupClass_HL;
// 	QScrollArea *scrollArea;
// 	QWidget *scrollAreaWidgetContents;
// 	QVBoxLayout *scrollAreaWidgetContents_VL;
// 	QSpacerItem *verticalSpacer;

	if (ExpandableGroupClass->objectName().isEmpty())
		ExpandableGroupClass->setObjectName(QString::fromUtf8("ExpandableGroupClass"));
	ExpandableGroupClass->resize(261, 721);

	m_expandableGroupClass_HL = new QHBoxLayout(ExpandableGroupClass);
	m_expandableGroupClass_HL->setSpacing(6);
	m_expandableGroupClass_HL->setContentsMargins(11, 11, 11, 11);
	m_expandableGroupClass_HL->setObjectName(QString::fromUtf8("horizontalLayout"));

	m_scrollArea = new QScrollArea(ExpandableGroupClass);
	m_scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
	m_scrollArea->setAutoFillBackground(true);
	m_scrollArea->setFrameShape(QFrame::Box);
	m_scrollArea->setWidgetResizable(true);

	 m_scrollAreaWidgetContents = new QWidget();
	 m_scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
	 m_scrollAreaWidgetContents->setGeometry(QRect(0, 0, 241, 701));
	 m_scrollAreaWidgetContents->setAutoFillBackground(true);

	 m_scrollAreaWidgetContents_VL = new QVBoxLayout(m_scrollAreaWidgetContents);
	 m_scrollAreaWidgetContents_VL->setSpacing(6);
	 m_scrollAreaWidgetContents_VL->setContentsMargins(11, 11, 11, 11);
	 m_scrollAreaWidgetContents_VL->setObjectName(QString::fromUtf8("verticalLayout_7"));


#if 0
	 group1_VL = new QVBoxLayout();
	 group1_VL->setSpacing(0);
	 group1_VL->setObjectName(QString::fromUtf8("verticalLayout"));

	 widget = new QWidget(scrollAreaWidgetContents);
	 widget->setObjectName(QString::fromUtf8("widget"));
	 widget->setAutoFillBackground(false);

	  DIYBtn *btn = new DIYBtn(widget);

	 widget_VL = new QVBoxLayout(widget);
	 widget_VL->setSpacing(6);
	 widget_VL->setContentsMargins(11, 11, 11, 11);
	 widget_VL->setObjectName(QString::fromUtf8("verticalLayout_5"));
	 widget_VL->setContentsMargins(0, -1, 0, 0);

	  widget_VL->addWidget(btn);

	 group1_VL->addWidget(widget);

	 //////////////////////////////////////////////////////////////////////////
	 frame = new QFrame(scrollAreaWidgetContents);
	 frame->setObjectName(QString::fromUtf8("frame"));
	 frame->setFrameShape(QFrame::Box);
	 frame->setFrameShadow(QFrame::Raised);
	 frame_VL = new QVBoxLayout(frame);
	 frame_VL->setSpacing(6);
	 frame_VL->setContentsMargins(11, 11, 11, 11);
	 frame_VL->setObjectName(QString::fromUtf8("verticalLayout_3"));
	 frame_VL->setContentsMargins(5, 5, 5, -1);

	 radioButton = new QRadioButton(frame);
	 radioButton->setObjectName(QString::fromUtf8("radioButton"));
	 frame_VL->addWidget(radioButton);

	 pushButton = new QPushButton(frame);
	 pushButton->setObjectName(QString::fromUtf8("pushButton"));
	 frame_VL->addWidget(pushButton);

	 group1_VL->addWidget(frame);
	 scrollAreaWidgetContents_VL->addLayout(group1_VL);
	 
	
#endif

	/****************添加其它的expandableGroup************************************/
	 for (int i = 0; i < m_nrGroup; i++)
	 {
		 //添加其它的expandableGroup
		 /************************************************************************/
		QVBoxLayout *groupName_VL;
		QVBoxLayout *widget_VL;
	    QWidget *widget;	
		//下层存放组件的布局
		QVBoxLayout *frame_VL ;
		//cell
		//QHBoxLayout *horizontalLayout;

		//默认组的名字形式为“groupN” N 为1， 2， 3 ……
		 char buffer[5]="";
		 std::string groupName = "group";
 		 _itoa_s(i , buffer, 5, 10);
 		 groupName += buffer; 
 
		  groupName_VL = new QVBoxLayout();
		  groupName_VL->setSpacing(0);
		  groupName_VL->setObjectName(QString::fromUtf8("verticalLayout"));
		  
		 //The upper widget
		  widget = new QWidget(m_scrollAreaWidgetContents);
		  widget->setObjectName(QString::fromUtf8("widget"));
		  widget->setAutoFillBackground(false);
		  DIYBtn *btn = new DIYBtn(widget);
		 // btn->setWidgetTitle("hello");
		  widget_VL = new QVBoxLayout(widget);
		  widget_VL->setSpacing(6);
		  widget_VL->setContentsMargins(11, 11, 11, 11);
		  widget_VL->setObjectName(QString::fromUtf8("verticalLayout_5"));
		  widget_VL->setContentsMargins(0, -1, 0, 0);
		  widget_VL->addWidget(btn);
		  groupName_VL->addWidget(widget);

	

		  //////////////////////////////////////////////////////////////////////////
		  QFrame *frame = new QFrame(m_scrollAreaWidgetContents);
		  frame->setObjectName(QString::fromUtf8("frame"));
		  frame->setFrameShape(QFrame::Box);
		  frame->setFrameShadow(QFrame::Raised);
		  frame->setVisible(false);
		  frame_VL = new QVBoxLayout(frame);
		  frame_VL->setSpacing(6);
		  frame_VL->setContentsMargins(11, 11, 11, 11);
		  frame_VL->setObjectName(QString::fromUtf8("verticalLayout_3"));
		  frame_VL->setContentsMargins(5, 5, 5, -1);

		  //水平布局用于和弹簧组合
		//  horizontalLayout = new QHBoxLayout();
		//  horizontalLayout->setSpacing(6);
		//  horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
		  //horizontalLayout->addWidget(spinBox);

		 // frame_VL->addLayout(horizontalLayout);

		  GROUP group;
		  group.ID = i;
		  group.groupName = groupName;
		  group.btn  = btn;
		  group.frame_VL = frame_VL;
		//  group.cell_HL = horizontalLayout;
		  groups.push_back(group);

		  //新建组件并添加
// 		   QRadioButton *radioButton = new QRadioButton(frame);
// 		  radioButton->setObjectName(QString::fromUtf8("radioButton"));
// 		  frame_VL->addWidget(radioButton);
// 		  QPushButton *pushButton = new QPushButton(frame);
// 		  pushButton->setObjectName(QString::fromUtf8("pushButton"));
// 		  frame_VL->addWidget(pushButton);


		  groupName_VL->addWidget(frame);

		  m_scrollAreaWidgetContents_VL->addLayout(groupName_VL);


		  connect(btn, SIGNAL(toggled(bool)), frame, SLOT(setVisible(bool)));

	 
			 /* createGroup();*/
		 /************************************************************************/
		

	 }

	/************************************************************************/

	 m_verticalSpacer = new QSpacerItem(20, 507, QSizePolicy::Minimum, QSizePolicy::Expanding);
	 m_scrollAreaWidgetContents_VL->addItem(m_verticalSpacer);

	 m_scrollArea->setWidget(m_scrollAreaWidgetContents);

	 m_expandableGroupClass_HL->addWidget(m_scrollArea);

	 QMetaObject::connectSlotsByName(ExpandableGroupClass);

#endif
}

void ExpandableWidget::setTilteName(int groupIndex, const QString &name )
{
	if (groupIndex >= groups.size())
	{
		return;
	}else
	{
		groups[groupIndex].btn->setWidgetTitle(name);
	}

	
}

void ExpandableWidget::addWidget( int groupIndex, QWidget* widget )
{
	if (groupIndex >= groups.size())
		return;
	//widget->setParent(groups[groupIndex].frame_VL);
	groups[groupIndex].frame_VL->addWidget(widget);

	//cell
 	QHBoxLayout *cellHL = new QHBoxLayout;
 	cellHL->setSpacing(6);
	groups[groupIndex].cell_HL = cellHL;
 	//cellHL->setObjectName(QString::fromUtf8("horizontalLayout"));
 	groups[groupIndex].cell_HL->addWidget(widget);

 	QSpacerItem *horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
 	groups[groupIndex].cell_HL->addItem(horizontalSpacer_2);
 	groups[groupIndex].frame_VL->addLayout(cellHL);
	

}

void ExpandableWidget::addWidget( int groupIndex, QWidget* leftWidget, QWidget* rightWidget )
{
	if (groupIndex >= groups.size())
		return;
	//widget->setParent(groups[groupIndex].frame_VL);
	//groups[groupIndex].frame_VL->addWidget(widget);

	//cell
	QHBoxLayout *cellHL = new QHBoxLayout;
	cellHL->setSpacing(6);
	groups[groupIndex].cell_HL = cellHL;
	cellHL->setObjectName(QString::fromUtf8("cellHorizontalLayout"));

	groups[groupIndex].cell_HL->addWidget(leftWidget);
	groups[groupIndex].cell_HL->addWidget(rightWidget);

	groups[groupIndex].frame_VL->addLayout(cellHL);
	
}

/*
void ExpandableGroup::createGroup()
{
	QVBoxLayout *group1_VL;
	group1_VL = new QVBoxLayout();
	group1_VL->setSpacing(0);
	group1_VL->setObjectName(QString::fromUtf8("verticalLayout"));

	//Upper Button
	widget = new QWidget(scrollAreaWidgetContents);
	widget->setObjectName(QString::fromUtf8("widget"));
	widget->setAutoFillBackground(false);
	DIYBtn *btn = new DIYBtn(widget);
	widget_VL = new QVBoxLayout(widget);
	widget_VL->setSpacing(6);
	widget_VL->setContentsMargins(11, 11, 11, 11);
	widget_VL->setObjectName(QString::fromUtf8("verticalLayout_5"));
	widget_VL->setContentsMargins(0, -1, 0, 0);
	widget_VL->addWidget(btn);
	group1_VL->addWidget(widget);

	//////////////////////////////////////////////////////////////////////////
	frame = new QFrame(scrollAreaWidgetContents);
	frame->setObjectName(QString::fromUtf8("frame"));
	frame->setFrameShape(QFrame::Box);
	frame->setFrameShadow(QFrame::Raised);
	frame->setVisible(false);
	frame_VL = new QVBoxLayout(frame);
	frame_VL->setSpacing(6);
	frame_VL->setContentsMargins(11, 11, 11, 11);
	frame_VL->setObjectName(QString::fromUtf8("verticalLayout_3"));
	frame_VL->setContentsMargins(5, 5, 5, -1);

	//新建组件并添加
	radioButton = new QRadioButton(frame);
	radioButton->setObjectName(QString::fromUtf8("radioButton"));
	frame_VL->addWidget(radioButton);

	pushButton = new QPushButton(frame);
	pushButton->setObjectName(QString::fromUtf8("pushButton"));
	frame_VL->addWidget(pushButton);

	group1_VL->addWidget(frame);

	scrollAreaWidgetContents_VL->addLayout(group1_VL);


	connect(btn, SIGNAL(toggled(bool)), frame, SLOT(setVisible(bool)));
}

*/
