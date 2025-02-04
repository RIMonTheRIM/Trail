#include "trlpch.h"
#include "WindowsWindow.h"

namespace Trail {
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);//returns a pointer that'll be saved as a uniue pointer ?
	}
	WindowsWindow::WindowsWindow(const WindowProps& props) {
		Init(props);
	}
	WindowsWindow::~WindowsWindow() {
		Shutdown();
	}
	void WindowsWindow::Init(const WindowProps& props) {
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		TRL_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);
		if (!s_GLFWInitialized) {
			//TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			TRL_CORE_ASSERT(success, "Could not initialize GLFW!");
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}
	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(m_Window);
	}
	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}
	void WindowsWindow::SetVSync(bool enabled) {
		if(enabled) //VSync just means that we want the GPU to wait for a frame to be rendered before rendering a new frame
			//if we put a swap interval it'll wait that interval amount of frames before rendering a new one
			//not having an interval will just put the VSync off
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled; //keeping track of the state of the VSYnc
	}
	bool WindowsWindow::IsVSync() const {
		return m_Data.VSync; //return the state of the VSync
	}
}