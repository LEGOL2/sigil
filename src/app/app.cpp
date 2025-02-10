#include <iostream>
#include <sigil.hpp>

void RenderLoop(Sigil &engine);

int main() {
    Sigil engine(800, 640, "Sigil Engine");

    RenderLoop(engine);
}

void RenderLoop(Sigil &engine) {
    float red = 0;
    float delta = 0.001;
    glClearColor(0.1, red, 0.86, 1.0);
    while (!engine.WindowShouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        red += delta;
        if (red > 1.0 || red < 0.0 ) { delta = -delta; }
        glClearColor(0.1, red, 0.86, 1.0);

        engine.SwapBuffers();
        engine.PollEvents();
    }
}
