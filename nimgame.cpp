#include<simplecpp>

//winning position: there is a strategy to win from this position. 

//losing position: whatever you do, opponet has a way of winning. 

bool isWinning(int nA, int nB, int nC){
  // return true if it is a winning position
    //otherwise false
  // consider all possible next states; if one of them is losing, then the current is winning. 
  // otherwise all possible next states are winning, and then the opponent will win. 
  
  if (nA==0 && nB==0 && nC==0)
    return false;
  // suppose I choose to remove from A
  for(int i=1; i<=nA; i++){
    // new state nA-i, nB, nC
    if(!isWinning(nA-i, nB, nC))
      return true;
  }  
  for (int i=1; i<=nB; i++){
    if(!isWinning(nA, nB-i, nC))
      return true;
  }
  for (int i=1; i<=nC; i++){
    if(!isWinning(nA, nB, nC-i))
      return true;
  }
  return false;
}

void winningMove(int& nA, int& nB, int& nC){
  // for given state, plays a winning move
  // and updates the state
  
  for (int i=1; i<=nA; i++){
    if (!isWinning(nA-i, nB, nC)){
      nA = nA-i;
      cout << "Computer removes " << i << " from A" << endl;
      return;
    }
  }  
  for (int i=1; i<=nB; i++){
    if (!isWinning(nA, nB-i, nC)){
      nB = nB-i;
      cout << "Computer removes " << i << " from B" << endl;
      return;
    }
  }
  for (int i=1; i<=nC; i++){
    if (!isWinning(nA, nB, nC-i)){
      nC = nC-i;
      cout << "Computer removes " << i << " from C" << endl;
      return;
    }
  }
  // if no winning move is found then just remove 1 
  // coin from any stack.
  
  if(nA>0) nA--;
  else if (nB>0) nB--;
  else if (nC > 0) nC--;
  return;
}

bool validMove(int &nA, int &nB, int &nC, char stack, int coins){
  bool valid=true;
  if(stack=='A' && coins <= nA && coins >0)
    nA = nA-coins;
  else if(stack == 'B' && coins <= nB && coins >0)
    nB = nB-coins;
  else if(stack == 'C' && coins <= nC && coins >0)
    nC = nC-coins;
  else{ 
    valid = false;
    cout << "not a valid move " << endl;
  }
  return valid;
}


main_program{
  cout << "Please enter three numbers as the initial state" << endl;
  int nA, nB, nC;
  cin >> nA >> nB >> nC;
  bool isYourTurn = true;
  if(isWinning(nA, nB, nC))
    isYourTurn = false; 
  // true means your turn
  // false means computer's turn.  
  while(nA!=0 || nB!=0 || nC!=0){
    if(isYourTurn){
      cout << "Your move, please enter A/B/C followed by a number" << endl;
      
      char stack; 
      int coins;
      do{
        cin >> stack >> coins;
        }
        while(!validMove(nA, nB, nC, stack, coins));
      cout << "State: " << nA << " " << nB << " " << nC << endl;
    }
    else{
      //cout << "Computer's move " << endl;
      winningMove(nA, nB, nC);  
      cout << "State: " << nA << " " << nB << " " << nC << endl;  
    }
    
    isYourTurn = !isYourTurn;      

  }
  if(isYourTurn)
    cout << "You lose, computer wins" << endl;
  else 
    cout << "You win, computer loses" << endl;
}