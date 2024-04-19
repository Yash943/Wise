#pragma once

#include "Event.h"
#include "sstream"

namespace Wise
{
	class WISE_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | Event CategoryInput)
	protected:
		KeyEvent(int keycode):m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class WISE_API KeyPressedEvent : public Event
	{
	public:
		KeyPresseedEvent(INT keycode, int repeatCount): KeyEvent(keycode). m_RepeatCount(repeatCount){}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << " KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";

			return ss;
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class WISE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode): KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}