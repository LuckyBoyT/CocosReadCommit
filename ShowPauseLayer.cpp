#include "ShowPauseLayer.h"

bool ShowPauseLayer::init()
{
	//加入暂停的灰色层.
	this->addPauseLayer();

	return true;
}
ShowPauseLayer* ShowPauseLayer::createWithRenderTexture(RenderTexture* texture)
{
	//创建了一个对象.加入内存释放池中.
	auto layer = new ShowPauseLayer(texture);
	if (layer && layer->init())
	{
		layer->autorelease();
		return layer;
	}
	else
	{
		delete layer;
		layer = NULL;
		return NULL;
	}
}
void ShowPauseLayer::addPauseLayer()
{
	//截图的暂停画面.
	m_bgSprite = Sprite::createWithTexture(m_bgRender->getSprite()->getTexture());
	//修改颜色为灰色.
	m_bgSprite->setColor(Color3B::GRAY);

	//需要根据x轴翻转下.
	m_bgSprite->setFlipY(true);

	//加入当前层中去.
	this->addChild(m_bgSprite);
}
ShowPauseLayer::ShowPauseLayer()
{

}
ShowPauseLayer::ShowPauseLayer(RenderTexture* render)
{
	m_bgRender = render;
}
ShowPauseLayer::~ShowPauseLayer()
{

}
