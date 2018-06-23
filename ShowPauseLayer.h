#pragma once

#include <iostream>
using namespace std;
#include "cocos2d.h"
USING_NS_CC;

class ShowPauseLayer : public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(ShowPauseLayer);
	static ShowPauseLayer* createWithRenderTexture(RenderTexture*);

	ShowPauseLayer();
	ShowPauseLayer(RenderTexture*);
	~ShowPauseLayer();

protected:
	void addPauseLayer();

	RenderTexture* m_bgRender;
	Sprite* m_bgSprite;
};
