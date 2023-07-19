#include <QCEngine.h>

class ExampleLayer : public QC::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		QC_INFO("ExampleLayer::Update");
	}

	void OnEvent(QC::Event& event) override
	{
		QC_TRACE("{0}", event);
	}
};

class Sandbox : public QC::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox() 
	{

	}
};

QC::Application* QC::CreateApplication()
{
	return new Sandbox();
}