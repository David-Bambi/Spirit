#ifndef KEY_HPP
#define KEY_HPP

#include <cstdint>

enum class Key : std::uint16_t
{
    W = GLFW_KEY_W,
    A = GLFW_KEY_A,
    S = GLFW_KEY_S,
    D = GLFW_KEY_D,
    SPACE = GLFW_KEY_SPACE,
    ESCAPE = GLFW_KEY_ESCAPE,
    LEFT = GLFW_KEY_LEFT,
    RIGHT = GLFW_KEY_RIGHT,
    UP = GLFW_KEY_UP,
    DOWN = GLFW_KEY_DOWN,
    MAJ = GLFW_KEY_LEFT_SHIFT
};

#endif