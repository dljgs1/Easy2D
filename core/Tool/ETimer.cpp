#include "..\etools.h"
#include "..\enodes.h"
#include "..\emanagers.h"
#include "..\Win\winbase.h"

e2d::ETimer::ETimer()
	: m_bRunning(false)
	, m_nRunTimes(0)
	, m_pParentNode(nullptr)
	, m_Callback(nullptr)
	, m_nInterval()
	, m_nRepeatTimes(-1)
	, m_bAtOnce(false)
{
}

e2d::ETimer::ETimer(const TIMER_CALLBACK & callback, int repeatTimes /* = -1 */, LONGLONG interval /* = 0 */, bool atOnce /* = false */)
	: m_bRunning(false)
	, m_nRunTimes(0)
	, m_pParentNode(nullptr)
	, m_Callback(nullptr)
	, m_nInterval()
	, m_nRepeatTimes(-1)
	, m_bAtOnce(false)
{
	this->setCallback(callback);
	this->setRepeatTimes(repeatTimes);
	this->setInterval(interval);
	m_bAtOnce = atOnce;
}

e2d::ETimer::ETimer(const EString & name, const TIMER_CALLBACK & callback, int repeatTimes /* = -1 */, LONGLONG interval /* = 0 */, bool atOnce /* = false */)
	: m_bRunning(false)
	, m_nRunTimes(0)
	, m_pParentNode(nullptr)
	, m_Callback(nullptr)
	, m_nInterval()
	, m_nRepeatTimes(-1)
	, m_bAtOnce(false)
{
	this->setName(name);
	this->setCallback(callback);
	this->setRepeatTimes(repeatTimes);
	this->setInterval(interval);
	m_bAtOnce = atOnce;
}

bool e2d::ETimer::isRunning() const
{
	return m_bRunning;
}

void e2d::ETimer::start()
{
	m_bRunning = true;
	m_tLast = GetNow();
}

void e2d::ETimer::stop()
{
	m_bRunning = false;
}

e2d::EString e2d::ETimer::getName() const
{
	return m_sName;
}

e2d::ENode * e2d::ETimer::getParentNode() const
{
	return m_pParentNode;
}

void e2d::ETimer::setName(const EString & name)
{
	m_sName = name;
}

void e2d::ETimer::setInterval(LONGLONG interval)
{
	SetInterval(m_nInterval, max(interval, 0));
}

void e2d::ETimer::setCallback(const TIMER_CALLBACK & callback)
{
	m_Callback = callback;
}

void e2d::ETimer::setRepeatTimes(int repeatTimes)
{
	m_nRepeatTimes = repeatTimes;
}

void e2d::ETimer::setRunAtOnce(bool bAtOnce)
{
	m_bAtOnce = bAtOnce;
}

void e2d::ETimer::bindWith(EScene * pParentScene)
{
	ETimerManager::bindTimer(this, pParentScene);
}

void e2d::ETimer::bindWith(ENode * pParentNode)
{
	ETimerManager::bindTimer(this, pParentNode);
}

void e2d::ETimer::_callOn()
{
	if (m_nRunTimes == m_nRepeatTimes)
	{
		this->stop();
		return;
	}

	if (m_Callback)
	{
		m_Callback(m_nRunTimes);
	}
	m_nRunTimes++;
}

bool e2d::ETimer::_isReady()
{
	if (m_bRunning && 
		m_pParentNode &&
		m_pParentNode->getParentScene() == EApp::getCurrentScene())
	{
		if (m_bAtOnce && m_nRunTimes == 0)
			return true;

		if (m_nInterval.QuadPart == 0)
			return true;

		if (IsIntervalFull(m_tLast, m_nInterval))
		{
			m_tLast.QuadPart += m_nInterval.QuadPart;
			return true;
		}
	}
	return false;
}
