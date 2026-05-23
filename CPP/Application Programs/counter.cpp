#include <iostream>
int main()
{
  // currVal is the number we’re counting; we’ll read new values into val
  // use ctrl+Z (windows) / Ctrl+D (linux/macOS) for termination
  int currVal = 0, val = 0;
  
  // read first number and ensure that we have data to process
  if (std::cin >> currVal) {
    int cnt = 1;                  // store the count for the current value
    while (std::cin >> val) {     // read the remaining numbers
      if (val == currVal)         // if the values are the same
        cnt++;                    // add 1 to cnt
    }
    std::cout << currVal << " occurs "
              << cnt << " times" << std::endl;
    currVal = val;
    cnt = 1;
  }
  
  return 0;
}
