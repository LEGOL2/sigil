#include <engine.hpp>
#include <stdio.h>

#include <cstdlib>

static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void ResizeCallback(GLFWwindow* window, int width, int height);
static void ErrorCallback(int error, const char* description);

Sigil::Sigil(size_t width, size_t height, const char* title) : width(width), height(height) {
    if (!glfwInit()) {
        Terminate();
    }
    glfwSetErrorCallback(ErrorCallback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(this->width, this->height, title, NULL, NULL);
    if (!window) {
        Terminate();
    }
    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);

    glViewport(0, 0, this->width, this->height);

    glfwSetKeyCallback(window, KeyCallback);
    glfwSetFramebufferSizeCallback(window, ResizeCallback);

    glfwSwapInterval(1);
}

Sigil::~Sigil() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool Sigil::WindowShouldClose() { return glfwWindowShouldClose(window); }

void Sigil::SwapBuffers() { glfwSwapBuffers(window); }

void Sigil::PollEvents() { glfwPollEvents(); }

void Sigil::Terminate(const char* description) {
    fprintf(stderr, "Error: %s\n", description);
    std::exit(-1);
}

void Sigil::Terminate() { std::exit(-1); }

static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(window, GLFW_TRUE);
}

static void ResizeCallback(GLFWwindow* window, int width, int height) {
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
}

static void ErrorCallback(int error, const char* description) { fprintf(stderr, "Error: %s\n", description); }
