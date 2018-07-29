#pragma once
#include "../util/errorLogging.h"
#include <GL/glew.h>
#include <glfw3.h>
#include <iostream>

class Window {

private:
	bool m_keys[1024];
	bool m_button[128];

	friend static void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);
	friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

public:
	std::string m_title;
	int m_width;
	int m_height;
	GLFWwindow* m_window;

	inline bool GetKey(int key) { return m_keys[key]; };
	inline bool GetMouse(int mouse) { return m_button[mouse]; };

public:
	Window(int width, int height, std::string title);
	~Window();

	void Clear() const;
	void Update();
	bool Closed() const;

	void SetTitle(std::string& title);
	inline int getWidth() { return m_width; };
	inline int getHeight() { return m_height; };

	void HideMouse();
	void ShowMouse();
	void GetMousePos(double* xpos, double* ypos);
	void SetMousePos(double xpos, double ypos);
};