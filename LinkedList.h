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
      tail->next = node;
      tail = node;
    }

    size++;
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

    size++;
  }
  void Delete(int data)
  {
    Node* itr = head;
    Node* prev = nullptr;

    while(itr->next)
    {
      if(itr->data == data)
      {
        prev->next = itr->next;

        itr->next = nullptr;
        delete itr;

        size--;
        break;
      }
      prev = itr;
      itr = itr->next;
    }
  }

private:
  Node* head = nullptr;
  Node* tail = nullptr;
  int size = 0;
};