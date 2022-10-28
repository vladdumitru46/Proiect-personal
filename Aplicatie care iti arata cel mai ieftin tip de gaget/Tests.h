#pragma once
#include "Gageturi.h"
#include "RepositoryGadgets.h"
#include "Service.h"
#include <string>
#include <assert.h>

using std::string;
class Tests
{
public:
	void test_create_gadgest();
	void test_search_gadget();
	void test_sort_gadgets_by_price();
	void test_gadget_types();
	void test_gadget_names();
	void run_tests();
};

