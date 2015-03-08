#ifndef _ControllerSimpleMove_H_
#define _ControllerSimpleMove_H_
#include "ControllerMoveBase.h"
#include "PosBase.h"
class ControllerSimpleMove : public ControllerMoveBase
{
public:
	ControllerSimpleMove();
	~ControllerSimpleMove();

	static ControllerSimpleMove* create(Entity* entity);
	bool init(Entity* entity);

	void checkMoveUpdate(float delta);
	/*按照给定的坐标点移动*/
	void moveByPosList(Vector<PosBase*>posList);
	/*按照给定的坐标点和移动速度*/
	void moveByPosList(Vector<PosBase*>posList, int iSpeed);
	/*按照给定的坐标点、速度、移动间隔时间移动*/
	void moveByPosList(Vector<PosBase*>posList, int iSpeed,int iSpanTime);
	/*按照给定坐标移动*/
	void moveByPos(PosBase* pos);
private:
	void moveOneStep();
	void nextMovePos();
private:
	Vector<PosBase*> m_movePosList;			//移动目的列表
	PosBase* m_curDestPos;								//当前移动目的地
	float m_MoveSpan;										//移动间隔的时间
	float m_fMoveTimeCount;							//计时器
};

#endif//_ControllerSimpleMove_H_