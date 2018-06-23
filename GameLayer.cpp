#include "GameLayer.h"
#pragma execution_character_set("utf-8")

GameLayer::GameLayer()
{
}

GameLayer::~GameLayer()
{
}

bool GameLayer::init()
{
	log("GameLayer init");
	Size size = Director::getInstance()->getWinSize();

  //放置一个菜单项
	auto menuItem = MenuItemFont::create("sdd", CC_CALLBACK_1(MouseTest::callback1, this));
	menuItem->setPosition(Vec2(300, 300));
  //把菜单项加到菜单中去.
	auto menu = Menu::create(menuItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

  //放置一张背景图.
	auto bg = Sprite::create("1.png");
	bg->setPosition(Vec2(480, 320));
	this->addChild(bg, 0);

	return true;
}

bool isPause = false;
void GameLayer::callback1(Ref*)
{
	if (isPause == false)
	{
		RenderTexture *render = RenderTexture::create(960, 640);
    //开始绘制.
		render->begin();
		this->visit();
    //结束绘制.
		render->end();

    //创建暂停层对象.
		auto layer = ShowPauseLayer::createWithRenderTexture(render);
		layer->setPosition(Vec2(480, 320));
		this->addChild(layer, 20,88);
		isPause = !isPause;
	}
	else if (isPause == true)
	{
		auto layer = this->getChildByTag(88);
		layer->removeFromParent();
    isPause = !isPause;
	}

}
