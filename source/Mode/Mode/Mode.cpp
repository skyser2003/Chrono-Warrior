#include "stdafx.h"
#include "Mode.h"

#include "Window/Window.h"
#include "KeyboardInput/KeyboardInput.h"
#include "MouseInput/MouseInput.h"

#include "Canvas/DxCanvas.h"
#include "Graphics/graphicsclass.h"
#include "Shaders/VertexShader/VertexShader.h"
#include "Shaders/PixelShader/PixelShader.h"
#include "TextureManager/TextureManager.h"
#include "Texture/textureclass.h"

#include "UIManager/UIManager.h"

namespace CW
{
	Mode::Mode()
	{
		mUIM.reset(new FG::UIManager);
	}
	Mode::~Mode()
	{
	}

	void Mode::Initialize(const std::shared_ptr<FG::Window>& window)
	{
		mWindow = window;

		mKeyboard.reset(new FG::KeyboardInput);
		mMouse.reset(new FG::MouseInput);

		window->RegisterInput(mKeyboard);
		window->RegisterInput(mMouse);
		mMouse->SetScreenSize(window->GetScreenWidth(), window->GetScreenHeight());
	}
	void Mode::Destroy()
	{

	}

	void Mode::InitializeGraphics()
	{
		HRESULT result;
		std::string vsFileName = "../Shaders/vstexture.hlsl";
		std::string psTextureFileName = "../Shaders/pstexture.hlsl";
		std::string psColorFileName = "../Shaders/pscolor.hlsl";

		mCanvas = &GetWindow()->GetCanvas();

		mVS = mCanvas->CreateVertexShader();
		result = mVS->CompileShader(vsFileName.c_str(), "VertexTextureMain");
		if (FAILED(result))
		{
			MessageBox(mCanvas->GetGraphics()->GetHwnd(), "Error compiling shader.  Check shader-error.txt for message.", vsFileName.c_str(), MB_OK);
			return;
		}

		mVS->SetupShaderBufferInputType("POSITION");
		mVS->SetupShaderBufferInputType("COLOR");
		mVS->SetupShaderBufferInputType("TEXCOORD");
		mVS->CreateShaderBufferDesc();
		mVS->CreateCBufferDesc("matrix", sizeof(FG::MatrixBufferType));

		mPS = mCanvas->CreatePixelShader();
		//result = mPS->CompileShader(psColorFileName.c_str(), "PixelColorMain");
		result = mPS->CompileShader(psTextureFileName.c_str(), "PixelTextureMain");
		if (FAILED(result))
		{
			MessageBox(mCanvas->GetHwnd(), "Error compiling shader.  Check shader-error.txt for message.", psTextureFileName.c_str(), MB_OK);
			return;
		}
		mPS->CreateSamplerState();

		auto& tm = mCanvas->GetTextureManager();
		tm.SetDevice(mCanvas->GetDevice());
	}
}