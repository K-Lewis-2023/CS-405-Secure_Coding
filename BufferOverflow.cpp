// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>

int main()
{
  std::cout << "Buffer Overflow Example" << std::endl;

  // TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
  //  even though it is a constant and the compiler buffer overflow checks are on.
  //  You need to modify this method to prevent buffer overflow without changing the account_order
  //  varaible, and its position in the declaration. It must always be directly before the variable used for input.

  const std::string account_number = "CharlieBrown42";
  char user_input[20];
  std::cout << "Enter a value: ";

  /* BEGIN Student Code */

  /*
   * True count for user input is 19 characters due to null value in array.
   * If 20 characters are needed, array needs to be resized.
   */

  //Change cin to cin.getline and limit to 20 characters
  std::cin.getline(user_input, 20);

  //Check input buffer for remaining characters
  if (std::cin.rdbuf()->in_avail() > 0) {
	  //If true, display error indicating potential overflow attempt
	  std::cout << "*** Error! Buffer Overflow Detected! ***" << std::endl;
  }
  /* END Student Code */

  std::cout << "You entered: " << user_input << std::endl;
  std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
