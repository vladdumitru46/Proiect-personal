#include "Tests.h"

void Tests::test_create_gadgest()
{
	Gadgets gadgets{ "SmartPhone", "Samsung", 4000, "Emag"};
	assert(gadgets.get_price() == 4000);
	assert(gadgets.get_store() == "Emag");
	assert(gadgets.get_name() == "Samsung");
	assert(gadgets.get_type() == "SmartPhone");
}

void Tests::test_search_gadget()
{
	RepositoryGadgets list_of_gadgets{ "TestFile.txt" };
	vector<Gadgets> list_of_found_gadgets = list_of_gadgets.search_gadgets_name_in_app("Samsung");
	assert(list_of_found_gadgets.size() == 4);
	try
	{
		vector<Gadgets> list_of_inexistent_gadgets = list_of_gadgets.search_gadgets_name_in_app("Samsufafafadfasang");
		assert(false);
	}
	catch (exception error)
	{
		assert(true);
	}
}

void Tests::test_sort_gadgets_by_price()
{
	RepositoryGadgets repo_gadget{ "TestFile.txt" };
	Service service_gadget{ repo_gadget };
	auto sorted_gadgtes_by_price = service_gadget.sort_by_price();
	assert(sorted_gadgtes_by_price[0].get_price() == 2000);
	assert(sorted_gadgtes_by_price[1].get_price() == 3000);
	assert(sorted_gadgtes_by_price[2].get_price() == 4000);
	assert(sorted_gadgtes_by_price[3].get_price() == 5000);
}

void Tests::test_gadget_types()
{
	RepositoryGadgets repo_gadget{ "TestFile.txt" };
	Service service_gadget{ repo_gadget };
	vector<string> gadget_types = service_gadget.all_gadgets_type_in_the_store();
	assert(gadget_types.size() == 1);
	assert(gadget_types[0] == "SmartPhone");
}

void Tests::test_gadget_names()
{
	RepositoryGadgets repo_gadget{ "TestFile.txt" };
	Service service_gadget{ repo_gadget };
	vector<string> gadget_names = service_gadget.all_gadgtes_name_with_a_type_in_the_store("SmartPhone");
	assert(gadget_names.size() == 4);
}

void Tests::run_tests()
{
	test_create_gadgest();
	test_search_gadget();
	test_sort_gadgets_by_price();
	test_gadget_types();
	test_gadget_names();
}
