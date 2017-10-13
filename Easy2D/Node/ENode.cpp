#include "..\enodes.h"
#include "..\Win\winbase.h"

e2d::ENode::ENode()
	: m_nZOrder(0)
	, m_bVisiable(true)
{
}

e2d::ENode::ENode(EPoint p) 
	: ENode()
{
	setPos(p);
}

e2d::ENode::ENode(int x, int y)
	: ENode()
{
	setPos(x, y);
}

e2d::ENode::~ENode()
{
}

bool e2d::ENode::_exec(bool active)
{
	return false;
}

void e2d::ENode::_onRender()
{
	D2D1_RECT_F rectangle = D2D1::RectF(
		m_Rect.left,
		m_Rect.top,
		m_Rect.right,
		m_Rect.bottom
	);
	ID2D1SolidColorBrush* m_pLightSlateGrayBrush;
	GetRenderTarget()->CreateSolidColorBrush(
		D2D1::ColorF(D2D1::ColorF::LightSlateGray),
		&m_pLightSlateGrayBrush
	);
	GetRenderTarget()->FillRectangle(&rectangle, m_pLightSlateGrayBrush);
}

int e2d::ENode::getX() const
{
	if (m_pParent)
	{
		return m_pParent->getX() + m_Rect.TopLeft().x;
	}
	return m_Rect.TopLeft().x;
}

int e2d::ENode::getY() const
{
	if (m_pParent)
	{
		return m_pParent->getY() + m_Rect.TopLeft().y;
	}
	return m_Rect.TopLeft().y;
}

CPoint e2d::ENode::getPos() const
{
	if (m_pParent)
	{
		return m_pParent->getPos() + m_Rect.TopLeft();
	}
	return m_Rect.TopLeft();
}

UINT32 e2d::ENode::getWidth() const
{
	return UINT32(m_Rect.Size().cx);
}

UINT32 e2d::ENode::getHeight() const
{
	return UINT32(m_Rect.Size().cy);
}

e2d::ESize e2d::ENode::getSize() const
{
	return e2d::ESize(m_Rect.Size());
}

e2d::ERect e2d::ENode::getRect() const
{
	return e2d::ERect(m_Rect);
}

void e2d::ENode::setX(int x)
{
	m_Rect.MoveToX(x);
}

void e2d::ENode::setY(int y)
{
	m_Rect.MoveToY(y);
}

void e2d::ENode::setPos(int x, int y)
{
	m_Rect.MoveToXY(x, y);
}

void e2d::ENode::setPos(EPoint p)
{
	m_Rect.MoveToXY(p.x, p.y);
}

void e2d::ENode::move(int x, int y)
{
	m_Rect.OffsetRect(x, y);
}

void e2d::ENode::move(EVector v)
{
	m_Rect.OffsetRect(v);
}

void e2d::ENode::setWidth(UINT32 width)
{
	m_Rect.BottomRight().x = m_Rect.TopLeft().x + width;
}

void e2d::ENode::setHeight(UINT32 height)
{
	m_Rect.BottomRight().y = m_Rect.TopLeft().y + height;
}

void e2d::ENode::setSize(UINT32 width, UINT32 height)
{
	setWidth(width);
	setHeight(height);
}

void e2d::ENode::setSize(ESize size)
{
	setSize(size.cx, size.cy);
}

void e2d::ENode::setRect(int x1, int y1, int x2, int y2)
{
	m_Rect.SetRect(x1, y1, x2, y2);
}

void e2d::ENode::setRect(EPoint leftTop, EPoint rightBottom)
{
	m_Rect.TopLeft() = leftTop;
	m_Rect.BottomRight() = rightBottom;
}

void e2d::ENode::setRect(ERect rect)
{
	m_Rect = rect;
}

int e2d::ENode::getZOrder() const
{
	return m_nZOrder;
}

void e2d::ENode::setZOrder(int z)
{
	m_nZOrder = z;
}

void e2d::ENode::setParent(ENode * parent)
{
	m_pParent = parent;
}

e2d::ENode *& e2d::ENode::getParent()
{
	return m_pParent;
}

e2d::EScene * &e2d::ENode::getParentScene()
{
	return m_pParentScene;
}

void e2d::ENode::setParentScene(EScene * scene)
{
	m_pParentScene = scene;
}

void e2d::ENode::setVisiable(bool value)
{
	m_bVisiable = value;
}

bool e2d::ENode::isVisiable() const
{
	return m_bVisiable;
}