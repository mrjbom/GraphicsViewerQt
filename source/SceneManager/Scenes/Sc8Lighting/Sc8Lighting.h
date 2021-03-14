#ifndef SC8LIGHTING_H
#define SC8LIGHTING_H


#include <QDebug>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_4_5_Core>
#include <GL/GLU.h>
#include "../../SceneManager.h"
#include "../../ShaderProgram.h"

#include "../../BasicObjects/ArrowPainter/ArrowPainter.h"

#include "../../Camera/Camera.h"

#include "../../glm/glm.hpp"
#include "../../glm/gtc/matrix_transform.hpp"
#include "../../glm/gtc/type_ptr.hpp"

#include <QSlider>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>

class Sc8Lighting : public SceneManager
{
private:
    QOpenGLFunctions_4_5_Core* glFunctions = nullptr;

private:
    int window_width = 0, window_height = 0;
    float mouse_last_xpos = 0;
    float mouse_last_ypos = 0;
    bool mouse_left_button_pressed = false;

    Camera* cam = nullptr;

    ShaderProgram* gBoxShaderProgram = nullptr;
    GLuint g_VAO_cube = 0;
    GLuint g_VBO_cube_vertexes = 0;
    GLuint g_VBO_cube_normals = 0;
    GLuint g_VBO_cube_wall_texcoords = 0;
    ShaderProgram* gLightShaderProgram = nullptr;
    GLuint g_VAO_light = 0;
    glm::vec3 g_light_to_cube_distance = glm::vec3(2.5f, 0.0f, 0.0f);
    glm::vec3 g_light_position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 g_light_color = glm::vec3(1.0f, 1.0f, 1.0f);
    ShaderProgram* gPyramideShaderProgram = nullptr;
    GLuint g_VAO_pyramide = 0;
    GLuint g_VBO_pyramide_vertexes = 0;
    GLuint g_VBO_pyramide_normals = 0;

    ArrowPainter* arrowPainter = nullptr;

    glm::mat4 model_matrix = glm::mat4(1.0f);
    glm::mat4 view_matrix = glm::mat4(1.0f);
    glm::mat4 projection_matrix = glm::mat4(1.0f);
    glm::mat4 rotation_matrix = glm::mat4(1.0f);

    float x_rot = 0;
    float y_rot = 0;
    float x_rotation_speed_in_degrees = 0;
    float y_rotation_speed_in_degrees = 0;
    float x_size_scale = 1;
    float y_size_scale = 1;
    float light_rotation_around_degress = 0.0f;

public:
    Sc8Lighting(QOpenGLContext* openGLContext);
    ~Sc8Lighting();
    void initScene(int start_window_width, int start_window_height) override;
    void drawScene() override;
    void finishScene() override;
    void resizeSceneWindow(int w, int h) override;
    void mousePressEventHandler(QMouseEvent event) override;
    void mouseReleaseEventHandler(QMouseEvent event) override;
    void mouseMoveEventHandler(QMouseEvent event) override;
    void keyPressEventHandler(QKeyEvent* event) override;
    void keyReleaseEventHandler(QKeyEvent* event) override;
};

#endif // SC8LIGHTING_H
