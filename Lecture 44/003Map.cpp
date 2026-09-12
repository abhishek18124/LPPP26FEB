#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main() {

	// unordered_map<string, string> capitalMap;
	map<string, string> capitalMap;

	cout << capitalMap.size() << endl;

	capitalMap["India"] = "New Delhi";
	capitalMap["India"] = "Mumbai";

	// capitalMap.insert({"India", "New Delhi"});

	capitalMap["China"] = "Bejing";
	capitalMap["Russia"] = "Moscow";
	capitalMap["Brazil"] = "Sao Paulo";
	capitalMap["Russia"] = "St. Petersberg";

	cout << capitalMap.size() << endl;

	for (pair<string, string> p : capitalMap) {
		string countryName = p.first;
		string countryCapital = p.second;
		cout << countryName << " " << countryCapital << endl;
	}

	cout << endl;

	capitalMap.erase("India");

	cout << capitalMap.size() << endl;

	for (pair<string, string> p : capitalMap) {
		string countryName = p.first;
		string countryCapital = p.second;
		cout << countryName << " " << countryCapital << endl;
	}

	cout << endl;

	capitalMap["Bharat"] = "Indraprastha";

	cout << capitalMap.size() << endl;

	// for (pair<string, string> p : capitalMap) {
	// 	string countryName = p.first;
	// 	string countryCapital = p.second;
	// 	cout << countryName << " " << countryCapital << endl;
	// }

	// cout << endl;

	for (auto [countryName, countryCapital] : capitalMap) {
		cout << countryName << " " << countryCapital << endl;
	}

	capitalMap["Australia"] = "Canberra";

	string country = "Australia";

	if (capitalMap.count(country)) {
		// country exists in the map<>
		cout << "capital of " << country << " = " << capitalMap[country];
	} else {
		// country doesn't exist in the map<>
		cout << country << " is not in the map<>" << endl;
	}

	cout << endl;

	if (capitalMap.find(country) != capitalMap.end()) {
		// country exists in the map<>
		cout << "capital of " << country << " = " << capitalMap[country];
	} else {
		// country doesn't exist in the map<>
		cout << country << " is not in the map<>" << endl;
	}

	return 0;

}