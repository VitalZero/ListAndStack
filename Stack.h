#pragma once
#include <iostream>

class Stack
{
private:
  class Node
  {
  public:
    Node* next = nullptr;
    int data = -1;
    ~Node() 
    {
      delete next;
      next = nullptr;
    }
  };

public:
  ~Stack()
  {
    delete top;
    top = nullptr;
  }

public:
  bool Empty()
  {
    return size == 0;
  }
  void Pop()
  {
    if(size > 0)
    {
      Node* tmp;
      tmp = top;

      if(top->next)
      {
       top = top->next;
      }
      else
      {
        top = nullptr;
      }
      
      tmp->next = nullptr;
      delete tmp;
      tmp = nullptr;
      
      size--;
    }
  }
  void Push(int data)
  {
    Node* node = new Node;
    node->data = data;

    if(!top)
    {
      top = node;
    }
    else
    {
      node->next = top;
      top = node;
    }

    size++;
  }
  int Top() const
  {
    if(size > 0)
    {
      return top->data;
    }
    
    return -1;
  }
  void Serialize(std::ostream& os)
  {
    Node* itr;
    itr = top;
    
    while(itr)
    {
      os << itr->data << "->";
      itr = itr->next;
    }
  }
  int Size() const
  {
    return size;
  }

private:
  Node* top = nullptr;
  int size = 0;
};