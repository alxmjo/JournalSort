# JournalSort
JournalSort is a simple C++ script which takes a group of journal entries grouped by day of the year, and organizes them into a single, chronological text file.

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
