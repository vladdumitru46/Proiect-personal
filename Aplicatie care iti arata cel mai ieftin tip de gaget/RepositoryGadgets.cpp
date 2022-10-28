#include "RepositoryGadgets.h"

void RepositoryGadgets::read_all_from_file()
{
	std::ifstream file_in{ file_name };
	if (!file_in.is_open())
		throw exception("The file can not be oppend!\n");
	string file_line;
	while (getline(file_in, file_line))
	{
		string type;
		string name;
		double price = 0;
		string store;
		std::stringstream file_lines{ file_line };
		string current_gadget;
		int number_of_curent_gadget = 0;
		while (getline(file_lines, current_gadget, ','))
		{
			if (number_of_curent_gadget == 0)
				type = current_gadget;
			if (number_of_curent_gadget == 1)
				name = current_gadget;
			if (number_of_curent_gadget == 2)
				price = stod(current_gadget);
			if (number_of_curent_gadget == 3)
				store = current_gadget;
			number_of_curent_gadget++;
		}
		Gadgets gadget_from_file{ type, name, price, store };
		vector_of_gadgets.push_back(gadget_from_file);
	}
	file_in.close();
}

void RepositoryGadgets::write_all_to_file()
{
	std::ofstream file_out{ file_name };
	if(!file_out.is_open())
		throw exception("The file can not be oppend!\n");
	for (auto& gadget : vector_of_gadgets)
	{
		file_out << gadget.get_type() << ',' << gadget.get_name() << ',' << gadget.get_price() << ',' << gadget.get_store() << std::endl;
	}
	file_out.close();
}

vector<Gadgets> RepositoryGadgets::search_gadgets_name_in_app(string gadget_name)
{
	vector<Gadgets> filtred_list_of_gadgets;
	for (auto gadget : vector_of_gadgets)
	{
		int ok = 1, number = 0;
		for (int j = 0; j < gadget.get_name().size(); j++)
		{
			ok = 1;
			number = 0;
			for (int i = 0; i < gadget_name.size() && ok == 1; i++)
			{
				number++;
				if (gadget.get_name()[i + j] != gadget_name[i])
				{
					ok = 0;
				}
			}
			if (ok == 1 && number == gadget_name.size())
			{
				break;
			}
		}
		if (ok == 1)
			filtred_list_of_gadgets.push_back(gadget);
	}
	if (filtred_list_of_gadgets.size() == 0)
		throw exception("We couldn't find any gadget with that name!\n");
	else
		return filtred_list_of_gadgets;
}

vector<Gadgets>& RepositoryGadgets::get_all_gadgets_from_file()
{
	return vector_of_gadgets;
}
