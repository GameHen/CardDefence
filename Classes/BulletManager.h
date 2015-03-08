#define BULLET_MAX_CACHE_NUM 10
#include "cocos2d.h"
USING_NS_CC;

class BulletBase;
class BulletManager :public Node
{
public:
	BulletManager();
	~BulletManager();
	static BulletManager* create();
	bool init();

	/*�ӻ����л�ȡһ��δ��ʹ�õ��ӵ�*/
	BulletBase* getAnyUnUsedBullet();
private:
	Vector<BulletBase*>m_bulletList;			/*�ӵ��б�*/
	void createBullets();								/*���������ӵ�*/
	void bulletLogicCheck(float dt);				/*�ӵ��߼�*/
};