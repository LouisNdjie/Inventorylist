#pragma once

#include<iostream>
using  std::cout;
using  std::cin;
using  std::endl;


class InventoryList
{
    //---------------------------------attributs
    private :
        struct ListElement
        {
            std::string item;
            ListElement * nextItem;
        };

        ListElement * inventory;
        int sizeOfInventory = 0;

    // --------------------------------methodes
    public:
        InventoryList(); //contructeur
        
        void new_inventory();
        bool is_empty_inventory();
        int inventory_length();
        void print_inventory_item();
        void push_back_item(std::string);
        void push_front_item(std::string);
        void pop_back_item();
        void pop_front_item();
        void clear_inventory();
        ~InventoryList(); //destructeur
    private:
        void reset_size();

    

};