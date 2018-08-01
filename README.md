# JournalSort
JournalSort is a simple C++ program which takes a group of journal entries grouped by day of the year, and organizes them into a single, chronological text file. 

I normally keep my journal organized as 366 plain text files (one for each day of the year, including February 29). The entries are not chronological (since they're broken out into individual files for each date), so every few years I'd like to compile all of these into a single, chronological document. That's what this program does.

### Input

**001.txt**  
Done: August 12  
Wednesday, 2015: I got a pet turtle.  

Tuesday, 2014: I got a pet dog.  

Monday, 2013: I got a pet cat.  

**002.txt**  
Done: August 13  
Thursday, 2015: My pet turtle died.  

Wednesday, 2014: My pet dog died.  

Tuesday, 2013: My pet cat died.  

### Output

**journal.txt**  
Monday, August 12, 2013: I got a pet cat.  
Tuesday, August 13, 2013: My pet cat died.  
...  
Tuesday, August 12, 2014: I got a pet dog.  
Wednesday, August 13, 2014: My pet dog died.  
...  
Wednesday, August 12, 2015: I got a pet turtle.  
Thursday, August 13, 2015: My pet turtle died.  

### Procedure
1. Download notes from app.simplenote.com
2. Copy journal files to an `entries` directory with ````mv `grep -lir 'Done: ' source-dir/*` path-to-dir/entries````
3. Verify presence of 366 .txt files in `entries` folder
4. Rename .txt files sequentially from 001.txt to 366.txt using Automator
  1. Ask for Finder Items...
  2. Get Folder Contents...
  3. Rename Finder Items: Make Sequential...
5. Move `entries` directory to same folder as program root
6. Compile program with `$ g++ -std=c++11 main.cpp -o app`
6. Run app with `$ ./app`
