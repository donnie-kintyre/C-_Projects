/*
 * Name: Tyler McDonald
 * Coding 06
 * Purpose: Creating a hash table class/object using a
 *          standard struct type and a linked list.
 */

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];

    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";

    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */

    // create your hash table object here
    Hashtable hashtable[HASHTABLESIZE];

    // show it is empty by calling getCount and printTable
    if (!hashtable->getCount()) {
      cout << "Table is empty!" << endl;
    } else {
      cout << "The Count is: " << hashtable->getCount() << endl;
    }

    cout << endl;

    hashtable->printTable();

    cout << endl;

    //Inserting all the test data

    for (int i = 0; i < testdatasize; i++) {
      cout << "Going to add " << ids[i] << " : " << strs[i];
      if (hashtable->insertEntry(ids[i], &strs[i])) {
        cout << " ACHIEVED!" << endl;
        cout << "\tThe count is now " << hashtable->getCount() << endl;
        cout << "\tThe data is: " << hashtable->getData(ids[i]) << endl;
      } else {
        cout << " Failed!!" << endl;
        cout << "\tThe count is still " << hashtable->getCount() << " There should be no change" << endl;
        cout << "\tThe data is " << hashtable->getData(ids[i]) << endl;
      }
      cout << endl;
    }

    cout << endl;
    //printing table to see the contents after test data was added
    hashtable->printTable();

    cout << endl;
    cout << endl;

    //Retreiving all the test data one at a time.
    string tempStr = "";

    for (int i = 0; i < HASHTABLESIZE; i++) {
      tempStr = hashtable->getData(ids[i]);
      if (tempStr != "") {
        cout << "Found! ID: " << ids[i] << " -- string: " << tempStr << endl;
      } else {
        cout << "No luck! ID: " << ids[i] << " -- was not found!" << endl;
      }
    }
    
    cout << endl;

    //Deleting random ids
    
    for (int i = 0; i < 50; i++) {
      int rand_num = rand() % 100;
      if (hashtable->removeEntry(rand_num)) {
        cout << "SUCCESS! ID: " << rand_num << " was found and deleted" << endl;
        cout << "The count is now " << hashtable->getCount() << endl;
      } else {
        cout << "FAIL! ID: " << rand_num << " was NOT found to delete" << endl;
      }
    }

    cout << endl;

    hashtable->printTable();

    //Getting random ids

    for (int i = 0; i < 50; i++) {
      int rand_num = rand() % 100;
      tempStr = hashtable->getData(rand_num);
      if (tempStr != "") {
        cout << "SUCCESS! ID: " << rand_num << " was found!" << endl;
      } else {
        cout << "FAIL! ID: " << rand_num << " was NOT found!" << endl;
      }
    }

    cout << endl;
    cout << endl;

    //random loop to call insertEntry and deleteEntry

    //Creating a non-empty string to test for loop
    string testStr = "TESTING!";

    for (int i = 0; i < 1000; i++) {
      int rand_num = (rand() % 400) - 200;
      int rand_call = rand() % 2;

      if (rand_call == 0) {
        if (hashtable->insertEntry(rand_num, &testStr)) {
          //Randomly pass an empty string with a positive int
          if ( rand_num >= 5 && rand_num <= 15) {
            testStr = "";
          }
          cout << "SUCCESS! added ID: " << rand_num << " String : " << testStr << endl;
          cout << "The count is now " << hashtable->getCount() << endl;
        } else {
          cout << "FAIL! Couldn't add ID: " << rand_num << " String : " << testStr << endl;
        }
      } else {
        if (hashtable->removeEntry(rand_num)) {
          cout << "SUCCESS! Deleted ID: " << rand_num << endl;
        } else {
          cout << "FAIL! Couldn't find ID: " << rand_num << endl;
        }
      }
    }

    cout << endl;
    cout << endl;

    //print out table to see results of previous for loop

    hashtable->printTable();

    return 0;
}
