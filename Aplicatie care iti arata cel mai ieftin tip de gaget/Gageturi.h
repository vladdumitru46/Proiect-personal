#pragma once
#include <string>
using std::string;


class Gadgets{
private:
	string type;
	string name;
	double price;
	string store;
public:
	Gadgets(string type, string name, double price, string store) noexcept : type{ type }, name{ name }, price{ price }, store{ store }{};
	Gadgets(const Gadgets& ot) : type{ ot.type }, name{ ot.name }, price{ ot.price }, store{ ot.store }{};
	string get_type();
	string get_name();
	double get_price();
	string get_store();
};

