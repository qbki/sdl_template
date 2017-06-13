#include "../headers/Object.h"
#include <glm/gtc/matrix_transform.hpp>

Object::Object() noexcept :
    m_color(0.f, 0.f, 0.f),
    m_scale(1.f, 1.f, 1.f),
    m_rotation(0.f, 0.f, 0.f),
    m_position(0.f, 0.f, 0.f)
    //m_matrix(1.f)
    //m_viewMatrix(1.f),
    //m_children()
{}


void Object::update(float elapsed_time) noexcept {
    if (m_updateCb) {
        m_updateCb(*this, elapsed_time);
    }

    //for (auto& child : m_children) {
        //child->update(elapsed_time, m_viewMatrix);
    //}
};


//void Object::render(const glm::mat4 &P) const noexcept {
    //for (auto& child : m_children) {
        //child->render(P);
    //}
//}


glm::mat4 Object::getWorldTransform() const noexcept {
    using namespace glm;

    mat4 _scale = scale(mat4{1.f}, m_scale);
    mat4 _rotate =
        rotate(mat4{1.f}, m_rotation.x, {1.f, 0.f, 0.f}) *
        rotate(mat4{1.f}, m_rotation.y, {0.f, 1.f, 0.f}) *
        rotate(mat4{1.f}, m_rotation.z, {0.f, 0.f, 1.f});
    mat4 _translate = translate(mat4{1.f}, m_position);

    return _scale * _rotate * _translate;
}
