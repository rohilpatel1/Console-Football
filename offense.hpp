#include <iostream>
#include <string>

#include "user.hpp"
#include "random/random.hpp"

void displayOffensiveOptions(int);
void showSpecialPlays();
void punt();

void kickOffToOpponent() {
  std::cout << "You kicked 65 yards to the end zone for a touchback. Out comes your defense." << std::endl;
  int yardAt = 25;
  currentPos = false;

  //showDefensivePlays()
}

void kickExtraPoint() {
  int prob = randint(1, 4);

  if (prob == 1) {
    std::cout << "Extra Point No Good" << std::endl;
  } else {
    pointsByClient++;

    std::cout 
    << "Extra Point is good! \n\n"
    << "You now have "
    << pointsByClient
    << ", and your opponent has "
    << pointsByOpponent
    << std::endl;
  }

  std::cout << "You now have " << pointsByClient << " points.!" <<std::endl;


  kickOffToOpponent();
}

void twoPointConversion() {
  int prob = randint(1, 2);

  if (prob == 1) {
    pointsByClient++;
    
    std::cout 
    << "2  P O I N T  C O N V E R S I O N\n"
    << std::endl;

    std::cout << "You now have " << pointsByClient << " points.!" <<std::endl;
    
  } else {
    std::cout
    << "Two point conversion is no good"
    << std::endl;

    yardAt = 25;
  }

  kickOffToOpponent();
}

void touchDownOptions() {
  std::cout 
  << "Choose an option: \n\n"
  << "1. Kick Extra Point\n"
  << "2. Attempt a 2 point conversion"
  << std::endl;
}

void touchdown() {
  int userSelect;
  pointsByClient += 6;

  std::cout << "\nT O U C H D O W N !\n" << std::endl;

  std::cout << "You now have " << pointsByClient << " points.\n" << std::endl;

  pointsByClient += 6;

  touchDownOptions();

  std::cin >> userSelect;

  switch(userSelect) {
    case 1:
      kickExtraPoint();
      break;
    case 2:
      twoPointConversion();
      break;
    default:
      std::cout << "That is not a valid option" << std::endl;
      touchDownOptions();
  }
}

void rushForYards() {
  std::cout << "\n";
  down++;
  int randomNumber = randint(-4, 7);

  if (randomNumber < 0) {
    int loss = 0 - randomNumber;
    yardAt += randomNumber;
    yardsToGo += loss;

    std::cout 
    << "There was a loss of " 
    << 0 - randomNumber
    << " on the play."
    << std::endl;
  } else if(randomNumber > 0) {
    yardsToGo -= randomNumber;
    yardAt += randomNumber;

    std::cout
    << "There was a gain of "
    << randomNumber
    << " on the play."
    << std::endl;
  } else {
    std::cout
    << "There was no gain on the play."
    << std::endl;
  }

  if (yardAt >= 100) {
    touchdown();
  } else {
    displayOffensiveOptions(down);
  }
}

void floatDownTheField() {
  down++;
  int randomNumber = randint(1, 2);

  if (randomNumber == 1) {
    int yardage = randint(8, 37);

    yardAt += yardage;

    yardsToGo = 10;
    down = 1;

    std::cout 
    << "You connected for " 
    << yardage
    << " yards." 
    << std::endl;

    if (yardAt > 50 && yardAt < 100) {
			std::cout
			<< "You are at your opponents "
			<< 100 - yardAt
			<< std::endl;
		} else if (yardAt < 50) {
			std::cout 
			<< "You are at your own " 
			<< yardAt 
			<< std::endl;
		} else if (yardAt == 50){
			std::cout 
			<< "You are at midfield"
			<< std::endl;
		}

    if (yardAt >= 100) {
      touchdown();
    } else {
      if (down == 5) {
        std::cout << "You have forced a turnover." << std::endl;
        //displayDefensiveOptions()
        return;
      } else {
        displayOffensiveOptions(down);
      }
    }
  } else {
    std::cout << "Pass was incomplete." << std::endl;

    if (down == 5) {
      std::cout << "You have forced a turnover." << std::endl;
      //displayDefensiveOptions()
      return;
    } else {
      displayOffensiveOptions(down);
    }
  }
}

void throwForYards() {
	down++;
	int randomNumber = randint(0, 10);
	std::string place;

	if (randomNumber > 7) {

		if (yardAt > 50 && yardAt < 100) {
			std::cout
			<< "You are at your opponents "
			<< 100 - yardAt
			<< std::endl;
		} else if (yardAt < 50) {
			std::cout 
			<< "You are at your own " 
			<< yardAt 
			<< std::endl;
		} else if (yardAt == 50){
			std::cout 
			<< "You are at midfield"
			<< std::endl;
		}

	} else {
		yardAt += randomNumber;
		yardsToGo -= randomNumber;

		if (yardsToGo <= 0) {
			yardsToGo = 10;
			down = 1;
		}

		if (yardAt > 50) {
			std::cout
			<< "You are at your opponents "
			<< 100 - yardAt
			<< std::endl;
		} else if (yardAt < 50 && yardAt > 0) {
			std::cout 
			<< "You are at your own " 
			<< yardAt << std::endl;
		} else if(yardAt == 50) {
			std::cout << "You are nodw at midfield" << std::endl;
		}
	}

  if (yardAt >= 100) {
    std::cout << "\nT O U C H D O W N !" << std::endl;
  } else {
    if (down == 5) {
      std::cout << "You have forced a turnover." << std::endl;
      //displayDefensiveOptions()
      return;
    } else {
      displayOffensiveOptions(down);
    }
  }
}

void showNormalPlays() {
	int userSelect;

  std::cout 
  << "Showing offensive plays: \n\n"
  << "1. Throw for few yards \n"
  << "2. Rush for some yards \n"
  << "3. Float down the field \n"
  << "4. Show special plays \n"
  << std::endl;

	std::cin >> userSelect;

	switch(userSelect) {
		case 1:
			throwForYards();
			break;
		case 2:
			rushForYards();
			break;
    case 3:
      floatDownTheField();
      break;
    case 4:
      showSpecialPlays();
      break;
		default:
			std::cout << "An error occured." << std::endl;
			showNormalPlays();
			break;
	}
}

void fieldGoal() {
  std::string n;
  int y;

  if (yardAt >= 60) {
    int prob = randint(1, 2);

    if (prob == 1) {
      std::cout << "F I E L D  G O A L!";
      pointsByClient += 3;
      std::cout << "\n You now have " << pointsByClient << "points!" << std::endl;
    } else {
      if (yardAt >= 50) {
        y = 100 - yardAt;
			  n = "their own";
		  } else if (yardAt < 50) {
			  n = "your own";
        y = yardAt;
		  } else {
		    n = "midfield";
		  }

      std::cout 
      << "Field Goal attempt was missed. Opponent takes over at "
      << n
      << " "
      << y
      << std::endl;
      }
  } else {
    if (yardAt >= 50) {
      y = 100 - yardAt;
			n = "their own";
		} else if (yardAt < 50) {
			n = "your own";
      y = yardAt;
		} else {
		n = "midfield";
		}
    
    std::cout 
    << "Field Goal attempt was short. Opponent takes over at "
    << n
    << " "
    << y
    << std::endl;

  }

  kickOffToOpponent();
}

void kneeBall() {
  down++;
  yardAt--;
  yardsToGo++;

  std::cout << "Ball was kneed. Loss of one on the play." << std::endl;

  if (down >= 5) {
    std::cout << "Turnover" << std::endl;
  } else {
    if (down == 5) {
      std::cout << "You have forced a turnover." << std::endl;
      //displayDefensiveOptions()
      return;
    } else {
      displayOffensiveOptions(down);
    }
  }
}

void showSpecialPlays() {
  int userSelect;

  std::cout 
  << "1. Hail Mary for end zone \n"
  << "2. Punt\n"
  << "3. Knee ball\n"
  << "4. Display Normal Offensive Options\n"
	<< "5. Field Goal"
  << std::endl;

  std::cin >> userSelect;

  switch(userSelect) {
    case 1:
      break;
    case 2:
      punt();
      break;
    case 3:
      kneeBall();
      break;
    case 4:
      showNormalPlays();
      break;
    case 5:
      fieldGoal();
    break;
    default:
      std::cout << "e" << std::endl;
  }
}

void kickOff() {
  yardAt = 25;
  yardsToGo = 10;
  down = 1;
	std::cout << "\nKickoff was made to the end zone. Touchback." << std::endl;

	displayOffensiveOptions(down);
}

void punt() {
  yardAt += 60;
	yardAt = 100 - yardAt;
	currentPos = false;

  if (yardAt <= 0) {
    yardAt = 20;
    std::cout 
	  << "You punted for 60 yards. The result of the play was a touchback, and the ball will be placed at the 20 yard line. " 
	  << yardAt
	  << std::endl;
  } else {
    std::cout 
	  << "You punted for 60 yards. Your opponent will start at their own " 
	  << yardAt
	  << std::endl;
  }

	// open the defense panel
}

void displayOffensiveOptions(int down) {
  std::cout << "\n";
  switch(down) {
    case 1:
      std::cout
      << "It is 1st & "
      << yardsToGo
      << std::endl;

      showNormalPlays();
      
      break;

    case 2:
      std::cout
      << "It is 2nd & "
      << yardsToGo
      << std::endl;

      showNormalPlays();
      break;

    case 3:
      std::cout
      << "It is 3rd & "
      << yardsToGo
      << std::endl;

      showNormalPlays();
      break;

    case 4:
      std::cout
      << "It is 4th & "
      << yardsToGo
      << std::endl;

      showSpecialPlays();
      break;

    default:
      std::cout << "e" << std::endl;
  }
}