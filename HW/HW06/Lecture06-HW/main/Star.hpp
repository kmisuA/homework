#include "MSList.h"
#include <GLFW/glfw3.h>

class Star {
private:
    float x;     
    float y;    
    float r;    
    float g;     
    float b;     

public:
    Star(float x, float y, float r, float g, float b)
        : x(x), y(y), r(r), g(g), b(b) {}

  
    ~Star() {}

    
    void render() {
        glBegin(GL_TRIANGLES);
        // Triangle 1
        glColor3f(r, g, b);
        glVertex2f(x - 0.06f, y + 0.04f);
        glVertex2f(x + 0.06f, y + 0.04f);
        glVertex2f(x, y - 0.04f);
        glEnd();

        glBegin(GL_TRIANGLES);
        // Triangle 2
        glColor3f(r, g, b);
        glVertex2f(x - 0.02f, y - 0.02f);
        glVertex2f(x, y + 0.1f);
        glVertex2f(x + 0.04f, y - 0.08f);
        glEnd();

        glBegin(GL_TRIANGLES);
        // Triangle 3
        glColor3f(r, g, b);
        glVertex2f(x - 0.04f, y - 0.08f);
        glVertex2f(x, y + 0.1f);
        glVertex2f(x + 0.02f, y - 0.02f);
        glEnd();
    }
};
