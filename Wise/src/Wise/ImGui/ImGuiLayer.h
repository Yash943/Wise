#pragma once

#include "Wise/Layer.h"
#include "Wise/Events/Event.h"
#include "Wise/Events/ApplicationEvent.h"
#include "Wise/Events/KeyEvent.h"
#include "Wise/Events/MouseEvent.h"


namespace Wise {

	class WISE_API  ImGuiLayer : public Layer
	{
	public: 
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizedEvent(WindowResizeEvent& e);
		float m_Time = 0.0f;
		
	};
}