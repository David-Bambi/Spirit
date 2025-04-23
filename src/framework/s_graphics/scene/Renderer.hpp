#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <glad/glad.h>

#include <vector>
#include <map>
#include <memory>

#include <scene/Renderable.hpp>

/**
 * @
 * @brief Renderer : Class for render the object of a scene. The renderer use the OpenGL. 
 * specification. So the class manage the buffer before send it to the vertex shader. 
 * 
 * This class is a singleton design pattern, so the constructor, clone constructor and assignation
 * are not permit.
 */
class Renderer
{
    private :
        static Renderer* _renderer;

        GLuint _VAO;
        std::vector<GLuint> _VBO;

        std::vector<std::shared_ptr<Renderable>> Obj;
        std::map<int, std::vector<std::shared_ptr<Renderable>>> Obj_instancied;

        std::vector<float> _Vertex_static;
        std::vector<unsigned int> _Index_static;


        bool _StaticBufferReady = false;

        Renderer();
        ~Renderer();

    public :
        void PrepareVBOBuffer(const std::shared_ptr<Renderable>& obj);

        // void PrepareDynamicBuffer(std::vector<float> VertexVec,
        //                           std::vector<unsigned int> IndexVec);

        // void PrepareTempBuffer(std::vector<float> VertexVec,
        //                        std::vector<unsigned int> IndexVec);

        static Renderer* GetInstance();
        static void DeleteInstance();

        void Render();
        void AddObj(const std::shared_ptr<Renderable>& obj);
    
        Renderer(Renderer &other) = delete;
        void operator=(const Renderer&) = delete;
};

#endif