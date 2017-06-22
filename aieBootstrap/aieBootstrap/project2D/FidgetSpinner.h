#pragma once
#include "Entity.h"
class FidgetSpinner : Entity
{
public:
	FidgetSpinner();
	~FidgetSpinner();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D*	m_2dRenderer);

private:
	aie::Texture*		m_fidgetTexture;

	float m_timer;
};

