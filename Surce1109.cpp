#include "../std_lib_facilities.h"

void text_file_to_binery_file(vector<string>& vs);  // The function converts a text file to a binary.
void binery_file_to_text_file(vector<string>& vs);  // The function converts a binary file to a text file.

int main()
{
	vector<string> vs;
	text_file_to_binery_file(vs);
	binery_file_to_text_file(vs);
	return 0;
}

void text_file_to_binery_file(vector<string>& vs)
{
	cout << "Enter the name of the text file to enter:\n";
			string iname;
			getline(cin, iname);
			ifstream ifs(iname);
			if (!ifs) error("Unable to open input file ", iname);
			for (string s; getline(ifs, s);)
			{
				vs.push_back(s);
			}
			cout << "Enter the file name for the binary entry:\n";
			string oname;
			getline(cin, oname);
			ofstream ofs{ oname, ios_base::binary };
			if (!ofs) error("Unable to open output file", oname);
			ofs.write(as_bytes(vs), sizeof vs);
}

void binery_file_to_text_file(vector<string>& vs)
{
	cout << "Enter the file name for binary reading:\n";
			string iname;
			getline(cin, iname);
			ifstream ifs(iname, ios_base::binary);
			if (!ifs) error("Unable to open input file ", iname);
			vector<string> vs2;
			ifs.read(as_bytes(vs2), sizeof vs);
			cout << "Enter the file name for the text entry:\n";
			string oname;
			getline(cin, oname);
			ofstream ofs(oname);
			for (string s: vs2)
			{
				ofs << s << '\n';
			}
}