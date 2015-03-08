#include "GlobalClient.h"

GlobalClient* GlobalClient::m_GlobalClient = NULL;


GlobalClient* GlobalClient::getInstance(){
	if (m_GlobalClient == NULL) {
		m_GlobalClient = new GlobalClient();
		if (m_GlobalClient && m_GlobalClient->init()) {
			m_GlobalClient->autorelease();
			m_GlobalClient->retain();
		}
		else {
			CC_SAFE_DELETE(m_GlobalClient);
			m_GlobalClient = NULL;
		}
	}

	return m_GlobalClient;
}

bool GlobalClient::init(){
	return true;
}
