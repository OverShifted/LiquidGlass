#define OE_CLIENT_INCLUDE_ENTRY_POINT
#include <OverEngine.h>

#include "LiquidGlass.h"

static ApplicationProps GenApplicationProps()
{
	ApplicationProps props;
	props.MainWindowProps.Title = "Liquid glass";
	props.MainWindowProps.Width = 1600;
	props.MainWindowProps.Height = 900;
	return props;
}

class LiquidGlassApp : public OverEngine::Application
{
public:
	LiquidGlassApp()
		: Application(GenApplicationProps())
	{
		PushLayer(new LiquidGlass());
		m_ImGuiEnabled = true;
	}

	~LiquidGlassApp()
	{
	}
};

OverEngine::Application* OverEngine::CreateApplication(int argc, char** argv)
{
	return new LiquidGlassApp();
}
