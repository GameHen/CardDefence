#ifndef _ControllerMoveBase_H_
#define _ControllerMoveBase_H_
#include "ControllerBase.h"
#include "Entity.h"
/*����ƶ��ļ��ʱ�䣬ʱ��Խ�̣��ƶ�Խ�죬ҲԽƽ����ʱ��̫�����ƶ��Ῠ��*/
#define CHECK_MOVE_SPEED_LVL1 0.1f
#define CHECK_MOVE_SPEED_LVL2 0.04f
#define CHECK_MOVE_SPEED_LVL3 0.03f

#define SPEED 1
class ControllerMoveBase :public ControllerBase
{
public:
	ControllerMoveBase();
	~ControllerMoveBase();

	CC_SYNTHESIZE(int, m_iSpeed, iSpeed);//�ƶ��ٶ�
	void bindMoveEndFunc(std::function<void()>moveEndFunc);
protected:
	Entity* m_entity;						//ʵ�����
	bool m_isMoving;					//�Ƿ������ƶ�
	bool m_isXLeft;						//���X�����Ƿ�������
	bool m_isYUp;							//���Y�����Ƿ�������
	int m_iCheckMoveSpeed;		//����ƶ��ļ��ʱ�䣬ʱ��Խ�̣��ƶ�Խ��
	/*������ǰ�����Ŀ�����꣬�����i��һ��Ҫ���õ�����*/
	Point getNextPos(Point curPos, Point destPos);
	/*�����ƶ�����ʱ�ص�*/
	std::function<void()> m_moveEndFunc;
};
#endif//_ControllerMoveBase_H_