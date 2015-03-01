#ifndef _I18N_H_
#define _I18N_H_
#include "cocos2d.h"
#include "EnumStrKey.h"
USING_NS_CC;
class I18N:public Ref
{
public:
	static I18N* getInstance();
	virtual bool init();
	/*根据整型的Key值获取字符串*/
	const char* getcStringByKey(int iKey);
	/*根据枚举的Key值获取字符串*/
	const char* getcString(EnumStrKey enStrKey);
private:
	/*从配置文件中读取字符串，保存到字典*/
	void loadStringsFromConf(const char *filePath);
	/*I18N对象*/
	static I18N* m_I18N;
	/*游戏中用到的字符串字典*/
	std::map<int, std::string> mStringMap;
};

#endif//_I18N_H_