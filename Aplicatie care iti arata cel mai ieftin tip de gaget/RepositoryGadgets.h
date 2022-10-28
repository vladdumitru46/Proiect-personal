#pragma once
#include "Gageturi.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <exception>
using std::vector;
using std::exception;
class RepositoryGadgets
{
private:
	vector<Gadgets> vector_of_gadgets;
	void read_all_from_file();
	void write_all_to_file();
	string file_name;
public:
	RepositoryGadgets(string file_name) noexcept : file_name{ file_name } {
		read_all_from_file();
	};
	vector<Gadgets> search_gadgets_name_in_app(string gadget_type);
	vector<Gadgets>& get_all_gadgets_from_file();
};

