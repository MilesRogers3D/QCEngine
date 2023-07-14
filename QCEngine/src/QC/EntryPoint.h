#pragma once

#ifdef QC_PLATFORM_WINDOWS

extern QC::Application* QC::CreateApplication();

int main(int argc, char** argv)
{
	QC::Log::Init();
	QC_CORE_INFO("Engine Started!");

	auto app = QC::CreateApplication();
	app->Run();
	delete app;
}

#endif