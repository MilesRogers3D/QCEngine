#include "Application.h"

#include "QC/Events/ApplicationEvent.h"
#include "QC/Log.h"

namespace QC
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		QC_TRACE(e);

		while (true);
	}
}