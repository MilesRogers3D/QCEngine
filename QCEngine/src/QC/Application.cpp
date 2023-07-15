#include "Application.h"

#include "QC/Events/ApplicationEvent.h"
#include "QC/Log.h"

namespace QC
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}