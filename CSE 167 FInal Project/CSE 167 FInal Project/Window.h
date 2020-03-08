#ifndef _WINDOW_H_
#define _WINDOW_H_

#ifdef __APPLE__
#define GLFW_INCLUDE_GLCOREARB
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "Object.h"
#include "shader.h"
#include "skybox.h"
#include "geometry.h"
#include "Cube.h"

class Window
{
public:
    class Material
    {
    public:
        glm::vec3 ambient;
        glm::vec3 diffuse;
        glm::vec3 specular;
        float shininess;
    };
    
    class directionLight
    {
    public:
        glm::vec3 lightColor;
        glm::vec3 direction;
    };
    
    class pointLight
    {
    public:
        glm::vec3 pointColor;
        glm::vec3 pointPosition;
    };
	// Initializes your shader program(s) and uniform variable locations
	static bool initializeProgram();
	// Initialize your OBJ objects here
	static bool initializeObjects();
	// Make sure to clean up any data you dynamically allocated here
	static void cleanUp();
	// Creates a GLFW window context
	static GLFWwindow* createWindow(int width, int height);
	// Is called whenever the window is resized
	static void resizeCallback(GLFWwindow* window, int width, int height);
	// Is called on idle.
	static void idleCallback();
	// This renders to the glfw window. Add draw calls here
	static void displayCallback(GLFWwindow*);
    static void rotateRobot(glm::vec3 prev, glm::vec3 after);
    static void rotateCamera(glm::vec3 prev, glm::vec3 after);
	// Add your key press event handling here
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    // Add mouse and scroll here
    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
    static void mouse_button_callback(GLFWwindow* window, int button, int action, int
    mods);
    static void cursor_position_callback(GLFWwindow* window,
    double xpos, double ypos);
    static glm::vec3 trackingBallMapping(double xpos, double ypos);
};

#endif