/*
 * Name: Tyler McDonald
 * Test 1
 * Purpose: Create a FIFO Queue using Linked Lists
 */

#include "main.h"


//Methods to make test case Data

void make_test_cases(int *ids, char **data, int num_cases) {

    for (int i = 0; i < num_cases; i++) {
        ids[i] = rand() % MAX_ID + 1;
        for (int j = 0; j < BUFFER_SIZE - 1; j++) {
            data[i][j] = 'a' + i;
        }
        data[i][BUFFER_SIZE - 1] = '\0';
    }
}

void display_test_cases(int *ids, char **data, int num_cases) {
  cout << "Displaying test cases..." << endl;
  for (int i = 0; i < num_cases; i++) {
      cout << ids[i] << ": " << data[i] << endl;
  }
}


int main() {

  //making temporary data holder for testing
  Data temp_struct;

  //making Fifo object
  Fifo fifo;

  //rand seed
    srand(time(NULL));

    // making 5 - 25 test cases
    int number_test_cases = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[number_test_cases];
    char *data[number_test_cases];
    for (int i = 0; i < number_test_cases; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    //filling arrays with test case data
    cout << "Making " << number_test_cases << " test cases..." << endl;
    make_test_cases(ids, data, number_test_cases);
    cout << "Test cases done" << endl << endl;
    display_test_cases(ids, data, number_test_cases);


    cout << endl;

    //Check if the fifo is empty.
    if (!fifo.isEmpty()) {
      cout << "fifo is not empty!" << endl;
    } else {
      cout << "fifo is empty!" << endl;
    }

    cout << endl;

    //Call pull method on an empty fifo
    if (fifo.pull(&temp_struct)) {
      cout << "fifo is not empty! We can pull it" << endl;
    } else {
      cout << "fifo is empty! We cannot pull it" << endl;
    }

    cout << endl;

    //Call peek method on an empty fifo
    if (fifo.peek(&temp_struct)) {
      cout << "fifo is not empty! We can peek" << endl;
    } else {
      cout << "fifo is empty! We cannot peek" << endl;
    }

    cout << endl;

    for (int i = 0; i < number_test_cases; i++) {
      if(fifo.push(ids[i], data[i])) {
        cout << "Successfully pushed " << ids[i] << " : " << data[i] << endl;
      } else {
        cout << "Error! Bad Data!" << endl;
      }
    }

      cout << endl;

    //Check if the fifo is empty.
    if (!fifo.isEmpty()) {
      cout << "fifo is not empty!" << endl;
    } else {
      cout << "fifo is empty!" << endl;
    }

      cout << endl;

    //Call peek method
    if (fifo.peek(&temp_struct)) {
      cout << "fifo is not empty! We can peek" << endl;
    } else {
      cout << "fifo is empty! We cannot peek" << endl;
    }

    cout << endl;

    //Empty the fifo before running next tests
    for (int i = 0; i < number_test_cases; i++) {
      if (fifo.pull(&temp_struct)) {
        cout << "Successfully pulled " << ids[i] << " : " << data[i] << endl;
      } else {
        cout << "Error! Underflow!" << endl;
      }
    }

    cout << endl;

    //For loop to randomly call push, pull, and peek methods
    for (int i = 0; i < number_test_cases; i++) {
      int rand_num = rand() % 3;

      if (rand_num == 0) {
        std::cout << fifo.pull(&temp_struct) << std::endl;
        std::cout << "We pullin'" << std::endl;
      } else if (rand_num == 1) {
          std::cout << fifo.push(ids[i], data[i]) << std::endl;
          std::cout << "We Pushin'" << std::endl;
      } else {
        std::cout << fifo.peek(&temp_struct) << std::endl;
        std::cout << "We Peekin'" << std::endl;
      }
    }

    cout << endl;

    //Empty the fifo before running next tests
   for (int i = 0; i < number_test_cases; i++) {
     if (fifo.pull(&temp_struct)) {
       cout << "Successfully pulled " << ids[i] << " : " << data[i] << endl;
     } else {
       cout << "Error! Underflow!" << endl;
     }
   }

   cout << endl;

   //Check if the fifo is empty.
   if (!fifo.isEmpty()) {
     cout << "fifo is not empty!" << endl;
   } else {
     cout << "fifo is empty!" << endl;
   }

   cout << endl;

   //Variables to hold an empty string
   string empty_str = "";
   string *empty_strptr;
   empty_strptr = &empty_str;

   //for loop to test an empty string with a positive and
   //negative int between -15 and 15
   for (int i = 0; i < number_test_cases*1.5; i++) {
     int rand_num = rand() % 31 + (-15);

     if (rand_num < 0) {
       if (!fifo.push(rand_num, *empty_strptr)) {
         cout << "FAIL! Passed an empty string and negative int" << endl;
       } else {
         cout << "Welp, you passed a negative int and an empty string. WHOMP WHOMP" << endl;
       }
     } else {
       if (!fifo.push(rand_num, *empty_strptr)) {
         cout << "FAIL! Passed an empty string and a positive int" << endl;
       } else {
         cout << "Welp, you passed a positive int with an empty string. WHOMP WHOMP" << endl;
       }
     }
   }

   cout << endl;

   //Check if the fifo is empty.
   if (!fifo.isEmpty()) {
     cout << "fifo is not empty!" << endl;
   } else {
     cout << "fifo is empty!" << endl;
   }

  cout << endl;

  //Call peek method
  if (fifo.peek(&temp_struct)) {
    cout << "fifo is not empty! We can peek" << endl;
  } else {
    cout << "fifo is empty! We cannot peek" << endl;
  }

  cout << endl;

  //For loop to pull all test cases pushed into fifo.
  //Underflow should occur once fifo is empty
  for (int i = 0; i < number_test_cases*1.5; i++) {
    if (fifo.pull(&temp_struct)) {
      cout << "Successfully pulled " << ids[i] << " : " << data[i] << endl;
    } else {
      cout << "Error! Underflow!" << endl;
    }
  }

  cout << endl;

  //Check if the fifo is empty.
  if (!fifo.isEmpty()) {
    cout << "fifo is not empty!" << endl;
  } else {
    cout << "fifo is empty!" << endl;
  }

  return 0;
}
