// Make Sure That bits/stdc++.h works or not. If not then set it up//
// Program made on Windows 10//
// Code is written and tested on Visual Studio 2019 C++//
// Code performs queries on given file database//
#include<bits/stdc++.h>   // Contains All Libraries Required
using namespace std;

template<typename T>// output stream overloaded for vectors
ostream& operator <<(ostream& cout, const vector<T>& V) { for (auto x : V)cout << x; cout << "\n"; return cout; }

// Structure Head Contains Heading column For structres Courses, Grades, CseStudents
struct Head {
	string Courses = "CourseID  CourseName\n";
	string Grades = "RollNo     CourseID  Grade\n";
	string CSEStudents = "RollNo     StudentName\n";
	Head() { ; }      // Empty Constructor
};
//Structure Course contains CourseID, CourseName
struct Courses {
	string CourseID, CourseName;
	Courses() { ; }               // Empty Constructor
	string column_name() {
		return Head().Courses;         // return Heading Column of Output
	}
	int Code(string s)       // Return Codeword for different string to compare efficiently
	{
		if (s == "CourseID")return 0;
		else if (s == "CourseName")return 1;
		else return -1;     // No element with name s is present
	}
	string& get(const int& CodeWord)     // return Value as per Codeword
	{
		switch (CodeWord)
		{
		case 0: return this->CourseID;
		default: return this->CourseName;
		}
	}
};
//structure Grades contains RollNo, CourseID, Grade
struct Grades {
	string RollNo, CourseID, Grade;
	Grades() { ; }            // Empty constructor
	string column_name() {
		return Head().Grades;         // return Heading Column of Output
	}
	int Code(string s)       // Return Codeword for different string to compare efficiently
	{
		if (s == "RollNo")return 0;
		else if (s == "CourseID")return 1;
		else if (s == "Grade")return 2;
		else return -1;      // No element with name s is present
	}
	string& get(const int& CodeWord)       // return Value as per Codeword
	{
		switch (CodeWord)
		{
		case 0: return this->RollNo;
		case 1: return this->CourseID;
		default: return this->Grade;
		}
	}
};
// structure CSEStudents Containing RollNo, StudentName
struct CSEStudents {
	string RollNo, StudentName;
	CSEStudents() { ; }        // Empty Constructor
	string column_name() {
		return Head().CSEStudents;            // return Heading Column of Output
	}
	int Code(string s)       // Return Codeword for different string to compare efficiently
	{
		if (s == "RollNo")return 0;               
		else if (s == "StudentName")return 1;
		else return -1;      // No element with name s is present
	}
	string& get(const int& CodeWord)       // return Value as per Codeword
	{
		switch (CodeWord)           
		{
		case 0: return this->RollNo;
		default: return this->StudentName;
		}
	}
};

// Overloaded Input and Output Streams for structures  CSEStudents, Grades, and Courses

	bool operator>> (istream & cin, Courses& courses)
	{
		string str, T;
		getline(cin, str);        // inputing whole line
		if (!str.size())return 0;            // empty line
		stringstream X(str);           // stringstreaming
		getline(X, courses.CourseID,',');          // partition on basis of ','
		getline(X, courses.CourseName, ',');       // partition on basis of ','
		X = (stringstream)courses.CourseID;        // Stringstreaming
		X >> courses.CourseID;
		if (!courses.CourseID.size())return 0;     // if CourseID not there 
		X = (stringstream)courses.CourseName;      //  stringstreaming
		courses.CourseName = "";                   // initialising to empty string
		while (X >> T)courses.CourseName += T+" ";     // Taking Whole Name
		if (!courses.CourseName.size())return 0;      // If no name given
		courses.CourseName.pop_back();             // popping last space charachter
		return 1;                // Successfully taken input
	}
	ostream& operator<<(ostream& cout, const Courses& courses)
	{
		cout << courses.CourseID << "   " << courses.CourseName<<"\n";   // cout overloaded for Courses
		return cout;
	}
	
	bool operator >>(istream & cin, Grades & grades)
	{
		string str, T;
		getline(cin, str);                 // Taking whole line
		if (!str.size())return 0;          // Empty line
		stringstream X(str);               // stringstreaming
		getline(X, grades.RollNo,',');          // partition on basis of ','
		getline(X, grades.CourseID, ',');       // partition on basis of ','
		getline(X, grades.Grade, ',');          // partition on basis of ','
		X = (stringstream)grades.RollNo; X >> grades.RollNo;            // Extracting Roll no
		if (!grades.RollNo.size())return 0;                             // RollNo empty
		X = (stringstream)grades.CourseID; X >> grades.CourseID;        // Extracting CourseID
		if (!grades.CourseID.size())return 0;                           // CourseID empty
		X = (stringstream)grades.Grade; X >> grades.Grade;              // Extracting Grade
		if (!grades.Grade.size())return 0;                              // Grade empty
		return 1;                           // Successfully taken input
	}
	ostream& operator <<(ostream & cout, const Grades & grades)
	{
		cout << grades.RollNo << "  " << grades.CourseID << "   " << grades.Grade<<"\n";    // cout overloaded for Grades
		return cout;
	}

	bool operator >>(istream & cin, CSEStudents & CSEstudents)
	{
		string str, T;
		getline(cin, str);            // Taking whole line
		if(!str.size())return 0;      // Empty line
		stringstream X(str);          // stringstreaming
		getline(X, CSEstudents.RollNo, ',');               // partition on basis of ','
		getline(X, CSEstudents.StudentName, ',');          // partition on basis of ','
		X = (stringstream)CSEstudents.RollNo; X >> CSEstudents.RollNo;          // Extracting RollNo
		if (!CSEstudents.RollNo.size())return 0;            // RollNo not given
		X = (stringstream)CSEstudents.StudentName;          // Extracting Student Name
		CSEstudents.StudentName = "";                 // initialising with empty string
		while (X >> T)CSEstudents.StudentName += T + " ";      // Taking whole name
		if (!CSEstudents.StudentName.size())return 0;          // Empty name
		CSEstudents.StudentName.pop_back();              // popback last space
		return 1;                      // Successfully taken input
	}
	ostream& operator <<(ostream & cout, const CSEStudents & CSEstudents)
	{
		cout << CSEstudents.RollNo << "  " << CSEstudents.StudentName<<"\n";     // cout overloaded for CSEStudents
		return cout;
	}

// Checks whether ';' present at correct place
bool check_line(string& str)
{
	int i = 0;
	while (i < (int)str.size() && str[i] != ';')++i;         // Finding first occurrence of ';'
	if(i>=(int)(str.size()) || i==0)return 0;           // Checking whether ';' present or not
	if (str[i - 1] == ' '|| str[i-1]=='\t')return 0;                // Checking for nospace before ';' if present then invalid
	str.resize(i+1);
	str.shrink_to_fit();
	return 1;                // Return true
}

template<typename T>                 // Takes input from File and store into Vector V
void INPUT(vector<T>& V, istream& cin)
{
	string head;
	while(!head.size() && getline(cin, head));          // Taking Column Names    
	while (cin) {
		T element=T();                 // Temperory Element
		if(cin >> element)V.push_back(element);      // Taking Input with overloaded cin
	}
}

template<typename T>      // Merges two sorted vectors
void Merge(vector<T>& a, const int& CodeWord, const int& left, const int& right)
{
	vector<T> b(right-left+1);    // Temperory vector
	int mid = left + ((right - left) >> 1);
	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <=right)              // merging
	{
		if (a[i].get(CodeWord)<=a[j].get(CodeWord))b[k++] = a[i++];
		else b[k++] = a[j++];
	}
	while (i <= mid)b[k++] = a[i++];               // elements left
	while (j <=right)b[k++] = a[j++];              // elements left
	for (i = 0; i < (int)b.size(); ++i)a[i + left] = b[i];      // updating vector  passed
}

template<typename T>      // Recursive Merge Sort algorithm
void MergeSort(vector<T>& a, const int& CodeWord, const int left, const int right) {
	if (left == right)return;      // Base condition (only one element)
	int mid = (left + ((right - left) >> 1));
	MergeSort(a, CodeWord, left, mid);                 // Sorting left half
	MergeSort(a, CodeWord, mid + 1, right);            // Sorting right half
	Merge(a, CodeWord, left, right);                   // Merging left and right half
}

template<typename T>      // Creates New vector = passed vector, calls MergeSort on new vector and returns New vector
vector<T> MergeSortUtil(vector<T>& a, const int& CodeWord)
{
	vector<T> b = a;     // Creating New vector
	MergeSort(b, CodeWord, 0, (int)a.size() - 1);           // Calling MergeSort on New vector
	return b;            // Returning New vector
}

template<typename T>      // Iterative Binary Search and returns the index of leftmost occurrence of Keyword. Returns -1 if not present
int BSearch(vector<T>& a, const int& CodeWord, const string& Keyword)
{
	int left_idx = 0, right_idx = (int)a.size() - 1;
	while (left_idx <= right_idx)
	{
		int mid = left_idx + ((right_idx - left_idx) >> 1);
		if (a[mid].get(CodeWord) == Keyword) {                     // Keyword matched
			if (right_idx==left_idx)return left_idx;               // If only index left the return
			else right_idx = mid;                                  // Choosing left half without loosing the current index
		}       
		else if (a[mid].get(CodeWord) < Keyword) { left_idx = mid + 1; }           // Choosing right half
		else right_idx = mid - 1;              // Choosing left half
	}
	return -1;        // If not present
}

template<typename T>    // Makes New vector and do BSearch on it after sorting it
vector<T> BSearchUtil(vector<T>& a, const int& CodeWord, const string& Keyword)
{
	vector<T> b = a;                   // New Vector
	MergeSort(b, CodeWord, 0, (int)a.size() - 1);                // Sorting New vector    
	int lower_bound_idx=BSearch(b, CodeWord, Keyword);           // Calling Bsearch
	
	if (lower_bound_idx == -1)return vector<T> ();               // If not Present return empty vector
	
	vector<T> V;                 // Make temporary vector V 
	while (lower_bound_idx<(int)a.size() && b[lower_bound_idx].get(CodeWord) == Keyword) {
		V.push_back(b[lower_bound_idx++]);            // V contains all the information with current KeyWord
	}

	return V;             // All occurrences returned
}

template<typename T>    // Performs Query SORTBY on coursename V
void SORTBY(vector<T>& V, stringstream& X)
{
	string str;
	X >> str;
	if (*(--str.end()) != ';'){ cout << "Invalid! ';' missing\n"; return; }       //Syntax error
	getline((stringstream)str, str, ';');
	if (T().Code(str) == -1) { cout<<"Invalid! wrong input\n"; return; }        //Syntax error
	cout << T().column_name();         // heading column
	cout << MergeSortUtil(V, T().Code(str));
}

template<typename T>    // Performs Query WHERE on coursename V
void WHERE(vector<T>& V, stringstream& X)
{
	string str,str2;
	while (!str.size() && getline(X, str, ' '));         
	getline(X, str2);
	if (str2.size())str += " " + str2;        
	str += str2;
	
	X = (stringstream)str;
	getline(X,str,';');               // partion on basis of ';'
	
	X=(stringstream)str;
	string U = str;
	getline(X, str, '=');             // partion on basis of '='
	
	if (str.size()==U.size() || T().Code(str) == -1) { cout << "Invalid! Either wrong input or space before '='\n"; return; } // Syntax error
	
	U = str;
	getline(X, str, '=');
	
	if (str.size() == 0) { cout << "Invalid! Either wrong input or space before '='\n"; return; }  //Syntax error
	if (str[0] == ' ' || str[0] == '\t') { cout << "Invalid! space before '=' \n"; return; }    // Suntax error
	
	cout << T().column_name();             //Column Head
	cout<<BSearchUtil(V, T().Code(U), str);      
}

template<typename T>    // Checks whether the condition is SORTBY or WHERE
void Condition(vector<T>& V, stringstream& X)
{
	string str;
	X >> str;
	if (str == ";") { cout << "Invalid! No space before ';'\n"; return; }
	else if (str == "WHERE") { WHERE(V, X); return; }
	else if (str == "SORTBY") { SORTBY(V, X); return; }
	else { cout << "No match found for " << str << " \n"; return; }     
}

// Takes Queries
void Queries(vector<Courses>& courses, vector<Grades>& grades, vector<CSEStudents>& CSEstudents)
{
	// If StudentName, RollNo, etc... not present then empty table is shown
	string str,T;
	bool f = 0;
	while (!str.size() && getline(cin, str));
	for (int i = 0; i < (int)str.size(); ++i)if (str[i] == '\t')str[i] = ' ';
	if (!check_line(str)) { cout << "Invalid! ';' not present or space before ';'\n"; return; }  // Checking for ';'
	stringstream X(str);
	X >> str;
	if (str != "SHOW") { cout << "Invalid! CASE SENSITIVE\n"; return; }                 // invalid Query
	X >> str;
	T = str;
	getline((stringstream)str,str,';');                      // removing semicolon
	if (str.size() != T.size())f = 1;                        // Type a or tyde d query
	if(str=="csestudents"){
		if (f)  cout << Head().CSEStudents << CSEstudents;      // type a query
		else  Condition(CSEstudents,X);              // type b or c query
	}
	else if(str=="grades"){
		if (f)cout << Head().Grades << grades;         // type a query
		else  Condition(grades,X);                   // type b or c query
	}
	else if (str == "courses") {
		if (f) cout << Head().Courses << courses;       // type a query
		else  Condition(courses,X);                  // type b or c query
	}
	else { 
		// type d query
		X = (stringstream)str;      // stringstreaming
		string U = str;
		getline(X, str, '=');
		if (U.size() == str.size()) { cout << "Invalid! Wrong Filename or No space on anyside of '='\n"; return; }          // Syntax error
		if (str != "CourseID") { cout << "Invalid! no match found for " << str << "\n"; return; }         // Syntax error
		getline(X, str, ' ');
		if(str.size() && (str[0]==' ' || str[0]=='\t')) { cout << "Invalid! No space on anyside of '='\n"; return; }   // Syntax error
		
		// proceeding with query type d
		vector<Grades> Temp1 = BSearchUtil(grades, Grades().Code("CourseID"), str);       // sorting then searching CourseID=str
		vector<CSEStudents> Temp2 = MergeSortUtil(CSEstudents, CSEStudents().Code("RollNo"));   // sorting only for Bsearch later
		cout << "RollNo     Grade  StudentName\n";
		for (int i = 0; i <(int) Temp1.size(); ++i)
		{
			int idx=BSearch(Temp2, CSEStudents().Code("RollNo"), Temp1[i].RollNo);        // Already sorted so directly Bsearch
			cout << Temp1[i].RollNo << "  " << Temp1[i].Grade << "     " << ((idx==-1)?"NULL":Temp2[idx].StudentName) << "\n";      // output
		}
		cout << "\n";     //New line
	}
}

// Shows Menu of the Program 
void Menu_Show()
{
	cout << "MENU\n";
	cout << "Press QUERY: For Query\n";
	cout << "Press CLEAR: To Clear the Screen\n";
	cout << "Press EXIT: To Exit the Program\n";
}

// Clears the screen//  OS other than WINDOWS please update it as per your OS
void clrscr()
{
	system("CLS");
}

// main function
int main()
{
	// fast input output statements 
	ios_base::sync_with_stdio(false);    
	cin.tie(NULL);
	cout.tie(NULL);

	vector<Courses> courses;             // (Dynamic array)  Vector of Courses
	vector<Grades> grades;               // (Dynamic array)  Vector of Grades
	vector<CSEStudents> CSEstudents;     // (Dynamic array)  Vector of CSEStudents
	{
		ifstream cin("courses.txt");  INPUT(courses, cin);		 cin.close();     // INPUT courses.txt
		cin.open("grades.txt");       INPUT(grades, cin);		 cin.close();     // INPUT grades.txt
		cin.open("csestudents.txt");  INPUT(CSEstudents, cin);	 cin.close();     // INPUT csestudents.txt
	}
	while (1)
	{
		cin.clear();
		fflush(stdin);
		Menu_Show();        // shows menu
		string key;         
		cin >> key;         // key input 
		cin.ignore(numeric_limits<streamsize>::max(), '\n');       // removing all the input after taking key
		if (key == "QUERY")Queries(courses, grades, CSEstudents);        // Asking for Query
		else if (key == "CLEAR")clrscr();           // Clear the Screen clrscr() is defined above 
		else if (key == "EXIT")exit(0);             // Exit the program
		else {
			cout << "Invalid! Enter Valid Key\n";     // Invalid key
		}
	}
	return 0;
}