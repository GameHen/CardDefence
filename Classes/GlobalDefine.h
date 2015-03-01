#ifndef __GlobalDefine_H__
#define __GlobalDefine_H__
#include "cocos2d.h"


/*����bool����������get��set����*/
#define CC_CC_SYNTHESIZE_BOOL(varName, funName)\
	protected: bool varName; \
	public: bool is##funName(void) const{ return varName; }\
	public: void set##funName(bool var){ varName = var; }
/*��Ϣ�ɷ�*/
#define NOTIFY cocos2d::NotificationCenter::getInstance()
#endif