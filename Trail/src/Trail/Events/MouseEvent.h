#pragma once
#include "Event.h"
#include <sstream>

namespace Trail {
	class TRL_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}
		inline float GetX() {return m_MouseX;}
		inline float GetY() {return m_MouseY;}

		std::string GetString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}


		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		EVENT_CLASS_TYPE(MouseMoved)

	private:
		float m_MouseX, m_MouseY;
	};
	class TRL_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset){}
		inline float GetXOffset() { return m_XOffset; }
		inline float GetYOffset() { return m_YOffset; }


		std::string GetString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		EVENT_CLASS_TYPE(MouseScrolled)
	private:
		float m_XOffset, m_YOffset;
	};

	class TRL_API MouseButtonEvent : public Event {
	public: 
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button) : m_Button(button){}

		int m_Button;
	};
	class TRL_API MouseButtonPressedEvent : public MouseButtonEvent {
	public: 
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string GetString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};
	class TRL_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string GetString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}