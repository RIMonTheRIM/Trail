#pragma once
#include "Trail/Core.h"
#include "Trail/Events/Event.h"

namespace Trail {
	class TRL_API Layer { //this class should be derived and the subclassed should represent the layers present in the application
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach(){} //similar to OnInit
		virtual void OnDetach(){} //similar to Onshutdown
		virtual void OnUpdate(){}
		virtual void OnEvent(Event& event){}

		inline const std::string& GetName() const { return m_Debugname;  }

	private:
		std::string m_Debugname; //we shouldn't be addressing the layers by name this is purely for debug
	};
}