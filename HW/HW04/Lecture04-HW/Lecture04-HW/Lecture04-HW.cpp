#include <GLFW/glfw3.h>
#include <iostream>

#define BLACK   {0.0f, 0.0f, 0.0f, 1.0f}
#define RED     {1.0f, 0.0f, 0.0f, 1.0f}
#define GREEN   {0.0f, 1.0f, 0.0f, 1.0f}
#define BLUE    {0.0f, 0.0f, 1.0f, 1.0f}
#define MAGENTA {1.0f, 0.0f, 1.0f, 1.0f}

float clearColor[4] = BLACK;
bool isDragging = false;

void setColor(const float color[4]) {
    glClearColor(color[0], color[1], color[2], color[3]);
}

const float black[4] = BLACK;
const float red[4] = RED;
const float green[4] = GREEN;
const float blue[4] = BLUE;
const float magenta[4] = MAGENTA;

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        setColor(red);
        isDragging = false;
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE && !isDragging) {
        setColor(black);
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        setColor(green);
        isDragging = false;
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE && !isDragging) {
        setColor(black);
    }
}

void cursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
        setColor(blue);
        isDragging = true;
    }
    else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
        setColor(magenta);
        isDragging = true;
    }
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }
    GLFWwindow* window = glfwCreateWindow(800, 600, "Lecture04_HW", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPosCallback);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
//여기가 최선 인거같습니다...
