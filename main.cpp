#include <regex>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <iomanip>

using namespace std;

void saveEntries(map<string, string>&, string);
int monthStringToIndex(string);
string dateToString(string);

int main()
{
    map<string, string> journal; // For storing journal entries

    // Loop through all journal entries
    for (int i = 0; i < 366; i++) {

        // Create a path and filename
        stringstream fileNameSS;
        string fileName;

        fileNameSS << "entries/" << setfill('0') << setw(3) << i << ".txt";
        fileName = fileNameSS.str();

        // Save entries to journal
        saveEntries(journal, fileName);
    }

    // Print journal contents
    for (const auto &p : journal) {
        cout << dateToString(p.first) << ": " << p.second << endl;
    }

    return 0;
}


// Take a reference to a map representing a journal and a .txt filename and add entries in that file to the map
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

        dateSS << position->str(1) << setfill('0') << setw(2) << monthStringToIndex(month) << setfill('0') << setw(2) << day;

        date = dateSS.str();
        entry = position->str(2);

        journal[date] = entry;
    }
}

// Takes a date in the form of YYYYMMDD and returns it as a long-form string
// "20150315" returns "Sunday, March 15, 2015"
string dateToString(string s) {
    struct tm tm = {0}; // Initialize all fields to zero
    tm.tm_isdst = -1; // Force DST lookup to prevent errors
    string formattedString;

    if (strptime(s.c_str(), "%Y%m%e", &tm)) {
        mktime(&tm); // Set day of the week

        // Use a stringstream to handle put_time() output
        stringstream buffer;
        buffer << put_time(&tm, tm.tm_mday < 10 ? "%A, %B%e, %Y" : "%A, %B %e, %Y");

        // Save output to formattedString;
        formattedString = buffer.str();
    }

    return formattedString;
}

// Take a month as a string as a parameter and return an int representing that month
// "January" returns 1, "February" returns 2, etc.
int monthStringToIndex(string month)
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