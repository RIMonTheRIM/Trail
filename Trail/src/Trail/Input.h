#pragma once

#include "Trail/Core.h"

namespace Trail {
	class TRL_API Input {
	public:
		inline static bool isKeyPressed(int keycode) { return s_Instance->isKeyPressedImpl(keycode); }
		inline static bool isMouseButtonPressed(int button){ return s_Instance->isMouseButtonPressedImpl(button);  }
		inline static float getMouseX() { return s_Instance->getMouseXImpl(); }
		inline static float getMouseY() { return s_Instance->getMouseYImpl(); }
	protected:
		virtual bool isKeyPressedImpl(int keycode) = 0;

		virtual bool isMouseButtonPressedImpl(int button) = 0;
		virtual float getMouseXImpl() = 0;
		virtual float getMouseYImpl() = 0;
	private:
		static Input* s_Instance;
	};
}