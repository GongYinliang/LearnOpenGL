#include <GLFW/glfw3.h>
#include <iostream>

void initSettingGLWindow();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void renderLoop();
// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
GLFWwindow* g_window = NULL;

int main()
{		
	initSettingGLWindow();

	renderLoop();

	glfwTerminate();
	return 0;
}

void initSettingGLWindow()
{
	// glfw ��ʼ��������
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	// glfw ���ڴ���
	// --------------------
	g_window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Learn OpenGL Window", NULL, NULL);
	if (g_window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return ;
	}
	glfwMakeContextCurrent(g_window);
	glfwSetFramebufferSizeCallback(g_window, framebuffer_size_callback); //ע���������������GLFW����ϣ��ÿ�����ڵ�����С��ʱ������������
																	   // glad: load all OpenGL function pointers
																	   // --------------------------------------	
}

void renderLoop()
{
	// render loop ��Ⱦѭ��
	// -----------
	while (!glfwWindowShouldClose(g_window))
	{
		/*if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);*/

		// render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(g_window);
		glfwPollEvents();
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height); //glViewport����ǰ�����������ƴ������½ǵ�λ�á��������͵��ĸ�����������Ⱦ���ڵĿ�Ⱥ͸߶ȣ����أ�
}