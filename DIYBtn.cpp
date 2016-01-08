#include "DIYBtn.h"
#include <QLabel>
#include <QIcon>
#include <QHBoxLayout>
#include <QMouseEvent>

DIYBtn::DIYBtn(QWidget *parent)
	: QFrame(parent ),
	isChecked(false),
	flag(false)
{

	QPixmap UnchekedPixmap ("pqMinus16.png");
	QPixmap CheckedPixmap("pqPlus16.png");

	setWidgetIcon(CheckedPixmap, UnchekedPixmap);
	setupUi(this);
	setWidgetTitle("title");

}

DIYBtn::~DIYBtn()
{
}

void DIYBtn::setupUi(QFrame *MyFrame)
{
	if (MyFrame->objectName().isEmpty())
		MyFrame->setObjectName(QString::fromUtf8("MyFrame"));
	MyFrame->setWindowModality(Qt::NonModal);
	MyFrame->resize(150, 25);
	MyFrame->setFrameShape(QFrame::Panel);
	MyFrame->setFrameShadow(QFrame::Raised);
	MyFrame->setLineWidth(1);

	m_horizontalLayout = new QHBoxLayout(MyFrame);
	m_horizontalLayout->setSpacing(6);
	m_horizontalLayout->setContentsMargins(11, 11, 11, 11);
	m_horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
	m_horizontalLayout->setContentsMargins(-1, 4, -1, 4);
	m_widgetTitle = new QLabel(MyFrame);
	m_widgetTitle->setObjectName(QString::fromUtf8("WidgetTitle"));
	//m_widgetTitle->setText("title");

	m_horizontalLayout->addWidget(m_widgetTitle);

	m_widgetIcon = new QLabel(MyFrame);
	m_widgetIcon->setObjectName(QString::fromUtf8("WidgetIcon"));
	m_widgetIcon->setEnabled(true);
	//m_widgetIcon->setText("addIconHere");
	//m_widgetIcon->setPixmap()
	m_widgetIcon->setPixmap(m_CheckedPixmap);

	m_widgetIcon->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

	m_horizontalLayout->addWidget(m_widgetIcon);

	m_horizontalLayout->setStretch(1, 1);

	QMetaObject::connectSlotsByName(MyFrame);

	QString styleSheet("border-radius: 5px;background-color:rgb(187, 227,202)");
	setStyleSheet(styleSheet);



}


void DIYBtn::toggle()
{
	setChecked(flag);
}

void DIYBtn::mousePressEvent( QMouseEvent *evt )
{
	if (evt->button() == Qt::LeftButton && evt->buttons() == Qt::LeftButton)
	{
		this->isChecked = true;
	}
}

void DIYBtn::mouseReleaseEvent( QMouseEvent * evt )
{
	if (isChecked && evt->button() == Qt::LeftButton)
	{
		toggle();
		isChecked = false;
	}
}

void DIYBtn::setChecked( bool val)
{

	if (val)
	{
		m_widgetIcon->setPixmap(m_CheckedPixmap);
		flag = false;
	}
	else
	{
		m_widgetIcon->setPixmap(m_UnchekedPixmap);
		flag = true;
	}
	emit toggled(flag);
}

void DIYBtn::setWidgetTitle(const QString& str)
{
	m_strWidgetTitle = str;
	m_widgetTitle->setText(m_strWidgetTitle);
}

QString DIYBtn::widgetTitle() const
{
	return m_strWidgetTitle;
}

void DIYBtn::setWidgetIcon( QPixmap checkedPixmap, QPixmap unchekedPixmap )
{
	 m_CheckedPixmap =checkedPixmap;
	 m_UnchekedPixmap=unchekedPixmap;
}
