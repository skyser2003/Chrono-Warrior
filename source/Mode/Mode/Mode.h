#pragma once

namespace FG
{
	class Window;
	class DxCanvas;
	class VertexShader;
	class PixelShader;
	class TextureClass;
	class KeyboardInput;
	class MouseInput;

	class UIManager;
}

namespace CW
{
	class Mode
	{
	public:
		Mode();
		virtual ~Mode();

		virtual void Initialize(const std::shared_ptr<FG::Window>& window);
		virtual void Destroy();

		virtual bool Run() = 0;

		std::shared_ptr<FG::Window> GetWindow() const { return mWindow; }
	protected:
		virtual void InitializeGraphics();

		virtual void Update(std::chrono::system_clock::duration dt) = 0;
		virtual void Draw(std::chrono::system_clock::duration dt) = 0;

		// UI variables
		std::unique_ptr<FG::UIManager> mUIM;

		// Graphics variables
		std::shared_ptr<FG::Window> mWindow;
		FG::DxCanvas* mCanvas;
		std::shared_ptr<FG::VertexShader> mVS;
		std::shared_ptr<FG::PixelShader> mPS;

		std::shared_ptr<FG::KeyboardInput> mKeyboard;
		std::shared_ptr<FG::MouseInput> mMouse;

		std::shared_ptr<FG::TextureClass> mLemon, mApple;
		std::shared_ptr<FG::TextureClass> mSoldier, mMage;
	};
}