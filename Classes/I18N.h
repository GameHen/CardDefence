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
	/*�������͵�Keyֵ��ȡ�ַ���*/
	const char* getcStringByKey(int iKey);
	/*����ö�ٵ�Keyֵ��ȡ�ַ���*/
	const char* getcString(EnumStrKey enStrKey);
private:
	/*�������ļ��ж�ȡ�ַ��������浽�ֵ�*/
	void loadStringsFromConf(const char *filePath);
	/*I18N����*/
	static I18N* m_I18N;
	/*��Ϸ���õ����ַ����ֵ�*/
	std::map<int, std::string> mStringMap;
};

#endif//_I18N_H_