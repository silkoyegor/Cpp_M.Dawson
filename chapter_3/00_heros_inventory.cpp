#include <iostream>
#include <string>
using namespace std;

class Equipment {
private:
  static const int MAX_ITEMS = 10;
  string inventory[MAX_ITEMS];
  int numItems = 0;
public:
  //Equipment(int size) { MAX_ITEMS = size; }
  void add_item(string item_name)
  {
    cout << "\tYou find " << item_name << ".\n";
    if (numItems < MAX_ITEMS) {
     inventory[numItems++] = item_name;
    } else {
     cout << "You have too may items and can't carry another.\n";
    }
  }
  
  void show_inventory() 
  {           
    cout << "\nYour items:\n";
    for (int i = 0; i < numItems; ++i) {
       cout << "  " << inventory[i] << endl;
    }
    cout << endl;
  }

  void change_item(int slot, string item) 
  {
    if (slot < numItems) {
      cout << "\tYou trade your " << inventory[slot] << " for " << item << ".\n";
      inventory[slot] = item;
    } else {
      cout << "This slot is empty, u can change only exists slots.\n";
    }
  }
};



int main()
{
  cout << "\t\tHero's inventory\n\n";
  Equipment equip;

  equip.add_item("staff");
  equip.add_item("silk robe");
  equip.add_item("wand");
  equip.show_inventory();
 
  equip.change_item(0, "epic staff");  
  equip.show_inventory();
  
  equip.add_item("healing potion");
  equip.show_inventory();

  return 0;
}
