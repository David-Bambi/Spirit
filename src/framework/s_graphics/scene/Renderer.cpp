#include <scene/Renderer.hpp>

#include <iostream>
#include <FreqUpd_e.hpp>

Renderer* Renderer::_renderer = nullptr;

Renderer::Renderer()
{
    glGenVertexArrays(1, &_VAO);
}

Renderer::~Renderer()
{       
    glDeleteVertexArrays(1, &_VAO);
}

/**
 * @brief Get the unique instance of the Renderer class.
 * 
 * @return Renderer* 
 */
Renderer* Renderer::GetInstance()
{
    if(_renderer == nullptr)
        _renderer = new Renderer();

    return _renderer;
}

/**
 * @brief Clean the memory for the singleton instance of renderer.
 */
void Renderer::DeleteInstance()
{
    delete _renderer;
    _renderer = nullptr;
}


/**
 * @brief Render the actual buffer to thought the OpenGL pipeline.
 * 
 */
void Renderer::Render()
{
    glBindVertexArray(_VAO);

    if (!_StaticBufferReady)
 

    for (auto obj : Obj)
    {
        PrepareVBOBuffer(obj);
        obj->Render();
    }
    
    
    glBindVertexArray(0);
}

/**
 * @brief Prepare the VBO buffer for the static object. This is called only once because it's the 
 * object at start of the scene that is not modifiable.
 */
void Renderer::PrepareVBOBuffer(const std::shared_ptr<Renderable>& obj)
{ 
    glBindVertexArray(_VAO);

    GLuint VBO;
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER,
                 obj->Vertex().size()*sizeof(float),
                 obj->Vertex().data(),
                 obj->DrawUsage);

    // Vertices
    glVertexAttribPointer(0 /*index*/,
                          3 /*size*/,
                          GL_FLOAT,
                          GL_FALSE, 
                          8 * sizeof(float)  /*stride*/, 
                          (void*)0 /*Offset*/);
    glEnableVertexAttribArray(0);

    // Texture
    glVertexAttribPointer(1 /*index*/,
                          2 /*size*/,
                          GL_FLOAT,
                          GL_FALSE, 
                          8 * sizeof(float)  /*stride*/, 
                          (void*)(3*sizeof(float)) /*Offset*/);
    glEnableVertexAttribArray(1);

    // Normal
    glVertexAttribPointer(2 /*index*/, 
                          3 /*size*/, 
                          GL_FLOAT, 
                          GL_FALSE, 
                          8 * sizeof(float) /*stride*/, 
                          (void*)(5* sizeof(float))/*offset*/);
    glEnableVertexAttribArray(2);

    _StaticBufferReady = true;
}

void Renderer::AddObj(const std::shared_ptr<Renderable>& obj)
{
    this-> Obj.push_back(obj);
}