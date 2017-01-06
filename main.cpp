#include <regex>
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <iomanip>
#include <map>

using namespace std;

int getMonthIndex(string);
void saveEntries(map<string, string>&, string);

int main()
{
    map<string, string> journal;
    saveEntries(journal, "001.txt");

    return 0;
}

void saveEntries(map<string, string>& journal, string filename) {
    string month;
    int day;

    // Declare an ifstream 'in' with filename '001.txt'
    ifstream in(filename);

    // Declare a buffer to hold contents
    stringstream buffer;

    // Read ifstream into buffer
    buffer << in.rdbuf();

    // Initialize string variable 'entryGroup' and assign string in buffer
    string entryGroup(buffer.str());

    // Parse month and day
    regex regexMonthDay("Done: (January|February|March|April|May|June|July|August|September|October|November|December) ([0-9]{1,2})\\n");
    smatch matchMonthDay;

    if (regex_search(entryGroup, matchMonthDay, regexMonthDay))
    {
        month = matchMonthDay[1];
        day = stoi(matchMonthDay[2]);
    }

    // Parse entries
    regex regexYearEntry("(?:Monday|Tuesday|Wednesday|Thursday|Friday|Saturday|Sunday), ([0-9]{1,4}): (.*)");
    sregex_iterator position(entryGroup.cbegin(), entryGroup.cend(), regexYearEntry);
    sregex_iterator end; // Default constructor defines past-the-end iterator

    for ( ; position != end; position++)
    {
        stringstream dateSS;

        string date;
        string entry;

        dateSS << position->str(1) << setfill('0') << setw(2) << getMonthIndex(month) << day;

        date = dateSS.str();
        entry = position->str(2);

        cout << "Date: " << date << endl;
        cout << "Entry: " << entry << endl;
        cout << endl;

        // TODO: Store date and entry in map
    }
}

int getMonthIndex(string month)
{
    map<string, int> months
            {
                    {"January",      1},
                    {"February",     2},
                    {"March",        3},
                    {"April",        4},
                    {"May",          5},
                    {"June",         6},
                    {"July",         7},
                    {"August",       8},
                    {"September",    9},
                    {"October",     10},
                    {"November",    11},
                    {"December",    12}
            };

    const auto iter = months.find(month);

    if (iter != months.cend())
        return iter->second;
    return -1;
}