#ifndef SC1VBOORANGE_H
#define SC1VBOORANGE_H

#include <QDebug>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLFunctions_4_5_Core>
#include <GL/GLU.h>
#include "../../SceneManager.h"
#include "../../ShaderProgram.h"

class Sc1VBOOrange : public SceneManager
{
private:
    QOpenGLFunctions_4_5_Core* glFunctions = nullptr;

private:
    ShaderProgram* gShaderProgram = nullptr;
    GLuint gVBO = 0;

public:
    Sc1VBOOrange(QOpenGLContext* openGLContext);
    ~Sc1VBOOrange();
    void initScene();
    void drawScene();
    void finishScene();
};

#endif // SC1VBOORANGE_H
