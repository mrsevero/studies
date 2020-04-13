#ifndef NATURAL_H
#define NATURAL_H

class Natural{
  
  private:
    unsigned int value;

  public:
    Natural(int v);
    ~Natural();
    Natural suc();
    Natural soma(Natural n);
    unsigned int getValue();
    Natural mult(Natural n);
};

#endif