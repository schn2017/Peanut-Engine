#include <vector>

class Node 
{
public:
  Node();
  ~Node();
private:
  Node* parentNode = nullptr;
  std::vector<Node*> m_childNodes;

  bool visible;
};