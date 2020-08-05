#pragma once
#include <iostream>

class LinkedList
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
  ~LinkedList() 
  {
    delete head;
    head = nullptr;
  }

public:
  void Serialize(std::ostream& os)
  {
    Node* itr;
    itr = head;

    while(itr)
    {
      os << itr->data << "->";
      itr = itr->next;
    }

    os << std::endl;
  }
  void Append(int data)
  {
    Node* node = new Node;
    node->data = data;

    if(!head)
    {
      tail = node;
      head = tail;
    }
    else
    {
      // Node* itr;
      // itr = head;

      // while(itr->next)
      // {
      //   itr = itr->next;
      // }

      tail->next = node;
      tail = node;
    }
  }
  void Insert(int data)
  {
    Node* node = new Node;
    node->data = data;

    if(!head)
    {
      head = node;
    }
    else
    {
      node->next = head;
      head = node;
    }
  }

private:
  Node* head = nullptr;
  Node* tail = nullptr;
};