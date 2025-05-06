#ifndef VERTICESDEF_HPP
#define VERTICESDEF_HPP

namespace VerticesDef
{
/** Vertices for a triangle
 *        1
 *        .
 *       / \
 *      /   \
 *     /     \
 *    /_______\
 *  2           3
 */
std::vector<glm::vec3> TriangleV = {
    glm::vec3(-1.0f, -1.0f, 0.0f), // 0
    glm::vec3(0.0f, 1.0f, 0.0f), // 1
    glm::vec3(1.0f, -1.0f, 0.0f) // 2
};

std::vector<glm::vec2> TriangleT = {
    glm::vec2(0.0f, 0.0f), // 0
    glm::vec2(0.5f, 1.0f), // 1
    glm::vec2(1.0f, 0.0f) // 2
};

/** Vertices for rectangle
 *
 *  0          1
 *   __________
 *  |          |
 *  |          |
 *  |          |
 *  |__________|
 *
 *  2          3
 */

std::vector<glm::vec3> RectangleV = {
    glm::vec3(-1.0f, 1.0f, 0.0f), // 0
    glm::vec3(1.0f, 1.0f, 0.0f), // 1
    glm::vec3(-1.0f, -1.0f, 0.0f), // 2
    glm::vec3(1.0f, -1.0f, 0.0f) // 3
};

/** Indexs of rectangle */
std::vector<unsigned int> RectangleI = {0, 1, 3, 0, 2, 3};

std::vector<glm::vec2> RectangleT = {
    glm::vec2(0.0f, 1.0f), // 0
    glm::vec2(1.0f, 1.0f), // 1
    glm::vec2(0.0f, 0.0f), // 2
    glm::vec2(1.0f, 0.0f) // 3
};

/** Vertices for the cube
 *
 *        5____________4
 *        /|         /|
 *       / |        / |
 *     1/__|_______/0 |
 *      | 7|_______|__|6
 *      | /        | /
 *      |/         |/
 *     3|__________|2
 *
 */

std::vector<glm::vec3> CubeV = {
    glm::vec3(1.0f, 1.0f, -1.0), // 0
    glm::vec3(-1.0f, 1.0f, -1.0), // 1
    glm::vec3(1.0f, -1.0f, -1.0), // 2
    glm::vec3(-1.0f, -1.0f, -1.0), // 3

    glm::vec3(1.0f, 1.0f, 1.0), // 4
    glm::vec3(-1.0f, 1.0f, 1.0), // 5
    glm::vec3(1.0f, -1.0f, 1.0), // 6
    glm::vec3(-1.0f, -1.0f, 1.0), // 7
};

/** Index of cube */
std::vector<unsigned int> CubeI = {
    0, 1, 2, // Front
    1, 3, 2, // Front
    1, 5, 0, // Top
    5, 4, 0, // Top
    3, 7, 2, // Bottom
    6, 7, 2, // Bottom
    1, 7, 3, // Left
    5, 1, 7, // Left
    0, 4, 2, // Right
    6, 4, 2, // Right
    5, 6, 7, // Back
    4, 5, 6, // Back
};

}; // namespace VerticesDef

#endif