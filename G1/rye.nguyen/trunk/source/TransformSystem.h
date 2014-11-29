#pragma once

class TransformSystem
{
private:
	static TransformSystem*	m_instance;
public:
	TransformSystem();
	virtual					~TransformSystem();

	static TransformSystem*	GetInstance();

	virtual void			Init();
	virtual void			Release();

	virtual void			Transformation();
};