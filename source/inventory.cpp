#include "../header/inventory.h"


InventoryList::InventoryList()
{
    cout << "Bienvenue dans votre inventaire" << endl;
    this->new_inventory();
}
// --------------------------------------------------
InventoryList::~InventoryList()
{
    this->clear_inventory();
    cout << "Vous venez de fermer votre inventaire" << endl;
}
// --------------------------------------------------
void InventoryList::new_inventory()
{
    this->inventory = NULL;
}
// --------------------------------------------------
bool InventoryList::is_empty_inventory()
{
    if(this->inventory == NULL)return true;
    return false;
}
// --------------------------------------------------
int InventoryList::inventory_length()
{
    ListElement * copy = this->inventory;   
    if(this->is_empty_inventory())
        return this->sizeOfInventory;

    while (this->inventory != NULL)
    {
        this->sizeOfInventory++;
        this->inventory = this->inventory->nextItem;
    }

    this->inventory = copy;

    return this->sizeOfInventory;
    
}
// --------------------------------------------------
void InventoryList::print_inventory_item()
{
    if(this->is_empty_inventory())
    {
        cout << "Votre inventaire est vide !!!" << endl;
        return;
    }

    ListElement * copy = this->inventory;
    this->reset_size();
    
    int  compteur = this->inventory_length();
    int i = 0;

    cout << "[";
    while(this->inventory != NULL)
    {        
        i++;
        cout <<"("<< i << ")" << " - ";
        if (i == compteur) cout << this->inventory->item;
        else cout << this->inventory->item << ", ";
        
        this->inventory = this->inventory->nextItem;
    } 
    cout << "]" << endl;

    this->inventory = copy;
}
// --------------------------------------------------
void InventoryList::push_back_item(std::string item)
{
    ListElement * insertElement;

    insertElement = new ListElement;
    if(insertElement == NULL)
    {
        std::cerr << "echec de l'allocation dynamique" << endl;
        exit(EXIT_FAILURE);
    }

    insertElement->item = item;
    insertElement->nextItem = NULL;

    if(this->is_empty_inventory())
    {
        this->inventory = insertElement;
        return;
    }

    ListElement * temp;
    temp = this->inventory;

    while(temp->nextItem != NULL)
        temp = temp->nextItem;

    temp->nextItem = insertElement;

}
// --------------------------------------------------
void InventoryList::push_front_item(std::string item)
{
    ListElement * insertElement;

    insertElement = new ListElement;
    if(insertElement == NULL)
    {
        std::cerr << "echec de l'allocation dynamique" << endl;
        exit(EXIT_FAILURE);
    }
    insertElement->item = item;

    if(this->is_empty_inventory())
        insertElement->nextItem = NULL;
    else
        insertElement->nextItem = this->inventory;

    this->inventory = insertElement;
}
// --------------------------------------------------
void InventoryList::pop_back_item()
{
    if(this->is_empty_inventory())
        return;
    
    if(this->inventory->nextItem == NULL)
    {
        delete this->inventory;
        this->inventory = NULL;

        return;
    }

    ListElement * temp = this->inventory;
    ListElement * tempBefore = this->inventory;

    while(temp->nextItem != NULL)
    {
        tempBefore = temp;
        temp = temp->nextItem;
    }

    tempBefore->nextItem = NULL;
    delete temp;
    temp = NULL;
}
// --------------------------------------------------
void InventoryList::pop_front_item()
{
    if(this->is_empty_inventory())
        return;
    
    ListElement * insertElement;

    insertElement = new ListElement;
    if(insertElement == NULL)
    {
        std::cerr << "echec de l'allocation dynamique" << endl;
        exit(EXIT_FAILURE);
    }

    insertElement = this->inventory->nextItem;

    delete this->inventory;
    this->inventory = NULL;

    this->inventory = insertElement;
}
// --------------------------------------------------
void InventoryList::clear_inventory()
{
   if(this->is_empty_inventory())
        return;

    while (this->inventory != NULL)
    {
        this->pop_front_item();
    }
}
// --------------------------------------------------
void InventoryList::reset_size()
{
    this->sizeOfInventory = 0;
}