#include "../std_lib_facilities.h"

int main()
{
	cout << "\n\nTo convert a text file to binary, press 1; \n"
		<< "to reverse convert a binary file to text, press 2;\n"
		<< "to exit, press 3:\n";
	char flag;
	vector<string> vs;
	vector<string> vs2;
	while (cin >> flag)
	{
		if (flag == '1')
		{
			cout << "Enter the name of the text file to enter:\n";
			string iname;
			cin.get();
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
			cout << "\n\nTo convert a text file to binary, press 1; \n"
				<< "to reverse convert a binary file to text, press 2;\n"
				<< "to exit, press 3:\n";
		}
		else if (flag == '2')
		{
			cout << "Enter the file name for binary reading:\n";
			string iname;
			cin.get();
			getline(cin, iname);
			ifstream ifs(iname, ios_base::binary);
			if (!ifs) error("Unable to open input file ", iname);
			ifs.read(as_bytes(vs2), sizeof vs);
			cout << "Enter the file name for the text entry:\n";
			string oname;
			getline(cin, oname);
			ofstream ofs(oname);
			for (string s: vs2)
			{
				ofs << s << '\n';
			}
			cout << "\n\nTo convert a text file to binary, press 1; \n"
				<< "to reverse convert a binary file to text, press 2;\n"
				<< "to exit, press 3:\n";
		}
		else if (flag == '3')
			break;
		else
		{
			cout << "Mistake! Repeat entry:\n"
				<< "to convert a binary file to text, press 1; \n"
				<< "to reverse convert a text file to binary, press 2;\n"
				<< "to exit, press 3:\n";
			char ch;
			while (cin.get(ch) && ch != '\n')
			{
				continue;
			}
		}
	}
	return 0;
}