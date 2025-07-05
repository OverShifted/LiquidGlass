#pragma once

#include <OverEngine.h>
#include "BlurPass.h"

using namespace OverEngine;

class LiquidGlass : public Layer
{
public:
	LiquidGlass();

	void UploadAllUniforms();

	void OnUpdate(TimeStep deltaTime) override;
	void OnImGuiRender() override;
	void OnEvent(Event& event) override;
private:
    SceneCamera m_Camera;
    SceneCamera m_ScreenCamera;
    Vector3 m_Position = { 0, 0, 0 };
    Vector3 m_CameraPosition = { 0, 0, 0 };

	Ref<Texture2D> bg = nullptr;
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
	float u_noise = 0.1;

	float u_glowWeight = 0.3;
	float u_glowBias = 0.0;
	float u_glowEdge0 = 0.06;
	float u_glowEdge1 = 0.0;

	int blurIters = 1;

	float velocityMultiplier = 1.0;
	float velocity = 2.0;
	float size = 3.5;

	float cameraVelocityMultiplier = 1.0;
	float cameraVelocity = 2.0;

	float lastDeltaTime = 0.0;
};
