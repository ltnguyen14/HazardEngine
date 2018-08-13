#include "window.h"

void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->m_keys[key] = action != GLFW_RELEASE;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) 
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->m_button[button] = action != GLFW_RELEASE;
}

Window::Window(int width, int height, std::string title)
	:m_title(title), m_width(width), m_height(height)
{
	if (!glfwInit()) {
		std::cout << "Error initializing GLFW!" << std::endl;
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (!m_window)
	{
		glfwTerminate();
		std::cout << "Error creating new window!" << std::endl;
		return;
	}

	glfwMakeContextCurrent(m_window);
	glEnable(GL_DEPTH_TEST);

	if (glewInit() != GLEW_OK) {
		std::cout << "Error initializing glew" << std::endl;
	}

	std::cout << "GLEW version: " << glGetString(GL_VERSION) << std::endl;

	glfwSetWindowUserPointer(m_window, this);
	glfwSetMouseButtonCallback(m_window, mouse_button_callback);
	glfwSetKeyCallback(m_window, key_callback);
}

Window::~Window()
{
	glfwTerminate();
}

void Window::Clear() const
{
	GLCALL(glClearColor(0.0, 0.0, 0.0, 1.0));
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::Update()
{
	glfwSwapBuffers(m_window);
	glfwPollEvents();
}

bool Window::Closed() const
{
	return glfwWindowShouldClose(m_window);
}

void Window::SetTitle(std::string& title)
{
	m_title = title;
}

void Window::HideMouse()
{
	glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}

void Window::ShowMouse()
{
	glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

void Window::GetMousePos(double * xpos, double * ypos)
{
	glfwGetCursorPos(m_window, xpos, ypos);
}

void Window::SetMousePos(double xpos, double ypos)
{
	glfwSetCursorPos(m_window, xpos, ypos);
}


