#pragma once

#include "Core.h"

namespace QC 
{
	class QC_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

