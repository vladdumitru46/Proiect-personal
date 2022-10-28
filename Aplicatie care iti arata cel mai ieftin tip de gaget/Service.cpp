#include "Service.h"


vector<Gadgets> Service::sort_by_price()
{
    auto& copy_of_gadgets_from_store = repo_gadget.get_all_gadgets_from_file();
    std::sort(copy_of_gadgets_from_store.begin(), copy_of_gadgets_from_store.end(), [](Gadgets& gadget_1, Gadgets& gadget_2)
        {
            return gadget_1.get_price() < gadget_2.get_price();
        });
    return copy_of_gadgets_from_store;
}

vector<Gadgets> Service::search_gadgets_by_name(string name_of_gadget)
{
    return repo_gadget.search_gadgets_name_in_app(name_of_gadget);
}

vector<string> Service::all_gadgets_type_in_the_store()
{
    map<string, int> all_gadgtes_types_that_apper_in_the_files;
    vector<string> gadget_types;
    for (auto gadget : repo_gadget.get_all_gadgets_from_file())
    {
        if (all_gadgtes_types_that_apper_in_the_files[gadget.get_type()] == 0)
            all_gadgtes_types_that_apper_in_the_files[gadget.get_type()]++;
    }
    for (auto gadget : all_gadgtes_types_that_apper_in_the_files)
    {
        gadget_types.push_back(gadget.first);
    }
    return gadget_types;
}

vector<string> Service::all_gadgtes_name_with_a_type_in_the_store(string type)
{
    map<string, int> all_gadgets_name_with_a_type;
    vector<string> gadget_names;
    for (auto gadget : repo_gadget.get_all_gadgets_from_file())
    {
        if (gadget.get_type() == type && all_gadgets_name_with_a_type[gadget.get_name()] == 0)
            all_gadgets_name_with_a_type[gadget.get_name()] = 1;
    }
    for (auto gadget : all_gadgets_name_with_a_type)
    {
        gadget_names.push_back(gadget.first);
    }
    return gadget_names;
}

vector<Gadgets>& Service::get_all_gadgets_from_store()
{
    return repo_gadget.get_all_gadgets_from_file();
}
