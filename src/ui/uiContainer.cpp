#include "ui/uiContainer.h"

UIContainer::UIContainer() : m_children(new UIElement *[m_capacity]) {}

UIContainer::~UIContainer() {
  for (std::size_t i = 0; i < m_size; ++i) {
    delete m_children[i];
  }
  delete[] m_children;
}

void UIContainer::add(UIElement *child) {
  if (child == nullptr) {
    return;
  }
  m_children[m_size++] = child;
}

void UIContainer::update(float dt) {
  for (std::size_t i = 0; i < m_size; i++) {
    m_children[i]->update(dt);
  }
}

void UIContainer::draw(Renderer &renderer) const {
  for (std::size_t i = 0; i < m_size; i++) {
    m_children[i]->draw(renderer);
  }
}
