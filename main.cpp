#include "header/inventory.h"

int main ()
{
    InventoryList Louis;

    Louis.push_front_item("marteau");
    Louis.push_front_item("machette");
    Louis.push_back_item("chette");

    cout << Louis.inventory_length() << endl;
    Louis.print_inventory_item();
   
    return 0;
}