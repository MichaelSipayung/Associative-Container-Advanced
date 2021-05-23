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
	while (std::cin >> word)
	{
		auto ret = word_count.insert({ word,1 });
		if (!ret.second) {
			++ret.first->second;
		}
		else {
			std::cout << "Delete \t:[" << "key" << "and value" << ret.second << "]" << std::endl;
		}
	}
	std::cout << "Result \t:[" << word_count.size() << "]" << std::endl;
	std::cout << "]" << std::endl;
	std::multimap<std::string, std::string> multiKey;
	multiKey.insert({ "michael", "c++" });
	multiKey.insert({ "michael", "my journey with Him" });
	multiKey.insert({ "stanley","c++ primer" });
	std::cout << "Implemented  of multimap \t: size [" << multiKey.size() << "]" << std::endl;
	std::cout << "Traverse the elements \t:[" << std::endl;
	for (auto& i : multiKey)
	{
		std::cout << i.first << "|" << i.second << "|" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "After erase an element \t:[";
	multiKey.erase("stanley");
	for (auto& list_num : multiKey)
	{
		std::cout << list_num.first << "|" << list_num.second << "|" << std::endl;
	}
	std::cout << "]" << std::endl;
	std::cout << "Erase all element\t:[";
	multiKey.erase(multiKey.begin(), multiKey.end());
	if (!multiKey.empty())
	{
		for (auto& list_num : multiKey)
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
	for (auto& multi_def : multiDef)
	{
		std::cout << multi_def.first << "|" << multi_def.second << "|";
	}
	std::cout << "]" << std::endl;
	std::cout << "Call by subscript operator\t:[" << multiDef["anna"] << std::endl;
	std::cout << "fetch the element and add 1 to current value\t:[ " << ++multiDef["anna"] << std::endl;
	std::set<int> setNum{ 1,2,3,4,5,67,9 };
	setNum.find(1);
	std::cout << "Finding element in map" << std::endl;
	std::map<std::string, int> mapNum;
	mapNum.insert(std::make_pair("michael", 987666));
	mapNum.insert(std::make_pair("john", 787668));
	if (mapNum.find("john") == mapNum.end())
	{
		std::cout << "find john and his number\t:[" << mapNum["john"] << std::endl;
	}
	else {
		std::cout << "john not exist" << std::endl;
	}
	std::map<std::string, int> mapTest;
	mapTest.insert(std::make_pair("michael", 123));
	mapTest.insert(std::make_pair("michael test", 1123));
	mapTest.insert(std::make_pair("michael pair", 2123));

	std::cout << "For multimap" << std::endl;
	std::multimap<std::string, int>  multimapNum;
	multimapNum.insert(std::make_pair("medan", 987767));
	multimapNum.insert(std::make_pair("medan", 887767));
	multimapNum.insert(std::make_pair("medan", 687767));
	multimapNum.insert(std::make_pair("jakarta", 687767));


	std::string nameToF = "medan";
	auto count = multimapNum.count(nameToF);
	auto findMichael = multimapNum.find(nameToF);
	std::cout << "show michael number \t:[";
	while (count)
	{
		std::cout << findMichael->second << "|";
		++findMichael;
		--count;
	}
	std::cout << "]" << std::endl;

	auto anotherTest = 98766;
	std::map<int, std::string> another;
	another.insert(std::make_pair(98766, "Michael"));
	another.insert(std::make_pair(98764, "John"));
	auto findTestNum = another.find(anotherTest);
	if (!another.empty())
	{
		if (findTestNum->first == anotherTest)
		{
			std::cout << "Find number \t: [" << findTestNum->first << "name" << findTestNum->second << "]" << std::endl;
		}
	}
	else
	{
		std::cout << "test not success find any data" << std::endl;
	}
	std::cout << "Test map ->  lower_bound and upper _bound" << std::endl;
	std::string findCh("desk");
	std::string findCh2("don");
	std::string findCh3("donch");

	std::multimap<std::string, std::string> authorIs;
	authorIs.insert(std::make_pair("michael", "Math-8797"));
	authorIs.insert(std::make_pair("michael", "lin-8797"));
	authorIs.insert(std::make_pair("dony", "cal-8797"));
	authorIs.insert(std::make_pair("jack", "cal-8797"));
	std::cout << "Apply lower_bound and upper bound \t:[ ";
	for (auto beg = authorIs.lower_bound(findCh), end = authorIs.upper_bound(findCh); beg != end; ++beg)
	{
		std::cout << beg->second << "|";
	}
	std::cout << "]" << std::endl;
	std::cout << "Test lower_bound" << std::endl;
	auto fin_low = authorIs.lower_bound(findCh2);
	auto fin_up = authorIs.upper_bound(findCh3);
	std::cout << "if up and lower return to the same iterator, the given key is not in the container"\
		<< std::endl;
	std::cout << "Size before \t:[" << authorIs.size() << "]" << std::endl;
	std::cout << "if find in lower bound write a key \t:[" << fin_low->second << "]" << std::endl;
	std::cout << "if find in upper bound write a key \t:[" << fin_up->second << "]" << std::endl;
	std::cout << "if not found in lower-bound ,  write result \t:[" << fin_low->second << "]" << std::endl;
	std::cout << "if not found in upper-bound ,  write result \t:[" << fin_low->second << "]" << std::endl;
	std::cout << "Size after \t:[" << authorIs.size() << "]" << std::endl;
	std::cout << "Using equal range " << std::endl;
	for (auto pos = authorIs.equal_range(findCh); pos.first != pos.second; ++pos.first) {
		std::cout << pos.first->second << "|"; //pos.first = refer to begiin 
	}

	std::cout << "]" << std::endl;
	std::cout << "Unordered Map" << std::endl;
	std::unordered_map<std::string, int>authorAge;
	authorAge.insert(std::make_pair("michael", 23));
	authorAge.insert(std::make_pair("joy", 29));
	authorAge.insert(std::make_pair("jane", 26));
	authorAge.insert(std::make_pair("hil", 29));
	std::cout << "Result \t:[";
	for (auto& i : authorAge)
	{
		std::cout << i.first << "|" << i.second <<"| ";
	}
	std::cout << "]" << std::endl;
	std::cout << "Compare the result with a map " << std::endl;
	std::map<std::string, int> autAgeN;
	autAgeN.insert(std::make_pair("michael", 23));
	autAgeN.insert(std::make_pair("joy", 29));
	autAgeN.insert(std::make_pair("jane", 26));
	autAgeN.insert(std::make_pair("hil", 29));
	std::cout << "Result \t:[";
	for (auto& i : autAgeN)
	{
		std::cout << i.first << "|" << i.second << "|";
	}
	std::cout << "]" << std::endl;




	return 0;

}