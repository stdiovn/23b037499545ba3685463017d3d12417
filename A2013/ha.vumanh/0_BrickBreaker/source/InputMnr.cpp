#include "stdafx.h"
#include "InputMnr.h"
#include <stdio.h>

InputMnr* InputMnr::m_IMr = NULL;

InputMnr* InputMnr::createIMr()
{
	if (m_IMr == NULL)
		m_IMr = new InputMnr();
	return m_IMr;
}

void InputMnr::freeIMr()
{
	delete m_IMr;
}