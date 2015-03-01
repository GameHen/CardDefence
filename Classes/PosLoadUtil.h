#ifndef _PosLoadUtil_H__
#define _PosLoadUtil_H__
#include "cocos2d.h"
#include "EnumPosType.h"
USING_NS_CC;
class PosBase;
class PosLoadUtil:public CCNode
{
public:
	static PosLoadUtil* getInstance();
	virtual bool init();

	Vector<PosBase*>loadPosWithFile(
		const char *sFilePath,
		EnumPosType enPosType, Node *container,
		int iLevel, bool isDebug);
	
private:
	static PosLoadUtil *m_posLoadUtil;
};

#endif//_PosLoadUtil_H__