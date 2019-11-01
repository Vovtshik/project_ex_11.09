#include "../std_lib_facilities.h"

int main()
{
    cout << "\n\nTo convert a text file to binary, press 1; \n"
         << "to reverse convert a binary file to text, press 2;\n"
         << "to exit, press 3:\n";
        vector<string> vs;
        char flag;
        while(cin >> flag)
        {
            if(flag == '1')
                {
                    cout << "Enter the name of the text file to enter:\n";
                    string iname;
                    cin.get();
                    getline(cin, iname);
                    ifstream ifs(iname);
                    if(!ifs) error("Unable to open input file ", iname);
                    
                    for(string s; ifs >> s;)
                    {
                        vs.push_back(s);
                    } 
                    cout << "Enter the file name for the binary entry:\n";
                    string oname;
                    getline(cin, oname);
                    ofstream ofs{oname, ios_base::binary | ios::out};
                     if(!ofs) error("Unable to open output file", oname);
                     for(string s: vs)
                     {
                         ofs.write((char*)&s, sizeof(s));
                     }
                     /* for(string s: vs)
                     {
                         ofs.write(as_bytes(s), sizeof(s));
                     } */
                   /*  for(size_t i = 0; i < vs.size(); ++i)
                    {
                        size_t size = vs[i].size();
                        ofs.write((char*)&size, sizeof(size));
                        ofs.write(vs[i].c_str(), size);
                    } */
                   /*  for(string s: vs)
                    {
                        // size_t size = s.size();
                        // ofs.write(as_bytes(s), sizeof(size));
                        ofs.write(as_bytes(s), sizeof(string));
                    } */
                    cout << "\n\nTo convert a text file to binary, press 1; \n"
                        << "to reverse convert a binary file to text, press 2;\n"
                        << "to exit, press 3:\n";
                    // break;
                }
            else if(flag == '2')
                {
                    cout << "Enter the file name for the binary entry:\n";
                    string iname;
                    cin.get();
                    getline(cin, iname);
                    ifstream ifs(iname, ios_base::binary | ios::in);
                    if(!ifs) error("Unable to open input file ", iname );
                    vector<string>vs2/* (vs.size()) */;
                    for(string s; ifs.read((char*)&s, sizeof(s));)
                    {
                        cout << s << '\n';
                        vs2.push_back(s);
                    }
                    /* for(string s; ifs.read(as_bytes(s), sizeof(s));)
                    {

                        cout << s << '\n';
                        vs2.push_back(s);
                        if(ifs.eof())
                            break;
                    } */
                   /*  for(size_t i = 0; i < vs2.size(); ++i)
                    {
                        size_t size;
                        ifs.read((char*)&size, sizeof(size));
                        char buf[size + 1];
                        ifs.read(buf, size);   
                    } */
                    /* for(string s; ifs.read(as_bytes(s), sizeof(string));)
                        vs.push_back(s); */
                    cout << "Enter the file name for the text entry:\n";
                    string oname;
                    getline(cin, oname);
                    ofstream ofs(oname);
                    for(string s: vs2)
                        ofs << s << '\n';
                    cout << "\n\nTo convert a text file to binary, press 1; \n"
                        << "to reverse convert a binary file to text, press 2;\n"
                        << "to exit, press 3:\n";
                    // break;
                }
            else if(flag == '3')
                break;
            else
                {
                    cout << "Mistake! Repeat entry:\n"
                    << "to convert a binary file to text, press 1; \n"
                    << "to reverse convert a text file to binary, press 2;\n"
                    << "to exit, press 3:\n";
                    char ch;
                    while(cin.get(ch) && ch != '\n')
                    {
                        continue;
                    }   
                }
        }
        
        
        
    return 0;
}