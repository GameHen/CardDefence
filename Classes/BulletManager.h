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

	/*从缓存中获取一个未被使用的子弹*/
	BulletBase* getAnyUnUsedBullet();
private:
	Vector<BulletBase*>m_bulletList;			/*子弹列表*/
	void createBullets();								/*创建缓存子弹*/
	void bulletLogicCheck(float dt);				/*子弹逻辑*/
};