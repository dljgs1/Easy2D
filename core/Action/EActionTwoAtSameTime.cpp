#include "..\eactions.h"

e2d::EActionTwoAtSameTime::EActionTwoAtSameTime(EAction * actionFirst, EAction * actionSecond) :
	m_pFirstAction(actionFirst),
	m_pSecondAction(actionSecond)
{
	ASSERT(m_pFirstAction && m_pSecondAction, "EActionTwoAtSameTime NULL pointer exception!");
	m_pFirstAction->retain();
	m_pSecondAction->retain();
}

e2d::EActionTwoAtSameTime::~EActionTwoAtSameTime()
{
	SafeRelease(&m_pFirstAction);
	SafeRelease(&m_pSecondAction);
}

e2d::EActionTwoAtSameTime * e2d::EActionTwoAtSameTime::clone() const
{
	return new EActionTwoAtSameTime(m_pFirstAction->clone(), m_pSecondAction->clone());
}

e2d::EActionTwoAtSameTime * e2d::EActionTwoAtSameTime::reverse(bool actionReverse) const
{
	if (actionReverse)
	{
		return new EActionTwoAtSameTime(m_pSecondAction->reverse(), m_pFirstAction->reverse());
	}
	else
	{
		return new EActionTwoAtSameTime(m_pSecondAction->clone(), m_pFirstAction->clone());
	}
}

void e2d::EActionTwoAtSameTime::_init()
{
	EAction::_init();
	m_pFirstAction->setTarget(m_pTarget);
	m_pSecondAction->setTarget(m_pTarget);

	m_pFirstAction->_init();
	m_pSecondAction->_init();
}

void e2d::EActionTwoAtSameTime::_update()
{
	EAction::_update();

	if (!m_pFirstAction->_isEnding())
	{
		m_pFirstAction->_update();
	}
	if (!m_pSecondAction->_isEnding())
	{
		m_pSecondAction->_update();
	}

	// 两个动作都结束时，动作结束
	if (m_pFirstAction->_isEnding() &&
		m_pSecondAction->_isEnding())
	{
		this->stop();
	}
}

void e2d::EActionTwoAtSameTime::_reset()
{
	EAction::_reset();

	m_pFirstAction->_reset();
	m_pSecondAction->_reset();
}

void e2d::EActionTwoAtSameTime::_resetTime()
{
	m_pFirstAction->_resetTime();
	m_pSecondAction->_resetTime();
}
