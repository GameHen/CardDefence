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
	/*���ո�����������ƶ�*/
	void moveByPosList(Vector<PosBase*>posList);
	/*���ո������������ƶ��ٶ�*/
	void moveByPosList(Vector<PosBase*>posList, int iSpeed);
	/*���ո���������㡢�ٶȡ��ƶ����ʱ���ƶ�*/
	void moveByPosList(Vector<PosBase*>posList, int iSpeed,int iSpanTime);
	/*���ո��������ƶ�*/
	void moveByPos(PosBase* pos);
private:
	void moveOneStep();
	void nextMovePos();
private:
	Vector<PosBase*> m_movePosList;			//�ƶ�Ŀ���б�
	PosBase* m_curDestPos;								//��ǰ�ƶ�Ŀ�ĵ�
	float m_MoveSpan;										//�ƶ������ʱ��
	float m_fMoveTimeCount;							//��ʱ��
};

#endif//_ControllerSimpleMove_H_