//Michael
//Figueroa
//900389292
//CS1410, crn 11297, Fall 2018
//Programming Assignment 5

#include <iostream> // for input & output
#include <cstdlib>  // For rand and srand
#include <ctime>    // For the time function
#include <fstream>  // For input and output of file
#include <iomanip>  // to limit decimal places for average
using namespace std;

//function to find average
double CalculateScore(int score1, int score2, int score3, int score4)
{

    //find lowest
    double lowest = score1;
    if (score2 < lowest)
        lowest = score2;
    else if (score3 < lowest)
        lowest = score3;
    else if (score4 < lowest)
        lowest = score4;

    //find average with lowest scores dropped
    int total = score1 + score2 + score3 + score4;
    double average = (total - lowest) / 3;

    return average;
}

int main()
{
    ofstream outputFile;
    outputFile.open("figueroa.txt");

    cout << "Enter the number of bowlers: (3-6): " << endl;
    int numBowlers;
    cin >> numBowlers;

    if (numBowlers < 3 || numBowlers > 6)
        cout << "Please enter a number between (3-6)" << endl;
    else
        cout << "There are " << numBowlers << " bowlers." << endl;
    cout << endl;

    outputFile << "There are " << numBowlers << " bowlers." << endl;

    for (int i = 1; i <= numBowlers; i++)
    {
        //set min and max score values
        const int MIN_VALUE = 80;
        const int MAX_VALUE = 180;

        //get the system time.
        int seed = time(0);
        int srand(seed);
        int score1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
        int score2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
        int score3 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
        int score4 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

        //output scores to console
        cout << "Scores for Bowler " << i << " are: " << score1 << ", " << score2 << ", " << score3 << ", " << score4 << endl;

        //output average to console
        double averageNew = CalculateScore(score1, score2, score3, score4);
        cout << "The average is " << setprecision(4) << averageNew << endl;
        cout << endl;

        //output to text file
        outputFile << "Scores for Bowler " << i << " are: " << score1 << ", " << score2 << ", " << score3 << ", " << score4 << endl;
        outputFile << "The average is " << setprecision(4) << averageNew << endl;
    }

    outputFile.close();

    return 0;
}
