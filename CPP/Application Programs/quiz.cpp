#include <iostream>

int main() {
  std::string questions[] = {"1. Who won 2022 FIFA World Cup?", 
                             "2. Who won 2022 FIFA World Cup's Best Player?", 
                             "3. Who won 2024 F1 World Championship?", 
                             "4. Who won 2024 F1 Monaco Grand Prix?"};
  
  std::string options[][4] = {{"A. Argentina", "B. Brazil", "C. France", "D. Portugal"},
                              {"A. Ronaldo", "B. Mbappe", "C. Messi", "D. Pedri"},
                              {"A. Hamilton", "B. Verstappen", "C. Leclerc", "D. Piastri"},
                              {"A. Verstappen", "B. Russel", "C. Norries", "D. Leclerc"}};
  
  char answers[4] = {'A', 'C', 'B', 'D'};
  
  int size_q = sizeof(questions)/sizeof(questions[0]);
  int size_op = sizeof(options[0])/sizeof(options[0][0]);
  int score = 0;
  char choice;
  
  for(int i = 0; i < size_q; i++) {
    std::cout << "\n========== QUESTION NUMBER " << i+1 << " ==========\n";
    std::cout << questions[i] << "\n";
    
    for(int j = 0; j < size_op; j++) {
      std::cout << options[i][j] << "\n";
    }
    
    std::cout << "Enter your choice : ";
    std::cin >> choice;
    choice = toupper(choice);
    
    if(choice == answers[i]) {
      std::cout << "CORRECT\n";
      score++;
    }
    else {
      std::cout << "WRONG\n";
      std::cout << "Correct answer :" << answers[i];
    }
    
  }
  
  std::cout << "\n================== RESULTS ==================\n";
  std::cout << "Correct answers = " << score << std::endl;
  std::cout << "Wrong answers = " << size_q - score << std::endl;
  std::cout << "Percentage = " << (score/ (double)size_q) * 100 << " %\n";
  
  return 0;
}