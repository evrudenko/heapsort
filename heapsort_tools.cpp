#include "heapsort_header.hpp"

// Удаление из строки лишних символов и пробелов.
string format_string(string &str) {
	size_t index = 0;

	// Циклы можно заменить одним регулярным выражением, не хватает знаний!
	while(true) {
		index = str.find("[");

		if(index == string::npos)
			break;

		str.replace(index, 1, "");
	}
	while(true) {
		index = str.find("]");

		if(index == string::npos)
			break;

		str.replace(index, 1, "");
	}
	while(true) {
		index = str.find(",");

		if(index == string::npos)
			break;

		str.replace(index, 1, "");
	}
	while(true) {
		index = str.find("'");

		if(index == string::npos)
			break;

		str.replace(index, 1, "");
	}

	auto tail_begin = unique(str.begin(), str.end(), [](char l, char r) {
		return isspace(l) && isspace(r) && l == r;
	});

	str.erase(tail_begin, str.end());

	if(str[0] == ' ')
		str.erase(0, 1);
	if(str[str.length() - 1] == ' ')
		str.erase(str.length() - 1, 1);

	return str;
}

// Чтение чисел файла в вектор.
template<typename T>
vector<T> read_array(string filename) {
	ifstream fin(filename);
	vector<T> v_res;

	if(!fin.is_open()) {
		cout << "ERRORS~!";
		return v_res;
	}

	stringstream ss;
	T buff_value;
	string buff_string;

	while(!fin.eof()) {
		getline(fin, buff_string);

		buff_string = format_string(buff_string);

		if(buff_string.length() < 1)
			continue;

		ss.str(buff_string);

		while(!ss.eof()) {
			ss >> buff_value;

			v_res.push_back(buff_value);
		}
		ss.clear();
	}

	fin.close();

	return v_res;
}

// Вывод массива(вектора) v в консоль.
template<typename T>
void list_array(const T &v) {
	for(int i = 0; i < v.size(); ++i)
		cout << v[i] << (i == v.size() - 1 ? "" : " ");
	cout << endl;
}