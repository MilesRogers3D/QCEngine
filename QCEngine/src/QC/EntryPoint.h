#pragma once

#ifdef QC_PLATFORM_WINDOWS

extern QC::Application* QC::CreateApplication();

int main(int argc, char** argv)
{
	auto app = QC::CreateApplication();
	app->Run();
	delete app;
}

#endif