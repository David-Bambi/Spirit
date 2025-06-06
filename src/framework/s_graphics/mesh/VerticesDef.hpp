#ifndef VERTICESDEF_HPP
#define VERTICESDEF_HPP

#include <glm/gtc/constants.hpp>
#include <iostream>

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

/**
 * * Vertices for a circle
 */
std::vector<glm::vec3> CircleV(int n)
{
    // Radius = 1
    // Angle = 2 PI Radius
    // i = nième angle
    // (2 PI R / n) * i
    //
    // Separate the circle into n parts
    // Multiply by i for the nth angle
    //
    //        (cos angle, sin angle)
    //         .__.
    //         | /
    //         |/
    //         .
    //         (0.0)
    //
    //

    std::vector<glm::vec3> circleV;
    circleV.push_back(glm::vec3(0.0f, 0.0f, 0.0f)); // Center of the circle

    for (int i = 0; i < n; ++i)
    {
        float angle = 2.0f * glm::pi<float>() * i / n;
        circleV.push_back(glm::vec3(cos(angle), sin(angle), 0.0f));
    }
    return circleV;
};

/**
 * * Indexs for a circle
 */
std::vector<unsigned int> CircleI(int n)
{
    //     n   i   i+1
    //      .__.__.
    //       \ | /
    //        \|/
    //         .
    //         0

    // Separate the circle into n parts
    std::vector<unsigned int> circleI;
    for (int i = 1; i < n; ++i)
    {
        circleI.push_back(0);
        circleI.push_back(i);
        circleI.push_back(i + 1);
    }

    // Last triangle
    circleI.push_back(0);
    circleI.push_back(n);
    circleI.push_back(1);

    return circleI;
};

/**
 * * Vertices for a sphere
 */
std::vector<glm::vec3> SphereV(float sector, float stack)
{
//        _   Stack     .  Sector            
//        _\           / \
//        __\         /   \
//        ___|        |    |
//        __/          \  /
//         /            \. 
//
//  With the parametric equation 
//  x = (r * cos(phi)) * cos(theta)
//  y = (r * cos(phi)) * sin(theta)
//  z = r * sin(theta)
//   
//  r = rayon = 1 
//  phi = angle de l'axe z vis à vis le plan xy
//  theta = angle entre x et y
//   
//  Sector step = 2
//
//
    const float PI = glm::pi<float>();
    const float sectorStep = 2 * PI / sector;
    const float stackStep = PI / stack;
    float sectorAngle, stackAngle;

    float xy, z, x, y;

    std::vector<glm::vec3> retvec = {};

    for(int i = 0; i <= stack; ++i)
    {
        stackAngle = PI / 2 - i * stackStep;        // starting from pi/2 to -pi/2
        xy = cosf(stackAngle);             // r * cos(u)
        z = sinf(stackAngle);  

        for (int j = 0; j <= sector; ++j)
        {
            sectorAngle = j * sectorStep;

            // vertex position (x, y, z)
            x = xy * cosf(sectorAngle);
            y = xy * sinf(sectorAngle);
            retvec.push_back(glm::vec3(x, y, z));
        }
    }
    return retvec;
};

/**
 * * Indexs for a sphere
 */
std::vector<unsigned int> SphereI(float sector, float stack)
{
    // k1 ___ ___                 1st iteration  1st iteration
    //   |\  |\  |  Stack = 10     k1 = 0        i == 0
    // k2|_\_|_\_|                 k2 = 11       ind [1]
    //   |\  |                                   ind [11]
    //   |_\_|                                   ind [12]
    //
    //    Sector = 10                            2snd iteration
    //                                           k1 = 1
    //                                           k2 = 12
    // 

    std::vector<unsigned int> indices;
    unsigned int k1, k2;

    for(int i = 0; i < stack; ++i)
    {
        k1 = i * (sector + 1);     // beginning of current stack
        k2 = k1 + sector + 1;      // beginning of next stack

        for(int j = 0; j < sector; ++j, ++k1, ++k2)
        {
            // 2 triangles per sector excluding first and last stacks
            // k1 => k2 => k1+1
            if(i != 0)
            {
                indices.push_back(k1);
                indices.push_back(k2);
                indices.push_back(k1 + 1);
            }

            // k1+1 => k2 => k2+1
            if(i != (sector-1))
            {
                indices.push_back(k1 + 1);
                indices.push_back(k2);
                indices.push_back(k2 + 1);
            }
        }
    }
    return indices;
};

}; // namespace VerticesDef

#endif