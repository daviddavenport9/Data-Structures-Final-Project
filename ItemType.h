#ifndef ITEMTYPE_H
#define ITEMTYPE_H

enum Comparison {LESS, EQUAL, GREATER };

class ItemType{

public : 
  ItemType();
  Comparison compareTo(ItemType) const;
  int getValue() const;
  void initialize(int number);
  void print();
  
  
private:
  int value;
};
#endif
