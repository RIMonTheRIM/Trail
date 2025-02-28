#pragma once

#include "Event.h"
#include <sstream>

namespace Trail {
	class TRL_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() const { return m_Keycode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput) //search about this (|)
	protected:
		KeyEvent(int keycode) : m_Keycode(keycode) {}
		int m_Keycode;
	};



	class TRL_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatcount) : KeyEvent(keycode), m_RepeatCount(repeatcount) {}
		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string GetString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_Keycode << " (" << m_RepeatCount << " repeats";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};


	class TRL_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode){}
		std::string GetString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_Keycode; //search about stringstreams
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyReleased)
	};
	class TRL_API KeyTypedEvent : public KeyEvent {
	public:
		KeyTypedEvent(int keycode) : KeyEvent(keycode){}

		std::string GetString() const override {
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_Keycode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}