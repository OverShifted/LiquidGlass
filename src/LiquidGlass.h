#pragma once

#include <OverEngine.h>
#include "BlurPass.h"

using namespace OverEngine;

class LiquidGlass : public Layer
{
public:
	LiquidGlass();

	void OnUpdate(TimeStep deltaTime) override;
	void OnImGuiRender() override;
	void OnEvent(Event& event) override;
	
private:
	struct Background {
		String name;
		String credits;
		Ref<Texture2D> texture;
	};

	void UploadAllUniforms();
	inline Background& CurrentBackground() { return backgrounds[backgroundId]; }

private:
    SceneCamera m_Camera;
    SceneCamera m_ScreenCamera;
    Vector3 m_Position = { 0, 0, 0 };
    Vector3 m_CameraPosition = { 0, 0, 0 };

	bool mouseControl = false;

	Ref<FrameBuffer> fb = nullptr;
	// Ref<FrameBuffer> finalFb = nullptr;

	Scope<BlurPass> blurPass = nullptr;
	Ref<FrameBuffer> blurIntermediate = nullptr;
	Ref<FrameBuffer> blurFinal = nullptr;

	float blurDownscaleFactor = 0.5;

	int aa = 1;
	// int finalAa = 2;
	float u_powerFactor = 3.0;
	float u_a = 0.7;
	float u_b = 2.3;
	float u_c = 5.2;
	float u_d = 6.9;
	float u_blurRadius = 2.0;
	float u_fPower = 1.0;
	float u_noise = 0.06;

	float u_glowWeight = 0.25;
	float u_glowBias = 0.0;
	float u_glowEdge0 = 0.5;
	float u_glowEdge1 = -0.5;

	int blurIters = 1;

	float velocityMultiplier = 1.0;
	float velocity = 2.0;
	float width = 3.5;
	float height = 3.5;

	float cameraVelocityMultiplier = 1.0;
	float cameraVelocity = 2.0;

	float lastDeltaTime = 0.0;

	Vector<Background> backgrounds;
	int backgroundId = 0;
};
