#include "..\\vulkanFramework\\include\\application.h"
#define TEST_CLASS_NAME CSimpleSkybox
class TEST_CLASS_NAME: public CApplication{
public:
    void initialize(){
		CApplication::initialize();
	}

	void update(){
		CApplication::update();
	}

	void recordGraphicsCommandBuffer(){
		objectList[0].Draw();
	}
};

#ifndef ANDROID
#include "..\\vulkanFramework\\include\\main.hpp"
#endif