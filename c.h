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
	//初始化窗口.
	void initWindow();
	//初始化两边的按钮.
	void initSidesButtons();
	//初始化可滚动区域.
	void initScrollArea();
	//初始化工具条.
	void initToolButtonBar();
	//初始化右键菜单.
	void initContextMenu();
	//初始化图片编辑窗口.
	void initEditedWidget();

	//让各部件回到初始状态.
	void returnDefaultPos();
	//连接信号与槽.
	void initConnect();
	//初始化LabelArray.
	void initLabelArray(QSize,int);
	//初始化提示label.
	void initToolTipLabel();
	//连接每个label的信号与槽.
	void connectLabelRowOneByOne();
	//清空LabelRow和Label.
	void clearRowLabelAndLabel();
	//重新加载图片.
	void reLoadFileAndPressentPictureId(QString);
	////获取放下的图片在路径中的图片位置.
	int  returnDropPictureId(QString path);
	//移动labelRow.
	void moveLabelRow(int pos);
	//根据要显示的图片,修改label的大小.
	void resizeLabelWithPicture(QImage *image);
	//显示labelRow边框.
	void showSelectedLabelFrame(int newSelected);
	//显示labelRow中的图片.
	void showLabelPicture();
	//
	void resizePictureSignPos();

	//设置桌面背景.
	void setBgPicture(QString style, QString tile);
	//创建标识符.
	void initPictureSign();
	//对图片进行缩放处理.
	void scaledPicture(int);

	//旋转的函数.
	void rotatePixmap(float angle);
	//翻转的函数.
	void filpPixmap(bool,bool);
private slots:
	//鼠标进入工具栏的槽函数.
	void enterToolBarSlot();
	//鼠标离开工具栏的槽函数.
	void setToolTipLabelText();

	//鼠标点击labelRow中的图片触发的槽函数.参数为图片的下标.
	void moveLabelRowSlot(QWidget *);

	//鼠标点击工具栏的槽函数.
	void pressBoostButtonSlot();
	void pressReduceButtonSlot();
	void pressSizeHintButtonSlot();
	void pressBeautiButtonSlot();
	void pressPreciousButtonSlot();
	void pressNextButtonSlot();
	void pressRorateSlot();
	void pressFilpSlot();
	void pressMoreButtonSlot();

	//右键菜单的对应的槽函数.
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
	//两边的按钮.
	QToolButton *m_leftButton;
	QToolButton *m_rightButton;
	//中央区域的可滚动区域.
	QScrollArea *m_area;
	//中心的QLabel.
	QLabel *m_label;
	//下面的labelArray.
	MyLabelRow *m_labelRow;
	//提示Lable.
	QLabel *m_toolTipLabel;

	//记录是否创建了labelRow.
	bool isCreateLabelRow = false;

	//保存被选中的图片.
	QPixmap m_showPicture;
	//保存经过缩放后的图片.
	QImage m_tempPicture;
	//标识是否发生旋转.记录已旋转的角度.
	bool isTransformSign = false;
	float rotateAngle = 0;
	//标识,是否显示过提示符了.
	bool isShowedMessageSign = false;
	//两个标识符.
	PictureSign *m_firstSign;
	PictureSign *m_lastSign;
	//图片信息对话框的对象.
	PictureMessage *m_pictureMessageDialog;

	//图片编辑.
	PictureEditedWidget *m_editedPictureWidget;

	//用来保存之前的位置.
	QPoint m_precMousePos;
	//用来进行缩放保存的位置.
	QPoint m_scaleMousePos;
	//用来记录用户是否按下左键移动.
	bool m_isPressed;

	//保存当前的图片缩放的倍数大小.
	int m_scalNumber;

	//用来保存是否进行水平和垂直方向上的变换.
	bool m_isHorizontalFilpSign = false;
	bool m_isVerticalFilpSign = false;
	

	//工具栏对象.
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

	//右键菜单对象.
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
