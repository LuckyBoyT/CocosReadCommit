#ifndef C_H
#define C_H

#include <QtWidgets/QWidget>
#include "ui_c.h"
#include "CustomClass.h"
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QShortCut>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include <QHBoxLayout>
#include <QtDebug>
#include <QToolButton>
#include <QMouseEvent>
#include <QScrollArea>
#include <QLabel>
#include "MyToolButton.h"
#include <QToolBar>
#include <QMenu>
#include "MyLabelRow.h"
#include <QMimeData>
#include "Contain.h"
#include <QMessageBox>
#include <QFileDialog>
#include "PictureSign.h"
#include "PictureMessage.h"
#include "PictureEditedWidget.h"

class c : public QWidget
{
	Q_OBJECT

public:
	c(QWidget *parent = 0);
	~c();

protected:
	bool eventFilter(QObject *o, QEvent *e);
	void leaveEvent(QEvent *event)override;
	void mousePressEvent(QMouseEvent *event)override;
	void mouseMoveEvent(QMouseEvent *event)override;
	void mouseReleaseEvent(QMouseEvent *event)override;
	void keyPressEvent(QKeyEvent *event)override;
	void contextMenuEvent(QContextMenuEvent *event)override;
	void resizeEvent(QResizeEvent *event)override;
	void dragEnterEvent(QDragEnterEvent *event);
	void dragMoveEvent(QDragMoveEvent *event);
	void dropEvent(QDropEvent *event);
	void closeEvent(QCloseEvent *event);
	void wheelEvent(QWheelEvent *event);
private:
	//��ʼ������.
	void initWindow();
	//��ʼ�����ߵİ�ť.
	void initSidesButtons();
	//��ʼ���ɹ�������.
	void initScrollArea();
	//��ʼ��������.
	void initToolButtonBar();
	//��ʼ���Ҽ��˵�.
	void initContextMenu();
	//��ʼ��ͼƬ�༭����.
	void initEditedWidget();

	//�ø������ص���ʼ״̬.
	void returnDefaultPos();
	//�����ź����.
	void initConnect();
	//��ʼ��LabelArray.
	void initLabelArray(QSize,int);
	//��ʼ����ʾlabel.
	void initToolTipLabel();
	//����ÿ��label���ź����.
	void connectLabelRowOneByOne();
	//���LabelRow��Label.
	void clearRowLabelAndLabel();
	//���¼���ͼƬ.
	void reLoadFileAndPressentPictureId(QString);
	////��ȡ���µ�ͼƬ��·���е�ͼƬλ��.
	int  returnDropPictureId(QString path);
	//�ƶ�labelRow.
	void moveLabelRow(int pos);
	//����Ҫ��ʾ��ͼƬ,�޸�label�Ĵ�С.
	void resizeLabelWithPicture(QImage *image);
	//��ʾlabelRow�߿�.
	void showSelectedLabelFrame(int newSelected);
	//��ʾlabelRow�е�ͼƬ.
	void showLabelPicture();
	//
	void resizePictureSignPos();

	//�������汳��.
	void setBgPicture(QString style, QString tile);
	//������ʶ��.
	void initPictureSign();
	//��ͼƬ�������Ŵ���.
	void scaledPicture(int);

	//��ת�ĺ���.
	void rotatePixmap(float angle);
	//��ת�ĺ���.
	void filpPixmap(bool,bool);
private slots:
	//�����빤�����Ĳۺ���.
	void enterToolBarSlot();
	//����뿪�������Ĳۺ���.
	void setToolTipLabelText();

	//�����labelRow�е�ͼƬ�����Ĳۺ���.����ΪͼƬ���±�.
	void moveLabelRowSlot(QWidget *);

	//������������Ĳۺ���.
	void pressBoostButtonSlot();
	void pressReduceButtonSlot();
	void pressSizeHintButtonSlot();
	void pressBeautiButtonSlot();
	void pressPreciousButtonSlot();
	void pressNextButtonSlot();
	void pressRorateSlot();
	void pressFilpSlot();
	void pressMoreButtonSlot();

	//�Ҽ��˵��Ķ�Ӧ�Ĳۺ���.
	void contextUpdateSlot();
	void contextMenuBatchConverFormatSlot();
	void contextMenuBatchConverSizeSlot();
	void contextMenuBatchRenameSlot();
	void contextMenuCutSlot();
	void contextMenuCopySlot();
	void contextMenuSaveAsSlot();
	void contextMenuPrintPictureSlot();
	void contextMenuOpenPicturePathSlot();
	void contextMenuLookPictureFirstSlot();
	void contextMenuDelSlot();
	void contextMenuPicturePropertySlot();
	void contextMenuCenterSlot();
	void contextMenuStretchSlot();
	void contextMenuTileSlot();
private:
	Ui::cClass ui;
	//���ߵİ�ť.
	QToolButton *m_leftButton;
	QToolButton *m_rightButton;
	//��������Ŀɹ�������.
	QScrollArea *m_area;
	//���ĵ�QLabel.
	QLabel *m_label;
	//�����labelArray.
	MyLabelRow *m_labelRow;
	//��ʾLable.
	QLabel *m_toolTipLabel;

	//��¼�Ƿ񴴽���labelRow.
	bool isCreateLabelRow = false;

	//���汻ѡ�е�ͼƬ.
	QPixmap m_showPicture;
	//���澭�����ź��ͼƬ.
	QImage m_tempPicture;
	//��ʶ�Ƿ�����ת.��¼����ת�ĽǶ�.
	bool isTransformSign = false;
	float rotateAngle = 0;
	//��ʶ,�Ƿ���ʾ����ʾ����.
	bool isShowedMessageSign = false;
	//������ʶ��.
	PictureSign *m_firstSign;
	PictureSign *m_lastSign;
	//ͼƬ��Ϣ�Ի���Ķ���.
	PictureMessage *m_pictureMessageDialog;

	//ͼƬ�༭.
	PictureEditedWidget *m_editedPictureWidget;

	//��������֮ǰ��λ��.
	QPoint m_precMousePos;
	//�����������ű����λ��.
	QPoint m_scaleMousePos;
	//������¼�û��Ƿ�������ƶ�.
	bool m_isPressed;

	//���浱ǰ��ͼƬ���ŵı�����С.
	int m_scalNumber;

	//���������Ƿ����ˮƽ�ʹ�ֱ�����ϵı任.
	bool m_isHorizontalFilpSign = false;
	bool m_isVerticalFilpSign = false;
	

	//����������.
	QToolBar *m_bottomToolBar;
	MyToolButton *m_boostButton;
	MyToolButton *m_reduceButton;
	MyToolButton *m_sizeHintButton;
	MyToolButton *m_beautiButton;
	MyToolButton *m_preciousButton;
	MyToolButton *m_nextButton;
	MyToolButton *m_leftRotateButton;
	MyToolButton *m_rightRotateButton;
	MyToolButton *m_horizontalFilpButton;
	MyToolButton *m_verticalFilpButton;
	MyToolButton *m_delButton;
	MyToolButton *m_moreButton;

	//�Ҽ��˵�����.
	QMenu *m_menu;
	QMenu *m_editPictureMenu;
	QMenu *m_setBackGroundMenu;
	QAction *m_updateAction;
	QAction *m_batchConverFormatAction;
	QAction *m_batchConverSizeAction;
	QAction *m_batchRenameAction;
	QAction *m_cutAction;
	QAction *m_copyAction;
	QAction *m_saveAsAction;
	QAction *m_openPicturePathAction;
	QAction *m_printPictureAction;
	QAction *m_lookPictureFirstAction;
	QAction *m_delAction;
	QAction *m_picturePropertyAction;
	QAction *m_centerAction;
	QAction *m_stretchAction;
	QAction *m_tileAction;
};

#endif // C_H
