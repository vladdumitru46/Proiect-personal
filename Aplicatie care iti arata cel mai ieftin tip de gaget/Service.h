#pragma once
#include "RepositoryGadgets.h"
#include <algorithm>
#include <map>
using std::map;
class Service
{
private: 
	RepositoryGadgets& repo_gadget;
public:
	Service(RepositoryGadgets& repo_gadget)noexcept : repo_gadget{ repo_gadget } {};
	vector<Gadgets> sort_by_price();
	vector<Gadgets> search_gadgets_by_name(string type_of_gadget);
	vector<string> all_gadgets_type_in_the_store();
	vector<string> all_gadgtes_name_with_a_type_in_the_store(string type);
	vector<Gadgets>& get_all_gadgets_from_store();
};

