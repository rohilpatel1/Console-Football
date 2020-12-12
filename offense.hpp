#include <iostream>
#include <string>

#include "user.hpp"
#include "random/random.hpp"

void displayOffensiveOptions(int);
void showSpecialPlays();
void punt();

void touchdown() {
  std::cout << "\nT O U C H D O W N !\n" << std::endl;

  pointsByClient += 6;

  std::cout 
  << "Choose an option:"
  << "1. Kick Extra Point"
  << "2. Attempt a 2 point conversion"
  << std::endl;
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

    if (yardAt > 50) {
			std::cout
			<< "You are at your opponents "
			<< yardAt
			<< std::endl;
		} else if (yardAt < 50) {
			std::cout 
			<< "You are at your own " 
			<< yardAt 
			<< std::endl;
		} else {
			std::cout 
			<< "You are at midfield"
			<< std::endl;
		}

    if (yardAt >= 100) {
      touchdown();
    } else {
      displayOffensiveOptions(down);
    }
  } else {
    std::cout << "Pass was incomplete." << std::endl;
    displayOffensiveOptions(down);
  }
}

void throwForYards() {
	down++;
	int randomNumber = randint(0, 10);
	std::string place;

	if (randomNumber > 7) {

		if (yardAt > 50) {
			std::cout
			<< "The pass was incomplete. You are at your opponents "
			<< yardAt
			<< std::endl;
		} else if (yardAt < 50) {
			std::cout 
			<< "The pass was incomplete. You are at your own " 
			<< yardAt 
			<< std::endl;
		} else {
			std::cout 
			<< "The pass was incomplete. You are at midfield"
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
		} else if (yardAt < 50) {
			std::cout 
			<< "You are at your own " 
			<< yardAt << std::endl;
		} else {
			std::cout << "You are nodw at midfield" << std::endl;
		}
	}

  if (yardAt >= 100) {
    std::cout << "\nT O U C H D O W N !" << std::endl;
  } else {
    displayOffensiveOptions(down);
  }
}

void showNormalPlays() {
	int userSelect;

  std::cout 
  << "Showing offensive plays: \n\n"
  << "1. Throw for few yards \n"
	<< "2. Float down the field \n"
  << "3. Rush for some yards \n"
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
      break;
    case 4:
      displayOffensiveOptions(down);
      break;
    case 5:
      fieldGoal();
    break;
    default:
      std::cout << "e" << std::endl;
  }
}

void kickOff() {
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