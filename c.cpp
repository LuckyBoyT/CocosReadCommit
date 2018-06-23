#include "c.h"
bool isContain(QPoint globalPos, QWidget *widget);


c::c(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);

	//��ʼ���ɹ�������.
	initScrollArea();

	//��ʼ�����ߵİ�ť.
	initSidesButtons();

	//��ʼ��������.
	initToolButtonBar();

	//��ʼ����������ʾlabel.
	initToolTipLabel();

	//��ʼ���Ҽ��˵�.
	initContextMenu();

	//��ʼ����ʶ.
	initPictureSign();

	//��ʼ��ͼƬ�༭����.
	initEditedWidget();

	//�����ź����.
	initConnect();

	//��ʼ������.
	initWindow();

}

c::~c()
{

}
//��ʼ������.
void c::initWindow()
{
	//�ô��ڽ�������ƶ��¼�.
	this->setMouseTracking(true);
	//�޸Ĵ��ڵĴ�С.
	this->resize(1000, 800);
	this->setMinimumSize(750, 300);
	//�ô��ڽ�����ק.
	this->setAcceptDrops(true);
	//�ô��ھ��н���.
	this->setFocusPolicy(Qt::ClickFocus);
	this->setFocus();

	this->setWindowTitle(QString::fromLocal8Bit("��ͼ����"));
}

//��ʼ�����ߵİ�ť.
void c::initSidesButtons()
{
	//����������ť����.
	m_leftButton = new QToolButton(this);
	m_rightButton = new QToolButton(this);

	//��õ�ǰ���ڵĴ�С.
	QSize size = this->size();

	m_leftButton->setIcon(QIcon("Resources/Icons/LeftButton.ico"));
	m_rightButton->setIcon(QIcon("Resources/Icons/RightButton.ico"));
	//����ͼ���С.

	m_leftButton->setIconSize(QSize(96, 96));
	m_rightButton->setIconSize(QSize(96, 96));
	//���ð�ť�Ĺ̶���С.

	m_leftButton->setFixedSize(100, 100);
	m_rightButton->setFixedSize(100, 100);

	//���ð�ť��λ��.
	m_leftButton->move(0, size.height() / 2 - m_leftButton->height() / 2);
	m_rightButton->move(size.width() - m_rightButton->width(), size.height() / 2 - m_leftButton->height() / 2);

	//���ð�ť����.����û��ʲôЧ��.
	m_leftButton->setAutoRaise(true);
	m_rightButton->setAutoRaise(true);

	//���ذ�ť������괥������ʱ��ʾ.��mousePressEvent���ж�.
	m_leftButton->setVisible(false);
	m_rightButton->setVisible(false);

}

//�����ź����.
void c::initConnect()
{
	//�����빤�������ź����.
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

	//����뿪���������ź����.
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

	//��������������ź����.
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

	//����������ť�Ĳۺ���.
	connect(m_leftButton, SIGNAL(clicked()), this, SLOT(pressPreciousButtonSlot()));
	connect(m_rightButton, SIGNAL(clicked()), this, SLOT(pressNextButtonSlot()));

	//�Ҽ��˵��Ĳۺ���.
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
//��ʼ��ͼƬ�༭��
void c::initEditedWidget()
{
	m_editedPictureWidget = new PictureEditedWidget(this);
	m_editedPictureWidget->setVisible(false);
}

//��ʼ���ɹ�������.
void c::initScrollArea()
{
	
	//����һ���ɹ�������Ķ���.
	m_area = new QScrollArea(this);
	m_area->setMinimumSize(this->size().width(), this->size().height());
	m_area->resize(this->size().width(), this->size().height());
	
	//����һ��label.������ʾͼƬ.
	m_label = new QLabel();
	m_label->setMinimumSize(this->size().width(), this->size().height());
	m_label->resize(this->size().width(), this->size().height());
	m_label->setAlignment(Qt::AlignCenter);
	//��Label��Ϊ�ɹ����������������.
	m_area->setWidget(m_label);
	//���ÿɹ������������Ӧ����ƶ��¼�.
	m_area->setMouseTracking(true);
	//�������Ķ���.
	m_area->setAlignment(Qt::AlignCenter);
	//��װ�¼�������.
	m_label->installEventFilter(this);
	m_label->setFocusPolicy(Qt::StrongFocus);


	//���ò���.
	QHBoxLayout *layout = new QHBoxLayout(this);
	layout->addWidget(m_area);
	//���ò��ֵ����ܿ�϶.
	layout->setContentsMargins(50, 0, 50, 50);

	m_area->horizontalScrollBar()->setVisible(false);
	m_area->verticalScrollBar()->setVisible(false);

	//��ʼ������.
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
//��ʼ��������.
void c::initToolButtonBar()
{
	//��ʼ��...�̶���СΪ645.�߶�Ϊ50.
	m_bottomToolBar = new QToolBar(this); m_bottomToolBar->setFixedSize(645, 50);
	m_boostButton = new MyToolButton(); m_boostButton->setIcon(QIcon("Resources/Icons/boost.ico")); m_boostButton->setFixedSize(50, 50); m_boostButton->setProperty("toolTip", QString::fromLocal8Bit("�Ŵ�(Up)"));
	m_reduceButton = new MyToolButton(); m_reduceButton->setIcon(QIcon("Resources/Icons/reduce.ico")); m_reduceButton->setFixedSize(50, 50); m_reduceButton->setProperty("toolTip", QString::fromLocal8Bit("��С(Down)"));
	m_sizeHintButton = new MyToolButton(); m_sizeHintButton->setIcon(QIcon("Resources/Icons/sizeHint.ico")); m_sizeHintButton->setFixedSize(50, 50); m_sizeHintButton->setProperty("toolTip", QString::fromLocal8Bit("ʵ�ʳߴ�(R)"));
	m_beautiButton = new MyToolButton(); m_beautiButton->setIcon(QIcon("Resources/Icons/beauti.ico")); m_beautiButton->setFixedSize(75, 50); m_beautiButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon); m_beautiButton->setText(QString::fromLocal8Bit("����(E)")); m_beautiButton->setProperty("toolTip", QString::fromLocal8Bit("�༭ͼƬ"));
	m_preciousButton = new MyToolButton(); m_preciousButton->setIcon(QIcon("Resources/Icons/precious.ico")); m_preciousButton->setFixedSize(50, 50); m_preciousButton->setProperty("toolTip", QString::fromLocal8Bit("��һ��(<-)"));
	m_nextButton = new MyToolButton(); m_nextButton->setIcon(QIcon("Resources/Icons/next.ico")); m_nextButton->setFixedSize(50, 50); m_nextButton->setProperty("toolTip", QString::fromLocal8Bit("��һ��(->)"));
	m_leftRotateButton = new MyToolButton(); m_leftRotateButton->setIcon(QIcon("Resources/Icons/leftRotate.ico")); m_leftRotateButton->setFixedSize(50, 50); m_leftRotateButton->setProperty("toolTip", QString::fromLocal8Bit("������ת90��(A)")); 
	m_rightRotateButton = new MyToolButton(); m_rightRotateButton->setIcon(QIcon("Resources/Icons/rightRotate.ico")); m_rightRotateButton->setFixedSize(50, 50); m_rightRotateButton->setProperty("toolTip", QString::fromLocal8Bit("������ת90��(S)"));
	m_horizontalFilpButton = new MyToolButton(); m_horizontalFilpButton->setIcon(QIcon("Resources/Icons/horizontalFilp.png")); m_horizontalFilpButton->setFixedSize(50, 50); m_horizontalFilpButton->setProperty("toolTip", QString::fromLocal8Bit("ˮƽ����(J)"));
	m_verticalFilpButton = new MyToolButton(); m_verticalFilpButton->setIcon(QIcon("Resources/Icons/verticalFilp.png")); m_verticalFilpButton->setFixedSize(50, 50); m_verticalFilpButton->setProperty("toolTip", QString::fromLocal8Bit("��ֱ����(K)"));
	m_delButton = new MyToolButton(); m_delButton->setIcon(QIcon("Resources/Icons/clean.ico")); m_delButton->setFixedSize(50, 50); m_delButton->setProperty("toolTip", QString::fromLocal8Bit("ɾ��(D)"));
	m_moreButton = new MyToolButton(); m_moreButton->setIcon(QIcon("Resources/Icons/more.ico")); m_moreButton->setFixedSize(50, 50); m_moreButton->setProperty("toolTip", QString::fromLocal8Bit("����(M)")); m_moreButton->setShortcut(Qt::Key_M);

	//�ӵ���������...
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
	//����ʾ.
	m_bottomToolBar->setVisible(false);

}
void c::contextUpdateSlot()
{
	//���·��������û��Ԫ�أ���ֱ�ӷ���.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	reLoadFileAndPressentPictureId(Contain::getInstance()->getPressentPictureAbsoluteFilePath());
}
//��ʼ���Ҽ��˵�.
void c::initContextMenu()
{
	m_menu = new QMenu();
	m_editPictureMenu = new QMenu(QString::fromLocal8Bit("�༭ͼƬ"));
	m_setBackGroundMenu = new QMenu(QString::fromLocal8Bit("��Ϊ����(W)"));
	m_updateAction = new QAction(QString::fromLocal8Bit("ˢ��"),this);
	m_batchConverFormatAction = new QAction(QString::fromLocal8Bit("����ת����ʽ"), this);
	m_batchConverSizeAction = new QAction(QString::fromLocal8Bit("����ת���ߴ�"), this);
	m_batchRenameAction = new QAction(QString::fromLocal8Bit("����������"), this);
	m_cutAction = new QAction(QString::fromLocal8Bit("����(T)"), this);
	m_copyAction = new QAction(QString::fromLocal8Bit("����(C)"), this);
	m_saveAsAction = new QAction(QString::fromLocal8Bit("��浽..."), this);
	m_openPicturePathAction = new QAction(QString::fromLocal8Bit("��ͼƬ�����ļ���"), this);
	m_printPictureAction = new QAction(QString::fromLocal8Bit("��ӡͼƬ"), this);
	m_lookPictureFirstAction = new QAction(QString::fromLocal8Bit("��ͼ����������ǰ"), this);
	m_delAction = new QAction(QString::fromLocal8Bit("ɾ��(D)"), this);
	m_picturePropertyAction = new QAction(QString::fromLocal8Bit("ͼƬ��Ϣ(I)"), this);
	m_centerAction = new QAction(QString::fromLocal8Bit("����"), this);
	m_stretchAction = new QAction(QString::fromLocal8Bit("����"), this);
	m_tileAction = new QAction(QString::fromLocal8Bit("ƽ��"), this);

	//���ÿ�ͼ��������ǰ,���Ա�ѡ��,��Ĭ�ϲ���ѡ��.
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
	//������ʶ��������������.
	m_firstSign = new PictureSign(QString::fromLocal8Bit("��ǰ���ǵ�һ��,�����������������һ��"), this);
	m_firstSign->setVisible(false);
	m_lastSign = new PictureSign(QString::fromLocal8Bit("��ǰ�������һ��,�������������ص�һ��"), this);
	m_lastSign->setVisible(false);
}
void c::resizeEvent(QResizeEvent *event)
{
	returnDefaultPos();
}

//��ԭ��������λ��.
void c::returnDefaultPos()
{
	QSize size = this->size();
	//�������Ҳఴť��λ��.
	m_leftButton->move(0, size.height() / 2 - m_leftButton->height() / 2);
	m_rightButton->move(size.width() - m_rightButton->width(), size.height() / 2 - m_leftButton->height() / 2);

	//����ͼƬ���͹�������λ��.
	this->m_bottomToolBar->move((size.width() - m_bottomToolBar->size().width()) / 2, size.height() - 100);
	this->m_toolTipLabel->move((size.width() - 600) / 2, size.height() - 130);

	//���labelRow����,��ı�label��λ��.
	if (isCreateLabelRow)
	{
		//�ñ�ѡ�е�ͼƬ�����м��λ��.ֱ�Ӱ�label�е�ͼ��������ż���.
		resizeLabelWithPicture(&m_label->pixmap()->toImage());
		//�ƶ��·���labelRow.
		moveLabelRow(Contain::getInstance()->getPressentPictureId());
		//�ƶ���ʶ.
		resizePictureSignPos();
		m_label->setMinimumSize(this->size().width(), this->size().height());
	}


}
//������¼�����������ע�͵�.����ûʲô����.
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
				//����ͼƬ������
				scaledPicture(event->delta() / 8.0 / 15.0);
				return true;
			}
			//��m_label���а�������.���������m_label��,��ֱ�Ӱ��յ�ǰ��İ���������д���.
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
	//����ͼƬ������
	scaledPicture(event->delta() / 8.0 / 15.0);
}
void c::leaveEvent(QEvent *event)
{
	//������Ƴ�ȥʱ,��ʧ.
	m_leftButton->setVisible(false);
	m_rightButton->setVisible(false);
	m_toolTipLabel->setVisible(false);

	if (m_labelRow && isCreateLabelRow)
		m_labelRow->setVisible(false);
	m_bottomToolBar->setVisible(false);

/*	if (m_labelRow && isCreateLabelRow)
	{
		QString path = Contain::getInstance()->getPressentPictureAbsoluteFilePath();
		//����.
		reLoadFileAndPressentPictureId(path);
	}*/
}

void c::scaledPicture(int factor)
{
	//�������ص�,��Ҫ�о��ĵط�.
	//�ж��Ƿ����ͼƬ.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;

	//��ȡ֮ǰ�ı���.
	int tempSize = m_scalNumber;
	qDebug() << "1" << endl;
	//
	if (m_scalNumber + factor >= 20)
		return;

	//��¼һ�µ�ǰ�ı���.
	m_scalNumber += factor;
	double temp = pow(1.125, m_scalNumber);

	//��ȡ��ǰ��ͼƬ.
	QImage presPixmap = Contain::getInstance()->getPressentPixmap().toImage();
	QImage displayPixmap = presPixmap.scaled(presPixmap.size()*temp, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

	//	��������label�Ĵ�С.
	m_label->resize(presPixmap.size()*temp);
	//������ʾ��С.
	m_label->setPixmap(QPixmap::fromImage(displayPixmap));

	//���ľ���λ�û�����ʾͼƬ�Ŀ��ƶ���������λ��.
	auto baseLabelAreaPos = m_area->mapFromGlobal(m_scaleMousePos);
	//���������λ�ú�����λ�õĲ�ֵ.
	auto offset = baseLabelAreaPos - QPoint(this->m_area->size().width() / 2, this->m_area->size().height() / 2);

	m_area->horizontalScrollBar()->setValue(m_area->horizontalScrollBar()->value() + offset.x());
	m_area->verticalScrollBar()->setValue(m_area->verticalScrollBar()->value() + offset.y());

}
void c::contextMenuEvent(QContextMenuEvent *event)
{
	//��û�з����任ʱ,��ʾ�����˵�.
	if (!isTransformSign)
		m_menu->exec(QCursor::pos());
	else//����ѯ���Ƿ񱣴�.
	{
		QMessageBox temp(QMessageBox::Information, QString::fromLocal8Bit("�任ͼƬ"), QString::fromLocal8Bit("����ͼƬ�����˱任����,�Ƿ���Ҫ����?"),
			QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, this);
		temp.setButtonText(QMessageBox::Yes, QString::fromLocal8Bit("�Զ���������"));
		temp.setButtonText(QMessageBox::No, QString::fromLocal8Bit("����ԭͼ"));
		temp.setButtonText(QMessageBox::Cancel, QString::fromLocal8Bit("������"));
		//�����û�ѡ����.
		int status = temp.exec();

		//����û�ѡ���Զ���������Ļ�.�򱣴��ͼƬ�ڵ�ǰ�ļ���.�Ҹ���.
		if (status == QMessageBox::Yes)
		{
			QString path;
			QString name;
			do
			{
				//�ж��Զ���������������Ƿ�����ͬ��.
				name += QString::fromLocal8Bit("_�任");
				path = Contain::getInstance()->getPressentPictureInfo().absolutePath() + "/" + Contain::getInstance()->getPressentPictureInfo().completeBaseName()
					+ name + "." + Contain::getInstance()->getPressentPictureInfo().suffix();
			} while (QFile::exists(path));

			QMatrix matrix;
			matrix.rotate(rotateAngle);
			//��ȡ��ǰ����תͼƬ,���Ҵ�����ָ��·����.
			QImage temp = Contain::getInstance()->getPressentPixmap().toImage().transformed(matrix).mirrored(m_isHorizontalFilpSign, m_isVerticalFilpSign);
			temp.save(path);
			//����.
			reLoadFileAndPressentPictureId(Contain::getInstance()->getPressentPictureAbsoluteFilePath());

			//�Ѻ���ת�йصı�ʶ����.
			isTransformSign = false;
			rotateAngle = 0;
			m_isHorizontalFilpSign = false;
			m_isVerticalFilpSign = false;
		}
		//����û�ѡ���˸���ԭͼ,����ɾ��ԭͼ,��������ͼ.�ڽ��и���,ע��,��ǰ��ͼƬ����ͼ.
		else if (status == QMessageBox::No)
		{
			//�ȼ�����ͼ.
			QString path = Contain::getInstance()->getPressentPictureAbsoluteFilePath();
			//�Ȼ�ȡ��ǰͼƬ��ԭʼͼ��.
			QImage image = QImage(Contain::getInstance()->getPressentPictureAbsoluteFilePath());

			//��ɾ��ԭͼ.
			QFile file(Contain::getInstance()->getPressentPictureAbsoluteFilePath());
			file.remove();

			//��ȡ��ǰ����תͼƬ,���Ҵ�����ָ��·����.
			QMatrix matrix;
			matrix.rotate(rotateAngle);
			QImage temp = image.transformed(matrix).mirrored(m_isHorizontalFilpSign, m_isVerticalFilpSign);
			temp.save(path);

			//����.
			reLoadFileAndPressentPictureId(path);
			//�Ѻ���ת�йصı�ʶ����.
			isTransformSign = false;
			rotateAngle = 0;
			m_isHorizontalFilpSign = false;
			m_isVerticalFilpSign = false;
		}
		//���������,����ֱ��x��,��ȡ����ת״̬,���һظ���ԭ��״̬.
		else
		{
			//�Ȱ���ת�йصı�ʶ����.
			isTransformSign = false;
			rotateAngle = 0;
			m_isHorizontalFilpSign = false;
			m_isVerticalFilpSign = false;
			//�ָ�ԭ����label.
			resizeLabelWithPicture(&Contain::getInstance()->getPressentPixmap().toImage());
		}

	}

}

void c::mousePressEvent(QMouseEvent *event)
{
	//������ʧ.
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

	//�ж�����Ƿ񴥼�������İ�ť.
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
		//�����޸�������״.
		temp.setShape(Qt::ArrowCursor);
		this->setCursor(temp);
		m_leftButton->setVisible(false);
		m_rightButton->setVisible(false);
	}


	//���������±߽�50����,����ʾ.
	QRect Left(0, size.height() - 50, size.width(), size.height());
	if (Left.contains(converToPagePoint))
	{
		qDebug() << "1";
		//��ʾ���������ı���Ϣ��.
		m_bottomToolBar->setVisible(true);
		m_toolTipLabel->setVisible(true);
		//����ͼƬ�Ž���ʱ�����������Ż���ʾlabelRow.
		if (isCreateLabelRow)
			m_labelRow->setVisible(true);
	}
	else
	{
		qDebug() << "2";
		//��֮����.
		m_bottomToolBar->setVisible(false);
		m_toolTipLabel->setVisible(false);
		if (isCreateLabelRow)
		{
			m_labelRow->setVisible(false);
			setToolTipLabelText();
		}
	}

	//�ж��Ƿ��а������.
	if (m_isPressed)
	{
		QPoint currentPt = event->pos();

		int widthOffset = m_precMousePos.x() - currentPt.x();
		int heightOffset = m_precMousePos.y() - currentPt.y();

		//��¼��ǰ����������ֵλ��.
		auto m_horiBarValue = m_area->horizontalScrollBar()->value() + widthOffset;
		auto m_vertBarValue = m_area->verticalScrollBar()->value() + heightOffset;

		m_area->horizontalScrollBar()->setValue(m_horiBarValue);
		m_area->verticalScrollBar()->setValue(m_vertBarValue);

		m_precMousePos = currentPt;
	}


}
void c::mouseReleaseEvent(QMouseEvent *event)
{
	//����.���¼���.
	m_isPressed = false;
	m_precMousePos = QPoint(0, 0);
}
void c::initLabelArray(QSize size, int len)
{
	//����m_labelRow����.
	m_labelRow = new MyLabelRow(size, len, this);
	isCreateLabelRow = true;

	this->m_labelRow->move(0, this->size().height() - 60);

	m_labelRow->setVisible(false);
	//����ÿ��label�Ĳ�.
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
	//������.
	m_firstSign->setVisible(false);
	m_lastSign->setVisible(false);

	auto label = static_cast<MyLabel*>(object);
	//��ʾ�µ�label.
	int pos = label->property("id").toInt();
	//�ƶ�labelRow��λ��.
	Contain::getInstance()->setBothId(pos);
	//�ƶ������LableRow.
	moveLabelRow(pos);
	//��ʾָ���±��ͼƬ..
	resizeLabelWithPicture(new QImage(Contain::getInstance()->getPictureInfoList()->at(pos).absoluteFilePath()));
	//labelRow�е�label�߿����ʽ�ĸı�.
	showSelectedLabelFrame(pos);
	//
	setToolTipLabelText();

	//ȡ�����ű����͹������ű���.
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
	//����Ѿ������������.
	clearRowLabelAndLabel();

	//����ק��ȥ��ͼƬ·���µ�����ͼƬ�ļ��Ž�������.
	QList<QUrl> pathList = event->mimeData()->urls();
	//��ȡ��ק�������ļ�����·��.
	QString path = pathList.first().toLocalFile();

	//���¼���ͼƬ·���͵�ǰ��ID.
	reLoadFileAndPressentPictureId(path);
}
//�������뵱ǰ�ļ�·���͵�ǰͼƬλ��.����Ϊ��ǰͼƬ�ľ���·��.
void c::reLoadFileAndPressentPictureId(QString filePath)
{
	//�����ԭ�������ڵ����ݲ���������ڵĻ�,���ͷ�m_labelRow.
	clearRowLabelAndLabel();

	QFileInfo temp(filePath);
	//���������ڵ�ͼƬ·��.
	auto i = temp.absolutePath();
	Contain::getInstance()->setPictureInfoList(temp.absolutePath());

	int num = Contain::getInstance()->getPictureInfoListSize();
	auto q = Contain::getInstance()->getPressentPictureId();
	if (!QFile::exists(filePath))
	{
		if (Contain::getInstance()->getPressentPictureId() >= num )
		{
			//���õ�ǰͼƬ���ļ��е�λ��.
			int id = Contain::getInstance()->getPressentPictureId();
			//�����λ�ÿ��Խ���΢��.
			Contain::getInstance()->setBothId(num - 1);
		}
		else
		{
			//���ֲ���.
			//Contain::getInstance()->setBothId(returnDropPictureId(filePath));
		}
	}
	else
	{
		//���id.
		Contain::getInstance()->clearId();
		//���õ�ǰͼƬ���ļ��е�λ��.
		Contain::getInstance()->setBothId(returnDropPictureId(filePath));
	}

	//��ʼ���������labelRow.
	initLabelArray(QSize(50, 50), Contain::getInstance()->getPictureInfoListSize());
	//�ƶ������labelRow.
	moveLabelRow(Contain::getInstance()->getPressentPictureId());
	//��ѡ�е�ͼƬ��ʾ��label����.
	resizeLabelWithPicture(new QImage(Contain::getInstance()->getPressentPictureAbsoluteFilePath()));
	//��ͼƬ��ʾ��labelRow��.
	showLabelPicture();
	//�޸���ʾ���ڵ���Ϣ.
	setToolTipLabelText();
}

//��Ӧlabel���е�ͼƬ.
void c::resizeLabelWithPicture(QImage *image)
{
	if (Contain::getInstance()->getPressentPictureId() < 0)
		return;
	QSize size = m_area->size();

	QSize s = image->size();

	//���ͼƬ�Ĵ�С�ȹ�������Ҫ��.������ܻ���һ������.
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

	//��������.
	m_tempPicture = image->scaled(QSize(X, Y), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	m_label->setPixmap(QPixmap::fromImage(*image));
	m_label->move(size.width() / 2 - X / 2, size.height() / 2 - Y / 2);
	}
	//����,label��С�ͺ�ͼƬһ����.
	else
	{
	m_label->resize(image->size());
	m_label->move(size.width() / 2 - image->size().width() / 2, size.height() / 2 - image->size().height() / 2);
	m_label->setPixmap(QPixmap::fromImage(*image));
	}*/

	//m_label->move(size.width() / 2 - image->size().width() / 2, size.height() / 2 - image->size().height() / 2);

	//�޸Ĵ�С.
	m_label->resize(image->size());
	//����ͼ��.
	m_label->setPixmap(QPixmap::fromImage(*image));

	resizePictureSignPos();
}
//�ƶ�labelRow��λ��.
void c::moveLabelRow(int pos)
{
	QSize size = this->size();
	//�ƶ������LableRow.
	this->m_labelRow->move(size.width() / 2 - 25 - 50 * pos, size.height() - 60);
}
//���labelRow��label.
void c::clearRowLabelAndLabel()
{
	//���������.
	if (isCreateLabelRow)
	{
		//Ȼ������ͷ�labelRow,�������Contain��������������.
		delete m_labelRow;
		m_labelRow = 0;
		isCreateLabelRow = false;
		Contain::getInstance()->clearPictureInfoList();
		m_label->clear();
	}
}

//�ѷŽ�����ͼƬ��·����ͼƬ��ʾ��labelRow��.
void c::showLabelPicture()
{
	//�Ȼ�ȡ��ǰ���ڵĿ��.
	int width = this->size().width();
	auto infoList = Contain::getInstance()->getPictureInfoList();
	for (int i = 0; i < infoList->size(); ++i)
	{
		//��ͼƬ��ʾ��label��.
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

		//������Ҫ�ڴ���һ���߳�ȥ������ʾ.
		QPixmap temp = c.scaled(X, Y, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		m_labelRow->getLabelList()[i]->setPixmap(temp);
	}
	showSelectedLabelFrame(Contain::getInstance()->getPressentPictureId());
}
//�ñ�ѡ�е�ͼƬ�ı߿���б仯.(����ǰѡ��ͼƬ�仯ʱ����Ҫ����)
void c::showSelectedLabelFrame(int newSelected)
{
	//�õ�ǰ��ͼƬ�߿���ɫ���֮ǰ��ͼƬ�߿�ָ�ԭ��������.
	auto list = m_labelRow->getLabelList();

	//��֮ǰѡ���ͼƬ�߿�ȥ.��ֹ�û��ٴε����ѡ��ͼƬ���ºڿ���ʧ.
	if (Contain::getInstance()->getPreciousPictureId() >= 0)
	{
		if (Contain::getInstance()->getPreciousPictureId() >= list.size())
			;
		else
			list[Contain::getInstance()->getPreciousPictureId()]->setFrameShape(QFrame::StyledPanel);
	}
	//����ѡ���ͼƬ�޸ı߿�.
	if (newSelected >= 0)
		list[newSelected]->setFrameShape(QFrame::WinPanel);
}
//ͼƬ��ʶ��λ��.
void c::resizePictureSignPos()
{
	QSize size = m_label->size();
	QPoint pos = m_label->pos();
	QPoint framePos = this->geometry().topLeft();
	//m_firstSign->move(pos.x() + size.width() / 2 - 150 + framePos.x(), pos.y() + size.height() / 2 - 25 + framePos.y());
	//m_lastSign->move(pos.x() + size.width() / 2 - 150 + framePos.x(), pos.y() + size.height() / 2 - 25 + framePos.y());
}
//��ȡ���µ�ͼƬ��·���е�ͼƬλ��.
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
//�������汳��.
void c::setBgPicture(QString style, QString tile)
{
	//���û��ͼƬ,��ֱ�ӷ���.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;

	//��õ�ǰͼƬ�ľ���·��.
	QString src = Contain::getInstance()->getPressentPictureAbsoluteFilePath();

	//�����ǿ��Ե�...
	QSettings set("HKEY_CURRENT_USER\\Control Panel\\Desktop", QSettings::NativeFormat);
	QString path(src);
	//����ע������Ϣ.
	set.setValue("Wallpaper", path);
	set.setValue("WallpaperStyle", style);

	if (tile == "1")
		set.setValue("TileWallpaper", tile);
	else
		set.setValue("TileWallpaper", "0");

	QByteArray byte = path.toLocal8Bit();
	SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, byte.data(), SPIF_SENDCHANGE | SPIF_SENDWININICHANGE);
}
//������������ͷ�labelRowָ����ڴ�.
void c::closeEvent(QCloseEvent *event)
{
	event->accept();
}
//��ʼ����������ʾlabel.
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
	//��ȡ�����źŵĶ���ָ��.
	auto pSender = qobject_cast<MyToolButton*>(this->sender());
	QString mes = pSender->property("toolTip").toString();
	this->m_toolTipLabel->setText(mes);
}
void c::setToolTipLabelText()
{
	//��û��ͼƬʱֱ�ӷ���.
	if (!isCreateLabelRow)
		return;
	//��ȡ��ǰͼƬ��һЩ������Ϣ.
	QPixmap temp = Contain::getInstance()->getPressentPixmap();
	QDateTime dateTime = Contain::getInstance()->getPressentPictureCreatedTime();
	int pressentId = Contain::getInstance()->getPressentPictureId();
	int totalId = Contain::getInstance()->getPictureInfoListSize();
	QString date = dateTime.toString("yyyy-MM-dd");
	QString fileName = Contain::getInstance()->getPressentPictureInfo().fileName();
	int size = Contain::getInstance()->getPressentPictureInfo().size() / 1024;

	//��ʱ��Ҫ��ʾ����.
	//QString str = fileName + " - " + QString("%1x%2").arg(temp.width()).arg(temp.height()) + " - " + "100%" + " - " + date + " - " + QString("%1KB").arg(size) + " - " + QString("%1/%2").arg(pressentId + 1).arg(totalId);
	QString str = fileName + " - " + QString("%1x%2").arg(temp.width()).arg(temp.height()) +  " - " + date + " - " + QString("%1KB").arg(size) + " - " + QString("%1/%2").arg(pressentId + 1).arg(totalId);
	this->m_toolTipLabel->setText(str);
}
void c::pressBoostButtonSlot()
{
	//�ж��Ƿ����ͼƬ.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	scaledPicture(1);
}
void c::pressReduceButtonSlot()
{
	//�ж��Ƿ����ͼƬ.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	scaledPicture(-1);
}
void c::pressSizeHintButtonSlot()
{
	//�ж��Ƿ����ͼƬ.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	scaledPicture(-m_scalNumber);
	m_scalNumber = 0;
}
void c::pressBeautiButtonSlot()
{
	//���������û��·��Ԫ��,��ֱ�ӷ���,�޷��򿪱༭����.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	//���ñ༭ͼƬ�ĳ�ʼ������.
	m_editedPictureWidget->setInitPicture(Contain::getInstance()->getPressentPictureAbsoluteFilePath());

	//��ʾ�༭����.
	m_editedPictureWidget->exec();
}
void c::pressPreciousButtonSlot()
{
	//�����ж��Ƿ�labelRow�Ƿ����.
	if (!isCreateLabelRow)
	{
		return;
	}
	int pos = 0;

	//�����ǰ��ʾ���ǵ�һ��ͼƬ��������ʾ��������������������ƶ�.
	if (Contain::getInstance()->getPressentPictureId() == 0)
	{
		//�տ�ʼû����ʾ��.�޸ı�ʶ,��ʶ�Ѿ���ʾ����.
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
	//�޸�ͬ����ǰ��ʾ��ͼƬ��λ��.
	Contain::getInstance()->setBothId(pos);
	//�ƶ������LableRow.
	moveLabelRow(pos);
	//��ʾָ���±��ͼƬ..
	resizeLabelWithPicture(new QImage(Contain::getInstance()->getPictureInfoList()->at(pos).absoluteFilePath()));
	//labelRow�е�label�߿����ʽ�ĸı�.
	showSelectedLabelFrame(pos);

	//����ת�Ƕȹ���,�Ƿ���ת��ʶ�޸�Ϊfalse.
	rotateAngle = 0;
	isTransformSign = false;
	m_isHorizontalFilpSign = false;
	m_isVerticalFilpSign = false;
}
void c::pressNextButtonSlot()
{
	//�����ж�labelRow�Ƿ����.
	if (!isCreateLabelRow)
	{
		return;
	}
	int pos = Contain::getInstance()->getPictureInfoList()->size() - 1;
	//�����ǰ��ʾ�������һ��ͼƬ.������ʾ,������������������ƶ�.
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
	//���õ�ǰ��ʾ��ͼƬ��λ��.
	Contain::getInstance()->setBothId(pos);
	//�ƶ������LableRow.
	moveLabelRow(pos);
	//��ʾָ���±��ͼƬ..
	resizeLabelWithPicture(new QImage(Contain::getInstance()->getPictureInfoList()->at(pos).absoluteFilePath()));
	//labelRow�е�label�߿����ʽ�ĸı�.
	showSelectedLabelFrame(pos);


	//����ת�Ƕȹ���,�Ƿ���ת��ʶ�޸�Ϊfalse.
	rotateAngle = 0;
	isTransformSign = false;
	m_isHorizontalFilpSign = false;
	m_isVerticalFilpSign = false;
}
void c::pressRorateSlot()
{
	//�ж��Ƿ����ͼƬ.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;

	//��ȡ�����źŵİ�ť.
	auto button = qobject_cast<MyToolButton*>(this->sender());
	//���������,��ֱ�ӷ���.
	if (!button)
		return;
	//�ж���ת����.
	float angle = (button == m_leftRotateButton) ? -90 : 90;
	rotatePixmap(angle);
}
void c::rotatePixmap(float angle)
{
	//�ж��Ƿ����ͼƬ.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;

	QMatrix matrix;
	matrix.rotate(angle);
	//��ñ仯�������ͼ.
	QImage image = m_label->pixmap()->transformed(matrix).toImage();

	//�޸Ĺ�����ת�ı�ʶ��.
	rotateAngle += angle;
	isTransformSign = true;

	//����label��ͼ��Ĵ�Сλ��.
	resizeLabelWithPicture(&image);
}
void c::pressFilpSlot()
{
	//�ж��Ƿ����ͼƬ.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;

	auto button = qobject_cast<MyToolButton*>(this->sender());
	QImage image;
	//����������ˮƽ��ת.���з�ת.
	if (button == m_horizontalFilpButton)
	{
		//�޸ı�ʶ.
		m_isHorizontalFilpSign = !m_isHorizontalFilpSign;
		//��ñ仯�������ͼ.
		image = m_label->pixmap()->toImage().mirrored(true, false);
	}
	//���������Ǵ�ֱ��ת.
	else
	{
		//�޸ı�ʶ.
		m_isVerticalFilpSign = !m_isVerticalFilpSign;
		//��ñ仯�������ͼ.
		image = m_label->pixmap()->toImage().mirrored(false, true);
	}

	//�޸Ĺ��ڱ任�ı�ʶ��.
	isTransformSign = true;

	//����label��ͼ��Ĵ�Сλ��.
	resizeLabelWithPicture(&image);

}
void c::pressMoreButtonSlot()
{
	QMessageBox::information(this, QString::fromLocal8Bit("������Ϣ:"), QString::fromLocal8Bit("����:<a href='http://blog.csdn.net/qq_37233607' > http://blog.csdn.net/qq_37233607 </a>"));
}
void c::filpPixmap(bool horizontal, bool vertical)
{
	//�ж��Ƿ����ͼƬ.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;

	QImage image;
	if (horizontal)
	{
		m_isHorizontalFilpSign = !m_isHorizontalFilpSign;
	}
	if (vertical)
	{
		//�޸ı�ʶ.
		m_isVerticalFilpSign = !m_isVerticalFilpSign;
	}

	//��ñ仯�������ͼ.
	image = m_label->pixmap()->toImage().mirrored(horizontal, vertical);

	//�޸Ĺ��ڱ任�ı�ʶ��.
	isTransformSign = true;

	//����label��ͼ��Ĵ�Сλ��.
	resizeLabelWithPicture(&image);
}
void c::contextMenuBatchConverFormatSlot()
{
	//���������û��·��Ԫ��,��ֱ�ӷ���,�޷��򿪱༭����.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	//���ñ༭ͼƬ�ĳ�ʼ������.
	m_editedPictureWidget->setInitPicture(Contain::getInstance()->getPressentPictureAbsoluteFilePath());

	m_editedPictureWidget->exec();
}
void c::contextMenuBatchConverSizeSlot()
{
	//���������û��·��Ԫ��,��ֱ�ӷ���,�޷��򿪱༭����.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	//���ñ༭ͼƬ�ĳ�ʼ������.
	m_editedPictureWidget->setInitPicture(Contain::getInstance()->getPressentPictureAbsoluteFilePath());
	m_editedPictureWidget->setInitPage(1);

	m_editedPictureWidget->exec();
}
void c::contextMenuBatchRenameSlot()
{
	//���������û��·��Ԫ��,��ֱ�ӷ���,�޷��򿪱༭����.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	//���ñ༭ͼƬ�ĳ�ʼ������.
	m_editedPictureWidget->setInitPicture(Contain::getInstance()->getPressentPictureAbsoluteFilePath());
	m_editedPictureWidget->setInitPage(2);

	m_editedPictureWidget->exec();
}
void c::contextMenuCutSlot()
{
	//���в���,����ӵ����а�,Ȼ��ɾ��.
	contextMenuCopySlot();
	//���·��������û��Ԫ�أ���ֱ�ӷ���.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;

	//����ɾ����ǰͼƬ.
	QFile::remove(Contain::getInstance()->getPressentPictureInfo().absoluteFilePath());
	//�жϵ�ǰҪɾ����ͼƬ�Ƿ������һ�ŵ�λ�á�
	if (Contain::getInstance()->isLast())
	{
		//�жϵ�ǰ�Ƿ�ֻ����һ��ͼƬ.
		if (Contain::getInstance()->getPictureInfoListSize() == 1)
		{
			//����ǰ·���µ�ͼƬȫ����ɾ����...�ͷ�m_labelRow,�Ӳ�����ɾ����Ȼ���޸ı�ʶ��.
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
	//���������û��·��Ԫ��,��ֱ�ӷ��أ������ɸ�������.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	//��֪��Ϊʲô��...���а��޷�����ͼƬ��ֻ�ܸ����ı�..................
	QPixmap temp(Contain::getInstance()->getPressentPictureInfo().absoluteFilePath());
	auto clipboard = QApplication::clipboard();
	clipboard->setPixmap(temp);
}
void c::contextMenuSaveAsSlot()
{
	//���û��ͼƬ����,��ֱ�ӷ���.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	//�������Ϊ�Ի���.
	QFileDialog dialog(this, QString::fromLocal8Bit("���Ϊ"), "c:/users/administrator/desktop/" + Contain::getInstance()->getPressentPictureInfo().baseName() + "." + Contain::getInstance()->getPressentPictureInfo().suffix());
	dialog.setOptions(QFileDialog::HideNameFilterDetails | QFileDialog::ShowDirsOnly);
	dialog.setAcceptMode(QFileDialog::AcceptSave);
	//����ɹ�����˱���.
	if (dialog.exec() == QDialog::Accepted)
	{
		//����ͼƬ��ָ��λ��.
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
	//�����ǰû��ͼƬ,��ֱ�ӷ���.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;
	//��ͼƬ�����ļ���.
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
	//���·��������û��Ԫ�أ���ֱ�ӷ���.
	if (Contain::getInstance()->getPictureInfoListSize() == 0)
		return;

	//�༭��Ϣ��ʾ��.
	QString text = QString::fromLocal8Bit("ȷ��Ҫɾ��") + "\"" + Contain::getInstance()->getPressentPictureInfo().completeBaseName() + "." +
		Contain::getInstance()->getPressentPictureInfo().suffix() + "\"" + QString::fromLocal8Bit("��");
	QMessageBox box(this);
	box.setWindowTitle(QString::fromLocal8Bit("ȷ��ɾ���ļ�"));
	box.setText(text);
	box.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
	box.setIcon(QMessageBox::Warning);
	box.setButtonText(QMessageBox::Yes, QString::fromLocal8Bit("��(Y)"));
	box.setButtonText(QMessageBox::Cancel, QString::fromLocal8Bit("��(N)"));
	int status = box.exec();

	//����������.
	if (status == QMessageBox::Yes)
	{
		//����ɾ����ǰͼƬ.
		QFile::remove(Contain::getInstance()->getPressentPictureInfo().absoluteFilePath());
		//�жϵ�ǰҪɾ����ͼƬ�Ƿ������һ�ŵ�λ�á�
		if (Contain::getInstance()->isLast())
		{
			//�жϵ�ǰ�Ƿ�ֻ����һ��ͼƬ.
			if (Contain::getInstance()->getPictureInfoListSize() == 1)
			{
				//����ǰ·���µ�ͼƬȫ����ɾ����...�ͷ�m_labelRow,�Ӳ�����ɾ����Ȼ���޸ı�ʶ��.
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
	//���û��ͼƬ��ֱ�ӷ���.
	if (Contain::getInstance()->getPictureInfoList()->size() == 0)
		return;

	m_pictureMessageDialog = new PictureMessage(Contain::getInstance()->getPictureInfoList()->at(Contain::getInstance()->getPressentPictureId()).absoluteFilePath(), this);
	//��ʾΪ������Ծ����.
	int status = m_pictureMessageDialog->exec();
	m_pictureMessageDialog->raise();
	m_pictureMessageDialog->setFocus();
	m_pictureMessageDialog->activateWindow();
	//����û������ȷ��,�����¼���.
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
