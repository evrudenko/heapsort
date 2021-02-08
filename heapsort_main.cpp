#include "heapsort_tools.cpp"
#include "HeapSortingModule.cpp"

int main(int argc, char const *argv[]) {
	// ...

	if(argc != 2) {
		cout << "Right call: " << *argv << " filename.txt";
		return 1;
	}
	
	// Здесь тип задается вручную!
	auto v = read_array<double>(argv[1]);
	// auto v = read_array<string>(argv[1]);

	cout << "Unsorted array:" << endl;
	list_array<decltype(v)>(v);

	HeapSortingModule<decltype(v)::value_type>::sort(v);

	cout << "\nSorted array:" << endl;
	list_array<decltype(v)>(v);
	
	return 0;
}