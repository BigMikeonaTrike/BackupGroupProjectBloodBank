// The Group Project will be based on the NZ Blood Bank System.
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Objects

struct userDonor
{

    // User Attributes

    std::string firstName;
    std::string lastName;
    std::string dob;
    std::string nationality;
    std::string ethnicity;
    std::string gender;
    std::string healthConditions; // This needs to be a vecotr for multiple condition?.
    std::string bloodGroup;
    std::string contactNum;
    std::string email;
    std::string physAddress;

    // Donator Only
    std::string prevDonate;

    // Booking Details - Leave blank until case 4 on donorMenu()

    std::string date;
    std::string time;
    std::string venue;

    // Login Details

    std::string username;
    std::string password;

    //Constructor

    userDonor() {};

    userDonor(std::string fName, std::string lName, std::string date, std::string nat, std::string eth, std::string gen, std::string healthCon, std::string bloodG, std::string contactN, std::string em, std::string physAdd, std::string prevD, std::string user, std::string pass) {

        firstName = fName;
        lastName = lName;
        dob = date;
        nationality = nat;
        ethnicity = eth;
        gender = gen;
        healthConditions = healthCon;
        bloodGroup = bloodG;
        contactNum = contactN;
        email = em;
        physAddress = physAdd;
        prevDonate = prevD;
        username = user;
        password = pass;

    }

};

struct userRes
{

    // Attributes

    std::string recipient;
    std::string physAddress;
    std::string email;
    std::string contactNum;
    std::string validationStatus;

    // Login Details

    std::string username;
    std::string password;

    //Constructor

    userRes() {}

    userRes(std::string recip, std::string physAdd, std::string em, std::string contactN, std::string val, std::string user, std::string pass) {

        recipient = recip;
        physAddress = physAdd;
        email = em;
        contactNum = contactN;
        validationStatus = val;
        username = user;
        password = pass;

    }

};

// Global/Field Variables *****************************************************************


vector<userDonor> donorList;
vector<userRes> resList;

int registeredDonors = 0;
int registeredRes = 0;

userDonor currentDonor;
userRes currentRes;

int loginAttempts = 0;
std::ofstream donorFile;
std::ofstream recFile;

bool prevMenu = false;

map<int, userDonor> donationTimeTable;

// Global/Field Variables *****************************************************************


void readDonorFiles() {

    // Variables:

    std::string line;

    // New Donor User

    std::string firstName;
    std::string lastName;
    std::string dob;
    std::string nationality;
    std::string ethnicity;
    std::string gender;
    std::string healthConditions;
    std::string bloodGroup;
    std::string contactNum;
    std::string email;
    std::string physAddress;
    std::string prevDonate;
    std::string username;
    std::string password;

    ifstream inFile("donorFile.csv", ios::in);


    while (getline(inFile, line)) {

        stringstream seperatedLine(line);

        getline(seperatedLine, firstName, ',');
        getline(seperatedLine, lastName, ',');
        getline(seperatedLine, dob, ',');
        getline(seperatedLine, nationality, ',');
        getline(seperatedLine, ethnicity, ',');
        getline(seperatedLine, gender, ',');
        getline(seperatedLine, healthConditions, ',');
        getline(seperatedLine, bloodGroup, ',');
        getline(seperatedLine, contactNum, ',');
        getline(seperatedLine, email, ',');
        getline(seperatedLine, physAddress, ',');
        getline(seperatedLine, prevDonate, ',');
        getline(seperatedLine, username, ',');
        getline(seperatedLine, password, ',');

        userDonor newUser = userDonor(firstName, lastName, dob, nationality, ethnicity, gender, healthConditions, bloodGroup, contactNum, email, physAddress, prevDonate, username, password);

        //donorList.insert(donorList.begin(),newUser);

        donorList.push_back(newUser);

        registeredDonors++;

    }


}

void readRecFiles() {

    // Variables:

    std::string line;

    // New Rec User

    std::string recipient;
    std::string physAddress;
    std::string email;
    std::string contactNum;
    std::string validationStatus;
    std::string username;
    std::string password;

    ifstream inFile("recFile.csv", ios::in);

    while (getline(inFile, line)) {

        stringstream seperatedLine(line);

        getline(seperatedLine, recipient, ',');
        getline(seperatedLine, physAddress, ',');
        getline(seperatedLine, email, ',');
        getline(seperatedLine, contactNum, ',');
        getline(seperatedLine, validationStatus, ',');
        getline(seperatedLine, username, ',');
        getline(seperatedLine, password, ',');

        userRes newUser = userRes(recipient, physAddress, email, contactNum, validationStatus, username, password);

        resList.push_back(newUser);

        registeredRes++;
    }

}

int donorMenu() {
    std::cout << "\n\t\t Donor Menu\n\n";
    std::cout << "**************************************************************\n";
    std::cout << "*                                                            *\n";
    std::cout << "*                1. Procedure to donate blood                *\n";
    std::cout << "*                2. Benefits of blood donation               *\n";
    std::cout << "*                3. Change Info                              *\n";
    std::cout << "*                4. Book for donation                        *\n";
    std::cout << "*                5. Return to Login/Registration             *\n";
    std::cout << "*                                                            *\n";
    std::cout << "**************************************************************\n";


    int choice;
    int tracker = 0;

    std::cout << "\n\nPlease select a choice by entering the coresponding number. ";
    std::cin >> choice;

    switch (choice)
    {

        // Procedure to donate blood:

    case 1:
        std::cout << "********************************************************************************************************************************************\n";
        std::cout << "*                                                                                                                                          *\n";
        std::cout << "*             A blood donation can take up to 60 minutes (includes registration, donation and recovery).                                   *\n";
        std::cout << "*               The blood is collected in a sterile bag, and time on the bed can take about 5 to 10 minutes.                               *\n";
        std::cout << "*              A unit of blood(around 470 ml) will be collected.The needle is then removed and a bandage is applied.                       *\n";
        std::cout << "*                                                                                                                                          *\n";
        std::cout << "********************************************************************************************************************************************\n";

        donorMenu();

        //Benefits of blood donations

    case 2:
        std::cout << "********************************************************************************************************************************************\n";
        std::cout << "*                                                                                                                                          *\n";
        std::cout << "*                                Giving blood may lower your risk of sffering a heart attack.                                              *\n";
        std::cout << "*                                Giving blood can help your liver stay healthy.                                                            *\n";
        std::cout << "*                                Giving blood can reduce harmful iron stores                                                               *\n";
        std::cout << "*                                                                                                                                          *\n";
        std::cout << "********************************************************************************************************************************************\n";
        donorMenu();

    case 3:

        //manage info

        tracker = 0;

        for (userDonor d : donorList) {

            if (d.username == currentDonor.username) {

                std::cout << "************************************************************************************************************************\n";
                std::cout << "*                                                                                                                      *\n";
                std::cout << "*                                        Whats is your first name?                                                     *\n";
                std::cin >> donorList[tracker].firstName;

                std::cout << "*                                        Whats is your last name?                                                      *\n";
                std::cin >> donorList[tracker].lastName;

                std::cout << "                  Whats is your Date of birth? (Use '00/00/00' Format )                                                *\n";
                std::cin >> donorList[tracker].dob;

                std::cout << "*                                        Whats is your Nationality?                                                    *\n";
                std::cin >> donorList[tracker].nationality;

                std::cout << "*                                        Whats is your Ethnicity?                                                      *\n";
                std::cin >> donorList[tracker].ethnicity;

                std::cout << "*                                        Whats is your Gender?                                                         *\n";
                std::cin >> donorList[tracker].gender;

                std::cout << "*                                        Do you have any current health conditions?                                    *\n";
                std::cin >> donorList[tracker].healthConditions;

                std::cout << "*                                        Whats is your Blood Group?                                                    *\n";
                std::cin >> donorList[tracker].bloodGroup;

                std::cout << "*                                        Whats is your contact email?                                                  *\n";
                std::cin >> donorList[tracker].email;

                std::cout << "*                                        Whats is your Physical Address?                                               *\n";
                std::cin >> donorList[tracker].physAddress;

                std::cout << "*                What is the last date of your Blood donation? (Use '00/00/00' Format or Enter 'None' if you have'nt   *\n";
                std::cin >> donorList[tracker].prevDonate;

                std::cout << "*                                        Enter your desired Username                                                   *\n";
                std::cin >> donorList[tracker].username;

                std::cout << "*                                        Enter your desired Password                                                   *\n";
                std::cin >> donorList[tracker].password;
                std::cout << "*                                                                                                                      *\n";
                std::cout << "************************************************************************************************************************\n";

            }
            else {

                tracker++;

            }

        }

        donorMenu();


    case 4:

        tracker = 0;

        for (userDonor d : donorList) {

            if (d.username == currentDonor.username) {

                std::cout << "Full Name:\t" << donorList[tracker].firstName << " " << currentDonor.lastName << std::endl;
                std::cout << "Date of Birth:\t" << donorList[tracker].dob << std::endl;
                std::cout << "Any recent health condition(s):\t" << donorList[tracker].healthConditions << std::endl;

                if (donorList[tracker].date.empty() && donorList[tracker].time.empty()) {

                    std::cout << "Enter a date for when you'll donate your Blood (00/00/00 Format)";

                    //std::cin >> donorList[tracker].date;

                    for (userDonor ds : donorList) {


                        //ds.

                    }


                }

            }
            else {

                tracker++;

            }

        }



    case 5:

        prevMenu = 1;
        return false;

    default:
        break;
    }

}

void resMenu() {
    std::cout << "\n                               Recipient Menu\n\n";
    std::cout << "**********************************************************************************\n";
    std::cout << "*                1. Access donor information by blood group                      *\n";
    std::cout << "*                2. Access donors by blood group and location                    *\n";
    std::cout << "*                3. Potential donors contact details, find by name               *\n";
    std::cout << "*                                                                                *\n";
    std::cout << "**********************************************************************************\n";
    int choice;

    std::cout << "\n\nPlease select a choice by entering the coresponding number. ";
    std::cin >> choice;
    switch (choice) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;


    default:
        break;
    }



}


//EST
void adminMenu() {
    std::cout << "\n                                  Admin Menu\n\n";
    std::cout << "**********************************************************************************\n";
    std::cout << "*                1.                                                              *\n";
    std::cout << "*                2.                                                              *\n";
    std::cout << "*                3.                                                              *\n";
    std::cout << "*                                                                                *\n";
    std::cout << "**********************************************************************************\n";

    int choice;

    std::cout << "\n\nPlease select a choice by entering the coresponding number. ";
    std::cin >> choice;
    switch (choice) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        break;
    }
}

// Introduction

void introduction() {

    std::cout << "\n\t    The Blood Bank of New Zealand\n\n";

    std::cout << "*****************************************************\n";
    std::cout << "*                      About Us:                    *\n";
    std::cout << "* We are a New Zealand organisation that is aimming *\n";
    std::cout << "* to help get people who are in need of blood. Any  *\n";
    std::cout << "* donations we recieve is given to people in need!  *\n";
    std::cout << "*                                                   *\n";
    std::cout << "*                     Contact                       *\n";
    std::cout << "*           Phone Number: 022 196 9532              *\n";
    std::cout << "*           Address: 68 Mohaka Street               *\n";
    std::cout << "*           Open: Saturdays - Sundays               *\n";
    std::cout << "*                                                   *\n";
    std::cout << "*****************************************************\n";

}

bool recipientLogin() {

    std::string username;
    std::string password;

    std::cout << "\nPlease enter your Username: ";
    std::cin >> username;

    std::cout << "\nPlease enter your Password: ";
    std::cin >> password;

    for (userRes res : resList) {

        if ((res.username == username) || ("admin" == username)) {

            if ((res.password == password) || ("password" == password)) {

                currentRes = res;
                currentDonor = userDonor();
                return true;

            }

        }

    }

    loginAttempts++;

    if (loginAttempts >= 3) {

        std::cout << "\n\nToo many incorrect attempts. You have been returned to the Initial Menu ";
        loginAttempts = 0;
        return false;

    }
    else {

        recipientLogin();

    }

    return false;
}

bool donorLogin() {

    std::string username;
    std::string password;

    std::cout << "\nPlease enter your Username: ";
    std::cin >> username;

    std::cout << "\nPlease enter your Password: ";
    std::cin >> password;

    for (userDonor don : donorList) {


        if ((don.username == username) || ("admin" == username)) {

            if ((don.password == password) || ("password" == password)) {

                currentDonor = don;
                currentRes = userRes();
                return true;

            }

        }

    }

    loginAttempts++;

    if (loginAttempts >= 3) {

        std::cout << "\n\nToo many incorrect attempts. You have been returned to the Initial Menu ";
        loginAttempts = 0;
        return false;

    }
    else {

        donorLogin();

    }

    return false;

}

bool adminLogin() {

    std::string username;
    std::string password;

    std::cout << "\nPlease enter your Username: ";
    std::cin >> username;

    std::cout << "\nPlease enter your Password: ";
    std::cin >> password;


    if ("admin" == username) {

        if ("password" == password) {


            return true;

        }

    }


    loginAttempts++;

    if (loginAttempts >= 3) {

        std::cout << "\n\nToo many incorrect attempts. You have been returned to the Initial Menu ";
        loginAttempts = 0;
        return false;

    }
    else {

        adminLogin();

    }

    return false;

}


void donorRegistration() {

    std::string firstName;
    std::string lastName;
    std::string dob;
    std::string nationality;
    std::string ethnicity;
    std::string gender;
    std::string healthConditions;
    std::string bloodGroup;
    std::string contactNum;
    std::string email;
    std::string physAddress;
    std::string prevDonate;
    std::string username;
    std::string password;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    donorFile.open("donorFile.csv", std::ios::app);
    donorFile << "\n";

    std::cout << "\nWhats is your first name?: ";
    getline(std::cin, firstName);
    donorFile << firstName << ",";

    std::cout << "\nWhats is your last name?: ";
    getline(std::cin, lastName);
    donorFile << lastName << ",";

    std::cout << "\nWhats is your Date of birth? (Use '00/00/00' Format ): ";
    getline(std::cin, dob);
    donorFile << dob << ",";

    std::cout << "\nWhats is your Nationality?: ";
    getline(std::cin, nationality);
    donorFile << nationality << ",";

    std::cout << "\nWhats is your Ethnicity?: ";
    getline(std::cin, ethnicity);
    donorFile << ethnicity << ",";

    std::cout << "\nWhats is your Gender?: ";
    getline(std::cin, gender);
    donorFile << gender << ",";

    std::cout << "\nDo you have any current health conditions?: ";
    getline(std::cin, healthConditions);
    donorFile << healthConditions << ",";

    std::cout << "\nWhats is your Blood Group?: ";
    getline(std::cin, bloodGroup);
    donorFile << bloodGroup << ",";

    std::cout << "\nWhat is your Contact Number?: ";
    getline(std::cin, contactNum);
    donorFile << contactNum << ",";

    std::cout << "\nWhats is your contact email?: ";
    getline(std::cin, email);
    donorFile << email << ",";

    std::cout << "\nWhats is your Physical Address?: ";
    getline(std::cin, physAddress);
    donorFile << physAddress << ",";

    std::cout << "\nWhats is the last date of your Blood donation? (Use '00/00/00' Format or Enter 'None' if you haven't): ";
    getline(std::cin, prevDonate);
    donorFile << prevDonate << ",";

    std::cout << "\nEnter your desired Username: ";
    getline(std::cin, username);
    donorFile << username << ",";

    std::cout << "\nEnter your desired Password: ";
    getline(std::cin, password);
    donorFile << password << ",";

    userDonor newUser = userDonor(firstName, lastName, dob, nationality, ethnicity, gender, healthConditions, bloodGroup, contactNum, email, physAddress, prevDonate, username, password);

    donorList.push_back(newUser);

    donorFile.close();

    registeredDonors++;
}

void recipientRegistration() {

    std::string recipient;
    std::string physAddress;
    std::string email;
    std::string contactNum;
    std::string validationStatus;
    std::string username;
    std::string password;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    recFile.open("recFile.csv", std::ios::app);

    std::cout << "\nEnter the Name of the Hostpital OR Name of the Blood Bank OR Patient Name ";
    getline(std::cin, recipient);
    recFile << recipient << ",";

    std::cout << "\nEnter your physical address ";
    getline(std::cin, physAddress);
    recFile << physAddress << ",";

    std::cout << "\nEnter your email ";
    getline(std::cin, email);
    recFile << email << ",";

    std::cout << "\nEnter your Contact Number ";
    getline(std::cin, contactNum);
    recFile << contactNum << ",";

    std::cout << "\nEnter your Validation Status ";
    getline(std::cin, validationStatus);
    recFile << validationStatus << ",";

    std::cout << "\nEnter your desired Username ";
    getline(std::cin, username);
    recFile << username << ",";

    std::cout << "\nEnter your desired Password ";
    getline(std::cin, password);
    recFile << password << ",";

    userRes newUser = userRes(recipient, physAddress, email, contactNum, validationStatus, username, password);

    resList.push_back(newUser);

    recFile.close();

    registeredRes++;

}


// First Choice for user

void initialMenu() {

    std::cout << "\n\n";

    std::cout << "*****************************************************\n\n";
    std::cout << "*                     Menu                          *\n\n";
    std::cout << "*                Enter 1 to Login                   *\n\n";
    std::cout << "*               Enter 2 to Register                 *\n\n";
    std::cout << "*****************************************************\n\n";

    int firstChoice;

    std::cin >> firstChoice;

    std::cout << std::endl;

    switch (firstChoice)
    {

    case 1: // Login

        std::cout << "\n\t    Please Select your user type\n\n";

        std::cout << "*****************************************************\n";
        std::cout << "*                  1.)Recipient                     *\n";
        std::cout << "*                  2.)Donor                         *\n";
        std::cout << "*                  3.)AdminRecipient                *\n";
        std::cout << "*****************************************************\n";

        int loginTypeChoice;

        std::cin >> loginTypeChoice;

        switch (loginTypeChoice)
        {

        case 1:


            if (prevMenu != 1 && recipientLogin() == true) {


                resMenu();

            }
            else {

                prevMenu = 0;
                initialMenu();

            }

        case 2:

            if (prevMenu != 1 && donorLogin() == true) {

                donorMenu();

            }
            else {

                prevMenu = 0;
                initialMenu();

            }

        case 3:

            if (prevMenu != 1 && adminLogin() == true) {

                adminMenu();

            }
            else {

                prevMenu = 0;
                initialMenu();

            }

        default:
            break;
        }

        // Registration
    case 2:

        std::cout << "\n";

        std::cout << "           Are you a Donor or Recipient?\n";
        std::cout << "*****************************************************\n\n";
        std::cout << "*                Enter 1 for Recipient              *\n\n";
        std::cout << "*                  Enter 2 for Donor                *\n\n";
        std::cout << "*****************************************************\n\n";

        int registrationTypeChoice;

        std::cin >> registrationTypeChoice;

        std::cout << "\n\n";

        switch (registrationTypeChoice)
        {

        case 1:

            recipientRegistration();
            initialMenu();

        case 2:

            donorRegistration();
            initialMenu();

        default:
            break;
        }


    default:
        break;
    }
}

int main()
{
    readDonorFiles();
    readRecFiles();
    introduction();
    initialMenu();

}