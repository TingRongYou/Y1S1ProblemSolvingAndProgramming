#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

struct Customer {
	string name;
	int age;
	string contactNum;
	string email;
	string password;
};

struct Admin {
	string name;
	int age;
	string contactNum;
	string email;
	string password;
};

struct BookingInfo {
	int count = 1;
	string expert;
	string serviceType;
	Customer customer;
};

struct SessionType {
	const int TREATMENT = 2;
	const int CONSULTATION = 1;
};

struct Time {
	const int MAXDAILYHOUR = 6;
	const int MAXWEEKLYHOUR = 30;
	const int FIRSTBOOKINGHOUR = 9;
	const int LASTBOOKINGHOUR = 17;
	int totalDailyHours;
	int totalWeeklyHours;
};

void displayLogo();
void clearScreen();
void exitProgram();

bool emailIsValid(string email);
bool passwordIsValid(string password);
bool validDay(Date date);

string getMonthName(int userMonth);
int daysInMonth(Date date);
int getFirstWeekday(Date date);
int dayOfWeek(int day, int month, int year);
bool isWeekDay(Date date);
void printCalendar(Date date);

int selectWeek();
bool isValidWeekInDay(int weekSelection, Date date);

void examplePersonalDetails();
void exampleRegistration();

void customerPage();
void custLoginPage();
void custRegisterPage();

void customerOptionPage(BookingInfo& bookingInfo);

void serviceListPage(BookingInfo& bookingInfo);
void bodyTreatment(BookingInfo& bookingInfo);
void botox(BookingInfo& bookingInfo);
void scarRemoval(BookingInfo& bookingInfo);

void expertListPage(BookingInfo& bookingInfo);
void expertJeanne(BookingInfo& bookingInfo);
void expertKen(BookingInfo& bookingInfo);
void expertAn(BookingInfo& bookingInfo);

void bookServicePage(BookingInfo& bookingInfo);

void treatment(BookingInfo& bookingInfo);
void tBodyTreatment(BookingInfo& bookingInfo);
void tBotox(BookingInfo& bookingInfo);
void tScarRemoval(BookingInfo& bookingInfo);

void consultation(BookingInfo& bookingInfo);
void cBodyTreatment(BookingInfo& bookingInfo);
void cBotox(BookingInfo& bookingInfo);
void cScarRemoval(BookingInfo& bookingInfo);

void loadBookedSlots(bool consultationSlots[][10], bool treatmentSlots[][10], Date date, Time& time, BookingInfo bookingInfo);
void generateSlots(Date date, const SessionType& sessionType, const Time& time, bool isConsultation, int availableSlots[][3], bool slotStatus[][10], int& slotCount);

void selectSlot(int availableSlots[][3], bool consultationSlots[][10], bool treatmentSlots[][10], int slotCount, Date date, bool isConsultation, BookingInfo& bookingInfo);
void payment(bool isConsultation, int& payBy, BookingInfo& bookingInfo);
void receipt(BookingInfo& bookingInfo, bool isConsultation, int selectedSlot, int availableSlots[][3], Date date, int payBy);
void saveReceipt(BookingInfo& bookingInfo, string payMethod, string sessionType, string amount, Date date, int availableSlots[][3], int selectedSlot);
int bookNum();

void appointmentPage(BookingInfo& bookingInfo);

void aboutUsPage();

void adminPage();
void adminLoginPage();
void adminRegisterPage();

void adminOptionPage(string expertName);

void individualSchedulePage(const string& expertName);
void overallSchedulePage(const string& expertName);
void customerDetailsPage(const string& expertName);
void salesReportPage(const string& expertName);

int main() {

	char menuSelection;

	//Display company logo
	displayLogo();

	//Greetings	
	cout << "Nice to meet you :> and welcome to \"The Queen Beauty Service Application!\"" << endl << endl;

	//Display main menu
	cout << "This is our main menu: \n";

	cout << "\n#----------Main Menu----------#\n\n";
	cout << "(1) Customer\n";
	cout << "(2) Admin\n";
	cout << "(3) Exit";

	//Use do-while loop to repromt when the user enters invalid input
	do {

		//Prompt the user to input selection
		cout << "\n\nKey in the represented key to select the activitiies (1/2/3...): ";
		cin >> menuSelection;

		//Clear screen to ensure clean and tidy screen
		clearScreen();

		//Use switch case statement to select option
		switch (menuSelection) {
		case '1': customerPage(); break;
		case '2': adminPage(); break;
		case '3': exitProgram(); break;
		default: cout << "Please enter only 1,2 or 3!";
		}

	} while (menuSelection != '1' && menuSelection != '2' && menuSelection != '3');

	return 0;

}

void displayLogo() {

	cout << endl;
	cout << "  ___   __ __    ___    ___  ____       ____   ______       _____   ___  ____  __ __  ____   __    ___     " << endl;
	cout << " /   \\ |  |  |  /  _]  /  _]|    \\     |    \\ |      |     / ___/  /  _]|    \\|  |  ||    | /  ]  /  _]    " << endl;
	cout << "|     ||  |  | /  [_  /  [_ |  _  |    |  o  )|      |    (   \\_  /  [_ |  D  )  |  | |  | /  /  /  [_     " << endl;
	cout << "|  Q  ||  |  ||    _]|    _]|  |  |    |     ||_|  |_|     \\__  ||    _]|    /|  |  | |  |/  /  |    _]    " << endl;
	cout << "|     ||  :  ||   [_ |   [_ |  |  |    |  O  |  |  |       /  \\ ||   [_ |    \\|  :  | |  /   \\_ |   [_     " << endl;
	cout << "|     ||     ||     ||     ||  |  |    |     |  |  |       \\    ||     ||  .  \\   /  |  \\     ||     |    " << endl;
	cout << " \\__,_| \\__,_||_____||_____||__|__|    |_____|  |__|        \\___||_____||__|\\_| \\_/  |____\\____||_____|    " << endl;
	cout << endl;

}    

void clearScreen() {
	//ANSI escape code to clear screen and move cursor to the top left
	cout << "\033[2J\033[1;1H";
}

void exitProgram() {

	clearScreen();

	cout << "\n";

	cout << "                                       .%@#                            \n";
	cout << "                                       .*%*                            \n";
	cout << "                                         .                             \n ";
	cout << "                                       =@#                             \n";
	cout << "                    -@@%              .@#@=             .==.           \n";
	cout << "                    .+*-=      #:     ##=%%      +%.    *@@+           \n";
	cout << "                         :-     :     :@==*@:      .      ..           \n ";
	cout << "                         -@@*.  =@-   %*===@+   .#+    -#-             \n";
	cout << "                          +@#@- @@@- +%====%%  -%@+  -#@#              \n";
	cout << "                          .@**@#@+#@+@=====*@-+%=@=.#*+@.              \n";
	cout << "                           *@=+@#==*#=======%@+-=@%#-=@-               \n";
	cout << "                           :@*===================#+==#*                \n";
	cout << "                           %@===========-==========+@.                 \n";
	cout << "               .+#%***#+:   =@+===-+*+**+****=======@=                 \n";
	cout << "              *@#:     :##.  @%###+=-:.....:-=+*##=#%                  \n";
	cout << "             #@*         +%. --.                 .-+:                  \n";
	cout << "            :@@    -=-    *#                                           \n";
	cout << "            :@%  :@@-.   -*@*-                                         \n";
	cout << "            @@  @@-   .%= =@+%                        -: .=++-         \n";
	cout << "             =@#=@%    *+   @*@       :   .--   +%**: -@%##-.=@*       \n";
	cout << "              :%@@#    -*   %@: *+   *@- +@=.% #@- =+ =@@=   *@#       \n";
	cout << "                #@%*+===++**%+ *@%   @@.:@@ +=-@@ =*  +@@   -@@:       \n";
	cout << "                *@#  ...    %= %@+  :@@ -@@*. =@@+-  :@@@  :@@-        \n";
	cout << "                =@@         @: @@=  *@%  %@=  -@@=  :#=%# .@@+  -+=:   \n";
	cout << "                 @@+   :-. *#  #@*.*@@%   @#+++:+#++=     #@% :@#:*@+  \n";
	cout << "                :%@+. .:%%#.=+=-+=: %@. +*              :@@= .-   @@-  \n";
	cout << "                   -+#**+==@=  %      =+=:               +@@       @@= \n";
	cout << "                            =+=.                         *@#      .@@: \n";
	cout << "                                                         =@#      *@*  \n";
	cout << "                                                         #@:    =@*    \n";
	cout << "                                                           =#*++#*:    \n";

	cout << "\nThank you for using Queen Beauty Service Website\n";
	cout << "Have a nice day!\n\n";

}

bool emailIsValid(string email) {

	bool valid = true;

	//Ensure the first letter in email is an alphabet
	if (!isalpha(email[0])) {
		valid = false;
	}

	int at = -1, dot = -1;

	//Determine the position of @ and .
	for (int i = 0; i < email.length(); i++) {
		if (email[i] == '@') {
			at = i;
		}
		else if (email[i] == '.') {
			dot = i;
		}

	}

	//If @ not found or . not found or dot is placed in front of alliance the email is invalid
	if (at == -1 || dot == -1 || dot < at) {
		valid = false;
	}

	if (dot >= (email.length() - 1)) {
		valid = false;
	}

	return valid;

}

bool passwordIsValid(string password) {

	bool hasUpper = false, hasLower = false, hasDigit = false, hasPunct = false;

	//Password length must be 10 character
	if (password.length() < 10 || password.length() > 10) {
		return false;
	}

	//Find if there are any uppercase, lowercase, digit and punctuation in the password
	for (int i = 0; i < password.length(); i++) {
		if (isupper(password[i])) {
			hasUpper = true;
		}
		if (islower(password[i])) {
			hasLower = true;
		}
		if (isdigit(password[i])) {
			hasDigit = true;
		}
		if (ispunct(password[i])) {
			hasPunct = true;
		}
	}

	if (!hasUpper || !hasLower || !hasDigit || !hasPunct) {
		return false;
	}

	return true;

}

bool validDay(Date date) {

	bool validDay = true;

	if (date.day <= 0 || date.day > 31) {
		return false;
	}

	return true;

}

string getMonthName(int userMonth) {

	enum Months {
		JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE,
		JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
	};

	switch (userMonth) {
	case JANUARY: return "January";
	case FEBRUARY: return "February";
	case MARCH: return "March";
	case APRIL: return "April";
	case MAY: return "May";
	case JUNE: return "June";
	case JULY: return "July";
	case AUGUST: return "August";
	case SEPTEMBER: return "September";
	case OCTOBER: return "October";
	case NOVEMBER: return "November";
	case DECEMBER: return "December";
	default: return "Invalid month";
	}
}

int daysInMonth(Date date) {
	//Find total days in a month
	int monthDay[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int days = monthDay[date.month - 1];
	//If the year is leap year, days in february should be 29
	if (date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0)) {
		monthDay[1] = 29;
	}

	return days;
}

int getFirstWeekday(Date date) {
	int day, month, year;

	// Zeller's Congruence takes January and February as months 13 and 14 of the previous year
	if (date.month == 1 || date.month == 2) {
		month = date.month + 12;
		year = date.year - 1;
	}
	else {
		month = date.month;
		year = date.year;
	}

	day = (1 + ((13 * (month + 1)) / 5) + year + (year / 4) - (year / 100) + (year / 400)) % 7;
	return (day + 6) % 7;  // Convert to Sunday=0, Monday=1, ..., Saturday=6
}

int dayOfWeek(int day, int month, int year) {
	static int offset[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };  // Adjustment array for month offsets
	if (month < 3) year -= 1;  // If it's January or February, adjust the year
	return (year + year / 4 - year / 100 + year / 400 + offset[month - 1] + day) % 7;
}

bool isWeekDay(Date date) {
	int dayOfWeekIndex = dayOfWeek(date.day, date.month, date.year);
	if (dayOfWeekIndex == 0 || dayOfWeekIndex == 6) {
		cout << "\nSorry, we don't work on weekends. Please select a weekday (Monday to Friday)."; //0 for Sunday and 6 for Saturday
		return false;
	}
	return true;
}

void printCalendar(Date date) {

	int startingDay, totalWidth = 35, padding;
	string monthYear;

	startingDay = getFirstWeekday(date);
	monthYear = getMonthName(date.month) + " " + to_string(date.year);
	padding = (totalWidth - monthYear.length()) / 2;

	cout << "\n" << setw(padding + monthYear.length()) << monthYear << endl;
	cout << "-----------------------------------\n";
	cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

	//Adjust the space if the first day does not start in Sunday
	for (int weekDay = 0; weekDay < startingDay; weekDay++) {
		cout << "     ";
	}

	for (int day = 1; day <= daysInMonth(date); day++) {
		cout << setw(5) << day;
		if ((startingDay + day) % 7 == 0) {
			cout << "\n";
		}
	}

}

int selectWeek() {
	char weekSelection;

	cout << "\n\n#----------Weeks in October 2024----------#\n\n";
	cout << "(1) Week 1 [1 - 4]\n";
	cout << "(2) Week 2 [7 - 11]\n";
	cout << "(3) Week 3 [14 - 18]\n";
	cout << "(4) Week 4 [21 - 25]\n";
	cout << "(5) Week 5 [28 - 31]";

	do {

		cout << "\n\nKey in the represented key to select the weeks (1 - 5): ";
		cin >> weekSelection;

		switch (weekSelection) {
		case '1': return 1; break;
		case '2': return 2;	break;
		case '3': return 3;	break;
		case '4': return 4; break;
		case '5': return 5; break;
		default: cout << "Please enter only 1,2,3,4 or 5!";
		}

	} while (weekSelection != '1' && weekSelection != '2' && weekSelection != '3' && weekSelection != '4' && weekSelection != '5');

}

bool isValidWeekInDay(int weekSelection, Date date) {

	//To check that if the user input correct day for the week
	if (weekSelection == 1) {
		if (date.day >= 1 && date.day <= 4) {
			return true;
		}
		else {
			cout << "Please only enter the date for week 1\n";
			return false;
		}
	}
	else if (weekSelection == 2) {
		if (date.day >= 7 && date.day <= 11) {
			return true;
		}
		else {
			cout << "Please only enter the date for week 2\n";
			return false;
		}
	}
	else if (weekSelection == 3) {
		if (date.day >= 14 && date.day <= 18) {
			return true;
		}
		else {
			cout << "Please only enter the date for week 3\n";
			return false;
		}
	}
	else if (weekSelection == 4) {
		if (date.day >= 21 && date.day <= 25) {
			return true;
		}
		else {
			cout << "Please only enter the date for week 4\n";
			return false;
		}
	}
	else if (weekSelection == 5) {
		if (date.day >= 28 && date.day <= 31) {
			return true;
		}
		else {
			cout << "Please only enter the date for week 5\n";
			return false;
		}
	}
	else { return false; }
}

void examplePersonalDetails() {
	cout << "\n#----------Example Personal Details----------#\n";
	cout << "\nName: JohanKuengYiShin";
	cout << "\nAge: 19";
	cout << "\nContact Number: 0127775555\n";
	cout << "\n#--------------------------------------------#\n";
}

void exampleRegistration() {
	cout << "\n#----------Example Register Account----------#\n";
	cout << "\nEmail: abc123@gmail.com";
	cout << "\nPassword: Abcd12345*\n";
	cout << "\n#--------------------------------------------#\n";
}

void customerPage() {

	char custMenuSelection;

	cout << "\n#----------Customer----------#\n\n";
	cout << "(1) Login\n";
	cout << "(2) Register\n";
	cout << "(3) About us\n";
	cout << "(B) Back\n";
	cout << "(E) Exit";

	do {

		cout << "\n\nKey in the represented key to select the activitiies (1/2/B/E...): ";
		cin >> custMenuSelection;

		//Convert input to uppercase if is alphabet
		if (isalpha(custMenuSelection)) {
			custMenuSelection = toupper(custMenuSelection);
		}
		
		clearScreen();

		switch (custMenuSelection) {
		case '1': custLoginPage(); break;
		case '2': custRegisterPage(); break;
		case '3': aboutUsPage(); break;
		case 'B': main(); break;
		case 'E': exitProgram(); break;
		default: cout << "Please enter only 1,2,3,B or E!";
		}

	} while (custMenuSelection != '1' && custMenuSelection != '2' && custMenuSelection != '3' && custMenuSelection != 'B' && custMenuSelection != 'E');
}

void custLoginPage() {

	Customer customer; 
	BookingInfo bookingInfo;

	string userInputEmail, userInputPassword;

	bool existingLogin = false;

	do {

		cout << "\nEmail: ";
		cin >> userInputEmail;

		cout << "Password: ";
		cin >> userInputPassword;

		ifstream inCustomerDetailFile("customerDetail.dat");

		if (!inCustomerDetailFile) {
			cout << "Error: Unable to open customerDetail.dat. Please ensure the file exists in the correct directory." << endl;
			break;
		}		

		while (inCustomerDetailFile >> customer.name >> customer.age >> customer.contactNum >> customer.email >> customer.password) {
			//Check if the userInputEmail exist or not
			if (userInputEmail == customer.email && userInputPassword == customer.password) {

				existingLogin = true;
				
				bookingInfo.customer = customer;
		
				break;
			}

		}

		inCustomerDetailFile.close();

		if (!existingLogin) {
			cout << "\nInvalid email or password. Please try again！\n";
		}

	} while (!existingLogin);

	clearScreen();

	cout << "\nYou have successfully Login!\n";

	customerOptionPage(bookingInfo);

}

void custRegisterPage() {

	Customer customer;

	bool validEmail = false, validPassword = false;

	ofstream outCustomerDetailFile;
	outCustomerDetailFile.open("customerDetail.dat", ios::app);

	if (!outCustomerDetailFile) {
		cout << "Error: Unable to open customerDetail.dat. Please ensure the file exists in the correct directory.";
	}

	examplePersonalDetails();

	cout << "\n#----------Personal Details----------#\n";
	cout << "\nName: ";
	cin.get();
	getline(cin, customer.name);

	do {
		if (customer.age <= 0) {
			cout << "Invalid age!\n";
			clearScreen();
			examplePersonalDetails();
			cout << "\n#----------Personal Details----------#\n";

			cout << "\nName: " << customer.name << endl;
		}
		cout << "Age: ";
		cin >> customer.age;
	} while (customer.age <= 0);

	do {
		if (customer.contactNum[0] != '0' || customer.contactNum.length() != 10) {
			cout << "Invalid contact number!\n";
			clearScreen();
			examplePersonalDetails();
			cout << "\n#----------Personal Details----------#\n";

			cout << "\nName: " << customer.name << endl;
			cout << "Age: " << customer.age << endl;
		}
		cout << "Contact Number: ";
		cin >> customer.contactNum;
	} while (customer.contactNum[0] != '0' || customer.contactNum.length() != 10);

	clearScreen();
	cout << "\nPersonal Details successfully recorded";

	do {

		exampleRegistration();

		cout << "\n#----------Register Account----------#\n";
		cout << "\nEmail: ";
		cin >> customer.email;

		cout << "Password: ";
		cin >> customer.password;

		clearScreen();

		validEmail = emailIsValid(customer.email);

		if (!validEmail) {
			cout << "\nA valid email account should contain @ and .com!";
		}

		validPassword = passwordIsValid(customer.password);

		if (!validPassword) {
			cout << "\nA valid password should contain 10 characters with uppercase, lowercase, digit and special character!";
		}

	} while (!validEmail || !validPassword);

	outCustomerDetailFile << customer.name << " " << customer.age << " " << customer.contactNum << " " << customer.email << " " << customer.password << endl;
	outCustomerDetailFile.close();

	clearScreen();

	cout << "\nSuccessfully registered!\n";
	cout << "Please Login again\n";

	custLoginPage();

}

void customerOptionPage(BookingInfo& bookingInfo) {

	char customerOption;

	cout << "\n#----------Options----------#\n\n";
	cout << "(1) Service List\n";
	cout << "(2) Expert List\n";
	cout << "(3) Book Service\n";
	cout << "(4) Appointment\n";
	cout << "(B) Back\n";
	cout << "(E) Exit";

	do {

		cout << "\n\nKey in the represented key to select the activitiies (1/2/B/E...): ";
		cin >> customerOption;

		if (isalpha(customerOption)) {
			customerOption = toupper(customerOption);
		}

		clearScreen();

		switch (customerOption) {
		case '1': serviceListPage(bookingInfo); break;
		case '2': expertListPage(bookingInfo); break;
		case '3': bookServicePage(bookingInfo); break;
		case '4': appointmentPage(bookingInfo); break;
		case 'B': customerPage(); break;
		case 'E': exitProgram(); break;
		default: cout << "Please enter only 1,2,3,4,B or E!";
		}

	} while (customerOption != '1' && customerOption != '2' && customerOption != '3' && customerOption != '4' && customerOption != 'B' && customerOption != 'E');
}

void serviceListPage(BookingInfo& bookingInfo) {

	char serviceListSelection;

	cout << "\n#----------Service List----------#\n\n";
	cout << "(1) Body Treatment\n";
	cout << "(2) Botox\n";
	cout << "(3) Scar Removal\n";
	cout << "(B) Back\n";
	cout << "(E) Exit";

	do {

		cout << "\n\nKey in the represented key to select the activitiies (1/2/B/E...): ";
		cin >> serviceListSelection;

		if (isalpha(serviceListSelection)) {
			serviceListSelection = toupper(serviceListSelection);
		}

		clearScreen();

		switch (serviceListSelection) {
		case '1': bodyTreatment(bookingInfo); break;
		case '2': botox(bookingInfo); break;
		case '3': scarRemoval(bookingInfo); break;
		case 'B': customerOptionPage(bookingInfo); break;
		case 'E': exitProgram(); break;
		default: cout << "Please enter only 1,2,3,B or E!";
		}

	} while (serviceListSelection != '1' && serviceListSelection != '2' && serviceListSelection != '3' && serviceListSelection != 'B' && serviceListSelection != 'E');

}

void bodyTreatment(BookingInfo& bookingInfo) {

	char bodyTreatmentSelection;

	cout << "\n    ==================================================================================================================\n";
	cout << setw(65) << "Body Treatment\n";
	cout << "    ==================================================================================================================\n\n";

	cout << "\tAt Queen Beauty Service, our body treatment services are designed to rejuvenate and pamper your skin,\n";
	cout << "\tleaving you feeling refreshed and revitalized.\n";	
	cout << "\n\tWe offer a variety of treatments tailored to your unique needs,\n";
	cout << "\tfrom exfoliating scrubs that remove dead skin cells to nourishing wraps that hydrate and smooth your body.\n";
	cout << "\n\tEach session is carefully curated by our experts to ensure maximum relaxation and rejuvenation,\n";
	cout << "\thelping you achieve glowing, healthy skin.\n\n";

	cout << "    =================================================================================================================\n\n";

	do {

		cout << "Enter E(Exit), B(Back) or P(Proceed Booking): ";
		cin >> bodyTreatmentSelection;

		if (isalpha(bodyTreatmentSelection)) {
			bodyTreatmentSelection = toupper(bodyTreatmentSelection);
		}

		clearScreen();

		switch (bodyTreatmentSelection) {
		case 'B': serviceListPage(bookingInfo); break;
		case 'E': exitProgram(); break;
		case 'P': bookServicePage(bookingInfo); break;
		default: cout << "Please enter only B, E or P!\n\n";
		}

	} while (bodyTreatmentSelection != 'B' && bodyTreatmentSelection != 'E' && bodyTreatmentSelection != 'P');
}

void botox(BookingInfo& bookingInfo) {

	char botoxSelection;

	cout << "\n    ==================================================================================================================\n";
	cout << setw(65) << "Botox\n";
	cout << "    ==================================================================================================================\n\n";

	cout << "\tAt Queen Beauty Service, our Botox treatments are designed to rejuvenate and enhance your natural beauty.\n";
	cout << "\n\tAdministered by our expert Ken Ha Men,\n";
	cout << "\tour Botox services help smooth fine lines and wrinkles,\n";
	cout << "\tgiving you a youthful and refreshed appearance.\n";
	cout << "\n\tWhether you're looking to reduce the signs of aging or enhance facial contours,\n";
	cout << "\tour Botox treatments are tailored to your unique needs, ensuring safe\n";
	cout << "\tand effective results in a relaxing, professional environment.\n";
	cout << "\n\tExperience the confidence that comes with a more youthful look at Queen Beauty Service.\n";
	cout << "\tlifestyle.\n\n";

	cout << "    =================================================================================================================\n\n";

	do {

		cout << "Enter E(Exit), B(Back) or P(Proceed Booking): ";
		cin >> botoxSelection;

		if (isalpha(botoxSelection)) {
			botoxSelection = toupper(botoxSelection);
		}

		clearScreen();

		switch (botoxSelection) {
		case 'B': serviceListPage(bookingInfo); break;
		case 'E': exitProgram(); break;
		case 'P': bookServicePage(bookingInfo); break;
		default: cout << "Please enter only B, E or P!\n\n";
		}

	} while (botoxSelection != 'B' && botoxSelection != 'E' && botoxSelection != 'P');
}

void scarRemoval(BookingInfo& bookingInfo) {
	char scarRemovalSelection;

	cout << "\n    ==================================================================================================================\n";
	cout << setw(65) << "Scar Removal\n";
	cout << "    ==================================================================================================================\n\n";

	cout << "\tAt Queen Beauty Service, our scar removal treatments are designed to help you \n";
	cout << "\trestore confidence and achieve smoother, clearer skin.\n";
	cout << "\n\tWe use advanced techniques to effectively minimize the \n";
	cout << "\tappearance of scars caused by acne, injury, or surgery.\n";
	cout << "\n\tOur expert, An Seu Yeoung, ensures that each treatment is tailored to meet your individual needs,\n";
	cout << "\tdelivering noticeable and lasting improvements while prioritizing your comfort\n";
	cout << "\tand well-being throughout the process.\n";
	cout << "\n\tLet us help you on your journey to rejuvenated, scar-free skin.\n\n";


	cout << "    =================================================================================================================\n\n";

	do {

		cout << "Enter E(Exit), B(Back) or P(Proceed Booking): ";
		cin >> scarRemovalSelection;

		if (isalpha(scarRemovalSelection)) {
			scarRemovalSelection = toupper(scarRemovalSelection);
		}

		clearScreen();

		switch (scarRemovalSelection) {
		case 'B':  serviceListPage(bookingInfo); break;
		case 'E': exitProgram(); break;
		case 'P': bookServicePage(bookingInfo); break;
		default: cout << "Please enter only B, E or P!\n\n";
		}

	} while (scarRemovalSelection != 'B' && scarRemovalSelection != 'E' && scarRemovalSelection != 'P');
}

void expertListPage(BookingInfo& bookingInfo) {

	char expertListSelection;

	cout << "\n#----------Expert List----------#\n\n";
	cout << "(1) Jeanne Tan\n";
	cout << "(2) Ken Ha Men\n";
	cout << "(3) An Seu Yeoung\n";
	cout << "(B) Back\n";
	cout << "(E) Exit";

	do {

		cout << "\n\nKey in the represented key to select the activitiies (1/2/B/E...): ";
		cin >> expertListSelection;

		if (isalpha(expertListSelection)) {
			expertListSelection = toupper(expertListSelection);
		}

		clearScreen();

		switch (expertListSelection) {
		case '1': expertJeanne(bookingInfo); break;
		case '2': expertKen(bookingInfo); break;
		case '3': expertAn(bookingInfo); break;
		case 'B': customerOptionPage(bookingInfo); break;
		case 'E': exitProgram(); break;
		default: cout << "Please enter only 1,2,3,B or E!";
		}

	} while (expertListSelection != '1' && expertListSelection != '2' && expertListSelection != '3' && expertListSelection != 'B' && expertListSelection != 'E');

}

void expertJeanne(BookingInfo& bookingInfo) {

	char expertJeanneSelection;

	cout << "\n    ==================================================================================================================\n";
	cout << setw(65) << "Jeanne Tan\n";
	cout << "    ==================================================================================================================\n\n";

	cout << "\tMs.Jeanne is an expert in body treatment at Queen Beauty Service.\n";
	cout << "\n\tWith a deep understanding of various therapeutic techniques,\n";
	cout << "\tshe focuses on helping clients rejuvenate their bodies through personalized treatments.\n";
	cout << "\n\tShe is dedicated to providing exceptional care, \n";
	cout << "\tensuring that each session promotes relaxation, wellness, and overall physical well-being.\n\n";

	cout << "    =================================================================================================================\n\n";

	do {

		cout << "Enter E(Exit), B(Back) or P(Proceed Booking): ";
		cin >> expertJeanneSelection;
		 
		if (isalpha(expertJeanneSelection)) {
			expertJeanneSelection = toupper(expertJeanneSelection);
		}

		clearScreen();

		switch (expertJeanneSelection) {
		case 'B': expertListPage(bookingInfo); break;
		case 'E': exitProgram(); break;
		case 'P': bookServicePage(bookingInfo); break;
		default: cout << "Please enter only B, E or P!\n\n";
		}

	} while (expertJeanneSelection != 'B' && expertJeanneSelection != 'E' && expertJeanneSelection != 'P');
}

void expertKen(BookingInfo& bookingInfo) {

	char expertKenSelection;

	cout << "\n    ==================================================================================================================\n";
	cout << setw(65) << "Ken Ha Men\n";
	cout << "    ==================================================================================================================\n\n";

	cout << "\tMr.Ken is a highly skilled expert specializing in Botox treatments at Queen Beauty Service.\n";
	cout << "\n\tWith a focus on precision and client satisfaction,\n";
	cout << "\tKen is dedicated to delivering natural and effective results,\n";
	cout << "\thelping clients achieve a refreshed and youthful appearance.\n\n";

	cout << "    =================================================================================================================\n\n";

	do {

		cout << "Enter E(Exit), B(Back) or P(Proceed Booking): ";
		cin >> expertKenSelection;

		if (isalpha(expertKenSelection)) {
			expertKenSelection = toupper(expertKenSelection);
		}

		clearScreen();

		switch (expertKenSelection) {
		case 'B': expertListPage(bookingInfo); break;
		case 'E': exitProgram(); break;
		case 'P': bookServicePage(bookingInfo); break;
		default: cout << "Please enter only B, E or P!\n\n";
		}

	} while (expertKenSelection != 'B' && expertKenSelection != 'E' && expertKenSelection != 'P');

}

void expertAn(BookingInfo& bookingInfo) {

	char expertAnSelection;

	cout << "\n    ==================================================================================================================\n";
	cout << setw(65) << "An Seu Yeoung\n";
	cout << "    ==================================================================================================================\n\n";

	cout << "\tMs.An is a skilled expert in scar removal at Queen Beauty Service,\n";
	cout << "\tspecializing in advanced techniques to reduce and eliminate scars,\n";
	cout << "\thelping clients regain smooth, radiant skin. \n";
	cout << "\n\tWith a focus on personalized care,\n";
	cout << "\tAn is dedicated to delivering effective and lasting results.\n\n";

	cout << "    =================================================================================================================\n\n";

	do {

		cout << "Enter E(Exit), B(Back) or P(Proceed Booking): ";
		cin >> expertAnSelection;

		if (isalpha(expertAnSelection)) {
			expertAnSelection = toupper(expertAnSelection);
		}

		clearScreen();

		switch (expertAnSelection) {
		case 'B': expertListPage(bookingInfo); break;
		case 'E': exitProgram(); break;
		case 'P': bookServicePage(bookingInfo); break;
		default: cout << "Please enter only B, E or P!\n\n";
		}

	} while (expertAnSelection != 'B' && expertAnSelection != 'E' && expertAnSelection != 'P');
}

void bookServicePage(BookingInfo& bookingInfo) {

	char bookServiceSelection;

	cout << "\n#----------Book Service----------#\n\n";
	cout << "(1) Treatment\n";
	cout << "(2) Consultation\n";
	cout << "(B) Back\n";
	cout << "(E) Exit";

	do {

	cout << "\n\nKey in the represented key to select the activitiies (1/2/B/E...): ";
	cin >> bookServiceSelection;

	if (isalpha(bookServiceSelection)) {
		bookServiceSelection = toupper(bookServiceSelection);
	}

	clearScreen();

	switch (bookServiceSelection) {
	case '1': treatment(bookingInfo); break;
	case '2': consultation(bookingInfo); break;
	case 'B': customerOptionPage(bookingInfo); break;
	case 'E': exitProgram(); break;
	default: cout << "Please enter only 1,2,B or E!";
	}

	} while (bookServiceSelection != '1' && bookServiceSelection != '2' && bookServiceSelection != 'B' && bookServiceSelection != 'E');
}

void treatment(BookingInfo& bookingInfo) {
	
	char treatmentSelection;

	cout << "\n#----------Treatment----------#\n\n";
	cout << "(1) Body Treatment (By Ms.Jeanne)\n";
	cout << "(2) Botox          (By Mr.Ken)\n";
	cout << "(3) Scar Removal   (By Ms.An)\n";
	cout << "(B) Back\n";
	cout << "(E) Exit";

	do {

		cout << "\n\nKey in the represented key to select the activitiies (1/2/B/E...): ";
		cin >> treatmentSelection;

		if (isalpha(treatmentSelection)) {
			treatmentSelection = toupper(treatmentSelection);
		}

		clearScreen();

		switch (treatmentSelection) {
		case '1': tBodyTreatment(bookingInfo); break;
		case '2': tBotox(bookingInfo); break;
		case '3': tScarRemoval(bookingInfo); break;
		case 'B': bookServicePage(bookingInfo); break;
		case 'E': exitProgram(); break;
		default: cout << "Please enter only 1,2,3,B or E!";
		}

	} while (treatmentSelection != '1' && treatmentSelection != '2' && treatmentSelection != '3' && treatmentSelection != 'B' && treatmentSelection != 'E');

}

void tBodyTreatment(BookingInfo& bookingInfo) {

	Date desireDate;
	desireDate.year = 2024;
	desireDate.month = 10;

	SessionType session;
	Time time;

	bookingInfo.expert = "Jeanne";
	bookingInfo.serviceType = "BodyTreatment";

	bool treatmentSlots[1][10] = { false }, consultationSlots[1][10] = { false };
	bool validDayFormat = true, isValidDay = true;
	int availableSlots[10][3];
	int week, slotCount = 0;

	//Reprompt the user to select new week if the week chosen is disabled
	do {

		clearScreen();
		if (time.totalWeeklyHours >= 29) {
			cout << "\nMaximum booking for the week reached! Please select another week.\n";
		}

		printCalendar(desireDate);

		week = selectWeek();

		//Assign week start day for isValidWeekInDay to validate
		switch (week) {
		case 1: desireDate.day = 1; break;
		case 2: desireDate.day = 7; break;
		case 3: desireDate.day = 14; break;
		case 4: desireDate.day = 21; break;
		case 5: desireDate.day = 28; break;
		}

		loadBookedSlots(consultationSlots, treatmentSlots, desireDate, time, bookingInfo);

	} while (time.totalWeeklyHours >= 29);
	
	//Reprompt user to input new day while the day is disabled
	do {
		//Reprompt user to input day while day format is incorrect, day is not a weekday and day is not in the selected week
		do {

			if (!validDayFormat) {
				cout << "\nPlease ensure that the date format you entered is valid!";
			}

			cout << "\nEnter desired day (eg: 25): ";
			cin >> desireDate.day;

			validDayFormat = validDay(desireDate);
			isValidDay = validDayFormat && isWeekDay(desireDate) && isValidWeekInDay(week, desireDate);

		} while (!isValidDay);

		loadBookedSlots(consultationSlots, treatmentSlots, desireDate, time, bookingInfo);

		//If the day is available, then generate slots and allow user to select slots
		if (time.totalDailyHours < 5 && time.totalWeeklyHours < 29) {
			clearScreen();
			generateSlots(desireDate, session, time, false, availableSlots, treatmentSlots, slotCount);
			selectSlot(availableSlots, consultationSlots, treatmentSlots, slotCount, desireDate, false, bookingInfo);
		}
		//else display invalid message, then reprompt
		else {
			clearScreen();
			printCalendar(desireDate);
			cout << "\n\nThe slots are booked, please select another day.";
		}

	} while (time.totalDailyHours >= 5 || time.totalWeeklyHours >= 29);

}

void tBotox(BookingInfo& bookingInfo) {

	Date desireDate;
	desireDate.year = 2024;
	desireDate.month = 10;

	SessionType session;
	Time time;

	bookingInfo.expert = "Ken";
	bookingInfo.serviceType = "Botox";

	bool treatmentSlots[1][10] = { false }, consultationSlots[1][10] = { false };
	bool isValidDay = true, validDayFormat = true;
	int availableSlots[10][3];
	int week, slotCount = 0;

	do {

		clearScreen();
		if (time.totalWeeklyHours >= 29) {
			cout << "\nMaximum booking for the week reached! Please select another week.\n";
		}

		printCalendar(desireDate);

		week = selectWeek();

		switch (week) {
		case 1: desireDate.day = 1; break;
		case 2: desireDate.day = 7; break;
		case 3: desireDate.day = 14; break;
		case 4: desireDate.day = 21; break;
		case 5: desireDate.day = 28; break;
		}

		loadBookedSlots(consultationSlots, treatmentSlots, desireDate, time, bookingInfo);

	} while (time.totalWeeklyHours >= 29);

	do {

		do {

			if (!validDayFormat) {
				cout << "\nPlease ensure that the date format you entered is valid!";
			}

			cout << "\n\nEnter desired day (eg: 25): ";
			cin >> desireDate.day;

			validDayFormat = validDay(desireDate);
			isValidDay = validDayFormat && isWeekDay(desireDate) && isValidWeekInDay(week, desireDate);

		} while (!isValidDay);

		loadBookedSlots(consultationSlots, treatmentSlots, desireDate, time, bookingInfo);

		if (time.totalDailyHours < 5 && time.totalWeeklyHours < 29) {
			clearScreen();
			generateSlots(desireDate, session, time, false, availableSlots, treatmentSlots, slotCount);
			selectSlot(availableSlots, consultationSlots, treatmentSlots, slotCount, desireDate, false, bookingInfo);
		}
		else {
			clearScreen();
			printCalendar(desireDate);
			cout << "\n\nThe slots are booked, please select another day.";
		}

	} while (time.totalDailyHours >= 5 || time.totalWeeklyHours >= 29);

}

void tScarRemoval(BookingInfo& bookingInfo) {

	Date desireDate;
	desireDate.year = 2024;
	desireDate.month = 10;

	SessionType session;
	Time time;

	bookingInfo.expert = "An";
	bookingInfo.serviceType = "ScarRemoval";

	bool treatmentSlots[1][10] = { false }, consultationSlots[1][10] = { false };
	bool isValidDay = true, validDayFormat = true;
	int availableSlots[10][3];
	int week, slotCount = 0;

	do {

		clearScreen();
		if (time.totalWeeklyHours >= 29) {
			cout << "\nMaximum booking for the week reached! Please select another week.\n";
		}

		printCalendar(desireDate);

		week = selectWeek();

		switch (week) {
		case 1: desireDate.day = 1; break;
		case 2: desireDate.day = 7; break;
		case 3: desireDate.day = 14; break;
		case 4: desireDate.day = 21; break;
		case 5: desireDate.day = 28; break;
		}

		loadBookedSlots(consultationSlots, treatmentSlots, desireDate, time, bookingInfo);

	} while (time.totalWeeklyHours >= 29);

	do {

		do {

			if (!validDayFormat) {
				cout << "\nPlease ensure that the date format you entered is valid!";
			}

			cout << "\n\nEnter desired day (eg: 25): ";
			cin >> desireDate.day;

			validDayFormat = validDay(desireDate);
			isValidDay = validDayFormat && isWeekDay(desireDate) && isValidWeekInDay(week, desireDate);

		} while (!isValidDay);

		loadBookedSlots(consultationSlots, treatmentSlots, desireDate, time, bookingInfo);

		if (time.totalDailyHours < 5 && time.totalWeeklyHours < 29) {
			clearScreen();
			generateSlots(desireDate, session, time, false, availableSlots, treatmentSlots, slotCount);
			selectSlot(availableSlots, consultationSlots, treatmentSlots, slotCount, desireDate, false, bookingInfo);
		}
		else {
			clearScreen();
			printCalendar(desireDate);
			cout << "\n\nThe slots are booked, please select another day.";
		}

	} while (time.totalDailyHours >= 5 || time.totalWeeklyHours >= 29);

}

void consultation(BookingInfo& bookingInfo) {

	char consultationSelection;

	cout << "\n#----------Consultation----------#\n\n";
	cout << "(1) Ms.Jeanne   (Body Treatment)\n";
	cout << "(2) Mr.Ken      (Botox)\n";
	cout << "(3) Ms.An       (Scar Removal)\n";
	cout << "(B) Back\n";
	cout << "(E) Exit";

	do {

		cout << "\n\nKey in the represented key to select the activitiies (1/2/B/E...): ";
		cin >> consultationSelection;

		if (isalpha(consultationSelection)) {
			consultationSelection = toupper(consultationSelection);
		}

		clearScreen();

		switch (consultationSelection) {
		case '1': cBodyTreatment(bookingInfo); break;
		case '2': cBotox(bookingInfo); break;
		case '3': cScarRemoval(bookingInfo); break;
		case 'B': bookServicePage(bookingInfo); break;
		case 'E': exitProgram(); break;
		default: cout << "Please enter only 1,2,3,B or E!";
		}

	} while (consultationSelection != '1' && consultationSelection != '2' && consultationSelection != '3' && consultationSelection != 'B' && consultationSelection != 'E');

}

void cBodyTreatment(BookingInfo& bookingInfo) {

	Date desireDate;
	desireDate.year = 2024;
	desireDate.month = 10;

	SessionType session;
	Time time;

	bookingInfo.expert = "Jeanne";
	bookingInfo.serviceType = "BodyTreatment";

	bool consultationSlots[1][10] = {false}, treatmentSlots[1][10] = { false };
	bool isValidDay = true, validDayFormat = true;
	int availableSlots[10][3];
	int week, slotCount = 0;

	do {

		clearScreen();
		if (time.totalWeeklyHours >= 30) {
			cout << "\nMaximum booking for the week reached! Please select another week.\n";
		}

		printCalendar(desireDate);

		week = selectWeek();

		switch (week) {
		case 1: desireDate.day = 1; break;
		case 2: desireDate.day = 7; break;
		case 3: desireDate.day = 14; break;
		case 4: desireDate.day = 21; break;
		case 5: desireDate.day = 28; break;
		}

		loadBookedSlots(consultationSlots, treatmentSlots, desireDate, time, bookingInfo);

	} while (time.totalWeeklyHours >= 30);

	do {

		do {

			if (!validDayFormat) {
				cout << "\nPlease ensure that the date format you entered is valid!";
			}

			cout << "\n\nEnter desired day (eg: 25): ";
			cin >> desireDate.day;

			validDayFormat = validDay(desireDate);
			isValidDay = validDayFormat && isWeekDay(desireDate) && isValidWeekInDay(week, desireDate);

		} while (!isValidDay);

		loadBookedSlots(consultationSlots, treatmentSlots, desireDate, time, bookingInfo);

		if (time.totalDailyHours < 6 && time.totalWeeklyHours < 30) {
			clearScreen();
			generateSlots(desireDate, session, time, true, availableSlots, consultationSlots, slotCount);
			selectSlot(availableSlots, consultationSlots, treatmentSlots, slotCount, desireDate, true, bookingInfo);
		}
		else {
			clearScreen();
			printCalendar(desireDate);
			cout << "\n\nThe slots are booked, please select another day.";
		}

	} while (time.totalDailyHours >= 6 || time.totalWeeklyHours >= 30);

}

void cBotox(BookingInfo& bookingInfo) {

	Date desireDate;
	desireDate.year = 2024;
	desireDate.month = 10;

	SessionType session;
	Time time;

	bookingInfo.expert = "Ken";
	bookingInfo.serviceType = "Botox";

	bool consultationSlots[1][10] = { false }, treatmentSlots[1][10] = { false };
	bool isValidDay = true, validDayFormat = true;
	int availableSlots[10][3];
	int week, slotCount = 0;

	do {

		clearScreen();
		if (time.totalWeeklyHours >= 30) {
			cout << "\nMaximum booking for the week reached! Please select another week.\n";
		}

		printCalendar(desireDate);

		week = selectWeek();

		switch (week) {
		case 1: desireDate.day = 1; break;
		case 2: desireDate.day = 7; break;
		case 3: desireDate.day = 14; break;
		case 4: desireDate.day = 21; break;
		case 5: desireDate.day = 28; break;
		}

		loadBookedSlots(consultationSlots, treatmentSlots, desireDate, time, bookingInfo);

	} while (time.totalWeeklyHours >= 30);

	do {

		do {

			if (!validDayFormat) {
				cout << "\nPlease ensure that the date format you entered is valid!";
			}

			cout << "\n\nEnter desired day (eg: 25): ";
			cin >> desireDate.day;

			validDayFormat = validDay(desireDate);
			isValidDay = validDayFormat && isWeekDay(desireDate) && isValidWeekInDay(week, desireDate);

		} while (!isValidDay);

		loadBookedSlots(consultationSlots, treatmentSlots, desireDate, time, bookingInfo);

		if (time.totalDailyHours < 6 && time.totalWeeklyHours < 30) {
			clearScreen();
			generateSlots(desireDate, session, time, true, availableSlots, consultationSlots, slotCount);
			selectSlot(availableSlots, consultationSlots, treatmentSlots, slotCount, desireDate, true, bookingInfo);
		}
		else {
			clearScreen();
			printCalendar(desireDate);
			cout << "\n\nThe slots are booked, please select another day.";
		}

	} while (time.totalDailyHours >= 6 || time.totalWeeklyHours >= 30);

}

void cScarRemoval(BookingInfo& bookingInfo) {

	Date desireDate;
	desireDate.year = 2024;
	desireDate.month = 10;

	SessionType session;
	Time time;

	bookingInfo.expert = "An";
	bookingInfo.serviceType = "ScarRemoval";

	bool consultationSlots[1][10] = { false }, treatmentSlots[1][10] = { false };
	bool isValidDay = true, validDayFormat = true;
	int availableSlots[10][3];
	int week, slotCount = 0;

	do {

		clearScreen();
		if (time.totalWeeklyHours >= 30) {
			cout << "\nMaximum booking for the week reached! Please select another week.\n";
		}

		printCalendar(desireDate);

		week = selectWeek();

		switch (week) {
		case 1: desireDate.day = 1; break;
		case 2: desireDate.day = 7; break;
		case 3: desireDate.day = 14; break;
		case 4: desireDate.day = 21; break;
		case 5: desireDate.day = 28; break;
		}

		loadBookedSlots(consultationSlots, treatmentSlots, desireDate, time, bookingInfo);

	} while (time.totalWeeklyHours >= 30);

	do {

		do {

			if (!validDayFormat) {
				cout << "\nPlease ensure that the date format you entered is valid!";
			}

			cout << "\n\nEnter desired day (eg: 25): ";
			cin >> desireDate.day;

			validDayFormat = validDay(desireDate);
			isValidDay = validDayFormat && isWeekDay(desireDate) && isValidWeekInDay(week, desireDate);

		} while (!isValidDay);

		loadBookedSlots(consultationSlots, treatmentSlots, desireDate, time, bookingInfo);

		if (time.totalDailyHours < 6 && time.totalWeeklyHours < 30) {
			clearScreen();
			generateSlots(desireDate, session, time, true, availableSlots, consultationSlots, slotCount);
			selectSlot(availableSlots, consultationSlots, treatmentSlots, slotCount, desireDate, true, bookingInfo);
		}
		else {
			clearScreen();
			printCalendar(desireDate);
			cout << "\n\nThe slots are booked, please select another day.";
		}

	} while (time.totalDailyHours >= 6 || time.totalWeeklyHours >= 30);

}

void loadBookedSlots(bool consultationSlots[][10], bool treatmentSlots[][10], Date date, Time& time, BookingInfo bookingInfo) {

	ifstream inFile("bookedSlots.dat");
	int bookedDate;
	string expert;
	int selectedDate = static_cast<int>(date.day);
	int weekStartDay = 0, weekEndDay = 0;
	int startHour, endHour, slotNumber;

	time.totalDailyHours = 0;
	time.totalWeeklyHours = 0;

	//Initialize all consultaion and treatment slots to available
	for (int i = 0; i < 10; ++i) {
		consultationSlots[0][i] = false;
		treatmentSlots[0][i] = false;
	}

	//Initialize the week start and end date base on the input date
	if (date.day >= 1 && date.day <= 4) {
		weekStartDay = 1;
		weekEndDay = 4;
	}
	else if (date.day >= 7 && date.day <= 11) {
		weekStartDay = 7;
		weekEndDay = 11;
	}
	else if (date.day >= 14 && date.day <= 18) {
		weekStartDay = 14;
		weekEndDay = 18;
	}
	else if (date.day >= 21 && date.day <= 25) {
		weekStartDay = 21;
		weekEndDay = 25;
	}
	else if (date.day >= 28 && date.day <= 31) {
		weekStartDay = 28;
		weekEndDay = 31;
	}

	if (inFile.is_open()) {
		while (inFile >> bookedDate >> startHour >> endHour >> slotNumber >> expert) {
			//Check if the expert name in the file same with the expert chosen
			if (expert == bookingInfo.expert) {
				//Check if the booked date in the file within the week
				if (bookedDate >= weekStartDay && bookedDate <= weekEndDay) {
					time.totalWeeklyHours += (endHour - startHour); //Increase totalWeeklyHours if a slots is booked in the week
					//Check if the booked slots date in file same as selected date
					if (bookedDate == selectedDate) {
						time.totalDailyHours += (endHour - startHour); //Increase totalDailyHours if a slots is booked for the day
						//If the booked slots is a treatment slot
						if (endHour - startHour == 2) {
							//Disable the treatment slot
							if (slotNumber >= 1 && slotNumber <= 10) {
								treatmentSlots[0][slotNumber - 1] = true; 
							}
							//Disable the correspondent consultation slots
							if (slotNumber * 2 - 2 < 17) {
								consultationSlots[0][slotNumber * 2 - 2] = true; //If treatment slots [4]1500-1700 is disabled, then the slot [8]1600-1700 and [7]1500-1600 is disabled in consultation
							}
							if (slotNumber * 2 - 1 < 17) {
								consultationSlots[0][slotNumber * 2 - 1] = true;
							}
						}
						else {  //1-hour consultation
							//Disable the consultation slot
							consultationSlots[0][slotNumber - 1] = true;

							//Disable corresponding treatment slot
							if (slotNumber / 2 < 5) {
								if (slotNumber % 2 != 0) {
									slotNumber = ceil(slotNumber / 2); //If consultation slots [7]1600-1700 is disabled, then the slot [4]1500-1700 is disabled in treatment
									treatmentSlots[0][slotNumber] = true;
								}
								else {
									treatmentSlots[0][(slotNumber / 2) - 1] = true;
								}
							}
						}
					}

				}
			}

		}
		inFile.close();

	}
}

void generateSlots(Date date, const SessionType& sessionType, const Time& time, bool isConsultation, int availableSlots[][3], bool slotStatus[][10], int& slotCount) {

	int currentHour = time.FIRSTBOOKINGHOUR;
	int sessionDuration = isConsultation ? sessionType.CONSULTATION : sessionType.TREATMENT;

	string selectedDate = to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);

	cout << "\n#----------Slots available for " << selectedDate << "----------#\n\n";

	//Print every available sessions before the last booking hour
	while (currentHour + sessionDuration <= time.LASTBOOKINGHOUR) {
		cout << "\tSlot[" << slotCount + 1 << "] " << currentHour << ":00 - " << (currentHour + sessionDuration) << ":00";

		//Check slot availability
		bool isSlotUnavailable = slotStatus[0][slotCount];

		if (isSlotUnavailable) {
			cout << " [Unavailable]";
		}

		cout << endl;

		availableSlots[slotCount][0] = currentHour;
		availableSlots[slotCount][1] = currentHour + sessionDuration;
		availableSlots[slotCount][2] = sessionDuration;

		// Move to the next time slot
		currentHour += sessionDuration;
		slotCount++;
	}

}

void selectSlot(int availableSlots[][3], bool consultationSlots[][10], bool treatmentSlots[][10], int slotCount, Date date, bool isConsultation, BookingInfo& bookingInfo) {

	string selectedDate = to_string(date.day);

	int choice, payBy = 0;
	bool isValidChoice = false;

	char yesOrNo = 'Y';

	do {

		cout << "\nPlease select a slot by entering the slot number: ";
		cin >> choice;

		//Get slot number and ensure it is a valid slot number
		if (choice >= 1 && choice <= slotCount) {
			int selectedSlot = choice - 1;

			if (isConsultation && consultationSlots[0][selectedSlot]) {
				cout << "\nSorry, this consultation slot is already booked. Please select a different slot.\n";
			}
			else if (!isConsultation && treatmentSlots[0][selectedSlot]) {
				cout << "\nSorry, this treatment slot is already booked. Please select a different slot.\n";
			}
			else {
				do {
					//Let user make sure if they really want to book the slot
					cout << "\nPressing N in this state would bring you back to the Booking Type page.\n";
					cout << "Please be aware that once booked, the fee is NON-REFUNDABLE!\n\n";
					cout << "Are you sure you want to book the slot? (y/n): ";
					cin >> yesOrNo;

					if (isalpha(yesOrNo)) {
						yesOrNo = toupper(yesOrNo);
					}

					clearScreen();

					switch (yesOrNo) {
					case 'Y':

						//Make payment
						payment(isConsultation, payBy, bookingInfo);

						// Only mark slot as booked after successful payment
						if (payBy != 0) { // Check if a valid payment method was selected
							if (isConsultation) {
								consultationSlots[0][selectedSlot] = true;

								// Disable corresponding treatment slots if they overlap
								if (selectedSlot % 2 == 0 && selectedSlot + 1 < 10) {
									treatmentSlots[0][selectedSlot / 2] = true;  // Disable corresponding 2-hour treatment
								}
							}
							else {
								treatmentSlots[0][selectedSlot] = true;

								// Disable overlapping consultation slots
								if (selectedSlot * 2 < 10) {
									consultationSlots[0][selectedSlot * 2] = true;
									consultationSlots[0][selectedSlot * 2 + 1] = true;
								}
							}

							// Save the booked slot to file
							ofstream outFile("bookedSlots.dat", ios::app);
							if (outFile.is_open()) {
								outFile << selectedDate << " " << availableSlots[selectedSlot][0] << " "
									<< availableSlots[selectedSlot][1] << " " << (selectedSlot + 1) << " " << bookingInfo.expert << "\n";
								outFile.close();
							}
							else {
								cout << "Error saving booked slot to file.\n";
							}

							cout << "\nYou have successfully booked: " << availableSlots[selectedSlot][0] << ":00 - "
								<< availableSlots[selectedSlot][1] << ":00 (" << (isConsultation ? "Consultation" : "Treatment") << ")" << endl;

							//Print receipt after the user made payment
							receipt(bookingInfo, isConsultation, selectedSlot, availableSlots, date, payBy);

							char finalChoice;

							do {


								cout << "\nPlease enter M to return to the main menu or enter enter E to exit program: ";
								cin >> finalChoice;

								if (isalpha(finalChoice)) {
									finalChoice = toupper(finalChoice);
								}

								switch (finalChoice) {
								case 'M': clearScreen(); main(); break;
								case 'E': clearScreen(); exitProgram(); break;
								default: clearScreen(); cout << "\nPlease ensure that you only enter M or E!\n";
								}


							} while (finalChoice != 'M' && finalChoice != 'E');

							isValidChoice = true;  // Exit loop on valid choice
						}
						else {
							cout << "Payment was not completed. Slot booking was not finalized.\n";
						}

						break;
					case 'N':

						bookServicePage(bookingInfo);
						break;

					default:
						cout << "\nPlease ensure that you only enter Y or N!\n";
					}

				} while (yesOrNo != 'Y' && yesOrNo != 'N');
			}
		}
		else {
			cout << "\nInvalid choice! Please select a valid slot number." << endl;
		}
	} while (!isValidChoice);
}

void payment(bool isConsultation, int& payBy, BookingInfo& bookingInfo) {

	char userChoice;
	double amount = isConsultation ? 150 : 200;
	string sessionType = isConsultation ? "Consultation" : "Treatment";

	enum PaymentMethod {TNG = 1, ONLINEBANKING, CREDITCARD, DEBITCARD};

	clearScreen();

	cout << "\n#----------Total Amount for " << sessionType << "----------#\n\n";
	cout << setw(21) << fixed << setprecision(2) << "RM" << amount << endl;


	cout << "\n#----------Payment Method----------#\n\n";
	cout << "(1) TNG\n";
	cout << "(2) Online Banking\n";
	cout << "(3) Credit Card\n";
	cout << "(4) Debit Card\n";
	cout << "(B) Back\n";
	cout << "(E) Exit\n";
	
	do {

		cout << "\nPressing Back in this state would bring you back to the Booking Type page.\n";
		cout << "Key in the represented key to select the activitiies(1/2/B/E...) : ";
		cin >> userChoice;

		if (isalpha(userChoice)) {
			userChoice = toupper(userChoice);
		}

		clearScreen();

		switch (userChoice) {
		case '1':
			cout << "\nYou have made payment through TNG successfully!\n";
			payBy = 1;
			break;
		case '2':
			cout << "\nYou have made payment through through Online Banking successfully!\n";	
			payBy = 2;
			break;
		case '3':
			cout << "\nYou have made payment through Credit Card successfully!\n";
			payBy = 3;
			break;
		case '4':
			cout << "\nYou have made payment through Debit Card successfully!\n";
			payBy = 4;
			break;
		case 'B':
			clearScreen();
			bookServicePage(bookingInfo);
			break;
		case 'E':
			clearScreen();
			exitProgram();
			break;
		default:
			cout << "\nPlease enter only 1,2,3,4,B or E!\n";
		}

	} while (userChoice != '1' && userChoice != '2' && userChoice != '3' && userChoice != '4' && userChoice != 'B' && userChoice != 'E');

}

void receipt(BookingInfo& bookingInfo, bool isConsultation, int selectedSlot, int availableSlots[][3], Date date, int payBy) {

	string payMethod;
	string sessionType = isConsultation ? "Consultation" : "Treatment";
	string amount = isConsultation ? "150.00" : "200.00";

	//Get the latest booking Number from bookNum
	bookingInfo.count = bookNum();

	switch (payBy) {
	case 1: payMethod = "TNG"; break;
	case 2: payMethod = "OnlineBanking"; break;
	case 3: payMethod = "CreditCard"; break;
	case 4:	payMethod = "DebitCard"; break;
	default: payMethod = "Unknown";	break;
	}

	cout << "\n#----------------Receipt-----------------#\n\n";
	cout << "Booking Number: " << "B" << bookingInfo.count << endl;
	cout << "Expert: " << bookingInfo.expert << endl;
	cout << "Customer: " << bookingInfo.customer.name << endl;
	cout << "Payment Type: " << payMethod << endl;
	cout << "Booking Type: " << sessionType << endl;
	cout << "Service Type: " << bookingInfo.serviceType << endl;
	cout << "Fee: " << amount << endl;
	cout << "Date: " << date.day << "/" << date.month << "/" << date.year << endl;
	cout << "Time Range: " << availableSlots[selectedSlot][0] << ":00 to " << availableSlots[selectedSlot][1] << ":00" << endl;
	cout << "\n#----------Queen Beauty Service----------#\n\n";

	saveReceipt(bookingInfo, payMethod, sessionType, amount, date, availableSlots, selectedSlot);
	
}

void saveReceipt(BookingInfo& bookingInfo, string payMethod, string sessionType, string amount, Date date, int availableSlots[][3], int selectedSlot) {

	ofstream outReceiptFile("receipt.dat", ios::app);

	if (!outReceiptFile) {
		cout << "Error: Unable to open receipt.dat. Please ensure the file exists in the correct directory.";
	}

	outReceiptFile << bookingInfo.count << " " << bookingInfo.expert << " " << bookingInfo.customer.name << " "
		<< payMethod << " " << sessionType << " " << bookingInfo.serviceType << " " << amount << " "
		<< date.day << " " << date.month << " " << date.year << " " << availableSlots[selectedSlot][0] << " " << availableSlots[selectedSlot][1] << endl;

	outReceiptFile.close();

}

int bookNum() {
	int count = 0; // Initialize count to 0

	// Open the file to read the current booking number
	ifstream inBookNumFile("bookNum.dat");

	if (!inBookNumFile) {
		cout << "Error: Unable to open bookNum.dat. Please ensure the file exists in the correct directory.\n";
		return -1; // Return an error code
	}

	// Read the current booking number
	inBookNumFile >> count;
	inBookNumFile.close();

	// Increment the booking number
	count++;

	// Open the file to write the updated booking number
	ofstream outBookNumFile("bookNum.dat");

	if (!outBookNumFile) {
		cout << "Error: Unable to open bookNum.dat. Please ensure the file exists in the correct directory.";
		return -1; // Return an error code
	}

	// Write the updated booking number to the file
	outBookNumFile << count << endl;
	outBookNumFile.close();

	return count; // Return the updated booking number
}

void appointmentPage(BookingInfo& bookingInfo) {

	ifstream inReceiptFile("receipt.dat");

	if (!inReceiptFile) {
		cout << "Error: Unable to open receipt.dat. Please ensure the file exists in the correct directory.\n";
		return;
	}

	string bookingNumber, expert, customer, payMethod, sessionType, serviceType, amount;
	int day, month, year, startTime, endTime;

	bool hasBookings = false;

	cout << "\n#---------- Schedule for " << bookingInfo.customer.name << " ----------#\n";

	while (inReceiptFile >> bookingNumber >> expert >> customer >> payMethod >> sessionType
		>> serviceType >> amount >> day >> month >> year >> startTime >> endTime) {

		// Check if the customer name is file is same as current customer
		if (customer == bookingInfo.customer.name) {
			hasBookings = true;
			cout << "\nBooking Number: B" << bookingNumber;
			cout << "\nExpert: " << expert;
			cout << "\nService: " << serviceType;
			cout << "\nSession Type: " << sessionType;
			cout << "\nAmount Paid: RM" << amount;
			cout << "\nDate: " << day << "/" << month << "/" << year;
			cout << "\nTime: " << startTime << ":00 to " << endTime << ":00";
			cout << "\n---------------------------------------\n";
		}
	}

	if (!hasBookings) {
		cout << "No bookings found for " << bookingInfo.customer.name << ".\n";
	}

	inReceiptFile.close();

	char appointmentPageSelection;

	do {
		cout << "Please enter B to return to last page or enter E to Exit: ";
		cin >> appointmentPageSelection;

		if (isalpha(appointmentPageSelection)) {
			appointmentPageSelection = toupper(appointmentPageSelection);
		}

		switch (appointmentPageSelection) {
		case 'B': clearScreen(); customerOptionPage(bookingInfo); break;
		case 'E': clearScreen(); exitProgram(); break;
		default: cout << "\nPlease ensure that you enter only B or E!\n";
		}
	} while (appointmentPageSelection != 'B' && appointmentPageSelection != 'E');
}

void aboutUsPage() {

	char aboutSelection;

	cout << "\n    ============================================================================================\n";
	cout << setw(55) << "About us\n";
	cout << "    ============================================================================================\n\n";

	cout << "\tWelcome to Queen Beauty Service, a premier beauty center located in Malaysia,\n";
	cout << "\tdedicated to enhancing your natural beauty and well-being.\n";
	cout << "\n\tOur team of three experts is committed to providing top-notch services,\n";
	cout << "\tworking exclusively from Monday to Friday.\n";
	cout << "\n\tWe specialize in offering 2-hour personalized treatment sessions along with a 1-hour\n";
	cout << "\tconsultation to ensure that each client receives the best care and advice.\n";
	cout << "\n\tOur services include body treatments, botox, and scar removal,\n";
	cout << "\tall designed to rejuvenate your body and mind.\n";
	cout << "\n\tAt Queen Beauty Service, your beauty and health are our priorities.\n\n";

	cout << "    ============================================================================================\n\n";

	do {

		cout << "Enter B to back to last selection or enter E to exit: ";
		cin >> aboutSelection;

		if (isalpha(aboutSelection)) {
			aboutSelection = toupper(aboutSelection);
		}

		clearScreen();

		switch (aboutSelection) {
		case 'B': customerPage(); break;
		case 'E': exitProgram(); break;
		default: cout << "Please enter only B or E!\n\n";
		}

	} while (aboutSelection != 'B' && aboutSelection != 'E');

}

void adminPage() {

	char adminSelection;

	cout << "\n#----------Admin----------#\n\n";
	cout << "(1) Login\n";
	cout << "(2) Register\n";
	cout << "(B) Back\n";
	cout << "(E) Exit";

	do {

		cout << "\n\nKey in the represented key to select the activitiies (1/2/B/E...): ";
		cin >> adminSelection;

		if (isalpha(adminSelection)) {
			adminSelection = toupper(adminSelection);
		}

		clearScreen();

		switch (adminSelection) {
		case '1': adminLoginPage(); break;
		case '2': adminRegisterPage(); break;
		case 'B': main(); break;
		case 'E': exitProgram(); break;
		default: cout << "Please enter only 1,2,B or E!";
		}

	} while (adminSelection != '1' && adminSelection != '2' && adminSelection != 'B' && adminSelection != 'E');

}

void adminLoginPage() {

	Admin admin;

	string userInputEmail, userInputPassword;
	string expertName;

	bool existingLogin = false;

	do {

		cout << "\nEmail: ";
		cin >> userInputEmail;

		cout << "Password: ";
		cin >> userInputPassword;

		ifstream inAdminDetailFile("adminDetail.dat");

		if (!inAdminDetailFile) {
			cout << "Error: Unable to open adminDetail.dat. Please ensure the file exists in the correct directory." << endl;
		}

		while (inAdminDetailFile >> admin.name >> admin.age >> admin.contactNum >> admin.email >> admin.password) {
			if (userInputEmail == admin.email && userInputPassword == admin.password) {
				//Assign current admin name if the userInputEmail and userInputPassword exist
				expertName = admin.name;

				existingLogin = true;
				break;
			}
		}

		inAdminDetailFile.close();

		if (!existingLogin) {
			cout << "\nInvalid email or password. Please try again！\n";
		}

	} while (!existingLogin);

	clearScreen();

	cout << "\nYou have successfully Login!\n";

	adminOptionPage(expertName);

}

void adminRegisterPage() {

	Admin admin;
	bool validEmail = false, validPassword = false;

	ofstream outAdminDetailFile;
	outAdminDetailFile.open("adminDetail.dat", ios::app);

	if (!outAdminDetailFile) {
		cout << "Error: Unable to open adminDetail.dat. Please ensure the file exists in the correct directory.";
	}

	examplePersonalDetails();

	cout << "\n#----------Personal Details----------#\n";

	cout << "\nName: ";
	cin.get();
	getline(cin, admin.name);

	do {
		if (admin.age <= 0) {
			cout << "Invalid age!\n";
			clearScreen();
			examplePersonalDetails();
			cout << "\n#----------Personal Details----------#\n";

			cout << "\nName: " << admin.name << endl;
		}
		cout << "Age: ";
		cin >> admin.age;
	} while (admin.age <= 0);

	do {
		if (admin.contactNum[0] != '0' || admin.contactNum.length() != 10) {
			cout << "Invalid contact number!\n";
			clearScreen();
			examplePersonalDetails();
			cout << "\n#----------Personal Details----------#\n";

			cout << "\nName: " << admin.name << endl;
			cout << "Age: " << admin.age << endl;
		}
		cout << "Contact Number: ";
		cin >> admin.contactNum;
	} while (admin.contactNum[0] != '0' || admin.contactNum.length() != 10);

	clearScreen();
	cout << "\nPersonal Details successfully recorded";

	do {

		exampleRegistration();

		cout << "\n#----------Register Account----------#\n";
		cout << "\nEmail: ";
		cin >> admin.email;

		cout << "Password: ";
		cin >> admin.password;

		clearScreen();

		validEmail = emailIsValid(admin.email);

		if (!validEmail) {
			cout << "\nA valid email account should contain @ and .com!";
		}

		validPassword = passwordIsValid(admin.password);

		if (!validPassword) {
			cout << "\nA valid password should contain 10 characters with uppercase, lowercase, digit and special character!";
		}

	} while (!validEmail || !validPassword);

	outAdminDetailFile << admin.name << " " << admin.age << " " << admin.contactNum << " " << admin.email << " " << admin.password << endl;
	outAdminDetailFile.close();

	clearScreen();

	cout << "\nSuccessfully registered!\n";
	cout << "Please Login again\n\n";

	adminLoginPage();

}

void adminOptionPage(string expertName) {

	char adminOption;

	cout << "\n#----------Options----------#\n\n";
	cout << "(1) Individual Schedule\n";
	cout << "(2) Overall Schedule\n";
	cout << "(3) Customer Detail\n";
	cout << "(4) Sales reports\n";
	cout << "(B) Back\n";
	cout << "(E) Exit";

	do {

		cout << "\n\nKey in the represented key to select the activitiies (1/2/B/E...): ";
		cin >> adminOption;

		if (isalpha(adminOption)) {
			adminOption = toupper(adminOption);
		}

		clearScreen();

		switch (adminOption) {
		case '1': individualSchedulePage(expertName); break;
		case '2': overallSchedulePage(expertName); break;
		case '3': customerDetailsPage(expertName); break;
		case '4': salesReportPage(expertName); break;
		case 'B': adminPage(); break;
		case 'E': exitProgram(); break;
		default: cout << "Please enter only 1,2,3,4,B or E!";
		}

	} while (adminOption != '1' && adminOption != '2' && adminOption != '3' && adminOption != '4' && adminOption != 'B' && adminOption != 'E');
}

void individualSchedulePage(const string& expertName) {
	string customerName;

	// Prompt the admin to input the customer name for searching
	cout << "\nPlease enter customer name to search for individual schedule: ";
	cin >> customerName;

	// Open the file
	ifstream inReceiptFile("receipt.dat");
	if (!inReceiptFile) {
		cout << "Error: Unable to open receipt.dat. Please ensure the file exists in the correct directory.\n";
		return;
	}

	// Arrays to store the booking details
	string bookingNumber[100], expert[100], customer[100], payMethod[100], sessionType[100], serviceType[100], amount[100];
	int day[100], month[100], year[100], startTime[100], endTime[100];

	int count = 0;  // Track how many records are found

	// Read data into parallel arrays
	while (inReceiptFile >> bookingNumber[count] >> expert[count] >> customer[count] >> payMethod[count] >> sessionType[count]
		>> serviceType[count] >> amount[count] >> day[count] >> month[count] >> year[count] >> startTime[count] >> endTime[count]) {
		count++;
	}

	// Close the file
	inReceiptFile.close();

	// Array to store the found bookings
	string foundBookingNumber[100], foundSessionType[100], foundServiceType[100], foundAmount[100], foundPayMethod[100];
	int foundDay[100], foundMonth[100], foundYear[100], foundStartTime[100], foundEndTime[100];
	int foundCount = 0;  // Track found bookings

	// Linear search for bookings matching the expert and customer
	for (int i = 0; i < count; i++) {
		if (expert[i] == expertName && customer[i] == customerName) {
			foundBookingNumber[foundCount] = bookingNumber[i];
			foundSessionType[foundCount] = sessionType[i];
			foundServiceType[foundCount] = serviceType[i];
			foundAmount[foundCount] = amount[i];
			foundDay[foundCount] = day[i];
			foundMonth[foundCount] = month[i];
			foundYear[foundCount] = year[i];
			foundStartTime[foundCount] = startTime[i];
			foundEndTime[foundCount] = endTime[i];
			foundPayMethod[foundCount] = payMethod[i];
			foundCount++;
		}
	}

	if (foundCount == 0) {
		cout << "No bookings found for " << expertName << " and customer " << customerName << ".\n";
		return;
	}

	// Bubble sort to sort the found bookings by date and time
	for (int outerIndex = 0; outerIndex < foundCount - 1; outerIndex++) {
		for (int innerIndex = 0; innerIndex < foundCount - outerIndex - 1; innerIndex++) {
			// Compare days first, then start time
			if (foundDay[innerIndex] > foundDay[innerIndex + 1] ||
				(foundDay[innerIndex] == foundDay[innerIndex + 1] && 
					foundMonth[innerIndex] > foundMonth[innerIndex + 1]) ||
				(foundDay[innerIndex] == foundDay[innerIndex + 1] && 
					foundMonth[innerIndex] == foundMonth[innerIndex + 1] && 
					foundYear[innerIndex] > foundYear[innerIndex + 1]) ||
				(foundDay[innerIndex] == foundDay[innerIndex + 1] && 
					foundMonth[innerIndex] == foundMonth[innerIndex + 1] && 
					foundYear[innerIndex] == foundYear[innerIndex + 1] && 
					foundStartTime[innerIndex] > foundStartTime[innerIndex + 1])) {

				// Swap all arrays if the date or time is out of order
				swap(foundBookingNumber[innerIndex], foundBookingNumber[innerIndex + 1]);
				swap(foundSessionType[innerIndex], foundSessionType[innerIndex + 1]);
				swap(foundServiceType[innerIndex], foundServiceType[innerIndex + 1]);
				swap(foundAmount[innerIndex], foundAmount[innerIndex + 1]);
				swap(foundDay[innerIndex], foundDay[innerIndex + 1]);
				swap(foundMonth[innerIndex], foundMonth[innerIndex + 1]);
				swap(foundYear[innerIndex], foundYear[innerIndex + 1]);
				swap(foundStartTime[innerIndex], foundStartTime[innerIndex + 1]);
				swap(foundEndTime[innerIndex], foundEndTime[innerIndex + 1]);
				swap(foundPayMethod[innerIndex], foundPayMethod[innerIndex + 1]);
			}
		}
	}


	// Display the sorted bookings with cleaner formatting
	cout << "\n#---------- Schedule for " << customerName << " ----------#\n\n";

	// Print table headers
	cout << left << setw(12) << "Booking No"
		<< setw(15) << "Customer"
		<< setw(15) << "Service Type"
		<< setw(15) << "Session Type"
		<< setw(14) << "Amount Paid"
		<< setw(14) << "Date"
		<< setw(16) << "Time Range"
		<< setw(15) << "Payment Type" << endl;

	cout << string(115, '-') << endl;  // Separator line

	// Display sorted bookings
	for (int i = 0; i < foundCount; i++) {
		cout << left << setw(12) << ("B" + foundBookingNumber[i])
			<< setw(15) << customerName
			<< setw(15) << foundServiceType[i]
			<< setw(15) << foundSessionType[i]
			<< setw(14) << ("RM" + foundAmount[i])
			<< right << setw(2) << foundDay[i] << "/" << setw(2) << foundMonth[i] << "/" << setw(4) << foundYear[i]  // Date format
			<< setw(6) << foundStartTime[i] << ":00 - " << left << setw(2) << foundEndTime[i] << setw(6) << ":00"  // Time range
			<< setw(15) << foundPayMethod[i] << endl;  // Adjust payment type display as needed
	}

	cout << endl << string(115, '-') << endl;

	// Allow admin to return to previous page or exit
	char individualSchSelection;
	do {
		cout << "\nPlease enter B to return to the last page or enter E to Exit: ";
		cin >> individualSchSelection;

		if (isalpha(individualSchSelection)) {
			individualSchSelection = toupper(individualSchSelection);
		}

		switch (individualSchSelection) {
		case 'B': clearScreen(); adminOptionPage(expertName); break;
		case 'E': clearScreen(); exitProgram(); break;
		default: cout << "\nPlease ensure that you enter only B or E!\n";
		}
	} while (individualSchSelection != 'B' && individualSchSelection != 'E');
}

void overallSchedulePage(const string& expertName) {
	ifstream inReceiptFile("receipt.dat");

	if (!inReceiptFile) {
		cout << "Error: Unable to open receipt.dat. Please ensure the file exists in the correct directory.\n";
		return;
	}

	string bookingNumber, expert, customer, payMethod, sessionType, serviceType, amount;
	int day, month, year, startTime, endTime;

	// Arrays to store bookings for each week
	const int WEEKSINMONTH = 5;
	string weekBookings[WEEKSINMONTH][31];
	bool hasBookings[WEEKSINMONTH] = { false };

	while (inReceiptFile >> bookingNumber >> expert >> customer >> payMethod >> sessionType
		>> serviceType >> amount >> day >> month >> year >> startTime >> endTime) {

		if (expert == expertName) {
			int weekIndex;
			if (day >= 1 && day <= 4) weekIndex = 0;
			else if (day >= 7 && day <= 11) weekIndex = 1;
			else if (day >= 14 && day <= 18) weekIndex = 2;
			else if (day >= 21 && day <= 25) weekIndex = 3;
			else if (day >= 28 && day <= 31) weekIndex = 4;
			else continue; // Skip invalid days

			// Store booking details in the appropriate week
			weekBookings[weekIndex][day - 1] = "Date: " + to_string(day) + " | Time: " + to_string(startTime) + ":00 to " + to_string(endTime) + " | ";
			hasBookings[weekIndex] = true;
		}
	}

	inReceiptFile.close();

	// Display schedule
	cout << "\n#---------- Overall Schedule for " << expertName << " ----------#\n";

	for (int weekIndex = 0; weekIndex < WEEKSINMONTH; ++weekIndex) {
		if (hasBookings[weekIndex]) {
			cout << "\n#---------- Week " << weekIndex + 1 << " ----------#\n";
			for (int day = 0; day < 31; ++day) {
				//Print the stored booking details if the booking exist
				if (!weekBookings[weekIndex][day].empty()) {
					cout << weekBookings[weekIndex][day];
				}
			}
			cout << "\n";
		}
	}

	char overallSchSelection;
	do {
		cout << "\nPlease enter B to return to the last page or E to Exit: ";
		cin >> overallSchSelection;

		if (isalpha(overallSchSelection)) {
			overallSchSelection = toupper(overallSchSelection);
		}

		switch (overallSchSelection) {
		case 'B': clearScreen(); adminOptionPage(expertName); break;
		case 'E': clearScreen(); exitProgram(); break;
		default: cout << "\nPlease ensure that you enter only B or E!\n";
		}
	} while (overallSchSelection != 'B' && overallSchSelection != 'E');
}

void customerDetailsPage(const string& expertName) {
	ifstream inCustomerDetailFile("customerDetail.dat");
	if (!inCustomerDetailFile) {
		cout << "Error: Unable to open customerDetail.dat. Please ensure the file exists in the correct directory.\n";
		return;
	}

	ifstream inReceiptFile("receipt.dat");
	if (!inReceiptFile) {
		cout << "Error: Unable to open receipt.dat. Please ensure the file exists in the correct directory.\n";
		return;
	}

	string bookingNumber, expert, custName, payMethod, sessionType, serviceType, amountStr;
	int day, month, year, startTime, endTime;

	int count = 1;
	bool hasBookings = false;

	// Array to keep track of printed customer names
	const int MAX_CUSTOMERS = 100; // Adjust as needed
	string printedCustomers[MAX_CUSTOMERS];
	int printedCount = 0;

	while (inReceiptFile >> bookingNumber >> expert >> custName >> payMethod >> sessionType
		>> serviceType >> amountStr >> day >> month >> year >> startTime >> endTime) {

		if (expert == expertName) {
			hasBookings = true;

			// Check if customer has already been displayed
			bool alreadyPrinted = false;
			for (int i = 0; i < printedCount; i++) {
				if (printedCustomers[i] == custName) {
					alreadyPrinted = true;
					break;
				}
			}

			if (!alreadyPrinted) {
				// Add customer name to the printed list
				if (printedCount < MAX_CUSTOMERS) {
					printedCustomers[printedCount++] = custName;
				}

				// Reset file position to beginning
				inCustomerDetailFile.clear();
				inCustomerDetailFile.seekg(0, ios::beg);

				// Search for the corresponding customer
				Customer customer;
				while (inCustomerDetailFile >> customer.name >> customer.age >> customer.contactNum >> customer.email >> customer.password) {
					if (customer.name == custName) {
						cout << "\n#---------- [" << count << "] Customer ----------#\n";
						cout << "Name: " << customer.name << " | "
							<< "Age: " << customer.age << " | "
							<< "Contact Number: " << customer.contactNum << " | "
							<< "Email: " << customer.email << "\n";
						count++;
						break;  // Stop after finding the matching customer
					}
				}
			}
		}
	}

	inCustomerDetailFile.close();
	inReceiptFile.close();

	if (!hasBookings) {
		cout << "No bookings found for " << expertName << ".\n";
	}

	char customerDetailSelection;
	do {
		cout << "\nPlease enter B to return to the previous menu or E to Exit: ";
		cin >> customerDetailSelection;

		if (isalpha(customerDetailSelection)) {
			customerDetailSelection = toupper(customerDetailSelection);
		}

		// Handle the user's choice
		switch (customerDetailSelection) {
		case 'B': clearScreen(); adminOptionPage(expertName); break;
		case 'E': clearScreen(); exitProgram(); break;
		default: cout << "\nPlease enter only B or E!\n";
		}
	} while (customerDetailSelection != 'B' && customerDetailSelection != 'E');
}

void salesReportPage(const string& expertName) {
	ifstream inReceiptFile("receipt.dat");

	if (!inReceiptFile) {
		cout << "Error: Unable to open receipt.dat. Please ensure the file exists in the correct directory.\n";
		return;
	}

	// Variables to read data
	string bookingNumber, expert, customer, payMethod, sessionType, serviceType, amountStr;
	int day, month, year, startTime, endTime;

	// Arrays for weekly data
	int weeklyBooking[5] = { 0 };
	int weeklyHours[5] = { 0 };
	int weeklyTreatment[5] = { 0 };
	int weeklyConsultation[5] = { 0 };
	double weeklySales[5] = { 0.0 };

	// Monthly totals
	int monthlyBooking = 0;
	int monthlyHours = 0;
	int monthlyTreatment = 0;
	int monthlyConsultation = 0;
	double monthlySales = 0.0;

	bool hasBookings = false;

	cout << "\n#--------------------------------Sales Report for " << expertName << "--------------------------------#\n";

	while (inReceiptFile >> bookingNumber >> expert >> customer >> payMethod >> sessionType
		>> serviceType >> amountStr >> day >> month >> year >> startTime >> endTime) {

		// Convert string to double
		double amount = stod(amountStr);

		// Check if the booking matches the expert name
		if (expert == expertName) {
			hasBookings = true;

			// Calculate session duration in hours
			int hours = endTime - startTime;

			// Categorize the booking by week
			int weekIndex = -1;
			if (day >= 1 && day <= 4) weekIndex = 0;
			else if (day >= 7 && day <= 11) weekIndex = 1;
			else if (day >= 14 && day <= 18) weekIndex = 2;
			else if (day >= 21 && day <= 25) weekIndex = 3;
			else if (day >= 28 && day <= 31) weekIndex = 4;

			//Calculate total session or consultation booked
			if (sessionType == "Treatment") {
				monthlyTreatment++;
				weeklyTreatment[weekIndex]++;
			}
			else if (sessionType == "Consultation") {
				monthlyConsultation++;
				weeklyConsultation[weekIndex]++;
			}

			// Update weekly data
			if (weekIndex != -1) {
				weeklyHours[weekIndex] += hours;
				weeklySales[weekIndex] += amount;
				weeklyBooking[weekIndex]++;
			}

			// Update monthly data
			monthlyHours += hours;
			monthlySales += amount;
			monthlyBooking++;
		}
	}

	inReceiptFile.close();

	// Display weekly sales report
	cout << "\n#--------------------Weekly Sales Report (Bookings, Hours, Sales)-------------------#\n";
	cout << "Week         | 1           | 2           | 3           | 4           | 5           |\n";
	cout << "#-----------------------------------------------------------------------------------#\n";
	cout << "Bookings     |";
	for (int i = 0; i < 5; i++) {
		cout << setw(13) << right << weeklyBooking[i] << "|";
	}
	cout << "\n";

	cout << "Hours        |";
	for (int i = 0; i < 5; i++) {
		cout << setw(13) << right << weeklyHours[i] << "|";
	}
	cout << "\n";

	cout << "Treatment    |";
	for (int i = 0; i < 5; i++) {
		cout << setw(13) << right << weeklyTreatment[i] << "|";
	}
	cout << "\n";

	cout << "Consultation |";
	for (int i = 0; i < 5; i++) {
		cout << setw(13) << right << weeklyConsultation[i] << "|";
	}
	cout << "\n";

	cout << "Sales(RM)    |";
	for (int i = 0; i < 5; i++) {
		cout << setw(13) << right << weeklySales[i] << "|";
	}
	cout << "\n#-----------------------------------------------------------------------------------#\n";

	// Display monthly totals
	cout << "\n#---------- Monthly Totals ----------#\n";
	cout << "Total Bookings: " << monthlyBooking << "\n";
	cout << "Total Hours: " << monthlyHours << "\n";
	cout << "Total Treatment Sessions: " << monthlyTreatment << "\n";
	cout << "Total Consultation Sessions: " << monthlyConsultation << "\n";
	cout << "Total Sales: RM " << monthlySales << "\n";

	if (!hasBookings) {
		cout << "\nNo bookings found for " << expertName << ".\n";
	}

	char salesReportSelection;

	do {
		cout << "\nPlease enter B to return to the previous menu or E to Exit: ";
		cin >> salesReportSelection;

		if (isalpha(salesReportSelection)) {
			salesReportSelection = toupper(salesReportSelection);
		}

		switch (salesReportSelection) {
		case 'B': clearScreen(); adminOptionPage(expertName); break;
		case 'E': clearScreen(); exitProgram(); break;
		default: cout << "\nPlease enter only B or E!\n";
		}
	} while (salesReportSelection != 'B' && salesReportSelection != 'E');
}