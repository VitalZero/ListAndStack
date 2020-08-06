#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <chrono>

#include "LinkedList.h"
#include "Stack.h"

int main()
{

  {
    LinkedList list;

    list.Append(1);
    list.Append(2);
    list.Append(3);
    list.Append(4);
    list.Insert(10);

    std::cout << "head->next->..." << std::endl;
    list.Serialize(std::cout);

    list.Delete(3);
    list.Serialize(std::cout);
  }

  // {
  //   Stack stack;

  //   stack.Push(1);
  //   stack.Push(2);
  //   stack.Push(10);
  //   stack.Push(20);

  //   std::cout << "top->next->..." << std::endl;
  //   stack.Serialize(std::cout);
  //   std::cout << std::endl;

  //   std::cout << "peek: " << stack.Top() << std::endl;

  //   // debe sacar 20, y luego 10
  //   // pero saca 10 y luego 20
  //   std::cout << "top: " << stack.Top() << std::endl;
  //   stack.Pop();
  //   std::cout << "top: " << stack.Top() << std::endl;
  //   stack.Pop();

  //   // funciona bien, saca 2, luego 1
  //   std::cout << "top: " << stack.Top() << std::endl;
  //   stack.Pop();
  //   std::cout << "top: " << stack.Top() << std::endl;
  //   stack.Pop();

  //   // vacío
  //   std::cout << stack.Top() << std::endl;
  //   stack.Pop();
  //   std::cout << stack.Top() << std::endl;
  // }

  // std::cout << std::endl;

  //   LinkedList list1;
  // {
  //   auto start = std::chrono::steady_clock::now();


  //   for(int i = 0; i < 1000000; ++i)
  //   {
  //     list1.Append(i);
  //   }

  //   auto end = std::chrono::steady_clock::now();
  //   std::chrono::duration<float> elapsed;
  //   elapsed = end - start;

  //   std::cout << "list time 1'000,000 appends: " << elapsed.count() << " seconds"<< std::endl;

  // }

  //   LinkedList list;
  // {
  //   auto start = std::chrono::steady_clock::now();


  //   for(int i = 0; i < 1000000; ++i)
  //   {
  //     list.Insert(i);
  //   }

  //   auto end = std::chrono::steady_clock::now();
  //   std::chrono::duration<float> elapsed;
  //   elapsed = end - start;

  //   std::cout << "list time 1'000,000 inserts: " << elapsed.count() << " seconds"<< std::endl;
  // }

  //   Stack stack;
  // {
  //   auto start = std::chrono::steady_clock::now();


  //   for(int i = 0; i < 1000000; ++i)
  //   {
  //     stack.Push(i);
  //   }

  //   auto end = std::chrono::steady_clock::now();
  //   std::chrono::duration<float> elapsed;
  //   elapsed = end - start;

  //   std::cout << "stack time 1'000,000 pushes: " << elapsed.count() << " seconds" << std::endl;
  // }

  _CrtDumpMemoryLeaks();
  return 0;
}