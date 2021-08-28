/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 *
 * You may modify this file ONLY where indicated below
 */

#include "main.h"

int main() {
    /**************************************************************/
    /* DO NOT MODIFY ANYTHING BETWEEN THIS LINE AND THE ONE BELOW */
    /**************************************************************/

    //this program uses rand, this is the seed (do this only once!)
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

    /**************************************************************/
    /* MODIFY THE FILE FROM HERE DOWN */
    /**************************************************************/

    /*
     * At this point you have two parallel arrays. A simple integer array (ids)
     * that holds random integers, and 2D character array (which is a
     * 1D array of strings) holding 'dummy' strings. Compile and run the
     * program as-is and you will see the display of these two arrays.
     */

    // declare the stack
    Stack stack;

    /*****************************************
     * Perform your stack tests starting here
     *****************************************/

    /* first call isEmpty(), peek(), and pop() to show what happens when
     * you do that on an empty stack */

    cout << endl;
    cout << endl;

    //empty struct to pass into pop() and peek()
    Data temp_struct;

    //Check if the stack is empty.
    if (!stack.isEmpty()) {
      cout << "Stack is not empty!" << endl;
    } else {
      cout << "Stack is empty!" << endl;
    }

    cout << endl;

    //Call pop method on an empty stack
    if (stack.pop(&temp_struct)) {
      cout << "Stack is not empty! We can pop it" << endl;
    } else {
      cout << "Stack is empty! We cannot pop it" << endl;
    }

    cout << endl;

    //Call peek method on an empty stack
    if (stack.peek(&temp_struct)) {
      cout << "Stack is not empty! We can peek" << endl;
    } else {
      cout << "Stack is empty! We cannot peek" << endl;
    }

    cout << endl;

    //For loop to push struct data from the test cases into the stack.
    //Overflow should occur after 10 successful pushes
    for (int i = 0; i < number_test_cases; i++) {
      if(stack.push(ids[i], data[i])) {
        cout << "Successfully pushed " << ids[i] << " : " << data[i] << endl;
      } else {
        cout << "Error! Overflow!" << endl;
      }
    }

    cout << endl;

    //Check if the stack is empty.
    if (!stack.isEmpty()) {
      cout << "Stack is not empty!" << endl;
    } else {
      cout << "Stack is empty!" << endl;
    }

    cout << endl;

    //Call peek method
    if (stack.peek(&temp_struct)) {
      cout << "Stack is not empty! We can peek" << endl;
    } else {
      cout << "Stack is empty! We cannot peek" << endl;
    }

    cout << endl;

    //For loop to pop all test cases pushed into stack.
    //Underflow should occur once stack is empty
    for (int i = 0; i < number_test_cases; i++) {
      if (stack.pop(&temp_struct)) {
        cout << "Successfully popped " << ids[i] << " : " << data[i] << endl;
      } else {
        cout << "Error! Underflow!" << endl;
      }
    }

    cout << endl;

    //Check if the stack is empty.
    if (!stack.isEmpty()) {
      cout << "Stack is not empty!" << endl;
    } else {
      cout << "Stack is empty!" << endl;
    }

    cout << endl;

    //Call peek method
    if (stack.peek(&temp_struct)) {
      cout << "Stack is not empty! We can peek" << endl;
    } else {
      cout << "Stack is empty! We cannot peek" << endl;
    }

    cout << endl;

    //For loop to randomly call push, pop, and peek methods
    for (int i = 0; i < number_test_cases; i++) {
      int rand_num = rand() % 3;

      if (rand_num == 0) {
        std::cout << stack.pop(&temp_struct) << std::endl;
        std::cout << "We Poppin'" << std::endl;
      } else if (rand_num == 1) {
          std::cout << stack.push(ids[i], data[i]) << std::endl;
          std::cout << "We Pushin'" << std::endl;
      } else {
        std::cout << stack.peek(&temp_struct) << std::endl;
        std::cout << "We Peekin'" << std::endl;
      }
    }

    cout << endl;


    //Empty the stack before running next tests
    for (int i = 0; i < number_test_cases; i++) {
      if (stack.pop(&temp_struct)) {
        cout << "Successfully popped " << ids[i] << " : " << data[i] << endl;
      } else {
        cout << "Error! Underflow!" << endl;
      }
    }

    cout << endl;


    //Check if the stack is empty.
    if (!stack.isEmpty()) {
      cout << "Stack is not empty!" << endl;
    } else {
      cout << "Stack is empty!" << endl;
    }

    cout << endl;
    cout << endl;


    //Variables to hold an empty string
    string empty_str = "";
    string *empty_strptr;
    empty_strptr = &empty_str;

    //for loop to test an empty string with a positive and
    //negative int between -15 and 15
    for (int i = 0; i <STACK_SIZE*1.5; i++) {
      int rand_num = rand() % 31 + (-15);

      if (rand_num < 0) {
        if (!stack.push(rand_num, *empty_strptr)) {
          cout << "FAIL! Passed an empty string and negative int" << endl;
        } else {
          cout << "Welp, you passed a negative int and an empty string. WHOMP WHOMP" << endl;
        }
      } else {
        if (!stack.push(rand_num, *empty_strptr)) {
          cout << "FAIL! Passed an empty string and a positive int" << endl;
        } else {
          cout << "Welp, you passed a positive int with an empty string. WHOMP WHOMP" << endl;
        }
      }
    }

    cout << endl;

    //Check if the stack is empty.
    if (!stack.isEmpty()) {
      cout << "Stack is not empty!" << endl;
    } else {
      cout << "Stack is empty!" << endl;
    }

    cout << endl;

    //for loop to test a negative int with a non-empty string
    for (int i = 0; i < STACK_SIZE*1.5; i++) {
      int rand_num= rand() % 31 + (-15);

      if (!stack.push(rand_num, data[i])) {
        cout << "FAIL! Passed a negative int with a non-empty string" << endl;
      } else {
        cout << "SUCCESS! Passed a positive int with non-empty string" << endl;
      }

    }

    cout << endl;

    //Call peek method
    if (stack.peek(&temp_struct)) {
      cout << "Stack is not empty! We can peek" << endl;
    } else {
      cout << "Stack is empty! We cannot peek" << endl;
    }

    cout << endl;

    //Check if the stack is empty.
    if (!stack.isEmpty()) {
      cout << "Stack is not empty!" << endl;
    } else {
      cout << "Stack is empty!" << endl;
    }

    cout << endl;

    //For loop to pop all test cases pushed into stack.
    //Underflow should occur once stack is empty
    for (int i = 0; i < STACK_SIZE*1.5; i++) {
      if (stack.pop(&temp_struct)) {
        cout << "Successfully popped " << ids[i] << " : " << data[i] << endl;
      } else {
        cout << "Error! Underflow!" << endl;
      }
    }

    cout << endl;

    //Check if the stack is empty.
    if (!stack.isEmpty()) {
      cout << "Stack is not empty!" << endl;
    } else {
      cout << "Stack is empty!" << endl;
    }

    /*
     * Now perform an exhaustive series of tests on your stack. Push all the
     * cases. Pop all the cases. Randomly push and pop cases. Test peek() and
     * isEmpty() randomly and throughout the other cases. Your tests must be
     * exhaustive! Show all possible ways your stack can be used and abused,
     * and that your stack will gracefully handle ALL cases. You must use
     * automated testing (no user input). Make sure you run your program
     * many times to see what happens when the test cases are bigger, smaller,
     * or the same size as the size of your stack. Also show what happens
     * when you try and push negative ids and/or empty strings, which your
     * stack should not accept.
     */


    return 0;
}
