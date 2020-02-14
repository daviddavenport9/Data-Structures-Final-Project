#include "ItemType.h"
#include <iostream>

using namespace std;

  ItemType::ItemType(){
    
  }

 Comparison ItemType::compareTo(ItemType otherItem) const{
  if (value < otherItem.value){
    return LESS;
    }
  else if (value > otherItem.value){
    return GREATER;
    }
  else{
    return EQUAL;
    }
}

  int ItemType::getValue() const{
  return value;
}

  void ItemType::initialize(int number){
   value = number; 
}

void ItemType::print(){
  cout << value << " ";
}
