#ifndef MODEL_HPP
#define MODEL_HPP

#include <deque>
#include <memory>
#include <typeindex>
#include <unordered_map>

#include <component/Component.hpp>
#include <functional>
#include <model/Mesh.hpp>
class Model {
public:
  Model();
  ~Model();
  void Render();

  using Update = std::function<void(Model &)>;

  template <typename T> std::shared_ptr<T> get();

  void ProcessComponents();
  void SetUpdate(Update update);

private:
  std::deque<std::unique_ptr<Mesh>> _meshes;
  std::unordered_map<std::type_index, std::shared_ptr<Component>> _components;
  Update _Update = nullptr;

  friend class ModelBuilder;
};

#include <model/Model.tpp>

#endif