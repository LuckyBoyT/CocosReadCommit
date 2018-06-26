#include "PopUpLayer.h"
#pragma execution_character_set("utf-8")

PopUpLayer::PopUpLayer()
{
}


PopUpLayer::~PopUpLayer()
{
}
bool PopUpLayer::init()
{
	auto node = CSLoader::createNode("Layer.csb");
	this->addChild(node, 99);
	this->setContentSize(node->getContentSize());

//获取背景图对象.
	m_root = (ImageView*)node->getChildByName("Image_1");
//获取关闭按钮对象.
	m_closeImage = (ImageView*)m_root->getChildByName("closeImage");

	//设置激活触摸事件.
	m_closeImage->setTouchEnabled(true);
  
  //添加回调函数.void PopUpLayer::closeCallBack(Ref*, cocos2d::ui::Widget::TouchEventType type);
	m_closeImage->addTouchEventListener(CC_CALLBACK_2(PopUpLayer::closeCallBack, this));

//设置缩小为0.
	this->setScale(0);
  
//设置缩放到原大小.这样就可以形成弹出窗口的效果了.注意:弹出效果是根据锚点出发,回到锚点的效果.且层默认锚点是忽略的.可以使用Node或者打开锚点.
	this->runAction(ScaleTo::create(5.0f, 1));

	return true;
}
void PopUpLayer::closeCallBack(Ref*, cocos2d::ui::Widget::TouchEventType type)
{
	switch (type)
	{
	case Widget::TouchEventType::ENDED:
  //关闭弹出窗口的时候,也形成一个慢慢关闭的感觉.
		this->runAction(Sequence::create(ScaleTo::create(0.5f,0),CallFunc::create(CC_CALLBACK_0(PopUpLayer::removeMySelf,this)),NULL ));
		break;
	}
}
void PopUpLayer::removeMySelf()
{
//把当前窗口从父窗口内删除并且清除.
	this->removeFromParentAndCleanup(true);
}

