#include "FidgetSpinner.h"
#include "ResourceManager.h"
using namespace aie;
FidgetSpinner::FidgetSpinner()
{
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();

	m_fidgetTexture = pTextureManager->LoadResource("./textures/FStest.png");
}


FidgetSpinner::~FidgetSpinner()
{
}

void FidgetSpinner::Update(float deltaTime)
{
}

void FidgetSpinner::Draw(aie::Renderer2D * m_2dRenderer)
{
	m_2dRenderer->setRenderColour(tan(m_timer) + sin(m_timer) + 1, tan(m_timer) + 0, sin(m_timer) + 1, cos(m_timer) + 1);
	m_2dRenderer->drawSprite(m_fidgetTexture, sin(m_timer) * 100 + 600, 150, 50);
}
