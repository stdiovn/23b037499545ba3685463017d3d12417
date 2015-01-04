#include "stdafx.h"

#include "Mario.h"
#include "MarioOwnedState.h"


/////////////////////////////////////////////////////////////////////////////////
//STANDING
Standing* Standing::m_instance = 0;

Standing* Standing::getInstance()
{
	if(!m_instance)
		m_instance = new Standing();
	
	return m_instance;
}

void Standing::enter(Mario* mario)
{
	if(!mario->isBig())
		mario->setCurrentFrame(MarioSheet::MARIO_STAND);
	else if(!mario->canShoot())
		mario->setCurrentFrame(MarioSheet::BIG_MARIO_STAND);
	else
		mario->setCurrentFrame(MarioSheet::SUPER_MARIO_STAND);


	//////////////////////////////////////
	//Position_y depend on current frame and ground
	mario->setVeloc(0, 0);
	mario->setPosition(mario->getPosition().x, 
		mario->getGroundPosition() - mario->getFrameList()->at(mario->getCurrentFrame()).m_frameRect.height);
}

void Standing::execute(Mario* mario)
{
	if(GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT))
		mario->getStateMachine()->changeState(Running::getInstance());
	else if(GetAsyncKeyState(VK_LSHIFT))
		mario->getStateMachine()->changeState(Jumping::getInstance());
	else if(GetAsyncKeyState(VK_DOWN) && mario->isBig())
		mario->getStateMachine()->changeState(Sitting::getInstance());
}

void Standing::exit(Mario* mario)
{

}
/////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////
//RUNNING
Running* Running::m_instance = 0;

Running* Running::getInstance()
{
	if(!m_instance)
		m_instance = new Running();

	return m_instance;
}

void Running::enter(Mario* mario)
{
	if(!mario->isBig())
		mario->setCurrentFrame(MarioSheet::MARIO_RUN);
	else if(!mario->canShoot())
		mario->setCurrentFrame(MarioSheet::BIG_MARIO_RUN);
	else
		mario->setCurrentFrame(MarioSheet::SUPER_MARIO_RUN);
}

void Running::execute(Mario* mario)
{
	static int x = 0;
	x++;

	if(x > (GetAsyncKeyState(VK_LCONTROL) ? 2 : 4))
	{
		x = 0;

		//////////////////////////////////////////////////////////////////
		//Animation
		mario->setCurrentFrame(MarioSheet(mario->getCurrentFrame() + 1));

		if(!mario->isBig())
		{
			if(mario->getFrameList()->at(mario->getCurrentFrame()).m_id != "run")
				mario->setCurrentFrame(MarioSheet::MARIO_RUN);
		}
		else if(!mario->canShoot())
		{
			if(mario->getFrameList()->at(mario->getCurrentFrame()).m_id != "b_run")
				mario->setCurrentFrame(MarioSheet::BIG_MARIO_RUN);
		}
		else
		{
			if(mario->getFrameList()->at(mario->getCurrentFrame()).m_id != "s_run")
				mario->setCurrentFrame(MarioSheet::SUPER_MARIO_RUN);
		}
		//////////////////////////////////////////////////////////////////



		//////////////////////////////////////////////////////////////////
		//Set veloc, due to key press
		//If jump, change state to Jumping
		if(GetAsyncKeyState(VK_LEFT))
		{
			mario->setFlipping(FlippingFlag::FLIP_Y);

			if(mario->getVeloc().x > (GetAsyncKeyState(VK_LCONTROL) ? -6 : -3))
				mario->setVeloc(mario->getVeloc().x - mario->getAccel(), mario->getVeloc().y);
			if(!GetAsyncKeyState(VK_LCONTROL) && mario->getVeloc().x < -3)
				mario->setVeloc(-3, mario->getVeloc().y);

			if(GetAsyncKeyState(VK_LSHIFT))
				mario->getStateMachine()->changeState(Jumping::getInstance());
		}
		else if(GetAsyncKeyState(VK_RIGHT))
		{
			mario->setFlipping(FlippingFlag::FLIP_NONE);

			if(mario->getVeloc().x < (GetAsyncKeyState(VK_LCONTROL) ? 6 : 3))
				mario->setVeloc(mario->getVeloc().x + mario->getAccel(), mario->getVeloc().y);
			if(!GetAsyncKeyState(VK_LCONTROL) && mario->getVeloc().x > 3)
				mario->setVeloc(3, mario->getVeloc().y);

			if(GetAsyncKeyState(VK_LSHIFT))
				mario->getStateMachine()->changeState(Jumping::getInstance());
		}
		//////////////////////////////////////////////////////////////////
		//Change to Standing state
		else if(mario->getVeloc().x == 0)
			mario->getStateMachine()->changeState(Standing::getInstance());
	}

	if(GetAsyncKeyState(VK_DOWN))
		mario->getStateMachine()->changeState(Sitting::getInstance());
}

void Running::exit(Mario* mario)
{

}
/////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////
//SITTING
Sitting* Sitting::m_instance = 0;

Sitting* Sitting::getInstance()
{
	if(!m_instance)
		m_instance = new Sitting();

	return m_instance;
}

void Sitting::enter(Mario* mario)
{
	//Note: Normal Mario can't sit
	if(!mario->canShoot())
		mario->setCurrentFrame(MarioSheet::BIG_MARIO_SIT);
	else
		mario->setCurrentFrame(MarioSheet::SUPER_MARIO_SIT);

	mario->setPosition(mario->getPosition().x, 
		mario->getGroundPosition() - mario->getFrameList()->at(mario->getCurrentFrame()).m_frameRect.height);
}

void Sitting::execute(Mario* mario)
{
	if(!GetAsyncKeyState(VK_DOWN))
		mario->getStateMachine()->changeState(Standing::getInstance());
	else if(GetAsyncKeyState(VK_LSHIFT))
		mario->getStateMachine()->changeState(SitJumping::getInstance());
}

void Sitting::exit(Mario* mario)
{

}
/////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////
//JUMPING
Jumping* Jumping::m_instance = 0;

Jumping* Jumping::getInstance()
{
	if(!m_instance)
		m_instance = new Jumping();

	return m_instance;
}

void Jumping::enter(Mario* mario)
{
	if(!mario->isBig())
		mario->setCurrentFrame(MarioSheet::MARIO_JUMP);
	else if(!mario->canShoot())
		mario->setCurrentFrame(MarioSheet::BIG_MARIO_JUMP);
	else
		mario->setCurrentFrame(MarioSheet::SUPER_MARIO_JUMP);

	mario->setVeloc(mario->getVeloc().x, -17);
}

void Jumping::execute(Mario* mario)
{
	if(GetAsyncKeyState(VK_LSHIFT) && mario->getVeloc().y < 0)
		mario->setVeloc(mario->getVeloc().x, mario->getVeloc().y + GRAVITATION / 2);
	else
		mario->setVeloc(mario->getVeloc().x, mario->getVeloc().y + 2 * GRAVITATION);



	if(GetAsyncKeyState(VK_LEFT))
	{
		mario->setFlipping(FlippingFlag::FLIP_Y);

		if(mario->getVeloc().x >(GetAsyncKeyState(VK_LCONTROL) ? -6 : -3))
			mario->setVeloc(mario->getVeloc().x - mario->getAccel(), mario->getVeloc().y);
		if(!GetAsyncKeyState(VK_LCONTROL) && mario->getVeloc().x < -3)
			mario->setVeloc(-3, mario->getVeloc().y);
	}
	else if(GetAsyncKeyState(VK_RIGHT))
	{
		mario->setFlipping(FlippingFlag::FLIP_NONE);

		if(mario->getVeloc().x < (GetAsyncKeyState(VK_LCONTROL) ? 6 : 3))
			mario->setVeloc(mario->getVeloc().x + mario->getAccel(), mario->getVeloc().y);
		if(!GetAsyncKeyState(VK_LCONTROL) && mario->getVeloc().x > 3)
			mario->setVeloc(3, mario->getVeloc().y);
	}



	if(mario->getVeloc().y >= 0)
		mario->getStateMachine()->changeState(Falling::getInstance());
}

void Jumping::exit(Mario* mario)
{
	mario->setVeloc(mario->getVeloc().x, 0);
}
/////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////
//FALLING
Falling* Falling::m_instance = 0;

Falling* Falling::getInstance()
{
	if(!m_instance)
		m_instance = new Falling();

	return m_instance;
}

void Falling::enter(Mario* mario)
{
	
}

void Falling::execute(Mario* mario)
{
	if(GetAsyncKeyState(VK_LEFT))
	{
		mario->setFlipping(FlippingFlag::FLIP_Y);

		if(mario->getVeloc().x > (GetAsyncKeyState(VK_LCONTROL) ? -6 : -3))
			mario->setVeloc(mario->getVeloc().x - mario->getAccel(), mario->getVeloc().y);
		if(!GetAsyncKeyState(VK_LCONTROL) && mario->getVeloc().x < -3)
			mario->setVeloc(-3, mario->getVeloc().y);
	}
	else if(GetAsyncKeyState(VK_RIGHT))
	{
		mario->setFlipping(FlippingFlag::FLIP_NONE);

		if(mario->getVeloc().x < (GetAsyncKeyState(VK_LCONTROL) ? 6 : 3))
			mario->setVeloc(mario->getVeloc().x + mario->getAccel(), mario->getVeloc().y);
		if(!GetAsyncKeyState(VK_LCONTROL) && mario->getVeloc().x > 3)
			mario->setVeloc(3, mario->getVeloc().y);
	}


	if(mario->getPosition().y >= mario->getGroundPosition() - mario->getFrameList()->at(mario->getCurrentFrame()).m_frameRect.height)
		mario->getStateMachine()->changeState(Standing::getInstance());
}

void Falling::exit(Mario* mario)
{
	mario->setVeloc(mario->getVeloc().x, 0);
	mario->setPosition(mario->getPosition().x, 
		mario->getGroundPosition() - mario->getFrameList()->at(mario->getCurrentFrame()).m_frameRect.height);
}
/////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////
//SITJUMPING
SitJumping* SitJumping::m_instance = 0;

SitJumping* SitJumping::getInstance()
{
	if(!m_instance)
		m_instance = new SitJumping();

	return m_instance;
}

void SitJumping::enter(Mario* mario)
{
	mario->setVeloc(mario->getVeloc().x, -18);
}

void SitJumping::execute(Mario* mario)
{
	if(GetAsyncKeyState(VK_LSHIFT) && mario->getVeloc().y < 0)
		mario->setVeloc(mario->getVeloc().x, mario->getVeloc().y + GRAVITATION / 2);
	else
		mario->setVeloc(mario->getVeloc().x, mario->getVeloc().y + 2 * GRAVITATION);

	if(!GetAsyncKeyState(VK_DOWN))
	{
		if(!mario->canShoot())
			mario->setCurrentFrame(MarioSheet::BIG_MARIO_JUMP);
		else
			mario->setCurrentFrame(MarioSheet::SUPER_MARIO_JUMP);
	}

	if(mario->getVeloc().y >= 0)
		mario->getStateMachine()->changeState(Falling::getInstance());
}

void SitJumping::exit(Mario* mario)
{
	mario->setVeloc(mario->getVeloc().x, 0);
}
/////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////
////RUNJUMPING
//RunJumping* RunJumping::m_instance = 0;
//
//RunJumping* RunJumping::getInstance()
//{
//	if(!m_instance)
//		m_instance = new RunJumping();
//
//	return m_instance;
//}
//
//void RunJumping::enter(Mario* mario)
//{
//	if(!mario->isBig())
//		mario->setCurrentFrame(MarioSheet::MARIO_JUMP);
//	else if(!mario->canShoot())
//		mario->setCurrentFrame(MarioSheet::BIG_MARIO_JUMP);
//	else
//		mario->setCurrentFrame(MarioSheet::SUPER_MARIO_JUMP);
//
//	mario->setVeloc(mario->getVeloc().x, -18);
//}
//
//void RunJumping::execute(Mario* mario)
//{
//	if(GetAsyncKeyState(VK_LSHIFT) && mario->getVeloc().y < 0)
//		mario->setVeloc(mario->getVeloc().x, mario->getVeloc().y + GRAVITATION / 2);
//	else
//		mario->setVeloc(mario->getVeloc().x, mario->getVeloc().y + 2 * GRAVITATION);
//
//	if(mario->getVeloc().y >= 0)
//		mario->getStateMachine()->changeState(Falling::getInstance());
//
//
//
//	if(GetAsyncKeyState(VK_LEFT))
//	{
//		mario->setFlipping(FlippingFlag::FLIP_Y);
//
//		if(mario->getVeloc().x > (GetAsyncKeyState(VK_LCONTROL) ? -4 : -2))
//			mario->setVeloc(mario->getVeloc().x - mario->getAccel(), mario->getVeloc().y);
//		if(!GetAsyncKeyState(VK_LCONTROL) && mario->getVeloc().x < -2)
//			mario->setVeloc(-2, mario->getVeloc().y);
//	}
//	else if(GetAsyncKeyState(VK_RIGHT))
//	{
//		mario->setFlipping(FlippingFlag::FLIP_NONE);
//
//		if(mario->getVeloc().x < (GetAsyncKeyState(VK_LCONTROL) ? 4 : 2))
//			mario->setVeloc(mario->getVeloc().x + mario->getAccel(), mario->getVeloc().y);
//		if(!GetAsyncKeyState(VK_LCONTROL) && mario->getVeloc().x > 2)
//			mario->setVeloc(2, mario->getVeloc().y);
//	}
//	else
//	{
//		if(mario->getVeloc().x > 0)
//			mario->setVeloc(mario->getVeloc().x - mario->getAccel(), mario->getVeloc().y);
//		else if(mario->getVeloc().x < 0)
//			mario->setVeloc(mario->getVeloc().x + mario->getAccel(), mario->getVeloc().y);
//	}
//
//}
//
//void RunJumping::exit(Mario* mario)
//{
//
//}
///////////////////////////////////////////////////////////////////////////////////