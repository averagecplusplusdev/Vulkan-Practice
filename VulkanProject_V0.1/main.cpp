// YOU WERE AT X:XX ON THE TRIANGLE VULKAN INSTANCE

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
typedef uint32_t uint32;

uint32 WIDTH = 800;
uint32 HEIGHT = 600;

class HelloTriangleApplication
{
public:
	void Run()
	{	
		InitWindow();
		InitVulkan();
		MainLoop();
		Cleanup();
	}

private:
	GLFWwindow *_window;
	VkInstance _instance;

	void InitWindow()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		_window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
	}
	void InitVulkan()
	{
		CreateInstance();
	}
	void MainLoop()
	{
		while (!glfwWindowShouldClose(_window))
		{
			glfwPollEvents();
		}
	}
	void Cleanup()
	{
		vkDestroyInstance(_instance, nullptr);
		glfwDestroyWindow(_window);
		glfwTerminate();
	}

	void CreateInstance()
	{

	}
};

int main()
{
	HelloTriangleApplication app;
	try 
	{
		app.Run(); 
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
