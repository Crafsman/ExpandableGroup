#ifndef DIYBTN_H
#define DIYBTN_H

#include <QFrame>
class QHBoxLayout;
class QLabel;
class QIcon;

class DIYBtn : public QFrame
{
	Q_OBJECT

	//Q_PROPERTY(bool checked READ checked WRITE setChecked)

public:
	DIYBtn(QWidget *parent = 0);
	~DIYBtn();

	void setWidgetTitle(const QString& str);
	QString widgetTitle() const;

	void setWidgetIcon(QPixmap checkedPixmap, QPixmap unchekedPixmap);

public slots:
	//Toggles the state of the checkable button
	void toggle();

	void setChecked(bool);
	inline bool checked() const{return isChecked; }


signals:
	void toggled(bool checked);
	

protected:
	void mousePressEvent(QMouseEvent *evt);
	void mouseReleaseEvent(QMouseEvent * evt);

private:

	void setupUi(QFrame *MyFrame);

	Q_DISABLE_COPY(DIYBtn);

	QHBoxLayout *m_horizontalLayout;
	QLabel *m_widgetTitle;
	QLabel *m_widgetIcon;

	QString m_strWidgetTitle;
	bool isChecked;
	bool flag;

	QPixmap m_CheckedPixmap;
	QPixmap m_UnchekedPixmap;
};

#endif // DIYBTN_H
