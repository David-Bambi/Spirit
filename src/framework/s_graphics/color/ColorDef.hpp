#ifndef COLORDEF_HPP
#define COLORDEF_HPP

#include <color/Color_t.hpp>

/**
 * @brief Namespace for predefine colors.
 */
namespace Color {
Color_t Red = {1.0f, 0.0f, 0.0f, 1.0f};
Color_t Green = {0.0f, 1.0f, 0.0f, 1.0f};
Color_t Blue = {0.0f, 0.0f, 1.0f, 1.0f};
Color_t Cyan = {0.0f, 1.0f, 1.0f, 1.0f};
Color_t Yellow = {1.0f, 1.0f, 0.0f, 1.0f};
Color_t Magenta = {1.0f, 0.0f, 1.0f, 1.0f};
Color_t White = {1.0f, 1.0f, 1.0f, 1.0f};
Color_t Black = {0.0f, 0.0f, 0.0f, 0.0f};

} // namespace Color

#endif