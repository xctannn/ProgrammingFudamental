//**************************************************************
//  TCP 1101 - PROGRAMMING FUNDAMENTALS
//  TRIMESTER 2110
//  ASSIGNMENT - Basic Data Analysis Program (BDAP)
// 
//  TT3V GROUP 7
//
//  GROUP MEMBERS : YAW BOON ZHE 1191103296
//                  TAN XIAO CHIN 1191103157
//                  TAN WEI-ZHENG 1191103142
//                  TEOH YE ZHIAN 1191102765
//**************************************************************

#include <iostream>
#include <stdio.h>
#include <string>
#include <cctype> 
#include <cstring> 
#include <fstream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string line;                                            // for read all txt line by line
string adminNameDisplay;                                // for display admin name at the top of the menu
string usernameDisplay;                                 // for display user name at the top of the menu
string logFile = "log.txt";                             // log file name

void start();                                           // start the program

// login page functions (Wei-Zheng)
int LoginMenu();                                         //display login menu
void createAdmin();                                      //create a admin account

// admin login functions (Wei-Zheng)
int Login();
bool adminCheckPass(string,string);                      // find password in text file
bool adminCheckAdminWord(string);                        // check "admin" word
char adminPage();                                        // show admin menu
int adminCheckTxt(string,string);                        // to check deleted account , "user" word , "admin" word and passoword boolen
int checkTextForAdminUser(string);                       // check is admin or user

// change user password functions (Wei-Zheng)
void changePasswordFunction();                           // read username and password from admin
void readNewPassword(string,string);                     // read new password and send password to changeTxt
void changeTxt(char[], string);                          // change password inside the text file

// create user accounts (Wei-Zheng)
bool firstLetter(char);                                  // check first letter is capital or not
bool testUpperCase(char[]);                              // check is there capital letter inside the password
bool testDigit (char[]);                                 // check is there digi inside the password
void createNewAcc();                                     // create a new user account
void openTxt(string ,char[]);                            // open text file using username and type in password
void adminOrUser(string);                                // print "admin" or "user" in the text file
void activeOrDelete(string);                             // print "Active" or "Delete"  in the text file
void deleteUser();                                       // read username from admin and print "Delete" word inside
void deleteFunction(string);

//login to user menu functions (Wei-Zheng)
bool loginFunction();                                    // read username and password from user and check them inside the text file
bool loginFunction2(string ,string);                     // to check for deleted user and password
int checkTextForUser(string);                           // to run checkUserWord function
bool checkDeletedUser(string);                           // check "delete" word inside the text file
bool checkUserWord(string);                              // check "user" word inside the text file
bool checkPassword(string,string);                       // check password inside the username.txt file

//user menu functions (Wei-Zheng)
int menuDisplay();                                       // display user menu
void changePasswordFunctionUser();                       // change password of the login user itself

// loadFile functions (Boon Zhe)
bool isInteger(const string &);                             // Checks if the string is an integer, accepts negative integers
bool isSufficientData(const string &, char, int);           // Checks if the row in the data file has the correct amount of columns
bool isComputable(int[], int);                              // Checks if the cell is under a column that is computable
bool isCorrectDataFormat(int, const string &, int[], int);  // Checks if the data in the data file has the correct format
bool getCol(const string &, int *);                         // Gets the total amount of columns in the data file
bool build_ColumnTitleArr(const string &, string[], int);   // Builds an array that contains all the title names of the columns
bool build_ComputableArr(const string &, int[] , int);      // Builds an array that contains the computable properties of all the columns
bool getRow(const string &, int *);                         // Gets the total amount of rows in the data file
bool build_Row(int, const string &, int[], vector<int> &, int); // Builds a vector that contains all the computable cells in one row
bool build_SingleCol(int, const string &, int[], vector<int> &, int, int);  // Builds a vector that contains all the cells in one column
bool build_DoubleCol(int, int, const string &, int[],  vector<int> &, vector<int> &, int, int); // Builds two vectors that each contains all the cells in each of their columns
bool loadFile(const string &, int*, int* &, string* &, int*);   // Compiler that loads the data file's format into the program

// statistical analysis functions (Xiao Chin)
// computations menu, get user input and compile user input (Xiao Chin)
void computationMenu(string[], int,int);    // displays statistical computation menu
void startAnalysis();                       // gets user input data file name to do computation
void getRowOrCol(char&);                    // get user input row or column for the computations
void getIntInput(int&);                     // get user input a integer and clear the buffer
void getComputationOption(string, vector<int>& , vector<int>& ,vector<int>& ,vector<int>& , int, int ,int[], string []);  // gets user choose which computation to be done
void checkComputationDone(int, bool &, bool&, bool& , bool& );  // to determine what computations are done to generate report
void generateAndQuit(int, int, int, int);                       // for option 10: generate report and quit
void logComputation(int, char,int,int = 0);                     // compiles user input and write to computationLog
int userActionForRow(string, vector<int>&, int, int, int[]);    // gets user input a row number to do computation
int userActionForCol(string, vector<int>&, int, int, int[]);    // gets user input a column number to do computation
void userActionForTwoCols(string, vector<int>& , vector<int>&, int, int, int[],pair <int, int>&);      // gets user input two column number to do computation
void compileUserChoice(int, char, string, vector<int>&, vector<int>&, vector<int>&, vector<int>&, int[], int,int,int); // compiles all the user's input and decide which computation is done

// computations functions (Xiao Chin)
void buildComputableRow(vector<int>& ,int [],int);                    // returns a the vector that contains all computable data
int findMinimum(vector<int>, int, int[], char,int,int);               // finds minimum of the vector passed through
int findMaximum(vector<int>, int, int[], char,int,int);               // finds maximum of the vector passed through
double findMedian(vector<int>, int, int[], char,int,int);             // finds median of the vector passed through
double findMean(vector<int>&, int, int[], char, int&,int,int);        // finds mean of the vector passed through
double findVariance(vector<int>, int, int [], char, int,int,int);     // finds variance of the vector passed through
double findSTDV(vector<int>, int, int [], char, int,int,int);         // finds standard deviation of the vector passed through

// Pearson’s correlation functions (Xiao Chin)
double findCorrelation(vector<int>, vector<int>, int,int,pair<int, int>);                 // finds correlation of two vectors passed through
void displayCorrTable(vector<int>, vector<int>, int,double,double,double,double,double);  // displays the table of computation of the correlation

// Distinct data members functions (Xiao Chin)
void findOccurencesOfNum(vector<int>, vector<int>&, int);                                 // counts the occurrences of each number (frequency)
void displayDistinctData(vector<int>, int,int,int);                                       // displays the distinct numbers and the frequency in tabular form

// Plot a histogram functions (Xiao Chin)
void histogramMenu();                                                       // display guidelines to plot histogram
void getDatapoints(int &, int &);                                           // get user input two datapoints to plot histogram
void histogramRange(double&,double&, int&, int&);                           // calculate the range of data set and determine the bar of histogram
void groupData(vector<int>, vector<int> &, double,double, int, int, int);   // groups data based on the range (for histogram)
void plotHistogram(vector<int>, int,int,int);                               // displays histogram

// log functions (Boon Zhe)
void startLog(const string &);                                                              // Inititalizes log file
void computationLog(const string &, const string &, const string &, const string & = " ");  // Writes the computations done by a user into a log
void systemLog(const string &, const string &, const string &, const string & = " ");       // Wrties the user inputs into a log

// rename filename function (Boon Zhe)
void renameMainMenu();                                  // Main Menu to rename a file
void renameDataFileMenu();                              // Sub Menu to rename a data file
void renameReportMenu();                                // Sub Menu to rename a report file
void renameHTMLReportMenu();                            // Sub Menu to rename a HTML report file
bool renameHTMLFile(const string &, const string &);    // Renames an HTML file
bool renameDataFile(const string &, const string &);    // Renames a txt, csv, or dat file
bool renameReportFile(const string &, const string &);  // Renames a txt report file
bool checkCurrentDataFile(const string &);              // Checks for errors in the file name
bool checkCurrentReport(const string &);                // Checks for errors in the file name
bool checkCurrentHTMLReport(const string &);            // Checks for errors in the file name
bool isDataFileType(const string &);                    // Checks if the file is a txt, csv, or dat file type
bool isTXT(const string &);                             // Checks if the file is a txt file type
bool isHTML(const string &);                            // Checks if the file is a html file type
string to_Lowercase(string);                            // Converts the last 5 characters of a string to all lowercase characters

// save report function (Boon Zhe)
void clearFile(const string &);                         // Clears the content of the file
bool saveReport (const string &, const string &);       // Saves a txt file into a new file
bool saveHTMLReport (const string &, const string &);   // Saves a html file into a new file

// save and generate report functions (Ye Zhian)
// file header functions (Ye Zhian)
void startReportFile();          // start of txt file record include header
void startHTMLReportFile();          // start of html file record include header
void startCorrHTMLReportFile();      // start of html file record include header for correlation report
void startDistinctHTMLReportFile();  // start of html file record include header for distinct data report
void startHistogramHTMLReportFile(); // start of html file record include header for histogram report

// generate report functions (Ye Zhian)
bool generateFileOption();      // ask whether they want to generate report of their saved computation and type of report
int generateFileType();      // get user input on type of report
void generateFile();            // generate report of their saved computation
void generateCorrReport();      // generate report for correlations
void generateDistinctReport();  // generate report for distinct data numbers
void generateHistogramReport(); // generate report for histogram
void generalCorr(double,double,pair<int, int>&);      // correlation computation record in general txt report (without correlation table)
void generalCorrHTML(double,double,pair<int, int>&);  // correlation computation record in general html report (without correlation table)
void generalDistinct(double,double);        // distinct data computation record in general txt report (without distinct data table)
void generalDistinctHTML(double,double);    // distinct data computation record in general html report (without distinct data table)
void generalHistogram(double,double);       // histogram computation record in general txt report (without histogram table)
void generalHistogramHTML(double,double);   // histogram computation record in general html report (without histogram table)
void saveHistogram(double,vector<int>&,double&,double&, int&); // output of histogram record in txt
void saveHistogramHTML(double,vector<int>&,double &,double &, int &); // output of histogram record in html
void saveCorrTable(string,vector<int>, vector<int>, int,double,double,double,double,double,pair<int, int>&); // output of correlation record in txt
void saveCorr(string,vector<int>, vector<int>, int,double,double,double,double,double,pair<int, int>&);      // output of correlation record in html
void saveDistinctData(double,vector<int>, vector<int>&, int);       // output of distinct data record in txt
void saveDistinctDataHTML(double,vector<int>, vector<int>& ,int);   // output of distinct data record in html
void savaData(double,char,double,double);                           // output of general report in .txt
void saveDataHTML(double,char,double,double);                       // output of general report in .html

// ending code of HTML file (Ye Zhian)
void endHTMLReport();              // ending code of general html file
void endCorrHTMLReport();          // ending code of correlation html file
void endDistinctHTMLReport();      // ending code of distinct data html file
void endHistogramHTMLReport();     // ending code of histogram html file

// save reords of computations functions (Ye Zhian)
void askToSaveReport(int,char,int,double);   // ask user whether they want to save the computation as record everytime after they done first 6 computation
void askToSaveCorrReport(double,int,vector<int>, vector<int>, int,double,double,double,double,double,pair<int, int>&); // ask user whether they want to save the computation as record everytime after they done correlation computation
void askToSaveDistinctReport(int,int,vector<int>, vector<int>&, int); // ask user whether they want to save the computation as record everytime after they done distinct data computation
void askToSaveHistogramReport(int,int,vector<int>&,double&,double&, int&); // ask user whether they want to save the computation as record or not everytime after they done histogram computation
void askForGeneralReportName();                 // ask user to input name for their general report in txt
void askForGeneralHTMLReportName();             // ask user to input name for their general report in html
void askForCorrReportName();              // ask user to input name for their correlation report in txt
void askForCorrHTMLReportName();          // ask user to input name for their correlation report in html
void askForDistinctReportName();          // ask user to input name for their distinct data report in txt
void askForDistinctHTMLReportName();      // ask user to input name for their distinct data report in html
void askForHistogramReportName();         // ask user to input name for their histogram report in txt
void askForHistogramHTMLReportName();     // ask user to input name for their histogram report in html
void clearAllFile();                // clear all temporary file

// general functions
void enterContinue();       // ask user to enter any key to continue

void clearScreen()          // clear screen
{
    system( "cls" );
}

int main()
{
    clearScreen();
    startLog(logFile); // start the log 
    clearAllFile();    // clear all content of file before enter our program
    start();           // start the program
    return 0;
}

void enterContinue()
{
    string dummy;
    cout << "\nEnter to continue..." << endl;
    getline(cin, dummy);
    cin.ignore(1000,'\n');
}

// start of the program
void start()
{
    int userOrAdmin;   // user or admin from other function will determine which menu will user type in in admin or user
    userOrAdmin = LoginMenu();
    bool isProceedable = 0; //counter for loop to stop looping
    int choice;
    if(userOrAdmin == 1){ //1 means admin page
        do{
            choice = adminPage();
            if (choice == 1) createNewAcc();
            else if (choice == 2){
                userOrAdmin = loginFunction();
                break;
            }
            else if (choice == 3) deleteUser();
            else if (choice == 4) changePasswordFunction();
            else if (choice == 5) start();
            else adminPage();
        } while (isProceedable == 0);
    }
    if (userOrAdmin == 0){ // 0 means user page
        do{
            choice = menuDisplay();
            if(choice == 1) startAnalysis();
            else if(choice == 2) changePasswordFunctionUser();
            else if(choice == 3) renameMainMenu();
            else if(choice == 4) start();
        } while (isProceedable==0);
    }
}

//below are login page functions (Wei-Zheng)
int LoginMenu()
{
    char choice;
    int userOrAdmin;
    bool isProceedable;

    createAdmin();
    do{
        cout<< "\n                 WELCOME                  " << endl
            << " +----------------------------------------+" << endl
            << " |   Basic Data Analysis Program (BDAP)   |" << endl
            << " |                                        |" << endl
            << " | 1. Login                               |" << endl
            << " | 2. Quit                                |" << endl
            << " +----------------------------------------+" << endl;
            cout << "\nPlease enter your choice : ";
            cin >> choice;
            cin.ignore(100,'\n');
            if (choice == '1'){
                userOrAdmin = Login();
                isProceedable = 1;       // to quit the loop and return the choice to the
            }
            else if (choice=='2'){
                cout << "\nYou quit the program. Have a nice day. :D" << endl;
                exit(0);
            }
            else if(choice >= 'a' || choice >= 'A'){
                cout << "\nInvalid input. Please try again" << endl;
                isProceedable = 0;
                enterContinue();
            }
            else cout << "\nInvalid input. Please try again" << endl;
            clearScreen();
    }while (isProceedable!=1);

    return userOrAdmin;   // (can refer to line 286 and 290)
}

void createAdmin()
{
    ofstream output("Admin.txt");
    output << "Admin1" << endl
            << "\nAdministrator" << endl
            << "\nActive"  << endl;
    return;
}

//below are admin login functions (Wei-Zheng)
int Login()
{
    string username,password ;
    bool isAdminOrUser;
    int userOrAdmin;

    do{
        cout << "\nPlease enter your Username and Password."  << endl;
        cout << "\nUsername : " ;
        getline(cin,username);
        cout << "Password : " ;
        getline (cin,password);

        userOrAdmin = adminCheckTxt(username,password);
        if(userOrAdmin == 0){
            isAdminOrUser = 1;  // confirm the account name and password is correct
            systemLog(logFile,username,"logIn");
        }

        else if(userOrAdmin == 1){
            isAdminOrUser = 1;   // confirm the account name and password is correct
            systemLog(logFile,username,"logIn");
        }

        else
            isAdminOrUser = 0;

    }while(isAdminOrUser != true);

    return userOrAdmin;
}

int adminCheckTxt(string username,string password)
{
    ifstream input(username + ".txt");
    bool isPasswordFound, isDeleteUser;
    int i = 0,x = 3;
    int userOrAdmin;

    if(input.is_open()){
        isDeleteUser = checkDeletedUser(username);
        isPasswordFound = adminCheckPass(username,password);

        if(isDeleteUser==1){
            cout << "\nSorry this is a deleted user." << endl;
            return x;
        }
        else if(isPasswordFound==false){
            cout << "\nWrong password.Please try again." << endl;
            systemLog(logFile,username,"wrongPW");
            return x;
        }
        if(isPasswordFound==true){
            userOrAdmin = checkTextForAdminUser(username);
        }
        input.close();
    }
    else{
        cout << "\nSorry, Wrong Username.Please try again" << endl;
        return x;
    }
    return userOrAdmin;
}

int checkTextForAdminUser(string username)
{
    ifstream input(username + ".txt");
    int i = 0,x;
    string strtemp[20];
    int userOrAdmin;
    bool isAdminWord, isUserWord;
    ofstream output("text.txt");

    while(getline(input,line)){
        strtemp[i]=line;
        i++;
    }
    x = i;
    for(int i=0;i<=x;i++)
        output << strtemp[i] << endl;
    isAdminWord = adminCheckAdminWord(username);
    isUserWord = checkUserWord(username);

    if(isAdminWord==1){
        adminNameDisplay = username;
        userOrAdmin=1;    // define the user as the admin
    }
    else if(isUserWord == 1){
        usernameDisplay = username;
        userOrAdmin=0;   // define the user as the user
    }

    input.close();
    output.close();
    remove ("text.txt");
    return userOrAdmin;
}

bool adminCheckPass(string username,string password)
{
    ifstream input(username + ".txt");
    bool isPasswordFound = 0;
    string passwordInText;
        if(input.is_open())
        {
            while(getline(input,line)){
                if (line.find(password, 0) != string::npos)//string::npos means not found    // not equal to not found means found
                {
                    passwordInText = line;
                    if(passwordInText == password)
                    {
                        adminNameDisplay = username;
                        isPasswordFound=true;
                        break;
                    }
                    else
                        isPasswordFound=false;
                }
                else
                    isPasswordFound = 0;
            }
        }
    input.close();
    return(isPasswordFound);
}

bool adminCheckAdminWord(string username)
{
   ifstream check("text.txt");
   string str1 ="Administrator";
   bool isAdminWord;
        if(check.is_open()){
            while(getline(check,line)){
                if (line.find(str1, 0) != string::npos) //string::npos means not found    // not equal to not found means found
                {
                    isAdminWord = 1;
                    break;
                }
                else
                    isAdminWord = 0;
            }
        }
    check.close();
    return isAdminWord;
}

char adminPage()
{
    int choice = 0;
    clearScreen();
    do{
        cout << "           Hello " << adminNameDisplay  << endl;
        cout << "+---------------------------------------+" << endl
            << "|         Welcome to Admin page         |" << endl
            << "|                                       |" << endl
            << "|  1. Register a user account           |" << endl
            << "|  2. Login to a user account           |" << endl
            << "|  3. Delete a user account             |" << endl
            << "|  4. Change Password                   |" << endl
            << "|  5. Return to login page              |" << endl
            << "+---------------------------------------+" << endl;
        cout<< "\nPlease enter your choice : ";
        getIntInput(choice);

        if ( choice <=0 || choice >= 6)
            cout << "\nInvalid input. Please Try Again." << endl;
        else if(choice==5){
            systemLog(logFile,adminNameDisplay,"logOut");
            clearScreen();
        }
    } while (choice <= 0|| choice >= 6);

    return choice;
}

// below are change user password functions (Wei-Zheng)
void createNewAcc()
{
    char password[50];
    bool isLetterAlp ,isUpperCase,isDigital, isPassCorrect;
    string Username;
    ifstream infile;
    cout << "\nPlease enter your username."<< endl;
    getline(cin,Username);
    cin.sync();
    cout << "\nPlease enter your password." << endl << "Password must start with letter, must contain a digit and a capital letter. " << endl;
    cin >> password;
    cin.ignore(100,'\n');
    cin.clear();
    infile.open(Username+".txt");
    if(infile)
        { cout << "\nSorry the username is already exist" << endl; enterContinue(); return;}
    else{
         isLetterAlp = firstLetter(password[0]);   // test for first password is letter
         isUpperCase = testUpperCase(password);    // test for uppercase inside the password
         isDigital = testDigit(password);          // test for digital inside the digital

         if (isLetterAlp == true && isUpperCase == true && isDigital == true)
            isPassCorrect=1;
         else
            isPassCorrect=0;
         if (isPassCorrect == 1)
            openTxt(Username,password);
         else{
            cout << "\nSorry the password you entered does not meet the requirements."  << endl;
            createNewAcc();
        }}
}

bool firstLetter(char x)
{
    bool IsFirstLetter;
    if (x >= 'a' || x >= 'A')
        IsFirstLetter = true;
    else
        IsFirstLetter = false;
    return IsFirstLetter;
}

bool testUpperCase(char pass[])
{
    bool isUpperCase;
    for (int i=0 ; i<strlen(pass); i++){
        if (isupper(pass[i])){
            isUpperCase = true;
            break;
        }
        else
            isUpperCase = false;
    }
    return isUpperCase;
}

bool testDigit (char pass[])
{
    bool isDigit;
    for (int i=0; i < strlen(pass) ;i++)
    {
        if (isdigit(pass[i])){
            isDigit = true;
            break;
        }
        else
            isDigit = false;
    }
    return isDigit;
}

void openTxt(string username,char pass[])
{
    ofstream outputFile(username+".txt");
    outputFile << pass << endl;

    if(outputFile.is_open()){
        cout << "\nFile open succesfully. An user account has been created." << endl;
        adminOrUser(username);
        systemLog(logFile,adminNameDisplay,"createUser",username);
    }
    else
        cout << "\nFile fail to open. Please try again." << endl;

    outputFile.close();
    enterContinue();
}

void adminOrUser(string username)
{
    int choice1;
    ofstream outputFile;

    //append word to the text file instead of overwrite the old one
    outputFile.open(username+".txt",ios::out | ios::app);

    outputFile << "\nUser" << endl;
    outputFile << "\nActive" << endl;
    outputFile.close();
    return;
}

void deleteUser()
{
    string username, x;
    ifstream input;
    ofstream output;
    char choice;

    cout << "\nPlease enter username of the user account that you wish to delete.  " << endl;
    getline(cin,username);
    input.open(username+".txt");

    if(input)
    {
        cout << "\nDo you sure to delete the user account? \nEnter 'y' = yes, Enter others key to return to admin page." << endl;
        cin >> choice;
        if(choice=='y'|| choice=='Y')
        {
            deleteFunction(username);
            systemLog(logFile,adminNameDisplay,"deleteUser",username);
        }
    }
    else
        cout << "\nSorry the user account does not exist." << endl;

    output.close();
    cout << "\nReturning to Admin screen"<< endl;
    enterContinue();
}

void deleteFunction(string username)
{
    string strtemp[20];
    int i=0;
    ifstream input(username+".txt");

    while(getline(input,line))
    {
        strtemp[i]=line;
        i++;
    }
    input.close();

    ofstream output (username+".txt");
    for(int x=0;x<=i;x++)
    {
        if(strtemp[x]=="Active")
            strtemp[x]="Delete";
        output << strtemp[x] << endl;
    }
    cout << "\nThe user account has been deleted successfully." ;
}

void changePasswordFunction()
{
    int counter;
    string strtemp, username,password;
    ifstream input;
        do{
            cout << "Please enter username and currect password for the user account." << endl;
            cout << "\nUsername : ";
            getline(cin,username);
            cout << "Password : ";
            getline(cin,password);

            input.open(username+".txt");
            if(input.is_open()){
                counter = 1;
                input.close();
                readNewPassword(username,password);
            }
            else
                cout << "\nSorry the user account does not exist." << endl;
        }while (counter!=1);
}

void readNewPassword(string username,string password)
{
    ifstream input;
    char newPass[50];
    bool isLetterAlp ,isUpperCase,isDigital,isPassCorrect;
    input.open(username+".txt");

    if (checkPassword(username,password) == true){
        cout << "\nPlease enter your new password : ";
        cin.getline(newPass,50);

        isLetterAlp = firstLetter(newPass[0]);
        isUpperCase = testUpperCase(newPass);
        isDigital = testDigit(newPass);

        if (isLetterAlp == true && isUpperCase == true && isDigital == true) isPassCorrect=1;
        else isPassCorrect=0;

        if (isPassCorrect == 1)    changeTxt(newPass,username);
        else{
            cout << "\nSorry the password you entered doesn't meet the requirements." << endl;
            readNewPassword(username, password);
        }
    }
    else {
        cout << "\nIncorrect password." << endl;
        enterContinue();
    }
    return;
}

void changeTxt(char pass[],string username)
{
    ifstream input(username+".txt");
    string strtemp[20];
    int i = 0;

    while(getline(input,line)){
        strtemp[i]=line;
        i++;
    }

    ofstream output (username+".txt");
    output << pass << endl ;
    for ( int x=1; x<i ; x++)
        output << strtemp[x] << endl;

    cout << "\nYour password has been changed successfully." ;
    systemLog(logFile,username,"changePW");
    cin.get();

    input.close();
    output.close();
    return;
}

// below are login to user menu functions (Wei-Zheng)
bool loginFunction()
{
    string uninput,upinput;
    ifstream openFile;
    bool isUser, isAdminOrUser;

    do{
        cout << "\nPlease key in your username and password."<< endl;
        cout << "\nUsername : " ;
        getline(cin,uninput);
        cout << "Password : " ;
        getline(cin,upinput);

        openFile.open(uninput+".txt");

        if(openFile){
            isUser = loginFunction2(uninput,upinput);
            openFile.close();
        }
        else
            cout << "\nSorry wrong username input.Please try again" << endl;
    }while (isUser != true);

    if(isUser == true){
        isAdminOrUser = 0;       //define the user as a user account
        systemLog(logFile,usernameDisplay,"logIn");
    }
    return isAdminOrUser;
}

bool loginFunction2(string uninput,string upinput)
{
    bool isDeleteUser, isPassword ,isUser ;
    ifstream openFile(uninput+".txt");

    if(openFile){
        isDeleteUser = checkDeletedUser(uninput);
        isPassword = checkPassword(uninput,upinput);

        if(isDeleteUser == 1){
            cout << "\nSorry this is a deleted user account and cannot be use anymore." << "\nPlease enter other username to log in." << endl;
            isUser = 0;
        }
        else if(isPassword == false){
            cout << "\nIncorrect password." << endl;
            systemLog(logFile,uninput,"wrongPW");
            isUser = 0;
        }
        else if(isPassword == true){
            isUser=checkTextForUser(uninput);
            if(isUser == true)
                usernameDisplay=uninput;
            else{
                cout << "\nThis is not a user account. Please try again." ;
                isUser = 0;
            }
            openFile.close();
        }
    }
    else
        cout << "Sorry. Incorrect username and password" << endl;
    return isUser;
    }

int checkTextForUser(string username)
{
    ifstream input(username + ".txt");
    int i = 0,x;
    string strtemp[20];
    int user;
    bool isUserWord;
    ofstream output("text.txt");

    while(getline(input,line)){        //read text from username.txt to array
        strtemp[i] = line;
        i++;
    }
    x = i;
    for(int i = 0;i <= x; i++){        //output text to the text.txt file
        output << strtemp[i] << endl;
    }
    isUserWord = checkUserWord(username);

    if(isUserWord == 1){
        usernameDisplay = username;
        user = 1;
    }
    else if(isUserWord == 0)
        user = 0;

    input.close();
    output.close();
    remove ("text.txt");
    return user;
}

bool checkDeletedUser(string username)
{
    string str1 = "Delete";
    ifstream checkFile;
    bool isDeletedUser = false;

    checkFile.open(username +".txt");
    if(checkFile)
    {
        while(getline(checkFile,line))
        {
            if(line.find(str1,0) != string::npos) //string::npos means not found  // not equal to not found means found
                isDeletedUser = true;
        }
        checkFile.close();
    }
    return isDeletedUser;
}

bool checkUserWord(string username)
{
    string str1 = "User" ;
    ifstream checkFile;
    bool isUser = false;

    checkFile.open("text.txt");
    if(checkFile)
    {
        while(getline(checkFile,line))
        {
            if(line.find(str1,0) != string::npos)   // if str1="User" found
                isUser = true;
        }
        checkFile.close();
    }
    return isUser;
}

bool checkPassword(string username,string userPass)
{
    ifstream checkFile;
    bool isPasswordCorrect = 0;
    string password;

    checkFile.open(username+".txt");
    if(checkFile)
    {
        while(getline(checkFile,line))
        {
            if(line.find(userPass,0) != string::npos)   // if password found
                password = line;
                if(userPass == password)
                {
                    isPasswordCorrect=true;
                    break;
                }
                else
                    isPasswordCorrect=false;
        }
        checkFile.close();
    }
    return isPasswordCorrect;
}

// below are user menu functions (Wei-Zheng)
int menuDisplay()
{
    int choice;
    clearScreen();
    do
    {
        cout << "                  Hello  "<< usernameDisplay << endl;
        cout << "\n+---------------------------------------------------+"<< endl
            << "|                Welcome to User Menu               |"<< endl
            << "|                                                   |"<< endl
            << "|  1. Statistical analysis                          |"<< endl
            << "|  2. Change Password                               |"<< endl
            << "|  3. Rename file                                   |"<< endl
            << "|  4. Logout                                        |"<< endl
            << "+---------------------------------------------------+"<< endl;
        cout<< "\nPlease enter your choice : ";
        getIntInput(choice);

        if (choice <= 0 || choice >= 5){
            cout << "\nInvalid input. Please try again." << endl;
            enterContinue();
            clearScreen();
        }
        else if(choice==4){
            systemLog(logFile,usernameDisplay,"logOut");   // save logout to the log file
            clearScreen();
        }
    }while(choice <= 0|| choice >= 5);
    return choice;
}

void changePasswordFunctionUser()
{
    int counter;
    string strtemp, username=usernameDisplay,password;
    ifstream input;
    do{
        cout << "Please enter username and currect password for the user account." << endl;
        cout << "\nUsername : " << usernameDisplay << endl;
        cout << "Password : ";
        getline(cin,password);

        input.open(username+".txt");
        if(input.is_open()){
            counter = 1;
            input.close();
            readNewPassword(username,password);
        }
        else
            cout << "\nSorry the user account does not exist." << endl;
        }while (counter!=1);
}

// below are load data File functions (Boon Zhe)
bool loadFile(const string &fileName, int *data_col, int* &compArr, string* &columnTitleArr, int *data_row)
{
    if (!(isDataFileType(fileName))){   // Checks if the file name has the correct file format
        cout << "Invallid file format, please try again." << endl;
        return false;
    }
    
    if (getCol(fileName, data_col))
    {
        int *newComputableArrPtr = new int[*data_col];
        string *newColumnTitleArr = new string[*data_col];

        if (build_ComputableArr(fileName, newComputableArrPtr, *data_col) && build_ColumnTitleArr(fileName, newColumnTitleArr, *data_col))
        {
            compArr = newComputableArrPtr;
            columnTitleArr = newColumnTitleArr;
            
            if (getRow(fileName, data_row))
                if(isCorrectDataFormat(*data_row, fileName, compArr, *data_col)) 
                    return true;
        } 
    }
    return false;
}

bool getCol(const string &fileName, int *colNum)
{
    ifstream inputFile;
    inputFile.open(fileName);
    string line;

    if (inputFile) getline(inputFile,line);     // Checks if the data file exists
    else {
        cout << "File does not exist" << endl;
        return false;
    }

    inputFile.close();
    if (stoi(line) > 0) { // Only accepts positive integers
        *colNum = stoi(line);
        return true;
    }
    else cout << "The 1st line of the data file should be an integer that's greater than 0" << endl;

    return false;
}

bool build_ColumnTitleArr(const string &fileName, string arr[], int cols)
{
    ifstream inputFile;
    inputFile.open(fileName);
    string line, cell;

    for(int i = 0; i < 2; i++){     // getline 2 times to get to the 2nd line of the data file
        getline(inputFile,line);
    }
    stringstream lineStream(line);
    if (isSufficientData(line, ',', cols - 1)){ // Checks if the line has the right amount of data
        for (int i = 0; i < cols; i++){
            getline(lineStream, cell, ',');
            arr[i]= cell;
        }
        inputFile.close();
        return true;
    }
    else {
        cout << "The 2nd line of the data file does not have exactly " << cols << " column titles" << endl;
        inputFile.close();
        return false;
    }
}

bool build_ComputableArr(const string &fileName, int arr[], int cols)
{
    ifstream inputFile;
    inputFile.open(fileName);
    string cell,line;
    int cellInteger;

    for(int i = 0; i < 3; i++){     // getline 3 times to get to the 3rd line of the data file
        getline(inputFile,line);
    }

    stringstream lineStream(line);
    if (!(isSufficientData(line, ',', cols - 1))){
        cout << "The 3rd line of the data file does not have exactly " << cols << " integers" << endl;
        inputFile.close();
        return false;
    }

    for (int i = 0; i < cols; i++){
        getline(lineStream, cell, ',');
            cellInteger = stoi(cell);
            if (cellInteger == 0 || cellInteger == 1) arr[i] = cellInteger;
            else{
                cout << "Line 3 must only contain 1s and 0s" << endl;
                inputFile.close();
                return false;
            }
    }
    inputFile.close();
    return true;
}

bool getRow(const string &fileName, int *rowNum)
{
    ifstream inputFile;
    inputFile.open(fileName);
    string line;

    for(int i = 0; i < 4; i++){     // getline 4 times to get to the 4th line of the data file
        getline(inputFile,line);
    }

    inputFile.close();
    if (stoi(line) > 0)
    {
        *rowNum = stoi(line);
        return true;
    }
    else
    {
        cout << "The 4th line of the data file should be an integer that's greater than 0" << endl;
        return false;
    }
}

bool build_Row(int row_number, const string &fileName, int computable[], vector<int>& vector, int cols)
{
    ifstream inputFile;
    inputFile.open(fileName);
    string line, cell;
    for(int i = 0; i < row_number + 4; i++){     // getline 3 times to get to the 3rd line of the data file
        getline(inputFile,line);
    }
    if (isSufficientData(line, ',', cols - 1)){
        stringstream lineStream(line);
        for (int i = 0; i < cols; i++){
            getline(lineStream, cell, ',');
            if (isComputable(computable, i)){   // Don't add the cell into the vector if it is under an uncomputable column
                if (isInteger(cell)){   // Adds the cell into the vector if it is an integer
                    vector[i] = (stoi(cell));
                }
                else {
                    cout << "Column " << i+1 << " in row " << row_number << " is not an integer" << endl;
                    inputFile.close();
                    return false;
                }
            }
        }
        inputFile.close();
        return true;
    }
    else cout << "Row " << row_number << " does not have the correct amount of data" << endl;
    inputFile.close();
    return false;
}

bool build_SingleCol(int col_num, const string &fileName, int computable[],  vector<int>& colVector, int cols, int rows)
{
    if (isComputable(computable, col_num - 1)){     // Checks if the column is computable
        for (int i = 1; i <= rows; i++)
        {
            vector<int> row(cols);
            if (build_Row(i, fileName, computable,  row, cols)) colVector[i- 1] = (row.at(col_num - 1));
            else return false;
        }
        return true;
    }
    else {
        cout << "Column " << col_num << " is not computable" << endl;
        return false;
    }
}

bool build_DoubleCol(int col_num1, int col_num2, const string &fileName, int computable[],  vector<int>& col1, vector<int>& col2, int cols, int rows)
{
    if (isComputable(computable, col_num1 - 1) && isComputable(computable, col_num2 - 1)){ // Checks if the both of columns are computable
        for (int i = 1; i <= rows; i++)
        {
            vector<int> row(cols);
            if (build_Row(i, fileName, computable, row, cols))
            {
                col1[i - 1] = row[col_num1 - 1];
                col2[i - 1] = row[col_num2 - 1];
            }
            else return false;
        }
        return true;
    }
    else if (!(isComputable(computable, col_num1 - 1))) cout <<  "Column " << col_num1 << " is not computable" << endl;
    else if (!(isComputable(computable, col_num2 - 1))) cout <<  "Column " << col_num2 << " is not computable" << endl;
    return false;
}

bool isCorrectDataFormat(int rows, const string &fileName, int computable[], int cols)
{
    for(int i = 0; i < rows; i++)
    {
        vector<int> row(cols);
        if (!(build_Row(i + 1, fileName, computable, row, cols))) return false;
    }

    return true;
}

bool isComputable(int computableArr[], int i)
{
    return (computableArr[i] == 1);
}

bool isInteger(const string &string)
{
    char c;
    for (int i = 0; i< string.length(); i++)
    {
        c = string[i];
        if (!isdigit(c) && c != '-')
        {
            return false;
        }
    }
    return true;
}

bool isSufficientData(const string &line, char ch, int freq)
{
    int counter = count(line.begin(), line.end(), ch);
    return (counter == freq);
}

// below are statistical analysis functions (Xiao Chin)
void startAnalysis()
{
    string fileName;
    int data_cols, data_rows;
    int* computableArr = new int[0];
    string* colTitles = new string[0];
    startReportFile();
    startHTMLReportFile();
    startCorrHTMLReportFile();
    startDistinctHTMLReportFile();
    startHistogramHTMLReportFile();
    do{
        cout << "\nPlease enter the data file name (.txt/.csv/.dat): " << endl;             
        cin >> fileName;
    }while(!(loadFile(fileName, &data_cols, computableArr, colTitles, &data_rows))); //call load file function and check data file error

    cout << "\nThe data file has the correct data format. Proceeding to statistical analysis menu." << endl;
    enterContinue();

    vector<int> row(data_cols), column(data_rows), col1(data_rows), col2(data_rows); //initialize vectors for computations later
    getComputationOption(fileName,row,column,col1,col2,data_cols,data_rows,computableArr,colTitles);
}

void getRowOrCol(char &rowOrCol)
{
    cout << "\nEnter rowOrCol: ";
    cin >> rowOrCol;
    cin.clear();
    cin.ignore(100,'\n');
    while(!(rowOrCol == 'r' || rowOrCol == 'c')){       // check for invalid input
        cout << "\nPlease enter 'r' or 'c': ";
        cin >> rowOrCol;
        cin.clear();
        cin.ignore(100,'\n');
    }
}

void getIntInput(int &input)
{
    cin >> input;
    cin.clear();
    cin.ignore(100,'\n');
}

void getComputationOption(string fileName, vector<int>& row, vector<int>& column,vector<int>& col1,vector<int>& col2, int data_cols, int data_rows, int computableArr[],string colTitles[])
{
    int option;     // for user choice for computation
    char rowOrCol;  // for user choice for row or column
    int new_size;   
    bool report=0,corr=0,distinct=0,histogram=0;

    do {
        computationMenu(colTitles,data_cols,data_rows);      //display statistical computation menu
        do{
            cout << "\nEnter option 1 to 10: ";
            getIntInput(option);
        }while(option <= 0 || option >= 11);   // check valid option
        
        if (option != 10){
            getRowOrCol(rowOrCol);
            if ((option == 7 ||option == 8||option == 9) && (rowOrCol == 'r')){         // 7-correlation,8-distinct data,9-histogram only works for column
                cout << "\nOption " << option << " does not support computation for row" << endl;
                cout << "The program will compute option " << option << " for column for you :D" << endl;
                compileUserChoice(option,'c', fileName, row, column, col1, col2, computableArr, data_cols, data_rows, new_size);
            }
            else compileUserChoice(option, rowOrCol, fileName, row, column, col1, col2, computableArr, data_cols, data_rows, new_size);

            checkComputationDone(option,report,corr,distinct,histogram);
        }
        if (option == 10) generateAndQuit(report,corr,distinct,histogram);
        enterContinue();
    }while (option != 10);  // while option is not equal to quit
}

void checkComputationDone(int option, bool &report, bool& corr, bool& distinct, bool& histogram)
{
    if (option==1 || option==2 || option==3 || option==4 || option==5 || option==6) report = 1;
    if (option==7) corr = 1;
    if (option==8) distinct = 1;
    if (option==9) histogram = 1;
}

void generateAndQuit(int report, int corr, int distinct, int histogram)
{
    if(generateFileOption()){
        if (report==1) {
            cout << "\nFor general report - ";
            generateFile();
        }
        if (corr==1) {
            cout << "\nFor correlation report - ";
            generateCorrReport();
        }
        if (distinct==1) {
            cout << "\nFor distinct data report - ";
            generateDistinctReport();
        }
        if (histogram==1) {
            cout << "\nFor histogram report - ";
            generateHistogramReport();
        }
        cout << "\nThe reports are generated successfully." << endl;
    }
    clearAllFile(); // clear all temporary file
}

void computationMenu(string colTitles[],int cols,int rows)
{
    clearScreen();
    cout << endl;
    cout << "              Statistical Analysis Menu               " << endl;
    cout << "+---------------------------------------------------------------+" << endl;
    cout << "| Option :                                                      |" << endl;
    cout << "| 1. Find Minimum                                               |" << endl;
    cout << "| 2. Find Maximum                                               |" << endl;
    cout << "| 3. Find Median                                                |" << endl;
    cout << "| 4. Find Mean                                                  |" << endl;
    cout << "| 5. Find Variance                                              |" << endl;
    cout << "| 6. Find standard deviation                                    |" << endl;
    cout << "| 7. Correlation between any 2 selected columns                 |" << endl;
    cout << "| 8. Display the distinct numbers for any selected column       |" << endl;
    cout << "| 9. Plot a histogram for any selected column                   |" << endl;
    cout << "| 10.Generate text or html report and return to user menu       |" << endl;
    cout << "|                                                               |" << endl;
    cout << "| rowOrCol:                                                     |" << endl;
    cout << "| Enter 'r' for analyse data for specific row                   |" << endl;
    cout << "| Enter 'c' for analyse data for specific column                |" << endl;
    cout << "|                                                               |" << endl;
    cout << "| *Noted that option 7,8,9 only support computation for column  |" << endl;
    cout << "+---------------------------------------------------------------+" << endl;
    cout << "\nTotal number of data rows    : " << rows << endl;
    cout << "Total number of data columns : " << cols << endl;
    cout << "Data column titles           : ";
    for (int i = 0; i < cols; i++){         //displays column titles
        cout << colTitles[i] << "  ";
    }
    cout << endl;
}

int userActionForRow(string fileName, vector<int>& vector, int cols, int rows, int computable[])
{
    int row_number;
    vector.clear();
    vector.resize(cols);
    do{
        cout << "\nPlease enter row number between 1 to " << rows << " : ";
        getIntInput(row_number);      // get user input for a row number for computation
    }while(row_number <=0 || row_number > rows);    // check for valid input 
    
    if(!(build_Row(row_number, fileName, computable, vector, cols))){   // call build_Row function and build a vector for computation
        cout << "\nData file error "<< endl;
    }
    return row_number;
}

int userActionForCol(string fileName, vector<int>& vector, int cols, int rows, int computable[])
{
    int col_number;     // initialize a integer variable for column number
    do{                        
        cout << "\nPlease enter column number between 1 to " << cols << " : "; 
        getIntInput(col_number);              // get user input for a column number for computation 
    }while(col_number <= 0 || col_number > cols); // check invalid column input

    while (!(build_SingleCol(col_number, fileName, computable, vector, cols, rows)))  // call build_SingleCol function and build a vector for computation
    {
        cout << "\nPlease enter the column number that are computable  : "; // get user input again if build_SingleCol return false
        getIntInput(col_number);
    }
    return col_number; 
}

void userActionForTwoCols(string fileName, vector<int>& vector1, vector<int>& vector2, int cols, int rows, int computable[], pair <int, int>& p)
{
    int col_number1, col_number2;
    do {
        // get user input for two column number for computation
        do{
            cout << "\nEnter the first column number (between 1 to " << cols << ") : ";
            getIntInput(col_number1);
        }while(col_number1 <= 0 || col_number1 > cols); // check for invalid input
        do{
            cout << "\nEnter the second column number (between 1 to " << cols << ") : "; //
            getIntInput(col_number2);
        }while(col_number1 <= 0 || col_number1 > cols); // check for invalid input
    }while (!(build_DoubleCol(col_number1,col_number2,fileName,computable,vector1,vector2,cols,rows)));// call build_doubleCol function and build two vectors for computation
    p = make_pair(col_number1,col_number2);
}

void compileUserChoice(int option, char rowOrCol, string fileName, vector<int>& vectorRow, vector<int>& vectorCol, vector<int>& vectCol1, vector<int>& vectCol2, int computable[], int cols, int rows, int n)
{
    if (rowOrCol == 'r'){
        int rowNum = userActionForRow(fileName,vectorRow,cols,rows,computable);
        if (option == 1) findMinimum(vectorRow,cols,computable,rowOrCol,rowNum,option);
        else if (option == 2) findMaximum(vectorRow,cols,computable,rowOrCol,rowNum,option);
        else if (option == 3) findMedian(vectorRow,cols,computable,rowOrCol,rowNum,option);
        else if (option == 4) findMean(vectorRow,cols,computable,rowOrCol,n,rowNum,option);
        else if (option == 5) findVariance(vectorRow,cols,computable,rowOrCol,n,rowNum,option);
        else if (option == 6) findSTDV(vectorRow,cols,computable,rowOrCol,n,rowNum,option);
        logComputation(option,rowOrCol,rowNum);         // log the computations
    }
    else if (rowOrCol == 'c'){
        if (option != 7){
            int colNum = userActionForCol(fileName,vectorCol,cols,rows,computable);
            if (option == 1) findMinimum(vectorCol,rows,computable,rowOrCol,colNum,option);
            else if (option == 2) findMaximum(vectorCol,rows,computable,rowOrCol,colNum,option);
            else if (option == 3) findMedian(vectorCol,rows,computable,rowOrCol,colNum,option);
            else if (option == 4) findMean(vectorCol,rows,computable,rowOrCol,n,colNum,option);
            else if (option == 5) findVariance(vectorCol,rows,computable,rowOrCol,n,colNum,option);
            else if (option == 6) findSTDV(vectorCol,rows,computable,rowOrCol,n,colNum,option);
            else if (option == 8) displayDistinctData(vectorCol,rows,option,colNum);
            else if (option == 9) plotHistogram(vectorCol,rows,option,colNum);
            logComputation(option,rowOrCol,colNum); // log the computations
        }
        else if (option == 7){
            pair<int, int> p;   // initialize a pair to store the value of column number 1 and column number 2
            userActionForTwoCols(fileName, vectCol1,vectCol2,cols, rows, computable,p);
            findCorrelation(vectCol1,vectCol2,rows,option,p);
            logComputation(option,rowOrCol,p.first,p.second); // log the computations
        }
    }
}

void logComputation(int option, char rowOrCol,int num1, int num2)
{
    string loc = to_string(num1);  // for column number or row number // convert int to string
    string loc2 = to_string(num2); // for the second column number  // convert int to string
    if (rowOrCol == 'r'){
        string location = "row ";
        if (option == 1) computationLog(logFile,usernameDisplay,"Find Minimum", location + loc);
        else if (option == 2) computationLog(logFile,usernameDisplay,"Find Maximum", location + loc);
        else if (option == 3) computationLog(logFile,usernameDisplay,"Find Median", location + loc);
        else if (option == 4) computationLog(logFile,usernameDisplay,"Find Mean", location + loc);
        else if (option == 5) computationLog(logFile,usernameDisplay,"Find variance", location + loc);
        else if (option == 6) computationLog(logFile,usernameDisplay,"Find Standard deviation", location + loc);
    }
    else if (rowOrCol == 'c'){
        string location = "column ";
        if (option != 7)
        {
            if (option == 1) computationLog(logFile,usernameDisplay,"Find Minimum", location + loc);
            else if (option == 2) computationLog(logFile,usernameDisplay,"Find Maximum", location + loc);
            else if (option == 3) computationLog(logFile,usernameDisplay,"Find Median", location + loc);
            else if (option == 4) computationLog(logFile,usernameDisplay,"Find Mean", location + loc);
            else if (option == 5) computationLog(logFile,usernameDisplay,"Find variance", location + loc);
            else if (option == 6) computationLog(logFile,usernameDisplay,"Find Standard deviation", location + loc);
            else if (option == 8) computationLog(logFile,usernameDisplay,"Find distinct data members", location + loc);
            else if (option == 9) computationLog(logFile,usernameDisplay,"Plot a Histogram", location + loc);
        }
        else if (option == 7) computationLog(logFile,usernameDisplay,"Find Correlation between 2 columns", location+loc+", "+loc2);
    }
}

//below are computations functions (Xiao Chin)
int findMaximum(vector<int> vector, int size, int computable[], char rowOrCol, int num,int option)
{
    int max;
    if (rowOrCol == 'r') buildComputableRow(vector,computable,size);
    int n = vector.size();

    max = vector[0];
    for(int i = 1; i < n; i++){
        if(vector[i] > max){
            max = vector[i];
        }
    }
    cout << "\nThe maximum is " << max << endl;
    askToSaveReport(option,rowOrCol,num,max);
    return max;
}

int findMinimum(vector<int> vector, int size, int computable[], char rowOrCol, int num,int option)
{
    int min;
    if (rowOrCol == 'r') buildComputableRow(vector,computable,size);
    int n = vector.size();

    min = vector[0];
    for(int i = 1; i < n; i++){
        if(vector[i] < min){
            min = vector[i];
        }
    }
    cout << "\nThe minimum is " << min << endl;
    askToSaveReport(option,rowOrCol,num,min);
    return min;
}

double findMedian(vector<int> vector, int size, int computable[], char rowOrCol, int num,int option)
{
    double median;
    if (rowOrCol == 'r') buildComputableRow(vector,computable,size);
    int n = vector.size();

    sort(vector.begin(), vector.end()); // sort the vector

    if (n % 2 != 0) 
        median = static_cast<double>(vector[n / 2]); // odd case
    else 
        median = static_cast<double>(vector[(n - 1) / 2] + vector[n / 2]) / 2.0; // even case

    cout << setprecision(0) << fixed;
    cout << "\nThe median is  "<< median << endl;
    askToSaveReport(option,rowOrCol,num,median);
    return median;
}

double findSTDV(vector<int> vector, int size, int computable[], char rowOrCol, int n, int num,int option)
{
    double STDV;
    STDV = sqrt(findVariance(vector,size,computable,rowOrCol,n,num,option));
    cout << "\nThe standard deviation is " << setprecision(2) << fixed << STDV << endl;
    askToSaveReport(option,rowOrCol,num,STDV);
    return STDV;
}

double findVariance(vector<int> vector, int size, int computable[], char rowOrCol, int n, int num,int option)
{
    double mean, variance;
    double squareDiff = 0;
    mean = findMean(vector,size,computable,rowOrCol,n,num,option);

    for (int i = 0; i < n; i++){
        squareDiff += (vector[i] - mean) * (vector[i] - mean);
    }
    variance = squareDiff / static_cast<double>(n-1);
    if (option == 5){
        cout << "\nThe variance is " << setprecision(2) << fixed << variance << endl;
        askToSaveReport(option,rowOrCol,num,variance);
    }
    return variance;
}

double findMean(vector<int>& vector, int size, int computable[], char rowOrCol, int& n, int num,int option)
{
    double sum = 0;
    double mean;
    if (rowOrCol == 'r') buildComputableRow(vector,computable,size);
    n = vector.size();

    for (int i = 0; i < n; i++){
        sum += vector[i];
    }
    mean = sum / static_cast<double>(n);
    if (option == 4){
        cout << "\nThe mean is " << setprecision(2) << fixed << mean << endl;
        askToSaveReport(option,rowOrCol,num,mean);
    }
    return mean;
}

void buildComputableRow(vector<int>& vect,int computable[],int size)
{
    int j = 0;
    for(int i = 0; i < size; i++){
        if (!(isComputable(computable,i))) {
            vect.erase(vect.begin() + (i-j));
            j++;
        }
    }
}

// below are Pearson’s correlation functions (Xiao Chin)
void displayCorrTable(vector<int> vector_X, vector<int> vector_Y, int size,double sum_X, double sum_Y, double sum_XY, double sumSq_X, double sumSq_Y)
{
    cout << "\n\nComputation Table for correlation" << endl;
    cout << "\n+-----+-----------+-----------+-----------+-----------------+----------------+" << endl
            << "| No. |     x     |     y     |     xy    |   square of x   |   square of y  |" << endl
            << "+-----|-----------+-----------+-----------+-----------------+----------------+" << endl;
    cout << setprecision(0) << fixed;
    for (int i = 0; i < size; i++)
    {
        cout << "| " << setw(3) << i+1 << " | " << setw(9) << vector_X[i] << " | " << setw(9) << vector_Y[i] << " | ";
        cout << setw(9) << vector_X[i] * vector_Y[i] << " | " << setw(13) << pow(vector_X[i],2);
        cout << "   | " << setw(12) << pow(vector_Y[i],2) << "   |" << endl;
    }
    cout << "+-----|-----------+-----------+-----------+-----------------+----------------+" << endl;

    cout << "| " << setw(3) << "Sum" << " | " << setw(9) << sum_X << " | " << setw(9) << sum_Y << " | " ;
    cout << setw(9) << sum_XY << " | " << setw(13) << sumSq_X;
    cout << "   | " << setw(12) << sumSq_Y << "   |" << endl;
    cout << "+-----|-----------+-----------+-----------+-----------------+----------------+" << endl;

}

double findCorrelation(vector<int> vector_X, vector<int> vector_Y, int size,int option,pair <int, int> p)
{
    double sum_X = 0, sum_Y = 0, sum_XY = 0 , sumSquare_X = 0, sumSquare_Y = 0;
    double corr;

    for (int i = 0; i < size; i++)
    {
        sum_X += vector_X[i];
        sum_Y += vector_Y[i];
        sum_XY += (vector_X[i] * vector_Y[i]);
        sumSquare_X += vector_X[i] * vector_X[i];
        sumSquare_Y += vector_Y[i] * vector_Y[i];
    }

    displayCorrTable(vector_X,vector_Y,size,sum_X,sum_Y,sum_XY,sumSquare_X,sumSquare_Y);

    corr = static_cast<double>(size * sum_XY - sum_X * sum_Y) / sqrt((size * sumSquare_X - sum_X * sum_X) * (size * sumSquare_Y - sum_Y * sum_Y));
    cout << "\nCorrelation of the two column is : " ;
    cout << setprecision(4) << fixed << corr << endl;
    askToSaveCorrReport(corr,option,vector_X,vector_Y,size,sum_X,sum_Y,sum_XY,sumSquare_X,sumSquare_Y,p);
    return corr;
}

// below are plotting a histogram functions (Xiao Chin)
void histogramMenu()
{
    cout << "\n\n+------------------------------------------------------------+"<< endl;
    cout << "| Please enter two dataPoints that represent the range       |"<< endl;
    cout << "| of the data set you want to plot for histogram. Enter a    |"<< endl;
    cout << "| smaller value followed by a larger value.                  |"<< endl;
    cout << "| The program will determine the suitable number of bars     |"<< endl;
    cout << "| based on range of data set and plot a histogram.           |"<< endl;
    cout << "+------------------------------------------------------------+"<< endl;
}

void getDatapoints(int &dataPoint1, int &dataPoint2)
{
    string num;
    do{
        cout << "\nEnter starting data point : " ;
        getline(cin, num);
    }while(!(isInteger(num)));  // check integers
    dataPoint1 = stoi(num);
    do{
        cout << "\nEnter ending data point : " ;
        getline(cin, num);
    }while(!(isInteger(num))); // check integers
    dataPoint2 = stoi(num);

    while (dataPoint2 - dataPoint1 <= 5){
        cout << "\nThe range is too small. Please reenter :" << endl;
        do{
            cout << "\nEnter starting data point : " ;
            getline(cin, num);
        }while(!(isInteger(num)));  // check integers
        dataPoint1 = stoi(num);
        do{
            cout << "\nEnter ending data point   : " ;
            getline(cin, num);
        }while(!(isInteger(num))); // check integers
        dataPoint2 = stoi(num);
    }
}

void histogramRange(double &bar, double &range, int &dataPoint1, int &dataPoint2)
{
    if ((dataPoint2-dataPoint1) > 50){
        bar = 10.0;
    }
    range = (dataPoint2 - dataPoint1)/bar;
    range = ceil(range);        // round up the range
}

void groupData(vector<int> vect, vector<int> &groupVect, double bar,double range, int size, int dataPoint1, int dataPoint2)
{

    for(int i = 0; i < bar; i++){
        for(int j = 0; j < size; j++){
            if (vect[j] >= (dataPoint1+i*range) && vect[j] <= (dataPoint1+range*(1+i)-1)){
                groupVect[i]++;
            }
        }
    }
}

void plotHistogram(vector<int> vect, int size, int option, int col_num)
{
    int dataPoint1, dataPoint2;
    double bar = 5.0;  // histogram will have minimum 5 bars
    double range;
    histogramMenu();
    getDatapoints(dataPoint1,dataPoint2);
    histogramRange(bar,range,dataPoint1,dataPoint2);
    vector<int> dataForHistogram(bar);
    groupData(vect,dataForHistogram,bar,range,size,dataPoint1,dataPoint2);

    cout << setprecision(0) << fixed;
    cout << "\n\nHistogram :" << endl;
    cout << left << setw(11) << "\nCounts" << left << setw(11) << "Range" << endl;
    cout << endl;
    for (int i = 0; i < bar; i++){
        cout << "  "<< right << setw(2) << dataForHistogram[i] << right << setw(8) << (dataPoint1+i*range) << "-" << left << setw(8) << (dataPoint1+range*(1+i)-1);
        for (int j = 0; j < dataForHistogram[i]; j++){
            cout << "=";
        }
        cout << endl;
    }
    cout << endl;
    cout << right << setw(21) << "+/" << "----|----|----|----|----|----|----|----|----|----|/+"<< endl;
    cout << right << setw(21) << " 0 " << "    5    10   15   20   25   30   35   40   45   50"<< endl;
    askToSaveHistogramReport(option,col_num,dataForHistogram,bar,range,dataPoint1);
}

// below are Distinct data members functions (Xiao Chin)
void findOccurencesOfNum(vector<int> vect, vector<int>& freq, int size)
{
    for(int i = 0; i < size ; i++){
        int count = 1;
        for(int j = i+1; j < size; j++){
            if(vect[i] == vect[j]){
                count++; 
                freq[j] = -1;  //To avoid counting same element again
            }
        }
        if(freq[i] != -1){  
            freq[i] = count;
        }
    }
}

void displayDistinctData(vector<int> vect, int size,int option,int col_num)
{
    vector<int> freq(size);
    sort(vect.begin(), vect.end());     // sort vector to display distinct numbers in accending orders
    findOccurencesOfNum(vect,freq,size);
    cout << "\n\nDisplaying distinct numbers in tabular form (accending order)" << endl;
    cout<< "\n+--------------+-------------+" << endl
          << "| Data numbers |  Frequency  |" << endl
          << "+--------------+-------------+" << endl;
    cout << setprecision(0) << fixed;
    for(int i = 0; i < size; i++){
        if(freq[i] != -1){
            cout << "|" << setw(9) << vect[i] << "     |" << setw(8) << freq[i] << "     |" << endl;
        }
    }
    cout << "+--------------+-------------+" << endl;
    askToSaveDistinctReport(option,col_num,vect,freq,size);
}

//below are log function (Boon Zhe)
void startLog(const string &fileName)
{
    ofstream logFile;
    logFile.open(fileName);
    if (logFile)
    {
        logFile << "                                   ACTIVITY LOG                                   " << endl;
        logFile << "+--------------------+--------------------------------------------+--------------------+" << endl;
        logFile << "|        User        |                Input                       |      Location      |" << endl;
        logFile << "+--------------------+--------------------------------------------+--------------------+" << endl;
    }
    else cout << "No file found" << endl;

    logFile.close();
}

void computationLog(const string &fileName, const string &username, const string &input, const string &location )
{
    fstream logFile;
    logFile.open(fileName, fstream::app);

    logFile << "| " <<  left << setw(19) << username << "| " << left << setw(43) << input << "| " << left << setw(19) << location << "|" << endl; 
    logFile << "+--------------------+--------------------------------------------+--------------------+" << endl;
    
    logFile.close();
}

void systemLog(const string &fileName, const string &username, const string &userInput, const string& object)
{
    fstream logFile;
    logFile.open(fileName, fstream::app);

    if (userInput == "logIn")
        logFile << "| " <<  left << setw(19) << username << "| " << left << setw(43) << "Logged into the system" << "| " << left << setw(19) << "" << "|" << endl; 
    else if (userInput == "logOut")
        logFile << "| " <<  left << setw(19) << username << "| " << left << setw(43) << "Logged out of the system" << "| " << left << setw(19) << "" << "|" << endl; 
    else if (userInput == "changePW")
        logFile << "| " <<  left << setw(19) << username << "| " << left << setw(43) << "Changed password" << "| " << left << setw(19) << "" << "|" << endl;  
    else if (userInput == "wrongPW")
        logFile << "| " <<  left << setw(19) << username << "| " << left << setw(43) << "Entered the wrong password" << "| " << left << setw(19) << "" << "|" << endl; 
    else if (userInput == "createUser")     // object refers to the name of the newly created account
        logFile << "| " <<  left << setw(19) << username << "| " << left << setw(18) << "Created a new user: " << left << setw(23) << object << "| " << left << setw(19) << "" << "|" << endl; 
    else if (userInput == "deleteUser")         // object refers to the name of the newly deleted account
        logFile << "| " <<  left << setw(19) << username << "| " << left << setw(18) << "Deleted the user: " << left << setw(26) << object << "| " << left << setw(19) << "" << "|" << endl; 
    else if (userInput == "saveComputation")       // object refers to the name of the computation done
        logFile << "| " <<  left << setw(19) << username << "| " << left << setw(18) << "Saved a computation: " << left << setw(22) << object << "| " << left << setw(19) << "" << "|" << endl; 
    else if (userInput == "renameFile")     // object refers to the name of the newly renamed file
        logFile << "| " <<  left << setw(19) << username << "| " << left << setw(18) << "Renamed a file as: " << left << setw(24) << object << "| " << left << setw(19) << "" << "|" << endl; 
    else if (userInput == "generateReport")     // object refers to the name of the newly renamed file
        logFile << "| " <<  left << setw(19) << username << "| " << left << setw(18) << "Generated a Report as: " << left << setw(20) << object << "| " << left << setw(19) << "" << "|" << endl; 
    else if (userInput == "generateHTMLReport")     // object refers to the name of the newly renamed file
        logFile << "| " <<  left << setw(19) << username << "| " << left << setw(18) << "Generated a HTML Report as: " << left << setw(15) << object << "| " << left << setw(19) << "" << "|" << endl; 

    logFile << "+--------------------+--------------------------------------------+--------------------+" << endl;
    logFile.close();
}

//below are rename filename function (Boon Zhe)
void renameMainMenu()
{
    clearScreen();
    cout << "+----------------------------------------+" << endl;
    cout << "| Which file type do you wish to rename? |" << endl;
    cout << "|                                        |" << endl;
    cout << "| 1. Data File                           |" << endl;
    cout << "| 2. Report File                         |" << endl;
    cout << "| 3. HTML Report File                    |" << endl;
    cout << "|                                        |" << endl;
    cout << "| 0. Return to user menu                 |" << endl;
    cout << "+----------------------------------------+" << endl;

    string choice;
    cout << "\nPlease enter your choice : ";
    cin >> choice;
    while (choice != "0" && choice != "1" && choice != "2" && choice != "3"){
        cout << "\nInvalid input, please enter the options given : " ;
        cin >> choice;
    }
    cout << endl;

    if (choice == "0") menuDisplay();
    else if (choice == "1") renameDataFileMenu();
    else if (choice == "2") renameReportMenu();
    else if (choice == "3") renameHTMLReportMenu();
    cout << "\nYour file has been renamed." << endl;
    enterContinue();
}

void renameReportMenu()
{
    string currentName, newName;
    cout << "Please enter the name of the file that you wish to rename: " ;
    cin >> currentName;
    cout << endl;
    while (!(checkCurrentReport(currentName))){
        cin >> currentName;
        cout << endl;
    }

    cout << "Please enter the file's new name: " ;
    cin >> newName;
    cout << endl;
    while (!(renameReportFile(currentName, newName))){
        cin >> newName;
        cout << endl;
    }

    cout << currentName << " has been successfully renamed to " << newName << endl;
    systemLog(logFile,usernameDisplay, "renameFile", newName);
}

void renameHTMLReportMenu()
{
    string currentName, newName;
    cout << "Please enter the name of the HTML file that you wish to rename: " ;
    cin >> currentName;
    cout << endl;
    while (!(checkCurrentHTMLReport(currentName))){
        cin >> currentName;
        cout << endl;
    }

    cout << "Please enter the file's new name: " ;
    cin >> newName;
    cout << endl;
    while (!(renameHTMLFile(currentName, newName))){
        cin >> newName;
        cout << endl;
    }

    cout << currentName << " has been successfully renamed to " << newName << endl;
    systemLog(logFile, usernameDisplay, "renameFile", newName);
}

void renameDataFileMenu()
{
    string currentName, newName;

    cout << "Please enter the name of the data file that you wish to rename: " ;
    cin >> currentName;
    cout << endl;
    while (!(checkCurrentDataFile(currentName))){
        cin >> currentName;
        cout << endl;
    }

    cout << "Please enter the data file's new name: " ;
    cin >> newName;
    cout << endl;
    while(!(renameDataFile(currentName, newName))) {
        cin >> newName;
        cout << endl;
    }

    cout << currentName << " has been successfully renamed to " << newName << endl;
    systemLog(logFile, usernameDisplay, "renameFile", newName);
}

bool checkCurrentDataFile(const string &fileName)
{
    int len = fileName.length();
    if (len < 5){
        cout << fileName << " is not a valid name, please try again: " ;
        return false;
    }
    if (!(isDataFileType(fileName))){
        cout << fileName << " is not a data file, please try again: " ;
        return false;
    }
    if (to_Lowercase(fileName) == to_Lowercase(logFile)){
        cout << "You are not allowed to rename the log file, please try another file: " ;
        return false;
    }

    ifstream testFile(fileName);
    if (!(testFile)){
        cout << fileName << " does not exists in the directory, please try again: " ;
        testFile.close();
        return false;
    }

    testFile.close();
    return true;
}

bool checkCurrentReport(const string &fileName)
{
    int len = fileName.length();
    if (len < 5){
        cout << fileName << " is not a valid name, please try again: " ;
        return false;
    }
    if (!(isTXT(fileName))){
        cout << fileName << " is not a report file, please try again: " ;
        return false;
    }
    if (to_Lowercase(fileName) == to_Lowercase(logFile)){
        cout << "You are not allowed to rename the log file, please try another file:" ;
        return false;
    }

    ifstream testFile(fileName);
    if (!(testFile)){
        cout << fileName << " does not exists in the directory, please try again: ";
        testFile.close();
        return false;
    }

    testFile.close();
    return true;
}

bool checkCurrentHTMLReport(const string &fileName)
{
    int len = fileName.length();

    if (len < 6){
        cout << fileName << " is not a valid name, please try again: ";
        return false;
    }
    if (!(isHTML(fileName))){
        cout << fileName << " is not a HTML file, please try again: " ;
        return false;
    }

    ifstream testFile(fileName);
    if (!(testFile)){
        cout << fileName << " does not exists in the directory, please try again: ";
        testFile.close();
        return false;
    }

    testFile.close();
    return true;
}

bool renameHTMLFile(const string &currentFileName , const string &newFileName)
{
    const char* oldFile = (currentFileName).c_str();
    const char* newFile = (newFileName).c_str();

    if (newFileName.length() < 6){
        cout << newFileName << " is not a valid name, please try again: ";
        return false;
    }
    if (!(isHTML(newFileName))) {
        cout << "Invalid format, please try again: " << endl;
        return false;
    }

    ifstream testFile;
    testFile.open(newFileName);
    if (testFile){      // Checks if the file name already exists, to prevent overwriting of old files
        cout << newFileName << " already exists, please enter another file name: " ;
        testFile.close();
        return false;
    }

    rename(oldFile, newFile);
    testFile.close();
    return true;
}

bool renameReportFile(const string &currentFileName, const string &newFileName)
{
    const char* oldFile = (currentFileName).c_str();
    const char* newFile = (newFileName).c_str();

    if (newFileName.length() < 5){
        cout << newFileName << " is not a valid name, please try again: " ;
        return false;
    }
    if (!(isTXT(newFileName))) {
        cout << "Invalid format, please try again: " ;
        return false;
    }

    ifstream testFile;
    testFile.open(newFileName);
    if (testFile){      // Checks if the file name already exists, to prevent overwriting of old files
        cout << newFileName << " already exists, please enter another file name : " ;
        testFile.close();
        return false;
    }

    rename(oldFile, newFile);
    testFile.close();
    return true;
}

bool renameDataFile(const string &currentFileName , const string &newFileName)
{
    const char* oldFile = (currentFileName).c_str();
    const char* newFile = (newFileName).c_str();
    
    if (newFileName.length() < 5){
        cout << newFileName << " is not a valid name, please try again: ";
        return false;
    }
    if (!(isDataFileType(newFileName))) {
        cout << "Invalid format, please try again: " ;
        return false;
    }

    ifstream testFile;
    testFile.open(newFileName);
    if (testFile){      // Checks if the file name already exists, to prevent overwriting of old files
        cout << newFileName << " already exists, please enter another file name : " ;
        testFile.close();
        return false;
    }

    rename(oldFile, newFile);
    testFile.close();
    return true;
}

bool isDataFileType(const string &fileName)
{
    string substr = fileName.substr(fileName.length() - 4);
    substr = to_Lowercase(substr);    // converts the last 4 characters of the string
    return ((substr == ".txt") || (substr == ".csv") || (substr == ".dat"));
}

bool isTXT(const string &fileName)
{
    string substr = fileName.substr(fileName.length() - 4);
    substr = to_Lowercase(substr);    // converts the last 4 characters of the string
    return (substr == ".txt");
}

bool isHTML(const string &fileName)
{
    string substr = fileName.substr(fileName.length() - 5);
    substr = to_Lowercase(substr);
    return(substr == ".html");
}

string to_Lowercase(string str)
{
    for_each(str.begin(), str.end(), [](char & c) {   //converts every character of the string into a lowercase character
        c = ::tolower(c);
    });
    return str;
}

//below are save report function (Boon Zhe)
bool saveReport(const string &tempFileName, const string &saveFileName)
{
    if (saveFileName.length() < 5){
        cout << saveFileName << " is not a valid name, please try again: ";
        return false;
    }
    if (!(isTXT(saveFileName))){
        cout << "Invalid format, please try again: " ;
        return false;
    }
    ifstream testFile;
    testFile.open(saveFileName);
    if (testFile){ // Checks if the file name already exists, to prevent overwriting of old files
        cout << saveFileName << " already exists in the directory, please enter another file name: ";
        testFile.close();
        return false;
    }
    else testFile.close();
    ifstream readFile {tempFileName, std::ios::binary}; // binary doesnt process things like /n
    ofstream writeFile {saveFileName, std::ios::binary};
 
    writeFile << readFile.rdbuf();

    readFile.close();
    writeFile.close();
    return true;
}

bool saveHTMLReport(const string &tempFileName, const string &saveFileName)
{
    if (saveFileName.length() < 6){
        cout << saveFileName << " is not a valid name, please try again: ";
        return false;
    }
    if (!(isHTML(saveFileName))){       // Checks if the file name has .html in it
        cout << "Invalid format, please try again: " ;
        return false;
    }
    ifstream testFile;
    testFile.open(saveFileName);
    if (testFile){ // Checks if the file name already exists, to prevent overwriting of old files
        cout << saveFileName << " already exists in the directory, please enter another file name: " ;
        testFile.close();
        return false;
    }
    else testFile.close();
    ifstream readFile {tempFileName, std::ios::binary}; // binary doesnt process things like /n
    ofstream writeFile {saveFileName, std::ios::binary};
 
    writeFile << readFile.rdbuf();

    readFile.close();
    writeFile.close();
    return true;
}

void clearFile(const string &fileName)
{
    fstream inputFile;
    inputFile.open(fileName, fstream::out | fstream::trunc);
    inputFile.close();
}

//below are generate report functions (Ye Zhian)
bool generateFileOption()
{
    int option;

    cout << "\nDo you want to generate your computation record as report?(Enter 1 as yes,2 as no) : ";
    getIntInput(option);

    while(option < 1 || option > 2){
        cout << "\nPlease enter a valid option: ";
        getIntInput(option);
    }

    if (option==1) {
        cout << "\nDo you want to generate TXT file or HTML file?(1 for TXT file,2 for HTML file,3 for both type of file) : ";
        return true;
    }
    else return false;
}

int generateFileType()
{
    int choose;
    getIntInput(choose);
    while(choose < 1 || choose > 3 ){
        cout << "\n\nPlease enter a valid option: ";
        getIntInput(choose);
    }
    return choose;
}

void generateFile()
{
    int choose;
    string file;

    choose = generateFileType();
    if(choose==1) {
        askForGeneralReportName();
    }

    else if (choose==2){
        endHTMLReport();
        askForGeneralHTMLReportName();
    }

    else if (choose==3){
        endHTMLReport();
        askForGeneralReportName();
        askForGeneralHTMLReportName();
    }
}

void generateCorrReport()
{
    int choose;
    string file;

    choose=generateFileType();
    if(choose==1) {
        askForCorrReportName();
    }

    else if (choose==2){
        endCorrHTMLReport();
        askForCorrHTMLReportName();
    }

    else if (choose==3){
        endCorrHTMLReport();
        askForCorrReportName();
        askForCorrHTMLReportName();
    }
}

void generateDistinctReport()
{
    int choose;
    string file;

    choose=generateFileType();
    if(choose==1) {
    askForDistinctReportName();
    }

    else if (choose==2){
        endDistinctHTMLReport();
        askForDistinctHTMLReportName();
    }

    else if (choose==3){
        endDistinctHTMLReport();
        askForDistinctReportName();
        askForDistinctHTMLReportName();
    }
}

void generateHistogramReport()
{
    int choose;
    string file;

    choose=generateFileType();
    if(choose==1) {
        askForHistogramReportName();
    }

    else if (choose==2){
        endHistogramHTMLReport();
        askForHistogramHTMLReportName();
    }

    else if (choose==3){
        endHistogramHTMLReport();
        askForHistogramReportName();
        askForHistogramHTMLReportName();
    }
}

void generalHistogram(double option,double num)
{
    static_cast<double>(option);
    static_cast<double>(num);
    double arr[3] = {option, 2.0, num};

    ofstream outfile;
    outfile.open("Record1.txt",ios::out | ios::app);

    outfile <<setw(3) << arr[0] << " Histogram           ";
    outfile << "  col";
    outfile << "             "<< arr[2] << endl;

    outfile.close();
}

void generalHistogramHTML(double option,double num)
{
    static_cast<double>(option);
    static_cast<double>(num);
    double arr[3] = {option, 2, num};

    ofstream outfile;
    outfile.open("Record2.html",ios::out | ios::app);

    outfile << "<tr>" << endl;
    outfile << "<td>"<< arr[0] << " Histogram"<< "</td>" << endl;
    outfile << "<td style=\"text-align:center\">"<< " col"<< "</td>" << endl;
    outfile << "<td style=\"text-align:center\">"<<num<< "</td>" << endl;
    outfile << "<td>"<< " "<< "</td>" << endl;
    outfile << "</tr>" << endl;

    outfile.close();
}

void saveHistogram(double num,vector<int> &dataForHistogram,double &bar,double &range, int &dataPoint1)
{
    static_cast<double>(num);

    ofstream outfile;
    outfile.open("histogram.txt",ios::out | ios::app);

    outfile << "\nHistogram for column number "<<num<< ":" << endl;
    outfile << left << setw(11) << "\nCounts" << left << setw(11) << "Range" << endl;
    outfile << "  "<< right << setw(2) << dataForHistogram[0] << right << setw(8) << dataPoint1 << "-" << left << setw(8) << (dataPoint1+range-1);

    for (int j = 0; j < dataForHistogram[0]; j++){
        outfile << "=";
    }
    outfile << endl;

    for (int i = 1; i < bar; i++){
        outfile << "  "<< right << setw(2) << dataForHistogram[i] << right << setw(8) << (dataPoint1+i*range) << "-" << left << setw(8) << (dataPoint1+range*(1+i)-1);
        for (int j = 0; j < dataForHistogram[i]; j++){
            outfile << "=";
        }
        outfile << endl;
    }
    outfile << right << setw(21) << "+/" << "----|----|----|----|----|----|----|----|----|----|/+"<< endl;
    outfile << right << setw(21) << " 0 " << "    5    10   15   20   25   30   35   40   45   50"<< endl;
    outfile << endl;
    outfile.close();
}

void saveHistogramHTML(double num,vector<int> &dataForHistogram,double &bar,double &range, int &dataPoint1) //output of html in html
{
    static_cast<double>(num);

    ofstream outfile;
    outfile.open("histogram.html",ios::out | ios::app);

    outfile << "<br>" << endl;
    outfile << "<table>" << endl;
    outfile << "<caption>Histogram for column number "<<num<< "</caption>" << endl;
    outfile << "<col width=\"90\">" << endl;
    outfile << "<col width=\"90\">" << endl;
    outfile << "<col width=\"500\">" << endl;
    outfile << "<tr>" << endl;
    outfile << "<th>"<< "<span style=\"background-color:#F4AE85\"> Counts </span>" << "</th>"<< endl;
    outfile << "<th style=\"text-align:right\">"<< "<span style=\"background-color:#F4AE85\"> Range </span>" << "</th>"<< endl;
    outfile << "<th>"<< " " << "</th>"<< endl;
    outfile << "</tr>" << endl;
    outfile << "<tr>" << endl;
    outfile << "<td style=\"text-align:center\">"<<dataForHistogram[0] << "</td>" << endl;
    outfile << "<td style=\"text-align:right\">"<<dataPoint1 << "-" << (dataPoint1+range-1) << "</td>" << endl;
    outfile << "<td>";

    for (int j = 0; j < dataForHistogram[0]; j++){
        outfile << "=";
    }

    outfile << "</td>" << endl;
    outfile << "</tr>";
    outfile << endl;
    outfile << "<tr>" << endl;

    for (int i = 1; i < bar; i++){
        outfile << "<td style=\"text-align:center\">"<<dataForHistogram[i] << "</td>" << endl;
        outfile << "<td style=\"text-align:right\">"<<(dataPoint1+i*range) << "-" << (dataPoint1+range*(1+i)-1) << "</td>" << endl;
        outfile << "<td>";
        for (int j = 0; j < dataForHistogram[i]; j++){
            outfile << "=";
        }
        outfile << "</td>" << endl;
        outfile << "</tr>";
        outfile << endl;
    }

    outfile << "<tr>" << endl;
    outfile << "<td>"<< " "<< "</td>" << endl;
    outfile << "<td>"<< " "<< "</td>" << endl;
    outfile << "<td>"<< "=====|=====|=====|=====|=====|=====|=====|=====|=====|/+"<< "</td>" << endl;
    outfile << "</tr>" << endl;
    outfile << "<tr>" << endl;
    outfile << "<td>"<< " "<< "</td>" << endl;
    outfile << "<td>"<< " "<< "</td>" << endl;
    outfile << "<td>&ensp;&nbsp;&emsp;&emsp;5&emsp;&emsp;&nbsp;10&emsp;&emsp;15&emsp;&emsp;20&emsp;&emsp;25&emsp;&emsp;30&emsp;&emsp;35&emsp;&emsp;40&emsp;&emsp;50"<< "</td>" << endl;
    outfile << "</tr>" << endl;
    outfile << "</table>" << endl;
    outfile << endl;
    outfile.close();
}

void generalDistinct(double option, double num)
{
    static_cast<double>(option);
    static_cast<double>(num);
    double arr[3] = {option, 2, num};

    ofstream outfile;
    outfile.open("Record1.txt",ios::out | ios::app);

    outfile <<setw(3) << arr[0] << " Distinct Data       ";
    outfile << "  col";
    outfile << "             "<< arr[2] << endl;

    outfile.close();
}

void generalDistinctHTML(double option, double num)
{
    static_cast<double>(option);
    static_cast<double>(num);
    double arr[3] = {option, 2, num};

    ofstream outfile;
    outfile.open("Record2.html",ios::out | ios::app);

    outfile << "<tr>" << endl;
    outfile << "<td>"<< arr[0] << " Distinct Data"<< "</td>" << endl;
    outfile << "<td style=\"text-align:center\">"<< " col"<< "</td>" << endl;
    outfile << "<td style=\"text-align:center\">"<<num<< "</td>" << endl;
    outfile << "<td>"<< " "<< "</td>" << endl;
    outfile << "</tr>" << endl;

    outfile.close();
}

void saveDistinctData(double num,vector<int> vect, vector<int>& freq,int size) //distinct data computation output in txt
{
    static_cast<double>(num);

    ofstream outfile;
    outfile.open("distinct_data.txt",ios::out | ios::app);

    outfile << "\n\nDisplaying distinct numbers in tabular form (accending order) for column number "<<num << endl;
    outfile << "\n+--------------+-------------+" << endl
           << "| Data numbers |  Frequency  |" << endl
           << "+--------------+-------------+" << endl;

    for(int i = 0; i < size; i++){
        if(freq[i] != -1){
            outfile << "|" << setw(9) << vect[i] << "     |" << setw(8) << freq[i] << "     |" << endl;
        }
    }

    outfile << "+--------------+-------------+" << endl;
    outfile << endl;
    outfile.close();
}

void saveDistinctDataHTML(double num,vector<int> vect, vector<int>& freq,int size) //distinct data computation output in html
{
    static_cast<double>(num);

    ofstream outfile;
    outfile.open("distinct_data.html",ios::out | ios::app);

    outfile << "<br>" << endl;
    outfile << "<table style=\"width:33%\">" << endl;
    outfile << "<caption>Displaying distinct numbers in tabular form (accending order) for column number "<<num<< "</caption>" << endl;
    outfile << "<tr>" << endl;
    outfile << "<th>"<< "Data numbers"<< "</th>" << endl;
    outfile << "<th>"<< "Frequency"<< "</th>" << endl;
    outfile << "</tr>" << endl;

    for(int i = 0; i < size; i++){
        if(freq[i] != -1){
            outfile << "<tr>" << endl;
            outfile << "<td style=\"text-align:center\">"<<vect[i] << "</td>" << endl;
            outfile << "<td style=\"text-align:center\">"<<freq[i] << "</td>"<< endl;
            outfile << "</tr>" << endl;
            outfile << endl;
        }
    }

    outfile << "</table>" << endl;
    outfile << endl;
    outfile.close();
}

void generalCorrHTML(double corr,double option,pair <int, int>& p )
{
    static_cast<double>(option);
    double arr[1] = {option};

    ofstream outfile;
    outfile.open("Record2.html",ios::out | ios::app);

    outfile << "<tr>" << endl;
    outfile << "<td>"<< arr[0] << " Correlation"<< "</td>" << endl;
    outfile << "<td style=\"text-align:center\">"<< "col"<< "</td>" << endl;
    outfile << "<td style=\"text-align:center\">"<<p.first<< ","<<p.second<< "</td>" << endl;
    outfile << "<td>"<< " "<< "</td>" << endl;
    outfile << "</tr>" << endl;

    outfile.close();
}

void generalCorr(double corr,double option,pair <int, int>& p)
{
    static_cast<double>(option);
    double arr[1] = {option};

    ofstream outfile;
    outfile.open("Record1.txt",ios::out | ios::app);

    outfile <<setw(3) << arr[0] << " Correlation         ";
    outfile << "  col";
    outfile << "           "<<p.first<< ","<<p.second << endl;

    outfile.close();
}

void saveCorr(string corr,vector<int> vector_X, vector<int> vector_Y, int size,double sum_X, double sum_Y, double sum_XY, double sumSq_X, double sumSq_Y,pair <int, int>& p)
{
    ofstream outfile;
    outfile.open("correlation.html",ios::out | ios::app);

    outfile << "<br>" << endl;
    outfile << "<table>" << endl;
    outfile << "<caption> Correlation table for column number "<<p.first<< " and "<<p.second<< "</caption>" << endl;
    outfile << "<tr>";
    outfile << "<th>"<< "No."<< "</th>" << endl;
    outfile << "<th>"<< "x"<< "</th>" << endl;
    outfile << "<th>"<< "y"<< "</th>" << endl;
    outfile << "<th>"<< "xy"<< "</th>" << endl;
    outfile << "<th>"<< "square of x"<< "</th>" << endl;
    outfile << "<th>"<< "square of y"<< "</th>" << endl;
    outfile << "</tr>" << endl;

    outfile << setprecision(0) << fixed;

    for (int i = 0; i < size; i++)
    {
        outfile << "<tr>" << endl;
        outfile << "<td>"<<i+1 << "</td>" << endl;
        outfile << "<td>"<<vector_X[i] << "</td>" << endl;
        outfile << "<td>"<<vector_Y[i] << "</td>" << endl;
        outfile << "<td>"<<vector_X[i] * vector_Y[i] << "</td>" << endl;
        outfile << "<td>"<<pow(vector_X[i],2) << "</td>" << endl;
        outfile << "<td>"<<pow(vector_Y[i],2) << "</td>"<< endl;
        outfile << "</tr>" << endl;
    }

    outfile << "<tr>" << endl;
    outfile << "<td>"<< "Sum" << "</td>" << endl;
    outfile << "<td>"<< sum_X << "</td>" << endl;
    outfile << "<td>"<< sum_Y << "</td>" << endl;
    outfile << "<td>"<< sum_XY << "</td>" << endl;
    outfile << "<td>"<< sumSq_X<< "</td>" << endl;
    outfile << "<td>"<< sumSq_Y<< "</td>"<< endl;
    outfile << "</tr>" << endl;
    outfile << "<tr>" << endl;
    outfile << "<td colspan=\"6\" class=\"cap foot\">Correlation of the two column is : "<<corr<< "</td>" << endl;
    outfile << "</tr>" << endl;
    outfile << "</table>" << endl;
    outfile << endl;
    outfile.close();
}

void saveCorrTable(string corr,vector<int> vector_X, vector<int> vector_Y, int size,double sum_X, double sum_Y, double sum_XY, double sumSq_X, double sumSq_Y,pair <int, int>& p)
{
    ofstream outfile;
    outfile.open("correlation.txt",ios::out | ios::app);

    outfile << endl;
    outfile << "\nComputation Table for correlation of column number " <<p.first<< " and "<<p.second<< endl;
    outfile << "\n+-----+-----------+-----------+-----------+-----------------+----------------+" << endl
            << "| No. |     x     |     y     |     xy    |   square of x   |   square of y  |" << endl
            << "+-----|-----------+-----------+-----------+-----------------+----------------+" << endl;

    outfile << setprecision(0) << fixed;
    for (int i = 0; i < size; i++)
    {
        outfile << "| " << setw(3) << i+1 << " | " << setw(9) << vector_X[i] << " | " << setw(9) << vector_Y[i] << " | ";
        outfile << setw(9) << vector_X[i] * vector_Y[i] << " | " << setw(13) << pow(vector_X[i],2);
        outfile << "   | " << setw(12) << pow(vector_Y[i],2) << "   |" << endl;
    }

    outfile << "+-----|-----------+-----------+-----------+-----------------+----------------+" << endl;

    outfile << "| " << setw(3) << "Sum" << " | " << setw(9) << sum_X << " | " << setw(9) << sum_Y << " | " ;
    outfile << setw(9) << sum_XY << " | " << setw(13) << sumSq_X;
    outfile << "   | " << setw(12) << sumSq_Y << "   |" << endl;
    outfile << "+-----|-----------+-----------+-----------+-----------------+----------------+" << endl;
    outfile << "Correlation of the two column is : "<< corr;
    outfile << endl;
    outfile.close();

}

//below are save reords of computations functions (Ye Zhian)
void askForGeneralReportName()
{
    ifstream file;
    string filename;
    file.open("Record1.txt");

    if(file){
        cout << "Please input a name for your txt report(with .txt): ";
        cin >> filename;
        while(!(saveReport("Record1.txt",filename))) {
            cout << "Please input a valid name (with .txt): ";
            cin >> filename;
        }
    }
    systemLog(logFile,usernameDisplay,"generateReport",filename);
    file.close();
}

void askForGeneralHTMLReportName()
{
    ifstream file;
    string filename;
    file.open("Record2.html");

    if(file){
        cout << "Please input a name for your html report(with .html): ";
        cin >> filename;
        while(!(saveHTMLReport("Record2.html",filename))) {
            cout << "Please input a valid name (with .html): ";
        cin >> filename;
    }
    }
    systemLog(logFile,usernameDisplay,"generateHTMLReport",filename);
    file.close();

}

void askForCorrReportName()
{
    ifstream file;
    string filename;
    file.open("correlation.txt");

    if(file){
        cout << "Please input a name for your correlation txt report(with .txt): ";
        cin >> filename;
        while((saveReport("correlation.txt",filename)==false)) {
            cout << "Please input a valid name (with .txt): ";
            cin >> filename;
        }
    }
    systemLog(logFile,usernameDisplay,"generateReport",filename);
    file.close();
}

void askForCorrHTMLReportName()
{
    ifstream file;
    string filename;
    file.open("correlation.html");

    if(file){
        cout << "Please input a name for your correlation html report(with .html): ";
        cin >> filename;
        while(!(saveHTMLReport("correlation.html",filename))) {
            cout << "Please input a valid name (with .html): ";
            cin >> filename;
        }

    }
    systemLog(logFile,usernameDisplay,"generateHTMLReport",filename);
    file.close();
}

void askForDistinctReportName()
{
    ifstream file;
    string filename;
    file.open("distinct_data.txt");

    if(file){
        cout << "Please input a name for your distinct data txt report(with .txt): ";
        cin >> filename;
        while(!(saveReport("distinct_data.txt",filename))) {
            cout << "Please input a valid name (with .txt): ";
        cin >> filename;
    }
    }
    systemLog(logFile,usernameDisplay,"generateReport",filename);
    file.close();
}

void askForDistinctHTMLReportName()
{
    ifstream file;
    string filename;
    file.open("distinct_data.html");

    if(file){
        cout << "Please input a name for your distinct data html report(with .html): ";
        cin >> filename;
        while(!(saveHTMLReport("distinct_data.html",filename))) {
            cout << "Please input a valid name (with .html): ";
            cin >> filename;
        }
    }
    systemLog(logFile,usernameDisplay,"generateHTMLReport",filename);
    file.close();
}

void askForHistogramReportName()
{
    ifstream file;
    string filename;
    file.open("histogram.txt");

    if(file){
        cout << "Please input a name for your histogram txt report(with .txt): ";
        cin >> filename;
        while(!(saveReport("histogram.txt",filename))) {
            cout << "Please input a valid name (with .txt): ";
    cin >> filename;
}
    }
    systemLog(logFile,usernameDisplay,"generateReport",filename);
    file.close();
}

void askForHistogramHTMLReportName()
{
    ifstream file;
    string filename;
    file.open("histogram.html");

    if(file){
        cout << "Please input a name for your histogram html report(with .html): ";
        cin >> filename;
        while(!(saveHTMLReport("histogram.html",filename))) {
            cout << "Please input a valid name (with .html): ";
        cin >> filename;
    }
    }
    systemLog(logFile,usernameDisplay,"generateHTMLReport",filename);
    file.close();
}

void savaData(double option, char rowOrCol, double num, double result) 
{
    double rc;
    if (rowOrCol == 'r') rc = 1.0; // means row
    else rc = 2.0;                // means column

    static_cast<double>(option);
    static_cast<double>(num);
    double arr[4] = {option, rc, num, result};

    ofstream outfile;
    outfile.open("Record1.txt",ios::out | ios::app);

    if (arr[0]==1) outfile <<setw(3) << arr[0] << " Minimum             ";
    else if (arr[0]==2) outfile <<setw(3) << arr[0] << " Maximum             ";
    else if (arr[0]==3) outfile <<setw(3) << arr[0] << " Median              ";
    else if (arr[0]==4) outfile <<setw(3) << arr[0] << " Mean                ";
    else if (arr[0]==5) outfile <<setw(3) << arr[0] << " Variance            ";
    else if (arr[0]==6) outfile <<setw(3) << arr[0] << " Standard deviation  ";

    if (arr[1]==1) outfile << "  row";
    else if (arr[1]==2) outfile << "  col";

    outfile << "             "<< arr[2];
    outfile << "            "<< arr[3];
    outfile << endl;

    outfile.close();
}

void saveDataHTML(double option, char rowOrCol, double num, double result) 
{
     double rc;
     if (rowOrCol == 'r') rc = 1.0; // means row
     else rc = 2.0;                // means column

     static_cast<double>(option);
     static_cast<double>(num);
     double arr[4] = {option, rc, num, result};

    ofstream outfile;
    outfile.open("Record2.html",ios::out | ios::app);

    outfile << "<body>" << endl;
    outfile << "<tr>" << endl;
    if (arr[0]==1) outfile << "<td>"<< arr[0] << " Minimum"<< "</td>";
    else if (arr[0]==2) outfile << "<td>"<< arr[0] << " Maximum"<< "</td>";
    else if (arr[0]==3) outfile << "<td>"<< arr[0] << " Median"<< "</td>";
    else if (arr[0]==4) outfile << "<td>"<< arr[0] << " Mean"<< "</td>";
    else if (arr[0]==5) outfile << "<td>"<< arr[0] << " Variance"<< "</td>";
    else if (arr[0]==6) outfile << "<td>"<< arr[0] << " Standard deviation"<< "</td>";

    if (arr[1]==1) outfile << "<td style=\"text-align:center\">"<< "row"<< "</td>";
    else if (arr[1]==2) outfile << "<td style=\"text-align:center\">"<< "col"<< "</td>";

    outfile << "<td style=\"text-align:center\">"<< arr[2] << "</td>";
    outfile << "<td style=\"text-align:center\">"<< arr[3] << "</td>";
    outfile << endl;
    outfile << "</tr>" << endl;

    outfile.close();
}

void askToSaveReport(int option, char rowOrCol, int num, double result) 
{
    int choose;
    string save;
    cout << "\nDo you want to save this record? (Enter 1 = yes, enter other keys = no) : ";
    getIntInput(choose);

    if (choose==1) {
        cout << "\nYour record has been saved" << endl;
        savaData(option,rowOrCol,num,result);
        saveDataHTML(option,rowOrCol,num,result);

        if (option==1) save="Minimum";
        else if (option==2) save="Maximum";
        else if (option==3) save="Median";
        else if (option==4) save="Mean";
        else if (option==5) save="Variance";
        else if (option==6) save="Standard Deviation";
        systemLog(logFile,usernameDisplay,"saveComputation",save);
    }
    else return;
}

void askToSaveCorrReport(double corr,int option,vector<int> vector_X, vector<int> vector_Y, int size,double sum_X, double sum_Y, double sum_XY, double sumSq_X, double sumSq_Y,pair <int, int>& p)
{
    int choose;
    cout << "\nDo you want to save this record? (Enter 1 = yes, enter other keys = no) : ";
    getIntInput(choose);

    if (choose==1) {
        cout << "\nYour record has been saved" << endl;
        generalCorr(corr,option,p);
        generalCorrHTML(corr,option,p);
        saveCorrTable(to_string(corr),vector_X,vector_Y,size,sum_X,sum_Y,sum_XY,sumSq_X,sumSq_Y,p);
        saveCorr(to_string(corr),vector_X,vector_Y,size,sum_X,sum_Y,sum_XY,sumSq_X,sumSq_Y,p);
        systemLog(logFile,usernameDisplay,"saveComputation","Correlation");
    }
    else return;
}

void askToSaveDistinctReport(int option,int num, vector<int> vect, vector<int>& freq,int size)
{
    int choose;
    cout << "\nDo you want to save this record? (Enter 1 = yes, enter other keys = no) : ";
    getIntInput(choose);

    if (choose==1) {
        cout << "\nYour record has been saved" << endl;
        generalDistinct(option,num);
        generalDistinctHTML(option,num);
        saveDistinctData(num,vect,freq,size);
        saveDistinctDataHTML(num,vect,freq,size);
        systemLog(logFile,usernameDisplay,"saveComputation","Distinct Data");
    }
    else return;
}

void askToSaveHistogramReport(int option,int num,vector<int> &dataForHistogram,double &bar,double &range, int &dataPoint1)
{
    int choose;
    cout << "\nDo you want to save this record? (Enter 1 = yes, enter other keys = no) : ";
    getIntInput(choose);

    if (choose==1) {
        cout << "\nYour record has been saved" << endl;
        generalHistogram(option,num);
        generalHistogramHTML(option,num);
        saveHistogram(num,dataForHistogram,bar,range,dataPoint1);
        saveHistogramHTML(num,dataForHistogram,bar,range,dataPoint1);
        systemLog(logFile,usernameDisplay,"saveComputation","Histogram");
    }
    else return;
}

// below are ending code of HTML file (Ye Zhian)
void endHTMLReport()
{
    ofstream outfile;
    outfile.open("Record2.html",ios::out | ios::app);

    outfile << "</table>" << endl;
    outfile << "</center>" << endl;

    outfile.close();
}

void endCorrHTMLReport()
{
    ofstream outfile;
    outfile.open("correlation.html",ios::out | ios::app);

    outfile << "</center>" << endl;

    outfile.close();
}

void endDistinctHTMLReport()
{
    ofstream outfile;
    outfile.open("distinct_data.html",ios::out | ios::app);

    outfile << "</center>" << endl;

    outfile.close();
}

void endHistogramHTMLReport()
{
    ofstream outfile;
    outfile.open("histogram.html",ios::out | ios::app);

    outfile << "</center>" << endl;

    outfile.close();
}

void clearAllFile()
{
    clearFile("Record1.txt");
    clearFile("Record2.html");
    clearFile("correlation.txt");
    clearFile("correlation.html");
    clearFile("distinct_data.txt");
    clearFile("distinct_data.html");
    clearFile("histogram.txt");
    clearFile("histogram.html");
}

// below are file header functions (Ye Zhian)
void startReportFile()
{
    ofstream outfile;
    outfile.open("Record1.txt",ios::out | ios::app);

    outfile <<setw(10) << "Option"<<setw(21) << "Row/Col"<<setw(18) << "Num of row/col"<<setw(11) << "Result " << endl;

    outfile.close();
}

void startHTMLReportFile()
{
    ofstream outfile;
    outfile.open("Record2.html",ios::out | ios::app);

    outfile << "<style>" << endl;
    outfile << "table {" << endl;
    outfile << "border-collapse: collapse;" << endl;
    outfile << "border-spacing: 0;" << endl;
    outfile << "}" << endl;
    outfile << "th," << endl;
    outfile << "td {" << endl;
    outfile << "border: 1px solid #cecfd5;" << endl;
    outfile << "padding: 10px 15px;" << endl;
    outfile << "}" << endl;
    outfile << "thead {" << endl;
    outfile << "background: #395870;" << endl;
    outfile << "colour: #fff;" << endl;
    outfile << "}" << endl;
    outfile << "tbody tr:nth-child(even) {" << endl;
    outfile << "background: #f0f0f2;" << endl;
    outfile << "}" << endl;
    outfile << "td {" << endl;
    outfile << "border-bottom: 1px solid #cecfd5;" << endl;
    outfile << "border-right: 1px solid #cecfd5;" << endl;
    outfile << "}" << endl;
    outfile << "td:first-child {" << endl;
    outfile << "border-left: 1px solid #cecfd5;" << endl;
    outfile << "}" << endl;
    outfile << "</style>" << endl;

    outfile << "<center>" << endl;
    outfile << "<table>" << endl;
    outfile << "<br>" << endl;
    outfile << "<h1>Computation Report<h2>" << endl;
    outfile << "<tr>" << endl;
    outfile << "<th>"<< "Option"<< "</th>";
    outfile << "<th>"<< "Row/Col"<< "</th>";
    outfile << "<th>"<< "Num of row/col"<< "</th>";
    outfile << "<th>"<< "Result "<< "</th>" << endl;
    outfile << "</tr>" << endl;

    outfile.close();
}

void startCorrHTMLReportFile()
{
    ofstream outfile;
    outfile.open("correlation.html",ios::out | ios::app);
    outfile << "<center>" << endl;
    outfile << "<br>" << endl;
    outfile << "<h1>Computation Table for Correlation</h1>" << endl;
    outfile << "<style>" << endl;
    outfile << "table {" << endl;
    outfile << "border-collapse: collapse;" << endl;
    outfile << "border-spacing: 0;" << endl;
    outfile << "}" << endl;
    outfile << "th," << endl;
    outfile << "td {" << endl;
    outfile << "border: 1px solid #cecfd5;" << endl;
    outfile << "padding: 10px 15px;" << endl;
    outfile << "}" << endl;
    outfile << "thead {" << endl;
    outfile << "background: #395870;" << endl;
    outfile << "colour: #fff;" << endl;
    outfile << "}" << endl;
    outfile << "tbody tr:nth-child(even) {" << endl;
    outfile << "background: #f0f0f2;" << endl;
    outfile << "}" << endl;
    outfile << "td {" << endl;
    outfile << "border-bottom: 1px solid #cecfd5;" << endl;
    outfile << "border-right: 1px solid #cecfd5;" << endl;
    outfile << "}" << endl;
    outfile << "td:first-child {" << endl;
    outfile << "border-left: 1px solid #cecfd5;" << endl;
    outfile << "}" << endl;
    outfile << "</style>" << endl;

    outfile.close();
}

void startDistinctHTMLReportFile()
{
    ofstream outfile;
    outfile.open("distinct_data.html",ios::out | ios::app);
    outfile << "<center>" << endl;
    outfile << "<br>" << endl;
    outfile << "<h1>Computation Table for Distinct Data</h1>" << endl;
    outfile << "<style>" << endl;
    outfile << "table {" << endl;
    outfile << "border-collapse: collapse;" << endl;
    outfile << "border-spacing: 0;" << endl;
    outfile << "}" << endl;
    outfile << "th," << endl;
    outfile << "td {" << endl;
    outfile << "border: 1px solid #cecfd5;" << endl;
    outfile << "padding: 10px 15px;" << endl;
    outfile << "}" << endl;
    outfile << "thead {" << endl;
    outfile << "background: #395870;" << endl;
    outfile << "colour: #fff;" << endl;
    outfile << "}" << endl;
    outfile << "tbody tr:nth-child(even) {" << endl;
    outfile << "background: #f0f0f2;" << endl;
    outfile << "}" << endl;
    outfile << "td {" << endl;
    outfile << "border-bottom: 1px solid #cecfd5;" << endl;
    outfile << "border-right: 1px solid #cecfd5;" << endl;
    outfile << "}" << endl;
    outfile << "td:first-child {" << endl;
    outfile << "border-left: 1px solid #cecfd5;" << endl;
    outfile << "}" << endl;
    outfile << "</style>" << endl;

    outfile.close();
}

void startHistogramHTMLReportFile()
{
    ofstream outfile;
    outfile.open("histogram.html",ios::out | ios::app);
    outfile << "<center>" << endl;
    outfile << "<br>" << endl;
    outfile << "<h1>Computation Table for Histogram</h1>" << endl;
    outfile << "<style>" << endl;
    outfile << "table {" << endl;
    outfile << "border-collapse: collapse;" << endl;
    outfile << "border: 1px solid black;" << endl;
    outfile << "}" << endl;
    outfile << "th," << endl;
    outfile << "td {" << endl;
    outfile << "font-size:20px;" << endl;
    outfile << "}" << endl;
    outfile << "</style>" << endl;
    outfile.close();
}
