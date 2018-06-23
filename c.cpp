#include "c.h"
bool isContain(QPoint globalPos, QWidget *widget);


c::c(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);

	//初始化可滚动区域.
	initScrollArea();

	//初始化两边的按钮.
	initSidesButtons();

	//初始化工具栏.
	initToolButtonBar();

	//初始化工具栏提示label.
	initToolTipLabel();

	//初始化右键菜单.
	initContextMenu();

	//初始化标识.
	initPictureSign();

	//初始化图片编辑窗口.
	initEditedWidget();

	//连接信号与槽.
	initConnect();

	//初始化窗口.
	initWindow();

}

c::~c()
{

}
//初始化窗口.
void c::initWindow()
{
	//让窗口接受鼠标移动事件.
	this->setMouseTracking(true);
	//修改窗口的大小.
	this->resize(1000, 800);
	this->setMinimumSize(750, 300);
	//让窗口接受拖拽.
	this->setAcceptDrops(true);
	//让窗口具有焦点.
	this->setFocusPolicy(Qt::ClickFocus);
	this->setFocus();

	this->setWindowTitle(QString::fromLocal8Bit("美图看看"));
}

//初始化两边的按钮.
void c::initSidesButtons()
{
	//创建两个按钮对象.
	m_leftButton = new QToolButton(this);
	m_rightButton = new QToolButton(this);

	//获得当前窗口的大小.
	QSize size = this->size();

	m_leftButton->setIcon(QIcon("Resources/Icons/LeftButton.ico"));
	m_rightButton->setIcon(QIcon("Resources/Icons/RightButton.ico"));
	//设置图标大小.

	m_leftButton->setIconSize(QSize(96, 96));
	m_rightButton->setIconSize(QSize(96, 96));
	//设置按钮的固定大小.

	m_leftButton->setFixedSize(100, 100);
	m_rightButton->setFixedSize(100, 100);

	//设置按钮的位置.
	m_leftButton->move(0, size.height() / 2 - m_leftButton->height() / 2);
	m_rightButton->move(size.width() - m_rightButton->width(), size.height() / 2 - m_leftButton->height() / 2);

	//设置按钮浮动.好像并没有什么效果.
	m_leftButton->setAutoRaise(true);
	m_rightButton->setAutoRaise(true);

	//隐藏按钮，当鼠标触碰到了时显示.在mousePressEvent中判断.
	m_leftButton->setVisible(false);
	m_rightButton->setVisible(false);

}

//连接信号与槽.
void c::initConnect()
{
	//鼠标进入工具栏的信号与槽.
	connect(m_boostButton, SIGNAL(enterSignal()), this, SLOT(enterToolBarSlot()));
	connect(m_reduceButton, SIGNAL(enterSignal()), this, SLOT(enterToolBarSlot()));
	connect(m_sizeHintButton, SIGNAL(enterSignal()), this, SLOT(enterToolBarSlot()));
	connect(m_beautiButton, SIGNAL(enterSignal()), this, SLOT(enterToolBarSlot()));
	connect(m_preciousButton, SIGNAL(enterSignal()), this, SLOT(enterToolBarSlot()));
	connect(m_nextButton, SIGNAL(enterSignal()), this, SLOT(enterToolBarSlot()));
	connect(m_leftRotateButton, SIGNAL(enterSignal()), this, SLOT(enterToolBarSlot()));
	connect(m_rightRotateButton, SIGNAL(enterSignal()), this, SLOT(enterToolBarSlot()));
	connect(m_horizontalFilpButton, SIGNAL(enterSignal()), this, SLOT(enterToolBarSlot()));
	connect(m_verticalFilpButton, SIGNAL(enterSignal()), this, SLOT(enterToolBarSlot()));
	connect(m_delButton, SIGNAL(enterSignal()), this, SLOT(enterToolBarSlot()));
	connect(m_moreButton, SIGNAL(enterSignal()), this, SLOT(enterToolBarSlot()));

	//鼠标离开工具栏的信号与槽.
	connect(m_boostButton, SIGNAL(leaveSignal()), this, SLOT(setToolTipLabelText()));
	connect(m_reduceButton, SIGNAL(leaveSignal()), this, SLOT(setToolTipLabelText()));
	connect(m_sizeHintButton, SIGNAL(leaveSignal()), this, SLOT(setToolTipLabelText()));
	connect(m_beautiButton, SIGNAL(leaveSignal()), this, SLOT(setToolTipLabelText()));
	connect(m_preciousButton, SIGNAL(leaveSignal()), this, SLOT(setToolTipLabelText()));
	connect(m_nextButton, SIGNAL(leaveSignal()), this, SLOT(setToolTipLabelText()));
	connect(m_leftRotateButton, SIGNAL(leaveSignal()), this, SLOT(setToolTipLabelText()));
	connect(m_rightRotateButton, SIGNAL(leaveSignal()), this, SLOT(setToolTipLabelText()));
	connect(m_horizontalFilpButton, SIGNAL(leaveSignal()), this, SLOT(setToolTipLabelText()));
	connect(m_verticalFilpButton, SIGNAL(leaveSignal()), this, SLOT(setToolTipLabelText()));
	connect(m_delButton, SIGNAL(leaveSignal()), this, SLOT(setToolTipLabelText()));
	connect(m_moreButton, SIGNAL(leaveSignal()), this, SLOT(setToolTipLabelText()));

	//鼠标点击工具栏的信号与槽.
	connect(m_boostButton, SIGNAL(clicked()), this, SLOT(pressBoostButtonSlot()));
	connect(m_reduceButton, SIGNAL(clicked()), this, SLOT(pressReduceButtonSlot()));
	connect(m_sizeHintButton, SIGNAL(clicked()), this, SLOT(pressSizeHintButtonSlot()));
	connect(m_beautiButton, SIGNAL(clicked()), this, SLOT(pressBeautiButtonSlot()));
	connect(m_preciousButton, SIGNAL(clicked()), this, SLOT(pressPreciousButtonSlot()));
	connect(m_nextButton, SIGNAL(clicked()), this, SLOT(pressNextButtonSlot()));
	connect(m_leftRotateButton, SIGNAL(clicked()), this, SLOT(pressRorateSlot()));
	connect(m_rightRotateButton, SIGNAL(clicked()), this, SLOT(pressRorateSlot()));
	connect(m_horizontalFilpButton, SIGNAL(clicked()), this, SLOT(pressFilpSlot()));
	connect(m_verticalFilpButton, SIGNAL(clicked()), this, SLOT(pressFilpSlot()));
	connect(m_delButton, SIGNAL(clicked()), this, SLOT(contextMenuDelSlot()));
	connect(m_moreButton, SIGNAL(clicked()), this, SLOT(pressMoreButtonSlot()));

	//左右两个按钮的槽函数.
	connect(m_leftButton, SIGNAL(clicked()), this, SLOT(pressPreciousButtonSlot()));
	connect(m_rightButton, SIGNAL(clicked()), this, SLOT(pressNextButtonSlot()));

	//右键菜单的槽函数.
	connect(m_updateAction, SIGNAL(triggered()), this, SLOT(contextUpdateSlot()));
	connect(m_batchConverFormatAction, SIGNAL(triggered()), this, SLOT(contextMenuBatchConverFormatSlot()));
	connect(m_batchConverSizeAction, SIGNAL(triggered()), this, SLOT(contextMenuBatchConverSizeSlot()));
	connect(m_batchRenameAction, SIGNAL(triggered()), this, SLOT(contextMenuBatchRenameSlot()));
	connect(m_cutAction, SIGNAL(triggered()), this, SLOT(contextMenuCutSlot()));
	connect(m_copyAction, SIGNAL(triggered()), this, SLOT(contextMenuCopySlot()));
	connect(m_saveAsAction, SIGNAL(triggered()), this, SLOT(contextMenuSaveAsSlot()));
	connect(m_openPicturePathAction, SIGNAL(triggered()), this, SLOT(contextMenuOpenPicturePathSlot()));
	connect(m_printPictureAction, SIGNAL(triggered()), this, SLOT(contextMenuPrintPictureSlot()));
	connect(m_lookPictureFirstAction, SIGNAL(triggered()), this, SLOT(contextMenuLookPictureFirstSlot()));
	connect(m_delAction, SIGNAL(triggered()), this, SLOT(contextMenuDelSlot()));
	connect(m_picturePropertyAction, SIGNAL(triggered()), this, SLOT(contextMenuPicturePropertySlot()));
	connect(m_centerAction, SIGNAL(triggered()), this, SLOT(contextMenuCenterSlot()));
	connect(m_stretchAction, SIGNAL(triggered()), this, SLOT(contextMenuStretchSlot()));
	connect(m_tileAction, SIGNAL(triggered()), this, SLOT(contextMenuTileSlot()));
}
//初始化图片编辑框
void c::initEditedWidget()
{
	m_editedPictureWidget = new PictureEditedWidget(this);
	m_editedPictureWidget->setVisible(false);
}

//初始化可滚动区域.
void c::initScrollArea()
{
	
	//创建一个可滚动区域的对象.
	m_area = new QScrollArea(this);
	m_area->setMinimumSize(this->size().width(), this->size().height());
	m_area->resize(this->size().width(), this->size().height());
	
	//创建一个label.用来显示图片.
	m_label = new QLabel();
	m_label->setMinimumSize(this->size().width(), this->size().height());
	m_label->resize(this->size().width(), this->size().height());
	m_label->setAlignment(Qt::AlignCenter);
	//把Label作为可滚动区域的中心区域.
	m_area->setWidget(m_label);
	//设置可滚动区域可以相应鼠标移动事件.
	m_area->setMouseTracking(true);
	//设置中心对齐.
	m_area->setAlignment(Qt::AlignCenter);
	//安装事件过滤器.
	m_label->installEventFilter(this);
	m_label->setFocusPolicy(Qt::StrongFocus);


	//引用布局.
	QHBoxLayout *layout = new QHBoxLayout(this);
	layout->addWidget(m_area);
	//设置布局的四周空隙.
	layout->setContentsMargins(50, 0, 50, 50);

	m_area->horizontalScrollBar()->setVisible(false);
	m_area->verticalScrollBar()->setVisible(false);

	//初始化倍数.
	m_scalNumber = 0;
}
void c::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
	case Qt::Key_Up:
		scaledPicture(1);
		break;
	case Qt::Key_Down:
		scaledPicture(-1);
		break;
	case Qt::Key_Left:
		pressPreciousButtonSlot();
		break;
	case Qt::Key_Right:
		pressNextButtonSlot();
		break;
	case Qt::Key_R:
		pressSizeHintButtonSlot();
		break;
	case Qt::Key_D:
		contextMenuDelSlot();
		break;
	case Qt::Key_E:
		pressBeautiButtonSlot();
		break;
	case Qt::Key_A:
		rotatePixmap(-90);
		break;
	case Qt::Key_S:
		rotatePixmap(90);
		break;
	case Qt::Key_J:
		filpPixmap(true,false);
		break;
	case Qt::Key_K:
		filpPixmap(false,true);
		break;
	case Qt::Key_M:
		pressMoreButtonSlot();
		break;
	case Qt::Key_T:
		contextMenuCutSlot();
		break;
	case Qt::Key_C:
		contextMenuCopySlot();
		break;
	case Qt::Key_I:
		contextMenuPicturePropertySlot();
		break;
	default:
		break;
	}
}
//初始化工具栏.
void c::initToolButtonBar()
{
	//初始化...固定大小为645.高度为50.
	m_bottomToolBar = new QToolBar(this); m_bottomToolBar->setFixedSize(645, 50);
	m_boostButton = new MyToolButton(); m_boostButton->setIcon(QIcon("Resources/Icons/boost.ico")); m_boostButton->setFixedSize(50, 50); m_boostButton->setProperty("toolTip", QString::fromLocal8Bit("放大(Up)"));
	m_reduceButton = new MyToolButton(); m_reduceButton->setIcon(QIcon("Resources/Icons/reduce.ico")); m_reduceButton->setFixedSize(50, 50); m_reduceButton->setProperty("toolTip", QString::fromLocal8Bit("缩小(Down)"));
	m_sizeHintButton = new MyToolButton(); m_sizeHintButton->setIcon(QIcon("Resources/Icons/sizeHint.ico")); m_sizeHintButton->setFixedSize(50, 50); m_sizeHintButton->setProperty("toolTip", QString::fromLocal8Bit("实际尺寸(R)"));
	m_beautiButton = new MyToolButton(); m_beautiButton->setIcon(QIcon("Resources/Icons/beauti.ico")); m_beautiButton->setFixedSize(75, 50); m_beautiButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon); m_beautiButton->setText(QString::fromLocal8Bit("美化(E)")); m_beautiButton->setProperty("toolTip", QString::fromLocal8Bit("编辑图片"));
	m_preciousButton = new MyToolButton(); m_preciousButton->setIcon(QIcon("Resources/Icons/precious.ico")); m_preciousButton->setFixedSize(50, 50); m_preciousButton->setProperty("toolTip", QString::fromLocal8Bit("上一张(<-)"));
	m_nextButton = new MyToolButton(); m_nextButton->setIcon(QIcon("Resources/Icons/next.ico")); m_nextButton->setFixedSize(50, 50); m_nextButton->setProperty("toolTip", QString::fromLocal8Bit("下一张(->)"));
	m_leftRotateButton = new MyToolButton(); m_leftRotateButton->setIcon(QIcon("Resources/Icons/leftRotate.ico")); m_leftRotateButton->setFixedSize(50, 50); m_leftRotateButton->setProperty("toolTip", QString::fromLocal8Bit("向左旋转90°(A)")); 
	m_rightRotateButton = new MyToolButton(); m_rightRotateButton->setIcon(QIcon("Resources/Icons/rightRotate.ico")); m_rightRotateButton->setFixedSize(50, 50); m_rightRotateButton->setProperty("toolTip", QString::fromLocal8Bit("向右旋转90°(S)"));
	m_horizontalFilpButton = new MyToolButton(); m_horizontalFilpButton->setIcon(QIcon("Resources/Icons/horizontalFilp.png")); m_horizontalFilpButton->setFixedSize(50, 50); m_horizontalFilpButton->setProperty("toolTip", QString::fromLocal8Bit("水平翻滚(J)"));
	m_verticalFilpButton = new MyToolButton(); m_verticalFilpButton->setIcon(QIcon("Resources/Icons/verticalFilp.png")); m_verticalFilpButton->setFixedSize(50, 50); m_verticalFilpButton->setProperty("toolTip", QString::fromLocal8Bit("垂直翻滚(K)"));
	m_delButton = new MyToolButton(); m_delButton->setIcon(QIcon("Resources/Icons/clean.ico")); m_delButton->setFixedSize(50, 50); m_delButton->setProperty("toolTip", QString::fromLocal8Bit("删除(D)"));
	m_moreButton = new MyToolButton(); m_moreButton->setIcon(QIcon("Resources/Icons/more.ico")); m_moreButton->setFixedSize(50, 50); m_moreButton->setProperty("toolTip", QString::fromLocal8Bit("更多(M)")); m_moreButton->setShortcut(Qt::Key_M);

	//加到工具栏中...
	m_bottomToolBar->addWidget(m_boostButton);
	m_bottomToolBar->addWidget(m_reduceButton);
	m_bottomToolBar->addWidget(m_sizeHintButton);
	m_bottomToolBar->addWidget(m_beautiButton);
	m_bottomToolBar->addSeparator();
	m_bottomToolBar->addWidget(m_preciousButton);
	m_bottomToolBar->addWidget(m_nextButton);
	m_bottomToolBar->addSeparator();
	m_bottomToolBar->addWidget(m_leftRotateButton);
	m_bottomToolBar->addWidget(m_rightRotateButton);
	m_bottomToolBar->addWidget(m_horizontalFilpButton);
	m_bottomToolBar->addWidget(m_verticalFilpButton);
	m_bottomToolBar->addWidget(m_delButton);
	m_bottomToolBar->addWidget(m_moreButton);
	m_bottomToolBar->setMovable(false);
	//先显示.
	m_bottomToolBar->setVisible(false);

}
void c::contextUpdateSlot()
{
	//如果路径容器中没有元素，则直接返回.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	reLoadFileAndPressentPictureId(Contain::getInstance()->getPressentPictureAbsoluteFilePath());
}
//初始化右键菜单.
void c::initContextMenu()
{
	m_menu = new QMenu();
	m_editPictureMenu = new QMenu(QString::fromLocal8Bit("编辑图片"));
	m_setBackGroundMenu = new QMenu(QString::fromLocal8Bit("设为桌面(W)"));
	m_updateAction = new QAction(QString::fromLocal8Bit("刷新"),this);
	m_batchConverFormatAction = new QAction(QString::fromLocal8Bit("批量转换格式"), this);
	m_batchConverSizeAction = new QAction(QString::fromLocal8Bit("批量转换尺寸"), this);
	m_batchRenameAction = new QAction(QString::fromLocal8Bit("批量重命名"), this);
	m_cutAction = new QAction(QString::fromLocal8Bit("剪切(T)"), this);
	m_copyAction = new QAction(QString::fromLocal8Bit("复制(C)"), this);
	m_saveAsAction = new QAction(QString::fromLocal8Bit("另存到..."), this);
	m_openPicturePathAction = new QAction(QString::fromLocal8Bit("打开图片所在文件夹"), this);
	m_printPictureAction = new QAction(QString::fromLocal8Bit("打印图片"), this);
	m_lookPictureFirstAction = new QAction(QString::fromLocal8Bit("看图窗口总在最前"), this);
	m_delAction = new QAction(QString::fromLocal8Bit("删除(D)"), this);
	m_picturePropertyAction = new QAction(QString::fromLocal8Bit("图片信息(I)"), this);
	m_centerAction = new QAction(QString::fromLocal8Bit("居中"), this);
	m_stretchAction = new QAction(QString::fromLocal8Bit("拉伸"), this);
	m_tileAction = new QAction(QString::fromLocal8Bit("平铺"), this);

	//设置看图窗口总在前,可以被选中,且默认不被选中.
	m_lookPictureFirstAction->setCheckable(true);
	m_lookPictureFirstAction->setChecked(false);


	m_editPictureMenu->addAction(m_batchConverFormatAction);
	m_editPictureMenu->addAction(m_batchConverSizeAction);
	m_editPictureMenu->addAction(m_batchRenameAction);

	m_setBackGroundMenu->addAction(m_centerAction);
	m_setBackGroundMenu->addAction(m_tileAction);
	m_setBackGroundMenu->addAction(m_stretchAction);

	m_menu->addAction(m_updateAction);
	m_menu->addMenu(m_editPictureMenu);
	m_menu->addSeparator();
	m_menu->addAction(m_cutAction);
	m_menu->addAction(m_copyAction);
	m_menu->addAction(m_saveAsAction);
	m_menu->addSeparator();
	m_menu->addAction(m_openPicturePathAction);
	m_menu->addMenu(m_setBackGroundMenu);
	m_menu->addAction(m_printPictureAction);
	m_menu->addSeparator();
	m_menu->addAction(m_lookPictureFirstAction);
	m_menu->addSeparator();
	m_menu->addAction(m_delAction);
	m_menu->addSeparator();
	m_menu->addAction(m_picturePropertyAction);
}
void c::initPictureSign()
{
	//创建标识并且隐藏起来先.
	m_firstSign = new PictureSign(QString::fromLocal8Bit("当前已是第一张,继续游览将返回最后一张"), this);
	m_firstSign->setVisible(false);
	m_lastSign = new PictureSign(QString::fromLocal8Bit("当前已是最后一张,继续游览将返回第一张"), this);
	m_lastSign->setVisible(false);
}
void c::resizeEvent(QResizeEvent *event)
{
	returnDefaultPos();
}

//还原各部件的位置.
void c::returnDefaultPos()
{
	QSize size = this->size();
	//更新左右侧按钮的位置.
	m_leftButton->move(0, size.height() / 2 - m_leftButton->height() / 2);
	m_rightButton->move(size.width() - m_rightButton->width(), size.height() / 2 - m_leftButton->height() / 2);

	//更新图片栏和工具栏的位置.
	this->m_bottomToolBar->move((size.width() - m_bottomToolBar->size().width()) / 2, size.height() - 100);
	this->m_toolTipLabel->move((size.width() - 600) / 2, size.height() - 130);

	//如果labelRow存在,则改变label的位置.
	if (isCreateLabelRow)
	{
		//让被选中的图片放在中间的位置.直接把label中的图像进行缩放即可.
		resizeLabelWithPicture(&m_label->pixmap()->toImage());
		//移动下方的labelRow.
		moveLabelRow(Contain::getInstance()->getPressentPictureId());
		//移动标识.
		resizePictureSignPos();
		m_label->setMinimumSize(this->size().width(), this->size().height());
	}


}
//这里的事件过滤器可以注释掉.好像没什么作用.
bool c::eventFilter(QObject *o, QEvent *e)
{
/*	if (o == m_label)
	{
		if (isCreateLabelRow)
		{
			if (e->type() == QEvent::Wheel)
			{
				auto event = static_cast<QWheelEvent*>(e);
				m_scaleMousePos = QCursor::pos();
				//进行图片的缩放
				scaledPicture(event->delta() / 8.0 / 15.0);
				return true;
			}
			//对m_label进行按键监听.如果焦点在m_label中,则直接按照当前层的按键处理进行处理.
			else if (e->type() == QEvent::KeyPress)
			{
				auto event = static_cast<QKeyEvent*>(e);
				keyPressEvent(event);
			}
		}
	}*/
	return QObject::eventFilter(o, e);
}
void c::wheelEvent(QWheelEvent *event)
{
	m_scaleMousePos = QCursor::pos();
	//进行图片的缩放
	scaledPicture(event->delta() / 8.0 / 15.0);
}
void c::leaveEvent(QEvent *event)
{
	//当鼠标移出去时,消失.
	m_leftButton->setVisible(false);
	m_rightButton->setVisible(false);
	m_toolTipLabel->setVisible(false);

	if (m_labelRow && isCreateLabelRow)
		m_labelRow->setVisible(false);
	m_bottomToolBar->setVisible(false);

/*	if (m_labelRow && isCreateLabelRow)
	{
		QString path = Contain::getInstance()->getPressentPictureAbsoluteFilePath();
		//更新.
		reLoadFileAndPressentPictureId(path);
	}*/
}

void c::scaledPicture(int factor)
{
	//这里是重点,需要研究的地方.
	//判断是否存在图片.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;

	//获取之前的倍数.
	int tempSize = m_scalNumber;
	qDebug() << "1" << endl;
	//
	if (m_scalNumber + factor >= 20)
		return;

	//记录一下当前的倍数.
	m_scalNumber += factor;
	double temp = pow(1.125, m_scalNumber);

	//获取当前的图片.
	QImage presPixmap = Contain::getInstance()->getPressentPixmap().toImage();
	QImage displayPixmap = presPixmap.scaled(presPixmap.size()*temp, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

	//	重新设置label的大小.
	m_label->resize(presPixmap.size()*temp);
	//重新显示大小.
	m_label->setPixmap(QPixmap::fromImage(displayPixmap));

	//光标的绝对位置基于显示图片的可移动区域的相对位置.
	auto baseLabelAreaPos = m_area->mapFromGlobal(m_scaleMousePos);
	//计算出光标的位置和中心位置的差值.
	auto offset = baseLabelAreaPos - QPoint(this->m_area->size().width() / 2, this->m_area->size().height() / 2);

	m_area->horizontalScrollBar()->setValue(m_area->horizontalScrollBar()->value() + offset.x());
	m_area->verticalScrollBar()->setValue(m_area->verticalScrollBar()->value() + offset.y());

}
void c::contextMenuEvent(QContextMenuEvent *event)
{
	//当没有发生变换时,显示正常菜单.
	if (!isTransformSign)
		m_menu->exec(QCursor::pos());
	else//否则询问是否保存.
	{
		QMessageBox temp(QMessageBox::Information, QString::fromLocal8Bit("变换图片"), QString::fromLocal8Bit("您对图片进行了变换操作,是否需要保存?"),
			QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, this);
		temp.setButtonText(QMessageBox::Yes, QString::fromLocal8Bit("自动更名保存"));
		temp.setButtonText(QMessageBox::No, QString::fromLocal8Bit("覆盖原图"));
		temp.setButtonText(QMessageBox::Cancel, QString::fromLocal8Bit("不保存"));
		//保存用户选择结果.
		int status = temp.exec();

		//如果用户选择自动更名保存的话.则保存此图片在当前文件下.且更新.
		if (status == QMessageBox::Yes)
		{
			QString path;
			QString name;
			do
			{
				//判断自动更名保存的名字是否有相同的.
				name += QString::fromLocal8Bit("_变换");
				path = Contain::getInstance()->getPressentPictureInfo().absolutePath() + "/" + Contain::getInstance()->getPressentPictureInfo().completeBaseName()
					+ name + "." + Contain::getInstance()->getPressentPictureInfo().suffix();
			} while (QFile::exists(path));

			QMatrix matrix;
			matrix.rotate(rotateAngle);
			//获取当前的旋转图片,并且储存在指定路径下.
			QImage temp = Contain::getInstance()->getPressentPixmap().toImage().transformed(matrix).mirrored(m_isHorizontalFilpSign, m_isVerticalFilpSign);
			temp.save(path);
			//更新.
			reLoadFileAndPressentPictureId(Contain::getInstance()->getPressentPictureAbsoluteFilePath());

			//把和旋转有关的标识归零.
			isTransformSign = false;
			rotateAngle = 0;
			m_isHorizontalFilpSign = false;
			m_isVerticalFilpSign = false;
		}
		//如果用户选择了覆盖原图,则先删除原图,在增加新图.在进行更新,注意,当前的图片是新图.
		else if (status == QMessageBox::No)
		{
			//先加入新图.
			QString path = Contain::getInstance()->getPressentPictureAbsoluteFilePath();
			//先获取当前图片的原始图像.
			QImage image = QImage(Contain::getInstance()->getPressentPictureAbsoluteFilePath());

			//先删除原图.
			QFile file(Contain::getInstance()->getPressentPictureAbsoluteFilePath());
			file.remove();

			//获取当前的旋转图片,并且储存在指定路径下.
			QMatrix matrix;
			matrix.rotate(rotateAngle);
			QImage temp = image.transformed(matrix).mirrored(m_isHorizontalFilpSign, m_isVerticalFilpSign);
			temp.save(path);

			//更新.
			reLoadFileAndPressentPictureId(path);
			//把和旋转有关的标识归零.
			isTransformSign = false;
			rotateAngle = 0;
			m_isHorizontalFilpSign = false;
			m_isVerticalFilpSign = false;
		}
		//如果不保存,或者直接x掉,则取消旋转状态,并且回复到原来状态.
		else
		{
			//先把旋转有关的标识归零.
			isTransformSign = false;
			rotateAngle = 0;
			m_isHorizontalFilpSign = false;
			m_isVerticalFilpSign = false;
			//恢复原来的label.
			resizeLabelWithPicture(&Contain::getInstance()->getPressentPixmap().toImage());
		}

	}

}

void c::mousePressEvent(QMouseEvent *event)
{
	//先让消失.
	m_firstSign->setVisible(false);
	m_lastSign->setVisible(false);

	if (event->button() == Qt::LeftButton)
	{
		m_isPressed = true;
		m_precMousePos = event->pos();
	}
}
void c::mouseMoveEvent(QMouseEvent *event)
{

	//判断鼠标是否触及到两侧的按钮.
	QSize size = this->size();
	QPoint converToPagePoint = this->mapFromGlobal(event->globalPos());
	QRect leftRect(m_leftButton->pos(), m_leftButton->size());
	QRect rightRect(m_rightButton->pos(), m_rightButton->size());
	if (leftRect.contains(converToPagePoint) || rightRect.contains(converToPagePoint))
	{
		QCursor temp;
		temp.setShape(Qt::PointingHandCursor);
		this->setCursor(temp);
		m_leftButton->setVisible(true);
		m_rightButton->setVisible(true);
	}
	else
	{
		QCursor temp;
		//设置修改鼠标的形状.
		temp.setShape(Qt::ArrowCursor);
		this->setCursor(temp);
		m_leftButton->setVisible(false);
		m_rightButton->setVisible(false);
	}


	//当鼠标高于下边界50以内,则显示.
	QRect Left(0, size.height() - 50, size.width(), size.height());
	if (Left.contains(converToPagePoint))
	{
		qDebug() << "1";
		//显示工具栏和文本信息框.
		m_bottomToolBar->setVisible(true);
		m_toolTipLabel->setVisible(true);
		//当有图片放进来时，鼠标碰到后才会显示labelRow.
		if (isCreateLabelRow)
			m_labelRow->setVisible(true);
	}
	else
	{
		qDebug() << "2";
		//反之隐藏.
		m_bottomToolBar->setVisible(false);
		m_toolTipLabel->setVisible(false);
		if (isCreateLabelRow)
		{
			m_labelRow->setVisible(false);
			setToolTipLabelText();
		}
	}

	//判断是否有按下左键.
	if (m_isPressed)
	{
		QPoint currentPt = event->pos();

		int widthOffset = m_precMousePos.x() - currentPt.x();
		int heightOffset = m_precMousePos.y() - currentPt.y();

		//记录当前伸缩条的数值位置.
		auto m_horiBarValue = m_area->horizontalScrollBar()->value() + widthOffset;
		auto m_vertBarValue = m_area->verticalScrollBar()->value() + heightOffset;

		m_area->horizontalScrollBar()->setValue(m_horiBarValue);
		m_area->verticalScrollBar()->setValue(m_vertBarValue);

		m_precMousePos = currentPt;
	}


}
void c::mouseReleaseEvent(QMouseEvent *event)
{
	//归零.重新计算.
	m_isPressed = false;
	m_precMousePos = QPoint(0, 0);
}
void c::initLabelArray(QSize size, int len)
{
	//创建m_labelRow对象.
	m_labelRow = new MyLabelRow(size, len, this);
	isCreateLabelRow = true;

	this->m_labelRow->move(0, this->size().height() - 60);

	m_labelRow->setVisible(false);
	//连接每个label的槽.
	connectLabelRowOneByOne();
}
void c::connectLabelRowOneByOne()
{
	auto tempList = m_labelRow->getLabelList();
	for (int i = 0; i < tempList.size(); ++i)
	{
		connect(tempList[i], SIGNAL(clicked(QWidget *)), this, SLOT(moveLabelRowSlot(QWidget *)));
	}
}
void c::moveLabelRowSlot(QWidget *object)
{
	//先隐藏.
	m_firstSign->setVisible(false);
	m_lastSign->setVisible(false);

	auto label = static_cast<MyLabel*>(object);
	//显示新的label.
	int pos = label->property("id").toInt();
	//移动labelRow的位置.
	Contain::getInstance()->setBothId(pos);
	//移动下面的LableRow.
	moveLabelRow(pos);
	//显示指定下标的图片..
	resizeLabelWithPicture(new QImage(Contain::getInstance()->getPictureInfoList()->at(pos).absoluteFilePath()));
	//labelRow中的label边框的样式的改变.
	showSelectedLabelFrame(pos);
	//
	setToolTipLabelText();

	//取消缩放倍数和归零缩放倍数.
	scaledPicture(-m_scalNumber);
	m_scalNumber = 0;

}
void c::dragEnterEvent(QDragEnterEvent *event)
{
	if (event->mimeData()->hasUrls())
	{
		event->accept();
		event->setDropAction(Qt::MoveAction);
	}
}
void c::dragMoveEvent(QDragMoveEvent *event)
{
	if (event->mimeData()->hasUrls())
	{
		event->accept();
		event->setDropAction(Qt::MoveAction);
	}
}
void c::dropEvent(QDropEvent *event)
{
	//如果已经创建了则清空.
	clearRowLabelAndLabel();

	//把拖拽进去的图片路径下的所有图片文件放进容器中.
	QList<QUrl> pathList = event->mimeData()->urls();
	//获取拖拽进来的文件绝对路径.
	QString path = pathList.first().toLocalFile();

	//重新加载图片路径和当前的ID.
	reLoadFileAndPressentPictureId(path);
}
//重新载入当前文件路径和当前图片位置.参数为当前图片的绝对路径.
void c::reLoadFileAndPressentPictureId(QString filePath)
{
	//先清空原来容器内的数据并且如果存在的话,则释放m_labelRow.
	clearRowLabelAndLabel();

	QFileInfo temp(filePath);
	//更新容器内的图片路径.
	auto i = temp.absolutePath();
	Contain::getInstance()->setPictureInfoList(temp.absolutePath());

	int num = Contain::getInstance()->getPictureInfoListSize();
	auto q = Contain::getInstance()->getPressentPictureId();
	if (!QFile::exists(filePath))
	{
		if (Contain::getInstance()->getPressentPictureId() >= num )
		{
			//设置当前图片在文件中的位置.
			int id = Contain::getInstance()->getPressentPictureId();
			//这里的位置可以进行微调.
			Contain::getInstance()->setBothId(num - 1);
		}
		else
		{
			//保持不变.
			//Contain::getInstance()->setBothId(returnDropPictureId(filePath));
		}
	}
	else
	{
		//清空id.
		Contain::getInstance()->clearId();
		//设置当前图片在文件中的位置.
		Contain::getInstance()->setBothId(returnDropPictureId(filePath));
	}

	//初始化最下面的labelRow.
	initLabelArray(QSize(50, 50), Contain::getInstance()->getPictureInfoListSize());
	//移动下面的labelRow.
	moveLabelRow(Contain::getInstance()->getPressentPictureId());
	//让选中的图片显示在label框中.
	resizeLabelWithPicture(new QImage(Contain::getInstance()->getPressentPictureAbsoluteFilePath()));
	//把图片显示在labelRow中.
	showLabelPicture();
	//修改提示框内的信息.
	setToolTipLabelText();
}

//适应label框中的图片.
void c::resizeLabelWithPicture(QImage *image)
{
	if (Contain::getInstance()->getPressentPictureId() < 0)
		return;
	QSize size = m_area->size();

	QSize s = image->size();

	//如果图片的大小比滚动区域要大.这里可能会有一点问题.
	/*if ((image->size().width() > size.width()) || (image->size().height() > size.height()))
	{
	float scaledXY = 1.0*image->size().width() / image->size().height();
	float x = 1.0*image->size().width() / size.width();
	float y = 1.0*image->size().height() / size.height();
	float X, Y;
	if (x > y)
	{
	X = size.width() - 30;
	Y = X / scaledXY;
	}
	else
	{
	Y = size.height() - 30;
	X = Y * scaledXY;
	}
	m_label->resize(QSize(X, Y));

	//进行缩放.
	m_tempPicture = image->scaled(QSize(X, Y), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	m_label->setPixmap(QPixmap::fromImage(*image));
	m_label->move(size.width() / 2 - X / 2, size.height() / 2 - Y / 2);
	}
	//否则,label大小就和图片一样大.
	else
	{
	m_label->resize(image->size());
	m_label->move(size.width() / 2 - image->size().width() / 2, size.height() / 2 - image->size().height() / 2);
	m_label->setPixmap(QPixmap::fromImage(*image));
	}*/

	//m_label->move(size.width() / 2 - image->size().width() / 2, size.height() / 2 - image->size().height() / 2);

	//修改大小.
	m_label->resize(image->size());
	//设置图像.
	m_label->setPixmap(QPixmap::fromImage(*image));

	resizePictureSignPos();
}
//移动labelRow的位置.
void c::moveLabelRow(int pos)
{
	QSize size = this->size();
	//移动下面的LableRow.
	this->m_labelRow->move(size.width() / 2 - 25 - 50 * pos, size.height() - 60);
}
//清空labelRow和label.
void c::clearRowLabelAndLabel()
{
	//如果创建了.
	if (isCreateLabelRow)
	{
		//然后清空释放labelRow,并且清空Contain里面容器的数据.
		delete m_labelRow;
		m_labelRow = 0;
		isCreateLabelRow = false;
		Contain::getInstance()->clearPictureInfoList();
		m_label->clear();
	}
}

//把放进来的图片的路径下图片显示在labelRow中.
void c::showLabelPicture()
{
	//先获取当前窗口的宽度.
	int width = this->size().width();
	auto infoList = Contain::getInstance()->getPictureInfoList();
	for (int i = 0; i < infoList->size(); ++i)
	{
		//把图片显示在label中.
		QPixmap c(infoList->at(i).absoluteFilePath());
		float scaledXY = 1.0*c.size().width() / c.size().height();
		float x = 1.0*c.size().width() / 50;
		float y = 1.0*c.size().height() / 50;
		float X, Y;
		if (x > y)
		{
			X = 50;
			Y = X / scaledXY;
		}
		else
		{
			Y = 50;
			X = Y * scaledXY;
		}

		//这里需要在创建一个线程去挨个显示.
		QPixmap temp = c.scaled(X, Y, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		m_labelRow->getLabelList()[i]->setPixmap(temp);
	}
	showSelectedLabelFrame(Contain::getInstance()->getPressentPictureId());
}
//让被选中的图片的边框进行变化.(当当前选择图片变化时，需要调用)
void c::showSelectedLabelFrame(int newSelected)
{
	//让当前的图片边框颜色变深，之前的图片边框恢复原来的样子.
	auto list = m_labelRow->getLabelList();

	//让之前选择的图片边框淡去.防止用户再次点击已选中图片导致黑框消失.
	if (Contain::getInstance()->getPreciousPictureId() >= 0)
	{
		if (Contain::getInstance()->getPreciousPictureId() >= list.size())
			;
		else
			list[Contain::getInstance()->getPreciousPictureId()]->setFrameShape(QFrame::StyledPanel);
	}
	//让新选择的图片修改边框.
	if (newSelected >= 0)
		list[newSelected]->setFrameShape(QFrame::WinPanel);
}
//图片标识的位置.
void c::resizePictureSignPos()
{
	QSize size = m_label->size();
	QPoint pos = m_label->pos();
	QPoint framePos = this->geometry().topLeft();
	//m_firstSign->move(pos.x() + size.width() / 2 - 150 + framePos.x(), pos.y() + size.height() / 2 - 25 + framePos.y());
	//m_lastSign->move(pos.x() + size.width() / 2 - 150 + framePos.x(), pos.y() + size.height() / 2 - 25 + framePos.y());
}
//获取放下的图片在路径中的图片位置.
int c::returnDropPictureId(QString path)
{
	auto list = Contain::getInstance()->getPictureInfoList();
	for (int i = 0; i < list->size(); ++i)
	{
		auto q = list->at(i).absoluteFilePath();
		if (list->at(i).absoluteFilePath() == path)
		{
			return i;
		}
	}
	return -1;
}
//设置桌面背景.
void c::setBgPicture(QString style, QString tile)
{
	//如果没有图片,则直接返回.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;

	//获得当前图片的绝对路径.
	QString src = Contain::getInstance()->getPressentPictureAbsoluteFilePath();

	//这样是可以的...
	QSettings set("HKEY_CURRENT_USER\\Control Panel\\Desktop", QSettings::NativeFormat);
	QString path(src);
	//设置注册表的信息.
	set.setValue("Wallpaper", path);
	set.setValue("WallpaperStyle", style);

	if (tile == "1")
		set.setValue("TileWallpaper", tile);
	else
		set.setValue("TileWallpaper", "0");

	QByteArray byte = path.toLocal8Bit();
	SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, byte.data(), SPIF_SENDCHANGE | SPIF_SENDWININICHANGE);
}
//清空容器并且释放labelRow指向的内存.
void c::closeEvent(QCloseEvent *event)
{
	event->accept();
}
//初始化工具栏提示label.
void c::initToolTipLabel()
{
	m_toolTipLabel = new QLabel(this);
	m_toolTipLabel->setAlignment(Qt::AlignCenter);
	m_toolTipLabel->resize(600, 30);
	m_toolTipLabel->setFont(QFont("",15));

	m_toolTipLabel->setVisible(false);
	m_toolTipLabel->setStyleSheet("background-color: rgb(120, 120, 120)");
}

void c::enterToolBarSlot()
{
	//获取发射信号的对象指针.
	auto pSender = qobject_cast<MyToolButton*>(this->sender());
	QString mes = pSender->property("toolTip").toString();
	this->m_toolTipLabel->setText(mes);
}
void c::setToolTipLabelText()
{
	//当没有图片时直接返回.
	if (!isCreateLabelRow)
		return;
	//获取当前图片的一些基础信息.
	QPixmap temp = Contain::getInstance()->getPressentPixmap();
	QDateTime dateTime = Contain::getInstance()->getPressentPictureCreatedTime();
	int pressentId = Contain::getInstance()->getPressentPictureId();
	int totalId = Contain::getInstance()->getPictureInfoListSize();
	QString date = dateTime.toString("yyyy-MM-dd");
	QString fileName = Contain::getInstance()->getPressentPictureInfo().fileName();
	int size = Contain::getInstance()->getPressentPictureInfo().size() / 1024;

	//暂时不要显示比例.
	//QString str = fileName + " - " + QString("%1x%2").arg(temp.width()).arg(temp.height()) + " - " + "100%" + " - " + date + " - " + QString("%1KB").arg(size) + " - " + QString("%1/%2").arg(pressentId + 1).arg(totalId);
	QString str = fileName + " - " + QString("%1x%2").arg(temp.width()).arg(temp.height()) +  " - " + date + " - " + QString("%1KB").arg(size) + " - " + QString("%1/%2").arg(pressentId + 1).arg(totalId);
	this->m_toolTipLabel->setText(str);
}
void c::pressBoostButtonSlot()
{
	//判断是否存在图片.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	scaledPicture(1);
}
void c::pressReduceButtonSlot()
{
	//判断是否存在图片.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	scaledPicture(-1);
}
void c::pressSizeHintButtonSlot()
{
	//判断是否存在图片.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	scaledPicture(-m_scalNumber);
	m_scalNumber = 0;
}
void c::pressBeautiButtonSlot()
{
	//如果容器内没有路径元素,则直接返回,无法打开编辑窗口.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	//设置编辑图片的初始化容器.
	m_editedPictureWidget->setInitPicture(Contain::getInstance()->getPressentPictureAbsoluteFilePath());

	//显示编辑窗口.
	m_editedPictureWidget->exec();
}
void c::pressPreciousButtonSlot()
{
	//首先判断是否labelRow是否存在.
	if (!isCreateLabelRow)
	{
		return;
	}
	int pos = 0;

	//如果当前显示的是第一张图片，进行提示，如果还被点击，则进行移动.
	if (Contain::getInstance()->getPressentPictureId() == 0)
	{
		//刚开始没有显示过.修改标识,标识已经显示过了.
		if (!isShowedMessageSign)
		{
			isShowedMessageSign = true;
			m_firstSign->setVisible(true);
		}
		else
		{
			pos = Contain::getInstance()->getPictureInfoList()->size() - 1;
			isShowedMessageSign = false;
			m_firstSign->setVisible(false);
			m_lastSign->setVisible(false);
		}
	}
	else
	{
		pos = Contain::getInstance()->getPressentPictureId() - 1;
		isShowedMessageSign = false;
		m_firstSign->setVisible(false);
		m_lastSign->setVisible(false);
	}
	//修改同步当前显示的图片的位置.
	Contain::getInstance()->setBothId(pos);
	//移动下面的LableRow.
	moveLabelRow(pos);
	//显示指定下标的图片..
	resizeLabelWithPicture(new QImage(Contain::getInstance()->getPictureInfoList()->at(pos).absoluteFilePath()));
	//labelRow中的label边框的样式的改变.
	showSelectedLabelFrame(pos);

	//让旋转角度归零,是否旋转标识修改为false.
	rotateAngle = 0;
	isTransformSign = false;
	m_isHorizontalFilpSign = false;
	m_isVerticalFilpSign = false;
}
void c::pressNextButtonSlot()
{
	//首先判断labelRow是否存在.
	if (!isCreateLabelRow)
	{
		return;
	}
	int pos = Contain::getInstance()->getPictureInfoList()->size() - 1;
	//如果当前显示的是最后一张图片.进行提示,如果还被点击，则进行移动.
	if (Contain::getInstance()->getPressentPictureId() == Contain::getInstance()->getPictureInfoList()->size() - 1)
	{
		if (!isShowedMessageSign)
		{
			isShowedMessageSign = true;
			m_lastSign->setVisible(true);
		}
		else
		{
			pos = 0;
			isShowedMessageSign = false;
			m_firstSign->setVisible(false);
			m_lastSign->setVisible(false);
		}
	}
	else
	{
		pos = Contain::getInstance()->getPressentPictureId() + 1;
		isShowedMessageSign = false;
		m_firstSign->setVisible(false);
		m_lastSign->setVisible(false);
	}
	//设置当前显示的图片的位置.
	Contain::getInstance()->setBothId(pos);
	//移动下面的LableRow.
	moveLabelRow(pos);
	//显示指定下标的图片..
	resizeLabelWithPicture(new QImage(Contain::getInstance()->getPictureInfoList()->at(pos).absoluteFilePath()));
	//labelRow中的label边框的样式的改变.
	showSelectedLabelFrame(pos);


	//让旋转角度归零,是否旋转标识修改为false.
	rotateAngle = 0;
	isTransformSign = false;
	m_isHorizontalFilpSign = false;
	m_isVerticalFilpSign = false;
}
void c::pressRorateSlot()
{
	//判断是否存在图片.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;

	//获取发出信号的按钮.
	auto button = qobject_cast<MyToolButton*>(this->sender());
	//如果不存在,则直接返回.
	if (!button)
		return;
	//判断旋转方向.
	float angle = (button == m_leftRotateButton) ? -90 : 90;
	rotatePixmap(angle);
}
void c::rotatePixmap(float angle)
{
	//判断是否存在图片.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;

	QMatrix matrix;
	matrix.rotate(angle);
	//获得变化后的像素图.
	QImage image = m_label->pixmap()->transformed(matrix).toImage();

	//修改关于旋转的标识符.
	rotateAngle += angle;
	isTransformSign = true;

	//调节label和图像的大小位置.
	resizeLabelWithPicture(&image);
}
void c::pressFilpSlot()
{
	//判断是否存在图片.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;

	auto button = qobject_cast<MyToolButton*>(this->sender());
	QImage image;
	//如果点击的是水平翻转.进行翻转.
	if (button == m_horizontalFilpButton)
	{
		//修改标识.
		m_isHorizontalFilpSign = !m_isHorizontalFilpSign;
		//获得变化后的像素图.
		image = m_label->pixmap()->toImage().mirrored(true, false);
	}
	//如果点击的是垂直翻转.
	else
	{
		//修改标识.
		m_isVerticalFilpSign = !m_isVerticalFilpSign;
		//获得变化后的像素图.
		image = m_label->pixmap()->toImage().mirrored(false, true);
	}

	//修改关于变换的标识符.
	isTransformSign = true;

	//调节label和图像的大小位置.
	resizeLabelWithPicture(&image);

}
void c::pressMoreButtonSlot()
{
	QMessageBox::information(this, QString::fromLocal8Bit("作者信息:"), QString::fromLocal8Bit("博客:<a href='http://blog.csdn.net/qq_37233607' > http://blog.csdn.net/qq_37233607 </a>"));
}
void c::filpPixmap(bool horizontal, bool vertical)
{
	//判断是否存在图片.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;

	QImage image;
	if (horizontal)
	{
		m_isHorizontalFilpSign = !m_isHorizontalFilpSign;
	}
	if (vertical)
	{
		//修改标识.
		m_isVerticalFilpSign = !m_isVerticalFilpSign;
	}

	//获得变化后的像素图.
	image = m_label->pixmap()->toImage().mirrored(horizontal, vertical);

	//修改关于变换的标识符.
	isTransformSign = true;

	//调节label和图像的大小位置.
	resizeLabelWithPicture(&image);
}
void c::contextMenuBatchConverFormatSlot()
{
	//如果容器内没有路径元素,则直接返回,无法打开编辑窗口.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	//设置编辑图片的初始化容器.
	m_editedPictureWidget->setInitPicture(Contain::getInstance()->getPressentPictureAbsoluteFilePath());

	m_editedPictureWidget->exec();
}
void c::contextMenuBatchConverSizeSlot()
{
	//如果容器内没有路径元素,则直接返回,无法打开编辑窗口.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	//设置编辑图片的初始化容器.
	m_editedPictureWidget->setInitPicture(Contain::getInstance()->getPressentPictureAbsoluteFilePath());
	m_editedPictureWidget->setInitPage(1);

	m_editedPictureWidget->exec();
}
void c::contextMenuBatchRenameSlot()
{
	//如果容器内没有路径元素,则直接返回,无法打开编辑窗口.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	//设置编辑图片的初始化容器.
	m_editedPictureWidget->setInitPicture(Contain::getInstance()->getPressentPictureAbsoluteFilePath());
	m_editedPictureWidget->setInitPage(2);

	m_editedPictureWidget->exec();
}
void c::contextMenuCutSlot()
{
	//剪切操作,先添加到剪切板,然后删除.
	contextMenuCopySlot();
	//如果路径容器中没有元素，则直接返回.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;

	//则先删除当前图片.
	QFile::remove(Contain::getInstance()->getPressentPictureInfo().absoluteFilePath());
	//判断当前要删除的图片是否处于最后一张的位置。
	if (Contain::getInstance()->isLast())
	{
		//判断当前是否只有这一张图片.
		if (Contain::getInstance()->getPictureInfoListSize() == 1)
		{
			//当当前路径下的图片全部被删除后...释放m_labelRow,从布局中删除，然后修改标识符.
			clearRowLabelAndLabel();
		}
		else
			reLoadFileAndPressentPictureId(Contain::getInstance()->getPictureInfoList()->at(Contain::getInstance()->getPressentPictureId() - 1).absoluteFilePath());
	}
	else
	{
		reLoadFileAndPressentPictureId(Contain::getInstance()->getPictureInfoList()->at(Contain::getInstance()->getPressentPictureId() + 1).absoluteFilePath());
	}
}
void c::contextMenuCopySlot()
{
	//如果容器内没有路径元素,则直接返回，不构成复制条件.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	//不知道为什么啊...剪切板无法复制图片，只能复制文本..................
	QPixmap temp(Contain::getInstance()->getPressentPictureInfo().absoluteFilePath());
	auto clipboard = QApplication::clipboard();
	clipboard->setPixmap(temp);
}
void c::contextMenuSaveAsSlot()
{
	//如果没有图片存在,则直接返回.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	//设置另存为对话框.
	QFileDialog dialog(this, QString::fromLocal8Bit("另存为"), "c:/users/administrator/desktop/" + Contain::getInstance()->getPressentPictureInfo().baseName() + "." + Contain::getInstance()->getPressentPictureInfo().suffix());
	dialog.setOptions(QFileDialog::HideNameFilterDetails | QFileDialog::ShowDirsOnly);
	dialog.setAcceptMode(QFileDialog::AcceptSave);
	//如果成功点击了保存.
	if (dialog.exec() == QDialog::Accepted)
	{
		//保存图片到指定位置.
		QPixmap temp(Contain::getInstance()->getPressentPictureInfo().absoluteFilePath());
		QString path = dialog.selectedFiles()[0];
		temp.save(dialog.selectedFiles()[0]);
	}
}
void c::contextMenuPrintPictureSlot()
{

}
void c::contextMenuOpenPicturePathSlot()
{
	//如果当前没有图片,则直接返回.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	//打开图片所在文件夹.
	bool ok = QDesktopServices::openUrl(QUrl::fromLocalFile(Contain::getInstance()->getPressentPictureInfo().absolutePath()));
}
void c::contextMenuLookPictureFirstSlot()
{

	HWND hwnd = (HWND)this->winId();
	DWORD dwstyle = ::GetWindowLong(hwnd, GWL_EXSTYLE);
	DWORD err = GetLastError();
	if (dwstyle & WS_EX_TOPMOST)
	{
		dwstyle &= ~WS_EX_TOPMOST;
		::SetWindowLong(hwnd, GWL_EXSTYLE, dwstyle);
		::SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOREPOSITION | SWP_NOSIZE | SWP_SHOWWINDOW);
	}
	else
	{
		dwstyle |= WS_EX_TOPMOST;
		::SetWindowLong(hwnd, GWL_EXSTYLE, dwstyle);
		::SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOREPOSITION | SWP_NOSIZE | SWP_SHOWWINDOW);
	}
}
void c::contextMenuDelSlot()
{
	//如果路径容器中没有元素，则直接返回.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;

	//编辑信息提示框.
	QString text = QString::fromLocal8Bit("确定要删除") + "\"" + Contain::getInstance()->getPressentPictureInfo().completeBaseName() + "." +
		Contain::getInstance()->getPressentPictureInfo().suffix() + "\"" + QString::fromLocal8Bit("吗");
	QMessageBox box(this);
	box.setWindowTitle(QString::fromLocal8Bit("确定删除文件"));
	box.setText(text);
	box.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
	box.setIcon(QMessageBox::Warning);
	box.setButtonText(QMessageBox::Yes, QString::fromLocal8Bit("是(Y)"));
	box.setButtonText(QMessageBox::Cancel, QString::fromLocal8Bit("否(N)"));
	int status = box.exec();

	//如果点击了是.
	if (status == QMessageBox::Yes)
	{
		//则先删除当前图片.
		QFile::remove(Contain::getInstance()->getPressentPictureInfo().absoluteFilePath());
		//判断当前要删除的图片是否处于最后一张的位置。
		if (Contain::getInstance()->isLast())
		{
			//判断当前是否只有这一张图片.
			if (Contain::getInstance()->getPictureInfoListSize() == 1)
			{
				//当当前路径下的图片全部被删除后...释放m_labelRow,从布局中删除，然后修改标识符.
				clearRowLabelAndLabel();
			}
			else
				reLoadFileAndPressentPictureId(Contain::getInstance()->getPictureInfoList()->at(Contain::getInstance()->getPressentPictureId() - 1).absoluteFilePath());
		}
		else
		{
			reLoadFileAndPressentPictureId(Contain::getInstance()->getPictureInfoList()->at(Contain::getInstance()->getPressentPictureId() + 1).absoluteFilePath());
		}
	}

}
void c::contextMenuPicturePropertySlot()
{
	//如果没有图片则直接返回.
	if (Contain::getInstance()->getPictureInfoList()->size() == 0)
		return;

	m_pictureMessageDialog = new PictureMessage(Contain::getInstance()->getPictureInfoList()->at(Contain::getInstance()->getPressentPictureId()).absoluteFilePath(), this);
	//显示为顶级活跃窗口.
	int status = m_pictureMessageDialog->exec();
	m_pictureMessageDialog->raise();
	m_pictureMessageDialog->setFocus();
	m_pictureMessageDialog->activateWindow();
	//如果用户点击了确定,则重新加载.
	if (status == QDialog::Accepted)
	{
		reLoadFileAndPressentPictureId(m_pictureMessageDialog->getAbsoluteNewFilePath());
	}
}
void c::contextMenuCenterSlot()
{
	setBgPicture("0", "0");
}
void c::contextMenuStretchSlot()
{
	setBgPicture("2", "0");
}
void c::contextMenuTileSlot()
{
	setBgPicture("0", "1");
}
