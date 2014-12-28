#pragma once

#include "STDIO_FW\Core\Application.h"
#include "STDIO_FW\Video\Graphics.h"
#include "STDIO_FW\Video\Image.h"

#include <iostream>
#include <string>
#include "Component.h"

using namespace stdio_fw;
enum IDEntity
{
	Tart = 1,
	Turtle
};
class Entity
{
private:
	IDEntity m_ID;
	bool m_hasRenderer;
	bool m_hasMovement;
	bool m_hasAnimation;
	RenderComp m_RC;
	MoveComp m_MC;
	AnimationComp m_AC;
public:
	Entity();
	~Entity();

	void Init();
	void Release();

	IDEntity GetID();
	void SetID(int ID);

	void AddRender(char* Img, int X, int Y);
	void AddMove(int K, int Angle, int Type, int CenterX, int CenterY);
	void AddAnimation(std::vector <Image*> ImageList);

	RenderComp& GetRenderComp();
	MoveComp& GetMoveComp();
	AnimationComp& GetAnimationComp();

	bool	hasAnimationComponent();
	bool	hasRendererComponent();
	bool	hasMovementComponent();	
	
	void SetImage(Image* I);

	std::vector <Image*>& GetImageList();
};

