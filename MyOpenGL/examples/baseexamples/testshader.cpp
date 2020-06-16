#include "../config.h"
int testshader()
{
	init_glfw();
	GLFWwindow* window = create_glfwwindow("LearnOpenGL");
	init_glad();

	MyShader myShader("../MyOpenGL/shader/baseshader/baseshader.vs", "../MyOpenGL/shader/baseshader/baseshader.fs");

	float vertics[] = {
		// 坐标           颜色
		0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
	   -0.5f,-0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
		0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
	};

	unsigned int VBO, VAO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertics), vertics, GL_STATIC_DRAW);
	glBindVertexArray(VAO);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	while (!glfwWindowShouldClose(window))
	{
		process_input(window);
		glClearColor(0.2f, 0.3f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		myShader.use();
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	myShader.Close();
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
	glfwTerminate();
	return 0;
}