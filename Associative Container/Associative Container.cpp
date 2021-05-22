// Associative Container.cpp : Defines the entry point for the application.
//

#include "Associative Container.h"

int main()
{
	std::cout << "Hello CMake." << std::endl;
	std::vector<int> listNum{ 1,2,3,4,5,6,7,9 };
	std::set<int> dest;
	std::cout << "before insert \t: [" << dest.size() << "]" << "element" << std::endl;
	dest.insert(listNum.cbegin(), listNum.cend());
	std::cout << "After insert \t: [" << dest.size() << "]" << "element" << std::endl;
	std::cout << "Insert to map" << std::endl;
	std::map<std::string, size_t>  mapEl; 
	std::cout << "before insert to map \t: [" << mapEl.size() << "]" << "element" << std::endl;
	mapEl.insert(std::make_pair("michael", 34));
	std::cout << "after insert to map \t: [" << mapEl.size() << "]" << "element" << std::endl;
	std::map<std::string, size_t> word_count;
	std::string word;
	std::cout << "Please insert a word \t:[ ";
	while (std::cin>>word)
	{
		auto ret = word_count.insert({ word,1 });
		if (!ret.second) {
			++ret.first->second;
		}
		else {
			std::cout << "Delete \t:[" << "key"<< "and value" <<ret.second << "]" << std::endl;
		}
	}
	std::cout << "Result \t:["<< word_count.size() << "]" << std::endl;
	std::cout << "]" << std::endl;
	std::multimap<std::string, std::string> multiKey;
	multiKey.insert({ "michael", "c++" });
	multiKey.insert({ "michael", "my journey with Him" });
	multiKey.insert({ "stanley","c++ primer" });
	std::cout << "Implemented  of multimap \t: size [" << multiKey.size() << "]" << std::endl;
	std::cout << "Traverse the elements \t:["<<std::endl;
	for (auto& i : multiKey)
	{
		std::cout << i.first << "|" << i.second << "|"<<std::endl;
	}
	std::cout << std::endl;
	std::cout << "After erase an element \t:[";
	multiKey.erase("stanley");
	for (auto &list_num : multiKey)
	{
		std::cout << list_num.first << "|" << list_num.second << "|" << std::endl;
	}
	std::cout << "]" << std::endl;
	std::cout << "Erase all element\t:[";
	multiKey.erase(multiKey.begin(), multiKey.end());
	if(!multiKey.empty())
	{
		for (auto &list_num : multiKey)
		{
			std::cout << list_num.first << "|" << list_num.second << "|" << std::endl;
		}
	}
	else
	{
		std::cout << "Erase all element in multi key map]" << std::endl;
	}
	std::cout << "Subscripting a map \t:[";
	std::map<std::string, int> multiDef;
	multiDef["anna"] = 12;
	multiDef["jane"] = 12;
	for (auto &multi_def : multiDef)
	{
		std::cout << multi_def.first << "|" << multi_def.second << "|";
	}
	std::cout << "]" << std::endl;
	std::cout << "Call by subscript operator\t:[" << multiDef["anna"] << std::endl;
	std::cout << "fetch the element and add 1 to current value\t:[ " << ++multiDef["anna"] << std::endl;

	

	
	
	
	

	
	return 0;

}
