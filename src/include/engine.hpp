#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>

class Sigil {
   public:
    Sigil(size_t width, size_t height, const char* title);
    ~Sigil();

    bool WindowShouldClose();
    void SwapBuffers();
    void PollEvents();

   private:
    void Terminate(const char* description);
    void Terminate();

    size_t width;
    size_t height;
    GLFWwindow* window;
};
