#include "sorting.h"
//  Selection Sort, Insertion Sort, Bubble Sort, Shaker Sort, Shell Sort, Heap Sort, Merge Sort, Quick Sort, Counting Sort, Radix Sort, and Flash Sort.
vector<string> algos = {"selection-sort", "insertion-sort", "bubble-sort", "shaker-sort", "shell-sort", "heap-sort", "merge-sort", "quick-sort", "counting-sort", "radix-sort", "flash-sort"};
vector<string> output_parameters = {"-time", "-comp", "-both"};
vector<string> input_orders = {"-rand", "-sorted", "-rev", "-nsorted"};
//function to check if a string is a number
bool isNumber(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

void genAndWrite(string filename, int n, int dataType) {
    ofstream file;
    file.open(filename);
    int *a = new int[n];
    GenerateData(a, n, dataType);
    file << n << "\n";
    for (int i = 0; i < n; i++) {
        file << a[i] << " ";
    }
    file.close();
}

void processSort(vector<string> algs, string input_file, string output_params, int flag = 0) {

    vector<Record> result;

    for (int i = 0; i < algs.size(); ++i) {
        
        ifstream file;
        file.open(input_file);
        int n;
        file >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++) {
            file >> a[i];
        }
        file.close();


        string alg = algs[i];
        Record record;
        if (alg == "selection-sort") {
            record = getRecord(a, n, selectionSort, selectionSort);
        }
        if (alg == "insertion-sort") {
            record = getRecord(a, n, insertionSort, insertionSort);
        }
        if (alg == "bubble-sort") {
            record = getRecord(a, n, bubbleSort, bubbleSort);
        }
        if (alg == "shaker-sort") {
            record = getRecord(a, n, shakerSort, shakerSort);
        }
        if (alg == "shell-sort") {
            record = getRecord(a, n, shellSort, shellSort);
        }
        if (alg == "heap-sort") {
            record = getRecord(a, n, heapSort, heapSort);
        }
        if (alg == "merge-sort") {
            record = getRecord(a, n, mergeSort, mergeSort);
        }
        if (alg == "quick-sort") {
            record = getRecord(a, n, quickSort, quickSort);
        }
        if (alg == "counting-sort") {
            record = getRecord(a, n, countingSort, countingSort);
        }
        if (alg == "radix-sort") {
            record = getRecord(a, n, radixSort, radixSort);
        }
        if (alg == "flash-sort") {
            record = getRecord(a, n, flashSort, flashSort);
        }
        result.push_back(record);

        if (algs.size() == 1 && flag == 0) {
            ofstream ofs;
            ofs.open("output.txt");
            ofs << n << "\n";
            for (int i = 0; i < n; i++) {
                ofs << a[i] << " ";
            }
        }

        delete[] a;
    }

    if (output_params == "-time" || output_params == "-both" || output_params == "") {
        cout << "Running time: ";
        for (int i = 0; i < result.size(); i++) {
            if (i != result.size() - 1) cout << result[i].time << " | "; else cout << result[i].time;
        }
        cout << "\n";
    }

    if (output_params == "-comp" || output_params == "-both" || output_params == "") {
        cout << "Comparisons: ";
        for (int i = 0; i < result.size(); i++) {
            if (i != result.size() - 1) cout << result[i].comparison << " | "; else cout << result[i].comparison;
        }
        cout << "\n\n";
    }
    
}

void processArg(int argc, char* argv[]) {
    string mode = "";
    vector<string> algs;
    int input_size = 0;
    string input_order = "";
    string input_path = ""; //use this if input_size and input_order not specified
    string output_params = ""; //only apply to mode -a
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0) mode = "-c";
        else if (strcmp(argv[i], "-a") == 0) mode = "-a";

        else if (find(algos.begin(), algos.end(), argv[i]) != algos.end()) {
            algs.push_back(argv[i]);
        }

        else if (find(output_parameters.begin(), output_parameters.end(), argv[i]) != output_parameters.end()) {
            output_params = argv[i];
        }

        else if (isNumber(argv[i])) {
            input_size = stoi(argv[i]);
        }

        else if (find(input_orders.begin(), input_orders.end(), argv[i]) != input_orders.end()) {
            input_order = argv[i];
        } 
        
        else if (i != 0) {
            input_path = argv[i];
        }
    }

    if (mode == "") {
        cout << "Error: No mode specified\n";
        return;
    }

    if (algs.empty()) {
        cout << "Error: No algorithm specified\n";
        return;
    }

    if (mode == "-a") {
        cout << "ALGORITHM MODE\n";
    } else {
        cout << "COMPARISON MODE\n";
    }

    //output algs list
    cout << "Algorithms: ";
    for (int i = 0; i < algs.size(); i++) {
        if (i != algs.size() - 1) cout << algs[i] << " | "; else cout << algs[i];
    }
    cout << "\n";


    if (input_size != 0) {
    cout << "Input size: " << input_size << "\n";
    if (input_order != "") {
        cout << "Input order: " << input_order << "\n";
        cout << "--------------------\n";
        genAndWrite("input.txt", input_size, distance(input_orders.begin(), find(input_orders.begin(), input_orders.end(), input_order)));
        processSort(algs, "input.txt", output_params);
    } else {
        //run all orders, each order output to input_x.txt with x is datatype
        for (int i = 0; i < input_orders.size(); i++) {
            cout << "Input order: " << input_orders[i] << "\n";
            cout << "--------------------\n";
            int j;
            if (i == 0) j = 1; //random
            if (i == 1) j = 3; //sorted
            if (i == 2) j = 4; //rev
            if (i == 3) j = 2; //nsorted
            genAndWrite("input_" + to_string(j) + ".txt", input_size, i);
            processSort(algs, "input_" + to_string(j) + ".txt", output_params, 1);
        }
    }
    } else { //no input size, run from file
        ifstream file;
        file.open(input_path);
        if (!file) {
            cout << "Error: File not found\n";
            return;
        }
        int n; file >> n;
        file.close();
        cout << "Input file: " << input_path << "\n";
        cout << "Input size: " << n << "\n";
        cout << "--------------------\n";
        processSort(algs, input_path, output_params);
    }

    /*cout << "Mode: " << mode << "\n";
    cout << "Algorithms: ";
    for (int i = 0; i < algs.size(); i++) {
        cout << algs[i] << " ";
    }
    cout << "\n";
    cout << "Input size: " << input_size << "\n";
    cout << "Input order: " << input_order << "\n";
    cout << "Input path: " << input_path << "\n";
    cout << "Output parameters: " << output_params << "\n";*/



    return;
}


template <class T>
void HoanVi(T &a, T &b) {
	T x = a;
	a = b;
	b = x;
}

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n) {
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i ++)
	{
		int r1 = rand()%n;
		int r2 = rand()%n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType) {
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}