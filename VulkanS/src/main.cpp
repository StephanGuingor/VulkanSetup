#include "vkpch.h"
#include "App.h"
#include "Log.h"


int main(int argc,char** argv)
{
	VKSP::Log::Init();
	VK_TRACE("Application Started!");
	auto app = new VKSP::App();
	app->Run();
	delete app;

}

