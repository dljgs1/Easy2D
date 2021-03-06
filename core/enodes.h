#pragma once
#include "ebase.h"

namespace e2d 
{

class EText;
class ESprite;
class EAction;
class EButton;
class EButtonToggle;
class EGeometry;
class EMenu;
class ETransition;

class ENode :
	public EObject
{
	friend EScene;
	friend EButton;
	friend EButtonToggle;
	friend EGeometry;
	friend ETransition;

public:
	ENode();

	ENode(
		const EString & name
	);

	virtual ~ENode();

	// 重写这个函数，它将在节点进入场景时自动执行
	virtual void onEnter();

	// 重写这个函数，它将在节点离开场景时自动执行
	virtual void onExit();

	// 获取节点显示状态
	virtual bool isVisiable() const;

	// 获取节点名称
	virtual EString getName() const;

	// 获取节点绘图顺序
	virtual int getOrder() const;

	// 获取节点横坐标
	virtual float getPosX() const;

	// 获取节点纵坐标
	virtual float getPosY() const;

	// 获取节点坐标
	virtual EPoint getPos() const;

	// 获取节点宽度
	virtual float getWidth() const;

	// 获取节点高度
	virtual float getHeight() const;

	// 获取节点宽度（不考虑缩放）
	virtual float getRealWidth() const;

	// 获取节点高度（不考虑缩放）
	virtual float getRealHeight() const;

	// 获取节点大小（不考虑缩放）
	virtual ESize getRealSize() const;

	// 获取节点的中心点
	virtual float getPivotX() const;

	// 获取节点的中心点
	virtual float getPivotY() const;

	// 获取节点大小
	virtual ESize getSize() const;

	// 获取节点横向缩放比例
	virtual float getScaleX() const;

	// 获取节点纵向缩放比例
	virtual float getScaleY() const;

	// 获取节点横向倾斜角度
	virtual float getSkewX() const;

	// 获取节点纵向倾斜角度
	virtual float getSkewY() const;

	// 获取节点旋转角度
	virtual float getRotation() const;

	// 获取节点透明度
	virtual float getOpacity() const;

	// 获取父节点
	virtual ENode * getParent() const;

	// 获取节点所在场景
	virtual EScene * getParentScene() const;

	// 获取所有子节点
	virtual std::vector<ENode*> &getChildren();

	// 获取子节点数量
	virtual size_t getChildrenCount() const;

	// 根据名字获取子节点
	virtual ENode * getChild(
		const EString & name
	);

	// 设置节点是否显示
	virtual void setVisiable(
		bool value
	);

	// 设置节点名称
	virtual void setName(
		const EString & name
	);

	// 设置节点横坐标
	virtual void setPosX(
		float x
	);

	// 设置节点纵坐标
	virtual void setPosY(
		float y
	);

	// 设置节点坐标
	virtual void setPos(
		const EPoint & point
	);

	// 设置节点坐标
	virtual void setPos(
		float x,
		float y
	);

	// 移动节点
	virtual void movePosX(
		float x
	);

	// 移动节点
	virtual void movePosY(
		float y
	);

	// 移动节点
	virtual void movePos(
		float x,
		float y
	);

	// 移动节点
	virtual void movePos(
		const EVec & v
	);

	// 设置节点绘图顺序
	// 默认为 0
	virtual void setOrder(
		int order
	);

	// 设置横向缩放比例
	// 默认为 1.0f
	virtual void setScaleX(
		float scaleX
	);

	// 设置纵向缩放比例
	// 默认为 1.0f
	virtual void setScaleY(
		float scaleY
	);

	// 设置缩放比例
	// 默认为 (1.0f, 1.0f)
	virtual void setScale(
		float scaleX,
		float scaleY
	);

	// 设置缩放比例
	// 默认为 1.0f
	virtual void setScale(
		float scale
	);

	// 设置横向倾斜角度
	// 默认为 0
	virtual void setSkewX(
		float angleX
	);

	// 设置纵向倾斜角度
	// 默认为 0
	virtual void setSkewY(
		float angleY
	);

	// 设置倾斜角度
	// 默认为 (0, 0)
	virtual void setSkew(
		float angleX,
		float angleY
	);

	// 设置旋转角度
	// 默认为 0
	virtual void setRotation(
		float rotation
	);

	// 设置透明度
	// 默认为 1.0f, 范围 [0, 1]
	virtual void setOpacity(
		float opacity
	);

	// 设置中心点的横向位置
	// 默认为 0, 范围 [0, 1]
	virtual void setPivotX(
		float pivotX
	);

	// 设置中心点的纵向位置
	// 默认为 0, 范围 [0, 1]
	virtual void setPivotY(
		float pivotY
	);

	// 设置中心点位置
	// 默认为 (0, 0), 范围 [0, 1]
	virtual void setPivot(
		float pivotX,
		float pivotY
	);

	// 设置节点形状
	virtual void setGeometry(
		EGeometry * geometry
	);

	// 添加子节点
	virtual void addChild(
		ENode * child,
		int order = 0
	);

	// 从父节点移除
	virtual void removeFromParent();

	// 移除子节点
	virtual bool removeChild(
		ENode * child
	);

	// 移除子节点
	virtual void removeChild(
		const EString & childName
	);

	// 移除所有节点
	virtual void clearAllChildren();

	// 执行动画
	virtual void runAction(
		EAction * action
	);

	// 继续动画
	virtual void resumeAction(
		EAction * action
	);

	// 暂停动画
	virtual void pauseAction(
		EAction * action
	);

	// 停止动画
	virtual void stopAction(
		EAction * action
	);

	// 继续所有暂停动画
	virtual void startAllActions();

	// 暂停所有动画
	virtual void pauseAllActions();

	// 停止所有动画
	virtual void stopAllActions();

	// 判断点是否在节点内
	virtual bool isPointIn(
		EPoint point
	);

	// 修改节点的默认中心点位置
	static void setDefaultPiovt(
		float defaultPiovtX,
		float defaultPiovtY
	);

protected:
	// 更新节点
	virtual void _update();

	// 渲染节点
	virtual void _render();

	// 渲染几何图形
	virtual void _drawGeometry();

	// 节点被添加到场景时的执行程序
	virtual void _onEnter();

	// 节点从场景中消失时的执行程序
	virtual void _onExit();

	// 子节点排序
	void _sortChildren();

	// 设置节点所在场景
	virtual void _setParentScene(
		EScene * scene
	);

	// 对自身进行二维矩阵变换
	virtual void _updateTransform();

	// 更新所有子节点矩阵
	virtual void _updateChildrenTransform();

	// 更新所有子节点透明度
	virtual void _updateChildrenOpacity();

	// 更新节点矩阵
	static void _updateTransform(ENode * node);

	// 更新节点透明度
	static void _updateOpacity(ENode * node);

	// 设置节点宽度
	virtual void _setWidth(
		float width
	);

	// 设置节点高度
	virtual void _setHeight(
		float height
	);

	// 设置节点大小
	virtual void _setSize(
		const ESize & size
	);

	// 设置节点大小
	virtual void _setSize(
		float width,
		float height
	);

protected:
	EString		m_sName;
	size_t		m_nHashName;
	EPoint		m_Pos;
	ESize		m_Size;
	float		m_fScaleX;
	float		m_fScaleY;
	float		m_fRotation;
	float		m_fSkewAngleX;
	float		m_fSkewAngleY;
	float		m_fDisplayOpacity;
	float		m_fRealOpacity;
	float		m_fPivotX;
	float		m_fPivotY;
	int			m_nOrder;
	bool		m_bVisiable;
	bool		m_bDisplayedInScene;
	bool		m_bSortChildrenNeeded;
	bool		m_bTransformNeeded;
	EGeometry * m_pGeometry;
	EScene *	m_pParentScene;
	ENode *		m_pParent;
	D2D1::Matrix3x2F	m_MatriInitial;
	D2D1::Matrix3x2F	m_MatriFinal;
	std::vector<ENode*>		m_vChildren;
};


class ESprite :
	public ENode
{
public:
	// 创建一个空精灵
	ESprite();

	// 从文理资源创建精灵
	ESprite(
		ETexture * texture
	);

	// 从精灵帧创建精灵
	ESprite(
		ESpriteFrame * spriteFrame
	);

	// 从文件图片创建精灵
	ESprite(
		const EString & imageFileName
	);

	// 从文件图片创建精灵并裁剪
	ESprite(
		const EString & imageFileName,
		float x,
		float y,
		float width,
		float height
	);

	// 从资源图片创建精灵
	ESprite(
		LPCTSTR resourceName,
		LPCTSTR resourceType
	);

	// 从资源图片创建精灵并裁剪
	ESprite(
		LPCTSTR resourceName,
		LPCTSTR resourceType,
		float x,
		float y,
		float width,
		float height
	);

	virtual ~ESprite();
	
	// 加载精灵纹理
	void loadFrom(
		ETexture * texture
	);

	// 从本地文件加载纹理
	void loadFrom(
		const EString & imageFileName
	);

	// 从资源加载纹理
	void loadFrom(
		LPCTSTR resourceName,
		LPCTSTR resourceType
	);

	// 加载纹理并裁剪
	void loadFrom(
		ETexture * texture,
		float x,
		float y,
		float width,
		float height
	);

	// 从精灵帧加载资源
	void loadFrom(
		ESpriteFrame * frame
	);

	// 裁剪纹理
	void clip(
		float x,
		float y,
		float width,
		float height
	);

protected:
	// 渲染精灵
	virtual void _render() override;

protected:
	float	m_fSourceClipX;
	float	m_fSourceClipY;
	ETexture * m_pTexture;
};


class EText :
	public ENode
{
public:
	EText();

	EText(
		const EString & text
	);

	EText(
		EFont * font
	);

	EText(
		const EString & text,
		EFont * font
	);

	EText(
		const EString & text,
		EString fontFamily,
		float fontSize = 22,
		UINT32 color = EColor::WHITE,
		UINT32 fontWeight = EFontWeight::REGULAR,
		bool italic = false
	);

	virtual ~EText();

	// 获取文本
	EString getText() const;

	// 获取文本宽度
	virtual float getWidth() const override;

	// 获取文本宽度（不考虑缩放）
	virtual float getRealWidth() const override;

	// 获取字体
	EFont * getFont() const;

	// 设置文本
	void setText(
		const EString & text
	);

	// 设置字体
	void setFont(
		EFont * font
	);

	// 设置文字自动换行
	void setWordWrapping(
		bool value
	);

	// 设置文字换行宽度（WordWrapping 打开时生效）
	void setWordWrappingWidth(
		float wordWrapWidth
	);

protected:
	// 渲染文字
	virtual void _render() override;

	// 创建文字布局
	void _initTextLayout();

protected:
	EString	m_sText;
	bool	m_bWordWrapping;
	float	m_fWordWrappingWidth;
	EFont * m_pFont;
};


class EButton :
	public ENode
{
	friend EMenu;

public:
	// 创建一个空按钮
	EButton();

	// 创建按钮
	EButton(
		ENode * normal,		/* 普通状态 */
		const BUTTON_CLICK_CALLBACK & callback = nullptr
	);

	// 创建按钮
	EButton(
		ENode * normal,		/* 普通状态 */
		ENode * selected,	/* 鼠标按下状态 */
		const BUTTON_CLICK_CALLBACK & callback = nullptr
	);

	// 创建按钮
	EButton(
		ENode * normal,		/* 普通状态 */
		ENode * mouseover,	/* 鼠标移入状态 */
		ENode * selected,	/* 鼠标按下状态 */
		const BUTTON_CLICK_CALLBACK & callback = nullptr
	);

	// 创建按钮
	EButton(
		ENode * normal,		/* 普通状态 */
		ENode * mouseover,	/* 鼠标移入状态 */
		ENode * selected,	/* 鼠标移入状态 */
		ENode * disabled,	/* 按钮禁用状态 */
		const BUTTON_CLICK_CALLBACK & callback = nullptr
	);

	// 获取按钮状态是启用还是禁用
	bool isEnable() const;

	// 设置按钮启用或禁用
	void setEnable(
		bool bEnable
	);

	// 设置一般情况下显示的按钮
	virtual void setNormal(
		ENode * normal
	);

	// 设置鼠标移入按钮时显示的按钮
	virtual void setMouseOver(
		ENode * mouseover
	);

	// 设置鼠标选中按钮时显示的按钮
	virtual void setSelected(
		ENode * selected
	);

	// 设置按钮被禁用时显示的按钮
	virtual void setDisabled(
		ENode * disabled
	);

	// 设置回调函数
	void setCallback(
		const BUTTON_CLICK_CALLBACK & callback
	);

	// 设置中心点的横向位置
	// 默认为 0, 范围 [0, 1]
	virtual void setPivotX(
		float pivotX
	) override;

	// 设置中心点的纵向位置
	// 默认为 0, 范围 [0, 1]
	virtual void setPivotY(
		float pivotY
	) override;

	// 设置中心点位置
	// 默认为 (0, 0), 范围 [0, 1]
	virtual void setPivot(
		float pivotX,
		float pivotY
	) override;

protected:
	enum STATUS { NORMAL, MOUSEOVER, SELECTED };

	// 初始化按钮
	virtual void _init();

	// 设置按钮状态
	virtual void _setStatus(STATUS status);

	// 对自身进行二维矩阵变换
	virtual void _updateTransform() override;

	// 刷新按钮显示
	virtual void _updateVisiable();

	// 刷新按钮状态
	virtual void _updateStatus();

	// 执行按钮回调函数
	virtual void _runCallback();

protected:
	STATUS	m_eStatus;
	ENode * m_pNormal;
	ENode * m_pMouseover;
	ENode * m_pSelected;
	ENode * m_pDisabled;
	bool	m_bEnable;
	bool	m_bIsSelected;
	EListenerMouse * m_pListener;
	BUTTON_CLICK_CALLBACK m_Callback;
};


class EButtonToggle :
	public EButton
{
public:
	// 创建一个空的开关按钮
	EButtonToggle();

	// 创建开关按钮
	EButtonToggle(
		ENode * toggleOnNormal,
		ENode * toggleOffNormal,
		const BUTTON_CLICK_CALLBACK & callback = nullptr
	);

	// 创建开关按钮
	EButtonToggle(
		ENode * toggleOnNormal,
		ENode * toggleOffNormal,
		ENode * toggleOnSelected,
		ENode * toggleOffSelected,
		const BUTTON_CLICK_CALLBACK & callback = nullptr
	);

	// 创建开关按钮
	EButtonToggle(
		ENode * toggleOnNormal,
		ENode * toggleOffNormal,
		ENode * toggleOnMouseOver,
		ENode * toggleOffMouseOver,
		ENode * toggleOnSelected,
		ENode * toggleOffSelected,
		const BUTTON_CLICK_CALLBACK & callback = nullptr
	);

	// 创建开关按钮
	EButtonToggle(
		ENode * toggleOnNormal,
		ENode * toggleOffNormal,
		ENode * toggleOnMouseOver,
		ENode * toggleOffMouseOver,
		ENode * toggleOnSelected,
		ENode * toggleOffSelected,
		ENode * toggleOnDisabled,
		ENode * toggleOffDisabled,
		const BUTTON_CLICK_CALLBACK & callback = nullptr
	);

	// 切换开关状态，并执行回调函数
	void toggle();

	// 获取开关状态
	bool isToggleOn() const;

	// 打开或关闭开关
	// 仅设置按钮状态，不执行回调函数
	void setToggle(
		bool toggle
	);

	// 设置按钮打开状态下显示的按钮
	virtual void setNormal(
		ENode * normal
	) override;

	// 设置按钮打开状态下，鼠标移入按钮时显示的按钮
	virtual void setMouseOver(
		ENode * mouseover
	) override;

	// 设置按钮打开状态下，鼠标选中按钮时显示的按钮
	virtual void setSelected(
		ENode * selected
	) override;

	// 设置按钮打开状态下，被禁用时显示的按钮
	virtual void setDisabled(
		ENode * disabled
	) override;

	// 设置按钮关闭状态下显示的按钮
	void setNormalOff(
		ENode * normal
	);

	// 设置按钮关闭状态下，鼠标移入按钮时显示的按钮
	void setMouseOverOff(
		ENode * mouseover
	);

	// 设置按钮关闭状态下，鼠标选中按钮时显示的按钮
	void setSelectedOff(
		ENode * selected
	);

	// 设置按钮关闭状态下，按钮被禁用时显示的按钮
	void setDisabledOff(
		ENode * disabled
	);

protected:
	// 刷新按钮开关
	virtual void _updateToggle();

	// 执行按钮回调函数
	virtual void _runCallback() override;

protected:
	ENode * m_pNormalOn;
	ENode * m_pNormalOff;
	ENode * m_pMouseoverOn;
	ENode * m_pMouseoverOff;
	ENode * m_pSelectedOn;
	ENode * m_pSelectedOff;
	ENode * m_pDisabledOn;
	ENode * m_pDisabledOff;
	bool	m_bToggle;
};


class EMenu :
	public ENode
{
public:
	// 创建空菜单
	EMenu();

	// 创建菜单
	EMenu(
		int number,			/* 菜单中按钮的数量 */
		EButton * button1,	/* 第一个按钮 */
		...
	);

	// 获取菜单是否禁用
	bool isEnable() const;

	// 获取菜单中的按钮数量
	size_t getButtonCount() const;

	// 设置菜单启用或禁用
	void setEnable(
		bool enable
	);

	// 添加按钮
	void addButton(
		EButton * button
	);

	// 移除按钮
	bool removeButton(
		EButton * button
	);

protected:
	bool m_bEnable;
	std::vector<EButton*> m_vButtons;
};

}