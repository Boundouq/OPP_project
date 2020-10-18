#include <iostream>
#include <string>

using namespace std;

struct Data{
  double data;
  Data* next;
};

class FIFO{
  private:
    Data * head;
    Data * tail;

  public:
    FIFO();
    bool isEmpty();
    void enqueue(Data new_Data);
    double dequeue();
    void print();
};
